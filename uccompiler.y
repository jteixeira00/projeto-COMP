%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #define MAX 256
    int yylex(void);
    int yylex_destroy();
    int yylex();
    void yyerror(char *s);
    
    int flag2 = 0; //flag return


    typedef struct node{
        char* type;
        char* value;
        struct node *dad;
        struct node *bros;
        struct node *childs[MAX];
        int indexc;
    }node;

    struct node *head = NULL;
    struct node* createnode(char *type, char *value);
    struct node* addchild(node *dad, node *child);
    struct node* addbro(node *n1, node *n2);


%}


%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR 
%token <str> AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE
%token RPAR SEMI 

%token <str> RESERVED CHRLIT ID REALLIT INTLIT

%type <node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatementsOp
%type <node> DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterListOp ParameterDeclaration
%type <node> Declaration DeclarationOp TypeSpec Declarator Statement StatementOp Expr ExprOp4




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
%nonassoc THEN
%nonassoc ELSE

%union{
    char *str;
    struct node *node;
}

%%

Program:                    FunctionsAndDeclarations                    {   head = createnode("Program","");
                                                                            $$ = head;

                                                                            }
    ;
FunctionsAndDeclarations:   FunctionDefinition FunctionsAndDeclarations       {
    
                                                                            }
               
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

                |               INT                                         {struct node *typeInt = createnode("Int","");
                                                                            $$ = typeInt;}

                |               VOID                                        {}

                |               SHORT                                       {}
                
                |               DOUBLE                                      {}

    ;                        


Declarator:                     ID                                          {}

                |               ID ASSIGN Expr                              {}

    ;

Statement:                      SEMI                                            {$$ = NULL;}

                |               Expr SEMI                                       {$$ = $1;}


                |               LBRACE Statement RBRACE                         {$$ = $2;}
        
                |               LBRACE Statement Statement StatementOp RBRACE   {struct node *statlist = createnode("StatList", "");
                                                                                addchild(statlist, $2);
                                                                                addchild(statlist, $3);
                                                                                addbro($2, $3);
                                                                                if ($4 != NULL){
                                                                                    addchild(statlist, $4);
                                                                                    addbro($3, $4);}                                                                                
                                                                                $$ = statlist;}

                |               IF LPAR Expr RPAR Statement     %prec THEN      {struct node *if1 = createnode("If","");
                                                                                addchild(if1, $3);
                                                                                addchild(if1, $5);
                                                                                struct node *null = createnode("Null", "");
                                                                                addchild(if1, null);
                                                                                addbro($3, $5);
                                                                                addbro($5, null);
                                                                                $$ = if1;
                                                                                } 


                |               IF LPAR Expr RPAR Statement ELSE Statement      {struct node *if2 = createnode("If", "");
                                                                                addchild(if2, $3);
                                                                                addchild(if2, $5);
                                                                                addchild(if2, $7);
                                                                                addbro($3, $5);
                                                                                addbro($5, $7);
                                                                                $$ = if2;
                                                                                }


                |               WHILE LPAR Expr RPAR Statement                  {struct node *while1 = createnode("While", "");
                                                                                addchild(while1, $3);
                                                                                addchild(while1, $5);
                                                                                addbro($3, $5);
                                                                                $$ = while1;
                                                                                }


                |               RETURN SEMI                                     {struct node *return1 = createnode("Return", "");
                                                                                struct node *null = createnode("Null","");
                                                                                addchild(return1, null);
                                                                                $$=return1;
                                                                                }

                |               RETURN Expr SEMI                                {}

    ;



StatementOp:                  Statement StatementOp                             {}
                |                                                               {$$ = NULL;}
                
    ;                 


