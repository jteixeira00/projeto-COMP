#!/bin/sh

sudo lex uccompiler.l 
sudo yacc -d --verbose uccompiler.y 
sudo cc -o uccompiler y.tab.c lex.yy.c 