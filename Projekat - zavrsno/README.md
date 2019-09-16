# KK-DAG-od-TAC
## Projekat iz predmeta Konstrukcija Kompilatora (Matf, Beograd)


### Kratki opis:
Za zadati ulazni troadresni kod program generise graf na dot (graphviz) jeziku, koji nakon prevodjenja daje prikaz grafa kao izlaz

#### Pokretanje:
**make** - prevodi parser, lexer i ast i rezultat je **./graf**
**./graf < test > test.dot** - prosledjujemo na ulaz zadati TAC i izlaz ispisujemo u **test.dot**
**dot -Tpng test.dot -o test.png** - prevodjenje dot datoteke i generisanje slike u **.PNG** formatu
