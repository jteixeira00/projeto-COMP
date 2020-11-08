lex $1
yacc -d --verbose $2 
cc -o $3 y.tab.c lex.yy.c