%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include "y.tab.h"
    extern char *yytext;
    int type;

    int flag1 = 0; 	//tokens encontrados
	int flag2 = 0; 	//return
	int lex_erros = 0;
    int yydebug = 1;
    #define MAX 512
    int yylex();
    int yylex_destroy();
    
    extern int yywrap();
    


    extern int linha;
    extern int yyleng;
    extern int coluna;
    
    void yyerror (char *s);
    
    //int flag2 = 0; //flag return


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
    void print_tree(node *head, int depth);


%}


%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR 
%token <str> AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE
%token RPAR SEMI 

%token <str> RESERVED CHRLIT ID REALLIT INTLIT

%type <node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatementsOp StatementError
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
%left DIV MUL MOD
%right NOT

%nonassoc IF
%nonassoc THEN
%nonassoc ELSE

%union{
    char *str;
    struct node *node;
}

%%

Program:                    FunctionsAndDeclarations                        {head = createnode("Program","");
																			addchild(head,$1);
                                                                            $$ = head;}

    ;

FunctionsAndDeclarations:   FunctionDefinition FunctionsAndDeclarations       {
                                                                            if($2!=NULL){
                                                                                addbro($1, $2);
                                                                                }
                                                                            $$ = $1;}
               
                |           FunctionDeclaration FunctionsAndDeclarations     {
                                                                             if($2!=NULL){
                                                                                addbro($1, $2);
                                                                                }
                                                                            $$ = $1;
                                                                            }

                |           Declaration FunctionsAndDeclarations            {
                                                                            if($2!=NULL){
                                                                                addbro($1, $2);
                                                                                }
                                                                            $$ = $1;
                                                                            }

                |                                                           {$$ = NULL;}
    ;

FunctionDefinition:         TypeSpec FunctionDeclarator FunctionBody        {struct node *functiondef = createnode("FuncDefinition", "");
                                                                           
                                                                            addchild(functiondef, $1);
                                                                            addchild(functiondef, $2);
                                                                            addchild(functiondef, $3);
                                                                            addbro($1, $2);
                                                                            addbro($2, $3);
                                                                            $$ = functiondef;}
    ;

FunctionBody:               LBRACE DeclarationsAndStatementsOp RBRACE       {struct node *funcbody = createnode("FuncBody", "");
                                                                            addchild(funcbody, $2);
                                                                            $$ = funcbody;}
    ;

DeclarationsAndStatementsOp:    DeclarationsAndStatements                   {$$=$1;} 
                |                                                           {$$ = NULL;}
    ;

DeclarationsAndStatements:      Statement DeclarationsAndStatements         {
                                                                            if($2!=NULL){
                                                                                addbro($1, $2);}
                                                                            $$=$1;}

                |               Declaration DeclarationsAndStatements       {if($2!=NULL){
                                                                                addbro($1, $2);}
                                                                            $$=$1;}

                |               Statement                                   {$$ = $1;}

                |               Declaration                                 {$$ = $1;}

    ;

FunctionDeclaration:            TypeSpec FunctionDeclarator SEMI            {struct node *funcdeclaration = createnode("FuncDeclaration", "");
                                                                            addchild(funcdeclaration, $1);
                                                                            addchild(funcdeclaration, $2);
                                                                            addbro($1, $2);
                                                                            $$ = funcdeclaration;}

    ;

FunctionDeclarator:             ID LPAR ParameterList RPAR                  {struct node *id1 = createnode("Id",$1);
                                                                            addbro(id1, $3);
                                                                            $$ = id1;
                                                                            }
    ;

ParameterList:                  ParameterDeclaration ParameterListOp        {struct node *paramlist = createnode("ParamList", "");
                                                                            addchild(paramlist, $1);
                                                                            if($2!=NULL){
                                                                                addchild(paramlist, $2);
                                                                                addbro($1, $2);}
                                                                            $$=paramlist;
                                                                            }
    ;

ParameterListOp:                COMMA ParameterDeclaration ParameterListOp  {
                                                                            if($3!=NULL){
                                                                                addbro($2,$3);
                                                                                }
                                                                            $$ = $2;
                                                                            }
                |                                                           {$$ = NULL;}

    ;

ParameterDeclaration:           TypeSpec                                    {struct node *paramdeclaration = createnode("ParamDeclaration", "");
                                                                            addchild(paramdeclaration, $1);
                                                                            $$ = paramdeclaration;
                                                                            }

                |               TypeSpec ID                                 {struct node *paramdeclaration = createnode("ParamDeclaration", "");
                                                                            addchild(paramdeclaration, $1);
                                                                            struct node *id1 = createnode("Id", $2);
                                                                            addchild(paramdeclaration, id1);
                                                                            addbro($1, id1);
                                                                            
                                                                            $$ = paramdeclaration;}


    ;

