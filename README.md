In acest proiect avem mai multe fisiere.c, unul pentru fiecare task, in care se implementeaza un interpretor de biti similar unui procesor. Acesta va avea capacitatea de a decodifica si executa instructiuni simple de adunare, scadere, inmultire si impartire. 
Informatia este stocata sub forma de biti. Pentru un procesor informatia se repartizeaza in doua categorii: date si instructiuni. Practic, dandu-se un sir de biti, procesorul decodifica instructiunea, iar ulterior o executa.

Task 1:
Se da o instructiune sub forma unui numar, care prin intermediul shiftarii la dreapta a bitilor, se converteste in binar. 
Primii trei biti reprezinta numarul de instructiuni, ultimii patru sunt dimensiunea, iar ce ramane sunt operatiile, fiind ascociati doi biti pentru fiecare operatie (+, -, *, /).

Task 2:
Se bazeaza pe executarea instructiunii, avand operanzii si operatiile, trebuie calculat rezultatul, ce se va stoca in variabila result, folosidu-se, totodata, o functie auxiliara ecuation pentru realizarea operatiilor de adunare, scadere, inmultire si impartire. Calcularea rezultatului se va face in ordinea primirii operatiilor, nu conform prioritatii lor. 

Task 3:
In cadrul acestui task se extinde implementarea de la taskul 2 pentru a executa instructiuni ale caror operanzi pot avea orice dimensiune din intervalul [1,16[]. 

Task 4:
Acest task implementeaza precedenta operanzilor, astfel incat * si / au precedenta egala intre ei, insa precedenta mai mare decat + si -. 