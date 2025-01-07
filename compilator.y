%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilator.tab.h"

#define INT_TYPE 1
#define DOUBLE_TYPE 2
#define FLOAT_TYPE 3

extern FILE* yyin;
extern int lineNo;
extern int colNo;
int hasError = 0;
int yyerror(const char* s);
void yyrestart  (FILE * input_file );
extern int yylex();

class Symbol 
{
    char name[128];
    double value;
    int type;
    Symbol* next;

    Symbol* head;
    Symbol* tail;

public:
    Symbol();
    ~Symbol();
    bool exists(const char* n);
    void add(const char* n, int t);
    void setValue(const char* n, double v);
    double getValue(const char* n);
    int getType(const char* n);
    void printSymbols();
    void freeSymbols();
};

Symbol::Symbol() 
{
    head = nullptr;
    tail = nullptr;
}

Symbol::~Symbol() 
{
    freeSymbols();
}

bool Symbol::exists(const char* n) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
            return true;
        current = current->next;
    }
    return false;
}

void Symbol::add(const char* n, int t) 
{
    if (exists(n)) 
    {
        yyerror("Variable already declared");
        return;
    }
    Symbol* sym = new Symbol();
    strncpy(sym->name, n, sizeof(sym->name) - 1);
    sym->value = 0;
    sym->type = t;
    sym->next = nullptr;

    if (head == nullptr) 
    {
        head = tail = sym;
    } 
    else 
    {
        tail->next = sym;
        tail = sym;
    }
}

void Symbol::setValue(const char* n, double v) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
        {
            current->value = v;
            return;
        }
        current = current->next;
    }
    yyerror("Variable not declared");
}

double Symbol::getValue(const char* n) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
        {
            return current->value;
        }
        current = current->next;
    }
    yyerror("Variable not declared");
    return 0;
}

int Symbol::getType(const char* n) 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->name, n) == 0) 
        {
            return current->type;
        }
        current = current->next;
    }
    yyerror("Variable not declared");
    return 0;
}

void Symbol::printSymbols() 
{
    Symbol* current = head;
    printf("\nSymbol Table:\n");
    while (current != nullptr) 
    {
        printf("Name: %s Type: %s Value: %f\n", current->name, 
               (current->type == INT_TYPE ? "int" : 
                current->type == DOUBLE_TYPE ? "double" : "float"),
               current->value);
        current = current->next;
    }
}

