graf: lex.yy.o parser.o ast.o
	g++ -Wall -o $@ $^
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex
	flex $<
parser.o: parser.tab.cpp parser.tab.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -v -d $<
ast.o: ast.cpp ast.hpp
	g++ -Wall -c -o $@ $<

.PHONY: clean

clean:
	rm -f *~ *tab* lex.yy.c *.o stek_masina