Declaration:                    TypeSpec Declarator DeclarationOp SEMI      {struct node *declaration = createnode("Declaration","");                                                                            
                                                                            addchild(declaration, $1);
                                                                            addchild(declaration, $2);
                                                                            addbro($1, $2);
                                                                            if($3!=NULL){
                                                                                addbro(declaration,  $3);
                                                                                }

                                                                            $$ = declaration;}


                |               error SEMI                                  {struct node *null = createnode("Null","");
                                                                            $$ = null;}
                                                                             
    
    ;

DeclarationOp:                  COMMA Declarator DeclarationOp              {struct node *declaration = createnode("Declaration", "");
                                                                            if(type == 0){
                                                                                addchild(declaration,createnode("Char",""));                                                                                
                                                                            }
                                                                            if(type == 1){
                                                                                addchild(declaration,createnode("Int",""));
                                                                            }
                                                                            if(type == 2){
                                                                                addchild(declaration,createnode("Void",""));
                                                                            }
                                                                            if(type == 3){
                                                                                addchild(declaration,createnode("Short",""));
                                                                            }
                                                                            if(type == 4){
                                                                                addchild(declaration,createnode("Double",""));
                                                                            }
                                                                            addchild(declaration, $2);
                                                                            addbro(declaration->childs[0], $2);                                                                            
                                                                            

                                                                            if($3!=NULL){                                                                    
                                                                                addbro(declaration,$3);
                                                                                }
                                                                            $$ = declaration;
                                                                            }
                |                                                           {$$ = NULL;}

    ;

TypeSpec:                       CHAR                                        {$$ = createnode("Char","");
                                                                            type = 0;}

                |               INT                                         {$$ = createnode("Int","");
                                                                            type = 1;}

                |               VOID                                        {$$ = createnode("Void","");
                                                                            type = 2;}

                |               SHORT                                       {$$ = createnode("Short","");
                                                                            type = 3;}
                
                |               DOUBLE                                      {$$ = createnode("Double","");
                                                                            type = 4;}

    ;                        


Declarator:                     ID                                          {$$ = createnode("Id", $1);}

                |               ID ASSIGN Expr                              {struct node *id1 = createnode("Id", $1);
                                                                                 addbro(id1, $3);
                                                                                 $$ = id1;}

    ;

Statement:                      SEMI                                            {$$ = NULL;}

                |               Expr SEMI                                       {$$ = $1;}


                |               LBRACE StatementError RBRACE                         {$$ = $2;}
        
                |               LBRACE StatementError StatementError StatementOp RBRACE     {struct node *statlist = createnode("StatList", "");
                                                                                            addchild(statlist, $2);
                                                                                            addchild(statlist, $3);
                                                                                            addbro($2, $3);
                                                                                            if ($4 != NULL){
                                                                                            addchild(statlist, $4);
                                                                                            addbro($3, $4);}                                                                                
                                                                                            $$ = statlist;}

                |               IF LPAR Expr RPAR StatementError     %prec THEN      {struct node *if1 = createnode("If","");
                                                                                addchild(if1, $3);
                                                                                if($5 == NULL){
                                                                                    struct node *null = createnode("Null", ""); 
                                                                                    addchild(if1, null); 
                                                                                    addbro($3, null);
                                                                                    }
                                                                                else{
                                                                                    addchild(if1, $5);
                                                                                    addbro($3, $5);
                                                                                    }
                                                                                $$ = if1;} 


                |               IF LPAR Expr RPAR StatementError ELSE StatementError    {struct node *if2 = createnode("If", "");

                                                                                addchild(if2, $3);
                                                                                if($5 == NULL){
                                                                                    struct node *null = createnode("Null", ""); addchild(if2, null);}
                                                                                else{addchild(if2, $5);}
                                                                                if($7 == NULL){
                                                                                    struct node *null = createnode("Null", "");addchild(if2, null); }
                                                                                else{addchild(if2, $7);}
                                                                                addbro($3, if2->childs[1]);
                                                                                addbro(if2->childs[1], if2->childs[2]);
                                                                                $$ = if2;}


                |               WHILE LPAR Expr RPAR StatementError             {struct node *while1 = createnode("While", "");
                                                                                addchild(while1, $3);
                                                                                if($5 == NULL){
                                                                                    struct node *null = createnode("Null", ""); 
                                                                                    addchild(while1, null); 
                                                                                    addbro($3, null);
                                                                                    }
                                                                                else{
                                                                                    addchild(while1, $5);
                                                                                    addbro($3, $5);
                                                                                    }
                                                                                $$ = while1;}


                |               RETURN SEMI                                     {struct node *return1 = createnode("Return", "");
                                                                                struct node *null = createnode("Null","");
                                                                                addchild(return1, null);
                                                                                $$=return1;}

                |				RETURN Expr SEMI								{struct node *return1 = createnode("Return","");
																				addchild(return1, $2);
                                                                                $$=return1;}      

                              

                |              LBRACE error RBRACE                              {struct node *null = createnode("Null","");
                                                                                 $$ = null;}                                                                                                      

    ;