void Symbol::freeSymbols() 
{
    Symbol* current = head;
    while (current != nullptr) 
    {
        Symbol* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

Symbol* symbolTable=nullptr;
%}



%union {
    int int_val;
    double double_val;
    char* str_val;
}



%token <int_val> TOK_DECLARE_INT TOK_DECLARE_DOUBLE TOK_DECLARE_FLOAT
%token TOK_LPAREN TOK_RPAREN
%token <int_val> TOK_MULTIPLY TOK_DIVIDE TOK_PLUS TOK_MINUS TOK_ASSIGN TOK_SEMICOLON
%token TOK_IF TOK_ELSE TOK_EQUAL TOK_GREATER TOK_LESS TOK_LESS_EQUAL TOK_GREATER_EQUAL TOK_NOT_EQUAL TOK_LBRACE TOK_RBRACE 
%token <int_val> TOK_INT
%token <double_val> TOK_DOUBLE
%token <str_val> TOK_FLOAT
%token <str_val> TOK_ID 
%token TOK_PRINT TOK_SCANF
%token TOK_COMMA
%token <str_val> TOK_STRING TOK_AMPERSAND
%type <double_val> expr condition

%left TOK_PLUS TOK_MINUS
%left TOK_MULTIPLY TOK_DIVIDE
%left TOK_LPAREN TOK_RPAREN 

%%

program:
    statements
    {
        if (hasError)  YYABORT;
    }
    | 
    {
        if (hasError)  YYABORT;
    }
    ;



statements:
    statements statement
    {
        if (hasError)  YYABORT;
    }
    | statement
    {
        if (hasError)  YYABORT;
    }
    ;


statement:
    declaration
    {
        if (hasError)  YYABORT;
    }
    | assignment
    {
        if (hasError)  YYABORT;
    }
    | TOK_IF TOK_LPAREN condition TOK_RPAREN TOK_LBRACE statements TOK_RBRACE TOK_ELSE TOK_LBRACE statements TOK_RBRACE
    {
        if ($3) 
        {
            printf("DEBUG: Executing 'if' block\n");
        } else {
            printf("DEBUG: Executing 'else' block\n");
        }
    }
    |TOK_IF TOK_LPAREN condition TOK_RPAREN TOK_LBRACE statements TOK_RBRACE
    {
        if ($3) 
        {
            printf("DEBUG: Executing 'if' block\n");
        }
    }
  
    | TOK_PRINT TOK_LPAREN TOK_STRING TOK_RPAREN TOK_SEMICOLON
    {
         if (hasError) YYABORT;
        printf("%s\n", $3);
    }
    | TOK_PRINT TOK_LPAREN TOK_STRING TOK_COMMA TOK_ID TOK_RPAREN TOK_SEMICOLON
    {
        if (hasError)  YYABORT;
        if (!symbolTable->exists($5)) 
        {
            yyerror("Variable not declared");
            YYABORT;
        } 
        else 
        {
            int type = symbolTable->getType($5);
            double value = symbolTable->getValue($5);
            char result[1024];
            char* temp = $3;

            if ((strcmp(temp, "%d") == 0 && type == INT_TYPE)) 
            {
                printf("%d\n", (int)value);
            } 
            else if 
            ((strcmp(temp, "%f") == 0 || strcmp(temp, "%lf") == 0) && 
                       (type == DOUBLE_TYPE || type == FLOAT_TYPE))
            {
                printf("%f\n", value);
            } 
            else if (strstr(temp, "%d") && type == INT_TYPE) 
            {
                snprintf(result, sizeof(result), temp, (int)value);
                printf("%s\n", result);
            } 
            else if 
            ((strstr(temp, "%f") || strstr(temp, "%lf")) && 
                       (type == DOUBLE_TYPE || type == FLOAT_TYPE)) 
            {
                snprintf(result, sizeof(result), temp, value);
                printf("%s\n", result);
            } 
            else 
            {
                yyerror("Tip de variabila incompatibil cu formatul din printf!");
                YYABORT;
            }
        }
    }
    | TOK_SCANF TOK_LPAREN TOK_STRING TOK_COMMA TOK_AMPERSAND TOK_ID TOK_RPAREN TOK_SEMICOLON
    {   
        if(strcmp($5,"&"))
        {
            yyerror("Use & if you want to assign a value!\n");
            YYABORT;
        }
        else
        if (!symbolTable->exists($6)) 
        {
            yyerror("Variable not declared!\n");
            YYABORT;
        } else 
        {
            int type = symbolTable->getType($6);
            if ((strcmp($3, "%d") == 0 && type != INT_TYPE) ||
                (strcmp($3, "%f") == 0 && type != FLOAT_TYPE) ||
                (strcmp($3, "%lf") == 0 && type != DOUBLE_TYPE)) 
                {
                yyerror("Format does not match variable type!\n");
                YYABORT;
                } 
                else 
                {
                    double value;
                    printf("Introduce value for  %s: ", $6);
                    scanf("%lf", &value);
                    symbolTable->setValue($6,value);
                }
            }
        }
    ;

declaration:
    //declaratie int
    TOK_DECLARE_INT TOK_ID TOK_SEMICOLON
    {
        if (symbolTable->exists($2)) 
        {
            yyerror("Redeclaration of variable");
            yyin=NULL;
            YYABORT;
        } 
        else 
        {
            symbolTable->add($2, INT_TYPE);
            printf("Declaratie: int %s\n", $2);
        }
    }
    //declaratie double
    | TOK_DECLARE_DOUBLE TOK_ID TOK_SEMICOLON
    {
        if (symbolTable->exists($2)) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add($2, DOUBLE_TYPE);
            printf("Declaratie: double %s\n", $2);
        }
    }
    //declaratie float
    | TOK_DECLARE_FLOAT TOK_ID TOK_SEMICOLON
    {
        if (symbolTable->exists($2)) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else
        {
            symbolTable->add($2, FLOAT_TYPE);
            printf("Declaratie: float %s\n", $2);
        }
    }
    //declaratie int cu asignare
    | TOK_DECLARE_INT TOK_ID TOK_ASSIGN expr TOK_SEMICOLON
    {
        if (symbolTable->exists($2)) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add($2, INT_TYPE);
            symbolTable->setValue($2,(int)$4);
            printf("Declaratie: int %s = %d\n", $2, (int)$4);
        }
    }
    //declaratie double cu asignare
    | TOK_DECLARE_DOUBLE TOK_ID TOK_ASSIGN expr TOK_SEMICOLON
    {
        if (symbolTable->exists($2)) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add($2, DOUBLE_TYPE);
            symbolTable->setValue($2, $4);
            printf("Declaratie: double %s = %lf\n", $2, $4);
        }
    }
    //declaratie float cu asignare
    | TOK_DECLARE_FLOAT TOK_ID TOK_ASSIGN expr TOK_SEMICOLON
    {
        if (symbolTable->exists($2)) 
        {
            yyerror("Redeclaration of variable");
            YYABORT;
        } 
        else 
        {
            symbolTable->add($2, FLOAT_TYPE);
            symbolTable->setValue($2, $4);
            printf("Declaratie: float %s = %lf\n", $2, $4);
        }
    }
    ;


assignment:
    //asignare cu expresii
    TOK_ID TOK_ASSIGN expr TOK_SEMICOLON
    {
        if (!symbolTable->exists($1)) 
        {
            yyerror("Variable not declared");
        }

        if (hasError)  YYABORT;

        int type = symbolTable->getType($1);

        if (hasError)  YYABORT;

        if(symbolTable->getType($1)==INT_TYPE)
        {
            symbolTable->setValue($1,(int)$3);
        }
        else
            symbolTable->setValue($1,$3);

        if (type == INT_TYPE) 
        {
            printf("Atribuire: %s = %d\n", $1, (int)$3);
        } 
        else if (type == FLOAT_TYPE) 
        {
            printf("Atribuire: %s = %f\n", $1, (float)$3);
        } 
        else 
        {
            printf("Atribuire: %s = %lf\n", $1, $3);
        }
    }
    ;

