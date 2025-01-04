Folosind utilitarele flex & bison, implementati un interpreter pentru un limbaj de programare asemanator
cu C, care indeplineste urmatoarele cerinte:
1. Tipuri de Date Suportate:
• Interpretorul trebuie să suporte tipurile de date int, double și float.
• Trebuie să permită declararea și inițializarea variabilelor pentru fiecare dintre aceste
tipuri.
• Exemplu: int a = 5; double b = 3.14; float c = 2.5f;
2. Operații Aritmetice:
• Implementează operații aritmetice de bază: adunare, scădere, înmulțire, împărțire.
• Asigură-te că operațiile respectă regulile de conversie a tipurilor în C.
• Exemplu: a + b; b * c; a / 2;
3. Instrucțiuni de Control:
• Implementează instrucțiuni de control: if, else: executa ambele instructiuni indiferent de rezultatul din if((:
4. Input și Output:
• Permite citirea de input de la utilizator pentru variabile.
• Implementează afișarea de output în consolă.
• Exemplu:
printf("Introdu un numar: ");
scanf("%d", &a);
printf("Ai introdus: %d", a);
5. Gestionarea Erorilor:
• Tratează erorile comune, cum ar fi împărțirea la zero și depășirea limitelor tipurilor de
date.
• Afișează mesaje de eroare adecvate pentru utilizator.
• Exemplu:
// Împărțirea la zero
int d = 0;
if (d == 0) {
printf("Eroare: Împărțire la zero!");
} else {
a = a / d; }

6. Conversii de Tip:
• Implementează conversii explicite între int, double și float.
• Exemplu: double e = (double)a; float f = (float)e;
7. Comentarii:
• Permite utilizarea comentariilor de o linie (//) și pe mai multe linii (/* ... */).
• Exemplu:
// Aceasta este o linie de comentariu
int x = 5; /* Acesta este un comentariu
pe mai multe linii */
8. Interfață Utilizator:
• Dezvoltă o interfață simplă de linie de comandă pentru interacțiunea cu interpretorul.
• Asigură că interpretorul poate executa atât comenzi individuale, cât și scripturi din fișiere.
• Exemplu:
În linia de comandă: > int x = 5;
Executarea unui script dintr-un fișier: > run script.txt
