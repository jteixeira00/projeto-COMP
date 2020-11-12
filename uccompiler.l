
%X SINGLECOMMENT MULTICOMMENT

%{
    #include <string.h>
	#include "y.tab.h"
    int flag1;	//tokens encontrados
	int flag2; //returns
    int linha = 1;
    int coluna = 1;
    int commentstart_l;
    int commentstart_c;
%}




%option yylineno
sinal       [+|-]
letra       [a-zA-Z_]
numero      [0-9]
numeros07   [0-7]
expoente    [eE]{sinal}?{numero}+

ID          {letra}({numero}*{letra}*)*
INTLIT      {numero}+
CHRLIT      \'[^\n\\']\'|\'(\\n)\'|\'(\\t)\'|\'(\\\\)\'|\'\\\'\'|\'(\\\")\'|\'(\\{numeros07}{numeros07}?{numeros07}?)\'
REALLIT     ({numero}+"."{numero}*{expoente}?)|("."{numero}+{expoente}?)|({numero}+{expoente})
RESERVED	"++"|"--"|"["|"]"|"auto"|"break"|"case"|"const"|"volatile"|"_Bool"|"_Complex"|"_Imaginary"|"continue"|"restrict"|"default"|"do"|"long"|"inline"|"register"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatie"|"enum"|"extern"|"float"|"for"|"goto"


%%
{RESERVED}			{
						if(flag1==1){
							printf("RESERVED(%s)\n", yytext);
							}
						coluna+=yyleng;							
						yylval.str = (char *) strdup(yytext);
                        if(flag2 == 1){
							return RESERVED;
						}
						
					}

"char"              {
						if(flag1==1){
							printf("CHAR\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return CHAR;
						}
					}

"else"              {
						if(flag1==1){
							printf("ELSE\n");
							}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return ELSE;
						}
					}
"while"             {
						if(flag1==1){
							printf("WHILE\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return WHILE;
						}
					}

"if"                {
						if(flag1==1){
							printf("IF\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return IF;
						}
					}
					
"int"               {
						if(flag1==1){
							printf("INT\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return INT;
						}
					}

"short"             {
						if(flag1==1){
							printf("SHORT\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return SHORT;
						}
					}

"double"            {
						if(flag1==1){
							printf("DOUBLE\n");
							}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return DOUBLE;
						}
					}

"return"            {
						if(flag1==1){
							printf("RETURN\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return RETURN;
						}
					}

"void"              {
						if(flag1==1){
							printf("VOID\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return VOID;
						}
					}

"&"                 {
						if(flag1==1){
							printf("BITWISEAND\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return BITWISEAND;
						}
					}

"|"                 {
						if(flag1==1){
							printf("BITWISEOR\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return BITWISEOR;
						}
					}

"^"                 {
						if(flag1==1){
							printf("BITWISEXOR\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return BITWISEXOR;
						}
					}

"&&"                {
						if(flag1==1){
							printf("AND\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return AND;
						}
					}

"="                 {
						if(flag1==1){
							printf("ASSIGN\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return ASSIGN;
						}
					}

"*"                 {
						if(flag1==1){
							printf("MUL\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return MUL;
						}
					}

","                 {
						if(flag1==1){
							printf("COMMA\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return COMMA;
						}
					}

"/"                 {
						if(flag1==1){
							printf("DIV\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return DIV;
						}
					}

"=="                {
						if(flag1==1){
							printf("EQ\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return EQ;
						}
					}


">="                {
						if(flag1==1){
							printf("GE\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return GE;
						}
					}

">"                 {
						if(flag1==1){
							printf("GT\n");
						}
						coluna+=yyleng;	
                        if(flag2 == 1){
                            return GT;
						}
					}

"{"                 {
						if(flag1==1){
							printf("LBRACE\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return LBRACE;
						}
					}

"<="                {
						if(flag1==1){
							printf("LE\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return LE;
						}
					}

"("                 {
						if(flag1==1){
							printf("LPAR\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return LPAR;
						}
					}
					
"<"                 {
						if(flag1==1){
							printf("LT\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return LT;
						}
					}

"-"                 {
						if(flag1==1){
							printf("MINUS\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return MINUS;
						}
					}

"%"                 {
						if(flag1==1){
							printf("MOD\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return MOD;
						}
					}

"!="                {
						if(flag1==1){
							printf("NE\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return NE;
						}
					}

"!"                 {
						if(flag1==1){
							printf("NOT\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return NOT;
						}
					}

"||"                {
						if(flag1==1){
							printf("OR\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return OR;
						}
					}

"+"                 {
						if(flag1==1){
							printf("PLUS\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return PLUS;
						}
					}

"}"                 {
						if(flag1==1){
							printf("RBRACE\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return RBRACE;
						}
					}

")"                 {
						if(flag1==1){
							printf("RPAR\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return RPAR;
						}
					}

";"                 {
						if(flag1==1){
							printf("SEMI\n");
						}
						coluna+=yyleng;
                        if(flag2 == 1){
                            return SEMI;
						}
					}

" "|\t|\r|\f		{
						coluna+=yyleng;
					}

{INTLIT}            {
						if(flag1==1){
							printf("INTLIT(%s)\n", yytext);
						}
						coluna+=yyleng;
						yylval.str = (char *) strdup(yytext);
                        if(flag2 == 1){
							return INTLIT;
						}
					}

{REALLIT}           {
						if(flag1==1){
							printf("REALLIT(%s)\n", yytext);
						}
						coluna+=yyleng;
						yylval.str = (char *) strdup(yytext);
                        if(flag2 == 1){
							return REALLIT;
						}
					}
					
{ID}                {
						if(flag1==1){
							printf("ID(%s)\n", yytext);
						}
						coluna+=yyleng;
						yylval.str = (char *) strdup(yytext);
                        if(flag2 == 1){
							return ID;
						}
					}

{CHRLIT}            {
						if(flag1==1){
							printf("CHRLIT(%s)\n", yytext);
						}
						coluna+=yyleng;
						yylval.str = (char *) strdup(yytext);
                        if(flag2 == 1){
							return CHRLIT;
						}
					}

\'([^\n'\\]|(\\.))*'	{
							printf("Line %d, col %d: invalid char constant (%s)\n", linha, coluna,yytext); 
							coluna+=yyleng;
						}

\'([^\n'\\]|(\\.))*\\?	{
							printf("Line %d, col %d: unterminated char constant\n", linha, coluna); 
							coluna=1;
						}


\n|\r\n|\r 				{
							linha++;
							coluna=1;;
						}

.					{
						printf("Line %d, col %d: illegal character (%s)\n", linha, coluna, yytext);
						coluna+=yyleng;
					}
					




"//"				{BEGIN SINGLECOMMENT;}
<SINGLECOMMENT>\n	{
						linha++; 
						coluna = 1; 
						BEGIN 0;
					}

<SINGLECOMMENT>.	{;}


"/*"					{BEGIN MULTICOMMENT; 
						commentstart_l = linha;
						commentstart_c = coluna; 
						coluna +=yyleng;
						}

<MULTICOMMENT>\n		{
							linha++;
							coluna = 1;
						}

<MULTICOMMENT><<EOF>>	{
							printf("Line %d, col %d: unterminated comment\n", commentstart_l, commentstart_c);
							return 0;
						}

<MULTICOMMENT>.			{coluna+=yyleng;}

<MULTICOMMENT>"*/"		{coluna+=yyleng;BEGIN 0;}





%%
int yywrap(){
    return 1;
}


