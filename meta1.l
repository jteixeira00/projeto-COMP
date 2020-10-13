
%X SINGLECOMMENT MULTICOMMENT


%{
    #include <string.h>
    int flag1 = 1;
    int linha = 0;
    int coluna = 0;

    int commentstart_l;
    int commentstart_c;
%}





sinal       [+|-]
letra       [a-zA-Z_]
numero      [0-9]
numeros07   [0-7]
expoente    [eE]{sinal}?0|[1-9]{numero}*

ID          {letra}({numero}*{letra}*)*
INTLIT      {numero}+
CHRLIT      \'[^\n\']\'|\'(\\n)\'|\'(\\t)\'|\'(\\\\)\'|\'\\\'\'|\'(\\\")\'|\'(\\{numeros07}{numeros07}?{numeros07}?)\'
REALLIT     (0|[1-9]{numero}*"."{numero}*{expoente}?)|("."{numero}+{expoente}?)|(0|[1-9]{numero}*{expoente})

%%

"char"              {if(flag1==1){printf("CHAR\n");}coluna+=yyleng;}
"else"              {if(flag1==1){printf("ELSE\n");}coluna+=yyleng;}
"while"             {if(flag1==1){printf("WHILE\n");}coluna+=yyleng;}
"if"                {if(flag1==1){printf("IF\n");}coluna+=yyleng;}
"int"               {if(flag1==1){printf("INT\n");}coluna+=yyleng;}
"short"             {if(flag1==1){printf("SHORT\n");}coluna+=yyleng;}
"double"            {if(flag1==1){printf("DOUBLE\n");}coluna+=yyleng;}
"return"            {if(flag1==1){printf("RETURN\n");}coluna+=yyleng;}
"void"              {if(flag1==1){printf("VOID\n");}coluna+=yyleng;}
"&"                 {if(flag1==1){printf("BITWISEAND\n");}coluna+=yyleng;}
"|"                 {if(flag1==1){printf("BITWISEOR\n");}coluna+=yyleng;}
"^"                 {if(flag1==1){printf("BITWISEXOR\n");}coluna+=yyleng;}
"&&"                {if(flag1==1){printf("AND\n");}coluna+=yyleng;}
"="                 {if(flag1==1){printf("ASSIGN\n");}coluna+=yyleng;}
"*"                 {if(flag1==1){printf("MUL\n");}coluna+=yyleng;}
","                 {if(flag1==1){printf("COMMA\n");}coluna+=yyleng;}
"/"                 {if(flag1==1){printf("DIV\n");}coluna+=yyleng;}
"=="                {if(flag1==1){printf("EQ\n");}coluna+=yyleng;}
">="                {if(flag1==1){printf("GE\n");}coluna+=yyleng;}
">"                 {if(flag1==1){printf("GT\n");}coluna+=yyleng;}
"{"                 {if(flag1==1){printf("LBRACE\n");}coluna+=yyleng;}
"<="                {if(flag1==1){printf("LE\n");}coluna+=yyleng;}
"("                 {if(flag1==1){printf("LPAR\n");}coluna+=yyleng;}
"<"                 {if(flag1==1){printf("LT\n");}coluna+=yyleng;}
"-"                 {if(flag1==1){printf("MINUS\n");}coluna+=yyleng;}
"%"                 {if(flag1==1){printf("MOD\n");}coluna+=yyleng;}
"!="                {if(flag1==1){printf("NE\n");}coluna+=yyleng;}
"!"                 {if(flag1==1){printf("NOT\n");}coluna+=yyleng;}
"||"                {if(flag1==1){printf("OR\n");}coluna+=yyleng;}
"+"                 {if(flag1==1){printf("PLUS\n");}coluna+=yyleng;}
"}"                 {if(flag1==1){printf("RBRACE\n");}coluna+=yyleng;}
")"                 {if(flag1==1){printf("RPAR\n");}coluna+=yyleng;}
";"                 {if(flag1==1){printf("SEMI\n");}coluna+=yyleng;}
{ID}                {if(flag1==1){printf("ID(%s)\n", yytext);}coluna+=yyleng;}
{INTLIT}            {if(flag1==1){printf("INTLIT(%s)\n", yytext);}coluna+=yyleng;}
{CHRLIT}            {if(flag1==1){printf("CHRLIT(%s)\n", yytext);}coluna+=yyleng;}
{REALLIT}           {if(flag1==1){printf("REALLIT(%s)\n", yytext);}coluna+=yyleng;}


"//"				{BEGIN SINGLECOMMENT;}
<SINGLECOMMENT>\n	{linha++; coluna = 1; BEGIN 0;}
<SINGLECOMMENT>.	{;}


"/*"					{BEGIN MULTICOMMENT; commentstart_l = linha;commentstart_c = coluna; coluna +=yyleng;}
<MULTICOMMENT>\n		{linha++;coluna = 1;}
<MULTICOMMENT><<EOF>>	{printf("Line %d, col %d : unterminated comment\n")}
<MULTICOMMENT>.			{coluna+=yyleng;}
<MULTICOMMENT>"*/"		{BEGIN 0; coluna+=yyleng;}


%%

int main(int argc, char *argv[]){
	if (argc > 1){
		if (strcmp(argv[1], "-1")==0){
			flag1 = 1;
		}
		else if (strcmp(argv[1], "-e1")==0){
			flag1 = 0;

		}
		else{
			return 0;
		}


	}
	if (argc==1){
		flag1 = 0;

	}

    yylex();
    return 0;
}

int yywrap(){
    return 1;
}