StatementError:               Statement                                         {$$=$1;}

    
                |             error SEMI                                         {$$ = NULL;}

                ;

StatementOp:                  StatementError StatementOp                             {if($1 == NULL && $2 == NULL){
                                                                                    $$ = NULL;}
                                                                                    else if ($1 == NULL){
                                                                                        $$ = $2;}
                                                                                    else if ($2 == NULL){
                                                                                        $$ = $1;}
                                                                                    else{
                                                                                        $$ = addbro($1, $2);}
                                                                                }
                |                                                               {$$ = NULL;}
                
    ;                 


Expr:                           Expr ASSIGN Expr                                {struct node *store = createnode("Store","");
                                                                                 addchild(store, $1);
                                                                                 addchild(store, $3);
                                                                                 addbro($1, $3);
                                                                                 $$ = store;}

                |               Expr COMMA Expr                        {struct node *comma = createnode("Comma","");
                                                                                 addchild(comma, $1);
                                                                                 addchild(comma, $3);
                                                                                 addbro($1, $3);
                                                                                 $$ = comma;}


                |               Expr PLUS Expr                         {struct node *add = createnode("Add","");
                                                                                addchild(add, $1);
                                                                                    addchild(add, $3);
                                                                                 addbro($1, $3);
                                                                                 $$ = add;}                                                                                

                |               Expr MINUS Expr                                {struct node *sub = createnode("Sub","");
                                                                                addchild(sub, $1);
                                                                                addchild(sub, $3);
                                                                                addbro($1, $3);
                                                                                $$ = sub;}
                                                                                
                |               Expr MUL Expr                              {struct node *mul = createnode("Mul","");
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

                
                |               PLUS Expr           %prec NOT                            {struct node *plus = createnode("Plus","");
                                                                                    $$ = addchild(plus,$2);}

                |               MINUS Expr          %prec NOT                             {struct node *minus = createnode("Minus","");
                                                                                    $$ = addchild(minus,$2);}

                |               NOT Expr                                        {struct node *not = createnode("Not","");
                                                                                    $$ = addchild(not,$2);}


                |               ID LPAR ExprOp4 RPAR                            {struct node *id1 = createnode("Id",$1);
                                                                                struct node *call = createnode("Call","");
                                                                                addchild(call, id1);
                                                                                addchild(call, $3);
                                                                                addbro(id1, $3); 
                                                                                $$ = call;}
                                

                |               ID                                              {$$ = createnode("Id", $1);}

                |               INTLIT                                          {$$ = createnode("IntLit", $1);}

                |               CHRLIT                                          {$$ = createnode("ChrLit", $1);}

                |               REALLIT                                         {$$ = createnode("RealLit", $1);}
                
                |               LPAR Expr RPAR                                  {$$ = $2;} 

                |               ID LPAR error RPAR                              {struct node *null = createnode("Null","");
                                                                                 $$ = null;}
                
                |                LPAR error RPAR                                {struct node *null = createnode("Null","");
                                                                                 $$ = null;}
    ;


    
ExprOp4:                        ExprOp4 COMMA Expr                            	{addbro($1, $3);
                                                                                 $$ = $1;}
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

void print_tree(struct node *head, int depth){
    if (head == NULL){
        return;
    }

    for (int i = 0; i < depth; i++){
        printf("..");
    }

    if (strcmp(head->value, "") == 0){
        printf("%s\n", head->type);
    }
    else{
        printf("%s(%s)\n", head->type, head->value);
    }
    for (int j = 0; j < head->indexc; j++){
        print_tree(head->childs[j], depth + 1);
    }

    free(head);
}

int main(int argc, char **argv){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            //tokens e erros do lex
            flag1 = 1;
            yylex();
        }

        else if (strcmp(argv[1], "-e1") == 0){
            // erros lex;
            yylex();
        }

        else if (strcmp(argv[1], "-t") == 0){
            // arvore, return no lex
            flag2 = 1;
            yyparse();
            print_tree(head, 0);
        }

        else if (strcmp(argv[1], "-e2") == 0){
            // erros lex;
            flag2 = 1;
            yyparse();
        }

        else{
        	return 0;
        }
	}
	if (argc == 1){
		yylex();
	}

	return 0;
}


void yyerror(char *msg) {
    printf("Line %d, col %d: %s: %s\n", linha , coluna , msg , yytext);
}