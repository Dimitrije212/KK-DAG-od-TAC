# KK-DAG-od-TAC
## Projekat iz predmeta Konstrukcija Kompilatora (Matf, Beograd)


### Kratki opis:
Za zadati ulazni troadresni kod program generise graf na dot (graphviz) jeziku, koji nakon prevodjenja daje prikaz grafa kao izlaz

#### Pokretanje:
**make** - prevodi parser, lexer i ast i rezultat je **./graf** <br>
**./graf < test > test.dot** - prosledjujemo na ulaz zadati TAC i izlaz ispisujemo u **test.dot** <br>
**dot -Tpng test.dot -o test.png** - prevodjenje dot datoteke i generisanje slike u **.PNG** formatu <be>
  
### Literatura:
Takodje možete naći i *dotguide.pdf* koji sam koristio kao dodatni materijal kod graphviz-a
