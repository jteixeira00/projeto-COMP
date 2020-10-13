%{
    #include <string.h>
    int flag1 = 0;
    int linha = 0;
    int coluna = 0;


%}


sinal       [+|-]
letra       [a-zA-Z_]
numero      [0-9]
numeros07   [0-7]
expoente    [eE]{sinal}?0|[1-9]{numero}*

ID          {letra}{numero}*{letra}*
INTLIT      {numero}+
CHRLIT      [^\n\']|(\\n)|(\\t)|(\\\\)|(\\\")|(\\{numeros07}{numeros07}?{numeros07}?)
REALLIT     (0|[1-9]{numero}*"."{numero}*{expoente}?)|("."{numero}+{expoente}?)|(0|[1-9]{numero}*{expoente})
RESERVED    "auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"enum"|"extern"|"float"|"for"|"goto"|"[", "]"|"++"|"--"


%%


{ID}                {if(flag1==1){printf("ID(%s)\n", yytext);}coluna+=yleng;}
{INTLIT}            {if(flag1==1){printf("INTLIT(%s)\n", yytext);}coluna+=yleng;}
{CHRLIT}            {if(flag1==1){printf("CHRLIT(%s)\n", yytext);}coluna+=yleng;}
{REALLIT}           {if(flag1==1){printf("REALLIT(%s)\n", yytext);}coluna+=yleng;}
"char"              {if(flag1==1){printf("CHAR\n");}coluna+=yleng;}
"else"              {if(flag1==1){printf("ELSE\n");}coluna+=yleng;}
"while"             {if(flag1==1){printf("WHILE\n");}coluna+=yleng;}
"if"                {if(flag1==1){printf("IF\n");}coluna+=yleng;}
"int"               {if(flag1==1){printf("INT\n");}coluna+=yleng;}
"short"             {if(flag1==1){printf("SHORT\n");}coluna+=yleng;}
"double"            {if(flag1==1){printf("DOUBLE\n");}coluna+=yleng;}
"return"            {if(flag1==1){printf("RETURN\n");}coluna+=yleng;}
"void"              {if(flag1==1){printf("VOID\n");}coluna+=yleng;}
"&"                 {if(flag1==1){printf("BITWISEAND\n");}coluna+=yleng;}
"|"                 {if(flag1==1){printf("BITWISEOR\n");}coluna+=yleng;}
"^"                 {if(flag1==1){printf("BITWISEXOR\n");}coluna+=yleng;}
"&&"                {if(flag1==1){printf("AND\n");}coluna+=yleng;}
"="                 {if(flag1==1){printf("ASSIGN\n");}coluna+=yleng;}
"*"                 {if(flag1==1){printf("MUL\n");}coluna+=yleng;}
","                 {if(flag1==1){printf("COMMA\n");}coluna+=yleng;}
"/"                 {if(flag1==1){printf("DIV\n");}coluna+=yleng;}
"=="                {if(flag1==1){printf("EQ\n");}coluna+=yleng;}
">="                {if(flag1==1){printf("GE\n");}coluna+=yleng;}
">"                 {if(flag1==1){printf("GT\n");}coluna+=yleng;}
"{"                 {if(flag1==1){printf("LBRACE\n");}coluna+=yleng;}
"<="                {if(flag1==1){printf("LE\n");}coluna+=yleng;}
"("                 {if(flag1==1){printf("LPAR\n");}coluna+=yleng;}
"<"                 {if(flag1==1){printf("LT\n");}coluna+=yleng;}
"-"                 {if(flag1==1){printf("MINUS\n");}coluna+=yleng;}
"%"                 {if(flag1==1){printf("MOD\n");}coluna+=yleng;}
"!="                {if(flag1==1){printf("NE\n");}coluna+=yleng;}
"!"                 {if(flag1==1){printf("NOT\n");}coluna+=yleng;}
"||"                {if(flag1==1){printf("OR\n");}coluna+=yleng;}
"+"                 {if(flag1==1){printf("PLUS\n");}coluna+=yleng;}
"}"                 {if(flag1==1){printf("RBRACE\n");}coluna+=yleng;}
")"                 {if(flag1==1){printf("RPAR\n");}coluna+=yleng;}
";"                 {if(flag1==1){printf("SEMI\n");}coluna+=yleng;}

{RESERVED}          {if(flag1==1){printf("RESERVED(%s)\n", yytext);}coluna+=yleng;}