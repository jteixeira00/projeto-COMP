#!/bin/sh

flex $1.l
yacc -d --verbose $1.y
clang -o $1 y.tab.c lex.yy.c 