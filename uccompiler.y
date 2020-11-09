%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    int yylex(void);
    int yylex_destroy();
    int yylex();
    void yyerror(char *s);
    
    int flag2 = 0; //flag return
%}



%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR 
%token <str> AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE
%token RPAR SEMI 

%token <str> RESERVED CHRLIT ID REALLIT INTLIT


%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT

%nonassoc IF
%nonassoc ELSE


%union{
    char *str;
}

%%

FunctionsAndDeclarations:   FunctionDefinition FunctionsAndDeclarations       {}
               
                |           FunctionDeclaration FunctionsAndDeclarations     {}

                |           Declaration FunctionsAndDeclarations            {}

                |                                                           {}
    ;

FunctionDefinition:         TypeSpec FunctionDeclarator FunctionBody        {}
    ;

FunctionBody:               LBRACE DeclarationsAndStatementsOp RBRACE       {}
    ;

DeclarationsAndStatementsOp:    DeclarationsAndStatements                   {}
                
                |                                                           {}
    ;

DeclarationsAndStatements:      Statement DeclarationsAndStatements         {}

                |               Declaration DeclarationsAndStatements       {}

                |               Statement                                   {}

                |               Declaration                                 {}

    ;

FunctionDeclaration:            TypeSpec FunctionDeclarator SEMI            {}

    ;

FunctionDeclarator:             ID LPAR ParameterList RPAR                  {}
    ;

ParameterList:                  ParameterDeclaration ParameterListOp        {}
    ;

ParameterListOp:                COMMA ParameterDeclaration ParameterListOp  {}
                |                                                           {}

    ;

ParameterDeclaration:           TypeSpec                                    {}

                |               TypeSpec ID                                 {}


    ;

Declaration:                    TypeSpec Declarator DeclarationOp SEMI      {}

    ;

DeclarationOp:                  COMMA Declarator DeclarationOp                           {}
                |                                                           {}

    ;

TypeSpec:                       CHAR                                        {}

                |               INT                                         {}

                |               VOID                                        {}

                |               SHORT                                        {}
                
                |               DOUBLE                                       {}

    ;                        


Declarator:                     ID                                          {}

                |               ID ASSIGN Expr                              {}

    ;

Statement:                      SEMI                                            {}

                |               Expr SEMI                                       {}


                |               LBRACE StatementOp RBRACE                       {}


                |               IF LPAR Expr RPAR Statement                     {}

                |               IF LPAR Expr RPAR Statement ELSE Statement      {}


                |               WHILE LPAR Expr RPAR Statement                  {}


                |               RETURN SEMI                                     {}

                |               RETURN Expr SEMI                                {}

    ;


StatementOp:                    Statement StatementOp                           {}
                |                                                               {}
    ;



Expr:                           Expr ASSIGN Expr                                {}

                |               Expr COMMA Expr                                 {}


                |               Expr PLUS Expr                                {}
                |               Expr MINUS Expr                                {}
                |               Expr MUL Expr                                {}
                |               Expr DIV Expr                                {}
                |               Expr MOD Expr                                {}
            

                |               Expr OR Expr                               {}
                |               Expr AND Expr                               {}
                |               Expr BITWISEAND Expr                               {}
                |               Expr BITWISEOR Expr                               {}
                |               Expr BITWISEXOR Expr                               {}

                |               Expr EQ Expr                                {}
                |               Expr NE Expr                                {}
                |               Expr LE Expr                                {}
                |               Expr GE Expr                                {}
                |               Expr LT Expr                                {}
                |               Expr GT Expr                                {}

                
                |               PLUS Expr                                            {}

                |               MINUS Expr                                            {}

                |               NOT Expr                                            {}


                |               ID LPAR RPAR                                    {}

                |               ID LPAR Expr ExprOp4 RPAR                       {}


                |               ID                                              {}

                |               INTLIT                                          {}

                |               CHRLIT                                          {}

                |               REALLIT                                         {}
                
                |               LPAR Expr RPAR                                  {}

    ;  




                
    
ExprOp4:                        COMMA Expr ExprOp4                            {}
                |                                                               {}
    ;



%%


void yyerror(char *msg) {
    printf("%s", msg);
}