//conditii pentru if
condition:
    expr TOK_GREATER expr        { $$ = $1 > $3 ? 1 : 0; }
    | expr TOK_LESS expr         { $$ = $1 < $3 ? 1 : 0; }
    | expr TOK_EQUAL expr        { $$ = $1 == $3 ? 1 : 0; }
    | expr TOK_NOT_EQUAL expr    { $$ = $1 != $3 ? 1 : 0; }
    | expr TOK_GREATER_EQUAL expr { $$ = $1 >= $3 ? 1 : 0; }
    | expr TOK_LESS_EQUAL expr   { $$ = $1 <= $3 ? 1 : 0; }
    | expr                       { $$ = $1 != 0 ? 1 : 0; }
    ;

expr:
    TOK_INT                     { $$ = $1; }
    | TOK_DOUBLE                { $$ = $1; }
    | TOK_FLOAT                 { $$ = atof($1); }
    //pentru cast-uri
    | TOK_LPAREN TOK_DECLARE_INT TOK_RPAREN TOK_ID
    {
        $$ = (double)((int)symbolTable->getValue($4));
    }
    | TOK_LPAREN TOK_DECLARE_DOUBLE TOK_RPAREN TOK_ID
    {
        $$ = symbolTable->getValue($4);
    }
    | TOK_LPAREN TOK_DECLARE_FLOAT TOK_RPAREN TOK_ID
    {
        $$ = (double)((float)symbolTable->getValue($4));
    }
    | TOK_ID                    { $$ = symbolTable->getValue($1); }
    | expr TOK_PLUS expr        { $$ = $1 + $3; }
    | expr TOK_MINUS expr       { $$ = $1 - $3; }
    | expr TOK_MULTIPLY expr    { $$ = $1 * $3; }
    | expr TOK_DIVIDE expr
    {
        if ($3 == 0) {
            yyerror("Divizare la zero!");
            YYABORT;
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
    //pentru paranteze in efectuarea calculelor
    | TOK_LPAREN expr TOK_RPAREN { $$ = $2; }
    //daca vrem sa facem cast la o expresie
    | TOK_LPAREN TOK_DECLARE_INT TOK_RPAREN expr
    {
        $$ = (double)((int)$4);
    }
    | TOK_LPAREN TOK_DECLARE_DOUBLE TOK_RPAREN expr
    {
        $$ = $4;
    }
    | TOK_LPAREN TOK_DECLARE_FLOAT TOK_RPAREN expr
    {
        $$ = (double)((float)$4);
    }
    ;


%%

int yyerror(const char* s) 
{
    fprintf(stderr, "Eroare at line %d, column %d: %s\n", lineNo, colNo, s);
    hasError = 1;
    return 1;
}


int main(int argc, char* argv[]) 
{
    char line[1024];          

    printf("Tasteaza comenzi:\nRuleaza scripturi folosind comanda 'run nume_script':\n'exit' pentru a iesi.\n");

    while (1) 
    {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) 
            break;

        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0) 
        {
            printf("Iesire...\n");
            if (symbolTable != nullptr) {
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable = nullptr;
            }
            break;
        }

        if (strncmp(line, "run ", 4) == 0) 
        {   
            if (symbolTable != nullptr) 
            {
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable = nullptr;
            }

            symbolTable = new Symbol();

            char* filename = line + 4;
            FILE* file = fopen(filename, "r");
            if (!file) {
                perror("Eroare la deschiderea fisierului");
                continue;
            }

            lineNo = 1;
            colNo = 1;

            printf("Executam scriptul: %s\n", filename);
            yyin = file;

            yyparse();
            yyrestart(yyin);
            fclose(file);

            if (hasError) 
            {
                printf("Scriptul contine erori. Revenire la prompt.\n");
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable=nullptr;
                hasError = 0;
                continue;
            }

            printf("Scriptul a fost executat cu succes.\n");
            symbolTable->freeSymbols();
            delete symbolTable;
            symbolTable=nullptr;
        } 
        else 
        {   
            if(symbolTable==nullptr)
                {
                    symbolTable = new Symbol();
                    lineNo = 1;
                    colNo = 1;
                }

            FILE* cmdFile = fmemopen(line, strlen(line), "r");
            if (!cmdFile) 
            {
                perror("Eroare la procesarea comenzii");
                continue;
            }

            yyin = cmdFile;
            yyparse();
            fclose(cmdFile);

            if (hasError) 
            {
                printf("Comanda contine erori. Revenire la prompt.\n");
                hasError = 0;
                symbolTable->freeSymbols();
                delete symbolTable;
                symbolTable=nullptr;
                continue;
            }

            printf("Comanda a fost executata cu succes.\n");
            lineNo++;
            colNo=1;
        }
    }
    return 0;
}