Expr:                           Expr ASSIGN Expr                                {struct node *store = createnode("Store","");
                                                                                 addchild(store, $1);
                                                                                 addchild(store, $3);
                                                                                 addbro($1, $3);
                                                                                 $$ = store;}

                |               Expr COMMA Expr                                 {struct node *comma = createnode("Comma","");
                                                                                 addchild(comma, $1);
                                                                                 addchild(comma, $3);
                                                                                 addbro($1, $3);
                                                                                 $$ = comma;}


                |               Expr PLUS Expr                                {struct node *add = createnode("Add","");
                                                                                addchild(add, $1);
                                                                                    addchild(add, $3);
                                                                                 addbro($1, $3);
                                                                                 $$ = add;}                                                                                

                |               Expr MINUS Expr                                {struct node *sub = createnode("Sub","");
                                                                                addchild(sub, $1);
                                                                                addchild(sub, $3);
                                                                                addbro($1, $3);
                                                                                $$ = sub;}
                                                                                
                |               Expr MUL Expr                                {struct node *mul = createnode("Mul","");
                                                                                addchild(mul, $1);
                                                                                addchild(mul, $3);
                                                                                addbro($1, $3);
                                                                                $$ = mul;}

                |               Expr DIV Expr                                {struct node *div = createnode("Div","");
                                                                                addchild(div, $1);
                                                                                addchild(div, $3);
                                                                                addbro($1, $3);
                                                                                $$ = div;}

                |               Expr MOD Expr                                {struct node *mod = createnode("Mod","");
                                                                                addchild(mod, $1);
                                                                                addchild(mod, $3);
                                                                                addbro($1, $3);
                                                                                $$ = mod;}
            
                |               Expr OR Expr                               {struct node *or = createnode("Or","");
                                                                                addchild(or, $1);
                                                                                addchild(or, $3);
                                                                                addbro($1, $3);
                                                                                $$ = or;}

                |               Expr AND Expr                               {struct node *and = createnode("And","");
                                                                                addchild(and, $1);
                                                                                addchild(and, $3);
                                                                                addbro($1, $3);
                                                                                $$ = and;}

                |               Expr BITWISEAND Expr                            {struct node *bitewiseand = createnode("BitWiseAnd","");
                                                                                addchild(bitewiseand, $1);
                                                                                addchild(bitewiseand, $3);
                                                                                addbro($1, $3);
                                                                                $$ = bitewiseand;}

                |               Expr BITWISEOR Expr                               {struct node *bitewiseor = createnode("BitWiseOr","");
                                                                                addchild(bitewiseor, $1);
                                                                                addchild(bitewiseor, $3);
                                                                                addbro($1, $3);
                                                                                $$ = bitewiseor;}

                |               Expr BITWISEXOR Expr                               {struct node *bitewisexor = createnode("BitWiseXor","");
                                                                                addchild(bitewisexor, $1);
                                                                                addchild(bitewisexor, $3);
                                                                                addbro($1, $3);
                                                                                $$ = bitewisexor;}

                |               Expr EQ Expr                                {struct node *eq = createnode("Eq","");
                                                                                addchild(eq, $1);
                                                                                addchild(eq, $3);
                                                                                addbro($1, $3);
                                                                                $$ = eq;}

                |               Expr NE Expr                                {struct node *ne = createnode("Ne","");
                                                                                addchild(ne, $1);
                                                                                addchild(ne, $3);
                                                                                addbro($1, $3);
                                                                                $$ = ne;}

                |               Expr LE Expr                                {struct node *le = createnode("Le","");
                                                                                addchild(le, $1);
                                                                                addchild(le, $3);
                                                                                addbro($1, $3);
                                                                                $$ = le;}
                |               Expr GE Expr                                {struct node *ge = createnode("Ge","");
                                                                                addchild(ge, $1);
                                                                                addchild(ge, $3);
                                                                                addbro($1, $3);
                                                                                $$ = ge;}

                |               Expr LT Expr                                {struct node *lt = createnode("Lt","");
                                                                                addchild(lt, $1);
                                                                                addchild(lt, $3);
                                                                                addbro($1, $3);
                                                                                $$ = lt;}
                |               Expr GT Expr                                {struct node *gt = createnode("Gt","");
                                                                                addchild(gt, $1);
                                                                                addchild(gt, $3);
                                                                                addbro($1, $3);
                                                                                $$ = gt;}

                
                |               PLUS Expr                                       {struct node *plus = createnode("Plus","");
                                                                                    $$ = addchild(plus,$2);}

                |               MINUS Expr                                      {struct node *minus = createnode("Minus","");
                                                                                    $$ = addchild(minus,$2);}

                |               NOT Expr                                        {struct node *not = createnode("Not","");
                                                                                    $$ = addchild(not,$2);}


                |               ID LPAR ExprOp4 RPAR                            {struct node *id1 = createnode("Id","");
                                                                                struct node *call = createnode("Call","");
                                                                                addchild(call, id1);
                                                                                addchild(call, $3);
                                                                                addbro(id1, $3); 
                                                                                $$ = call;}
                                

                |               ID                                              {$$ = createnode("Id", "");}

                |               INTLIT                                          {$$ = createnode("IntLit", "");}

                |               CHRLIT                                          {$$ = createnode("ChrLit", "");}

                |               REALLIT                                         {$$ = createnode("RealLit", "");}
                
                |               LPAR Expr RPAR                                  {$$ = $2;}  
    ;


    
ExprOp4:                        ExprOp4 COMMA Expr                            	{struct node *comma = createnode("Comma","");
                                                                                 addchild(comma, $1);
                                                                                 addchild(comma, $3);
                                                                                 addbro($1, $3);
                                                                                 $$ = comma;}
                |               Expr  %prec THEN                                {$$ = $1;}            
                |                                                               {$$ = NULL; }
    ;



%%

struct node* createnode(char *type, char *value){
    node *new = (node *)malloc(sizeof(node));

    if(new==NULL){
        return NULL;
    }
    new->type = type;
    new->value = value;
    new->indexc = 0;
    new->dad = NULL;
    new->bros = NULL;
    return new;
}

struct node* addchild(struct node* dad, struct node* child){
    if (dad == NULL || child == NULL){
       return NULL;
    }

    dad->childs[dad->indexc] = child;
    dad->indexc++;
    child->dad = dad;

    node *aux = child->bros;

    while (aux != NULL){
        aux->dad = dad;
        dad->childs[dad->indexc] = aux;
        dad->indexc++;
        aux = aux->bros;
    }

    return dad;
}

struct node *addbro(struct node* n1, struct node* n2){
    struct node* aux= n1;
    if(aux!=NULL){
        while (aux->bros!=NULL){
            aux = aux->bros;
        }
        aux->bros = n2;
    }
    return n1;
}


void yyerror(char *msg) {
    printf("%s", msg);
}