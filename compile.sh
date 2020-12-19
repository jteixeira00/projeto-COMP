#!/bin/sh

flex $1.l
yacc -d --graph $1.y
clang -g -o $1 y.tab.c lex.yy.c 