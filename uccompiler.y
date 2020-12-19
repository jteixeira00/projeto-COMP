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
    

    int printtreeflag = 1;
    extern int linha;
    extern int yyleng;
    extern int coluna;
    
    void yyerror (char *s);
  
    
    typedef struct nodetf{
        char* type;
        char* name;
        int params;
        struct nodetf* next;
    }nodetf;
    
    typedef struct nodetg{
        char* type;
        char* name;
        char* params;
        struct nodetf* nexttf;
        struct nodetg* next;
    }nodetg;

    struct nodetg* globalTable;
    struct nodetf* current;
    typedef struct node{
        char* type; 
        char* value;
        struct node *dad;
        struct node *bros;
        struct node *childs[MAX];
        int nchildren;
        char* note;
    }node;

    struct node *head = NULL;
    struct node* createnode(char *type, char *value);
    struct node* addchild(node *dad, node *child);
    struct node* addbro(node *n1, node *n2);
    void printtree(node *head, int level);
    char* currentF;

%}


%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR 
%token <str> AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE
%token RPAR SEMI 

%token <str> RESERVED CHRLIT ID REALLIT INTLIT

%type <node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatementsOp StatementError
%type <node> DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterListOp ParameterDeclaration
%type <node> Declaration DeclarationOp TypeSpec Declarator Statement Expr ExprOp4 StatementAux FunctionsAndDeclarationsOP


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

FunctionsAndDeclarations:   FunctionDefinition FunctionsAndDeclarationsOP   {if($2!=NULL){
                                                                                addbro($1, $2);
                                                                                }
                                                                            $$ = $1;}
               
                |           FunctionDeclaration FunctionsAndDeclarationsOP     {
                                                                            if($2!=NULL){
                                                                                addbro($1, $2);
                                                                                }
                                                                            $$ = $1;
                                                                            }

                |           Declaration FunctionsAndDeclarationsOP           {
                                                                            if($2!=NULL){
                                                                                addbro($1, $2);
                                                                                }
                                                                            $$ = $1;
                                                                            }
                                    
                
    ;


  
    FunctionsAndDeclarationsOP: FunctionsAndDeclarations                    {$$=$1;}

                |                                                           {$$=NULL;}
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

DeclarationsAndStatements:       DeclarationsAndStatements Statement        {
                                                                            if($1 != NULL){
                                                                                addbro($1,$2);
                                                                                $$ = $1;}
                                                                            else{
                                                                                $$=$2;
                                                                            }
                                                                            
                                                                            
                                                                            }

                |               DeclarationsAndStatements Declaration       {addbro($1, $2);
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


Declarator:                     ID                                              {$$ = createnode("Id", $1);}

                |               ID ASSIGN Expr                                  {struct node *id1 = createnode("Id", $1);
                                                                                addbro(id1, $3);
                                                                                $$ = id1;}

    ;

StatementAux:                   StatementError                                  {$$ = $1;}

                |               StatementError StatementAux                     {addbro($1, $2); 
                                                                                if($1!=NULL){
                                                                                    $$ = $1;
                                                                                }
                                                                                else{
                                                                                    $$ = $2;}}

                ;

StatementError:               Statement                                         {$$=$1;}


                |             error SEMI                                        {struct node *null = createnode("Null", ""); $$=null;}

                ;


Statement:                      SEMI                                            {$$ = NULL;}

                |               Expr SEMI                                       {$$ = $1;}


                |               LBRACE StatementAux RBRACE                      {if($2!=NULL && $2->bros != NULL){
                                                                                struct node *statlist = createnode("StatList", "");
                                                                                addchild(statlist, $2);
                                                                                $$ = statlist;

                                                                                }
                                                                                else if($2!=NULL && $2->bros == NULL){
                                                                                    $$ = $2;
                                                                                }
                                                                                else{$$ = NULL;}
                                                                                }

                |               LBRACE RBRACE                                   {
                                                                                //struct node *null = createnode("Null", ""); $$=null;
                                                                                $$=NULL;}              

                |               IF LPAR Expr RPAR StatementError     %prec THEN     {struct node *if1 = createnode("If","");
                                                                                    addchild(if1, $3);
                                                                                    if($5 == NULL){
                                                                                    struct node *null = createnode("Null", ""); 
                                                                                    addchild(if1, null); 
                                                                                    addbro($3, null);
                                                                                    struct node *null1 = createnode("Null", ""); 
                                                                                    addchild(if1, null1);
                                                                                    addbro(null, null1);
                                                                                    }
                                                                                    else{
                                                                                    addchild(if1, $5);
                                                                                    addbro($3, $5);
                                                                                    struct node *null1 = createnode("Null", ""); 
                                                                                    addchild(if1, null1);
                                                                                    addbro($5, null1);
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


                |               Expr PLUS Expr                                  {struct node *add = createnode("Add","");
                                                                                addchild(add, $1);
                                                                                addchild(add, $3);
                                                                                addbro($1, $3);
                                                                                $$ = add;}                                                                                

                |               Expr MINUS Expr                                 {struct node *sub = createnode("Sub","");
                                                                                addchild(sub, $1);
                                                                                addchild(sub, $3);
                                                                                addbro($1, $3);
                                                                                $$ = sub;}
                                                                                
                |               Expr MUL Expr                                   {struct node *mul = createnode("Mul","");
                                                                                addchild(mul, $1);
                                                                                addchild(mul, $3);
                                                                                addbro($1, $3);
                                                                                $$ = mul;}

                |               Expr DIV Expr                                   {struct node *div = createnode("Div","");
                                                                                addchild(div, $1);
                                                                                addchild(div, $3);
                                                                                addbro($1, $3);
                                                                                $$ = div;}

                |               Expr MOD Expr                                   {struct node *mod = createnode("Mod","");
                                                                                addchild(mod, $1);
                                                                                addchild(mod, $3);
                                                                                addbro($1, $3);
                                                                                $$ = mod;}
            
                |               Expr OR Expr                                    {struct node *or = createnode("Or","");
                                                                                addchild(or, $1);
                                                                                addchild(or, $3);
                                                                                addbro($1, $3);
                                                                                $$ = or;}

                |               Expr AND Expr                                   {struct node *and = createnode("And","");
                                                                                addchild(and, $1);
                                                                                addchild(and, $3);
                                                                                addbro($1, $3);
                                                                                $$ = and;}

                |               Expr BITWISEAND Expr                            {struct node *bitewiseand = createnode("BitWiseAnd","");
                                                                                addchild(bitewiseand, $1);
                                                                                addchild(bitewiseand, $3);
                                                                                addbro($1, $3);
                                                                                $$ = bitewiseand;}

                |               Expr BITWISEOR Expr                             {struct node *bitewiseor = createnode("BitWiseOr","");
                                                                                addchild(bitewiseor, $1);
                                                                                addchild(bitewiseor, $3);
                                                                                addbro($1, $3);
                                                                                $$ = bitewiseor;}

                |               Expr BITWISEXOR Expr                            {struct node *bitewisexor = createnode("BitWiseXor","");
                                                                                addchild(bitewisexor, $1);
                                                                                addchild(bitewisexor, $3);
                                                                                addbro($1, $3);
                                                                                $$ = bitewisexor;}

                |               Expr EQ Expr                                    {struct node *eq = createnode("Eq","");
                                                                                addchild(eq, $1);
                                                                                addchild(eq, $3);
                                                                                addbro($1, $3);
                                                                                $$ = eq;}

                |               Expr NE Expr                                    {struct node *ne = createnode("Ne","");
                                                                                addchild(ne, $1);
                                                                                addchild(ne, $3);
                                                                                addbro($1, $3);
                                                                                $$ = ne;}

                |               Expr LE Expr                                    {struct node *le = createnode("Le","");
                                                                                addchild(le, $1);
                                                                                addchild(le, $3);
                                                                                addbro($1, $3);
                                                                                $$ = le;}

                |               Expr GE Expr                                    {struct node *ge = createnode("Ge","");
                                                                                addchild(ge, $1);
                                                                                addchild(ge, $3);
                                                                                addbro($1, $3);
                                                                                $$ = ge;}

                |               Expr LT Expr                                    {struct node *lt = createnode("Lt","");
                                                                                addchild(lt, $1);
                                                                                addchild(lt, $3);
                                                                                addbro($1, $3);
                                                                                $$ = lt;}

                |               Expr GT Expr                                    {struct node *gt = createnode("Gt","");
                                                                                addchild(gt, $1);
                                                                                addchild(gt, $3);
                                                                                addbro($1, $3);
                                                                                $$ = gt;}

                
                |               PLUS Expr           %prec NOT                   {struct node *plus = createnode("Plus","");
                                                                                $$ = addchild(plus,$2);}

                |               MINUS Expr          %prec NOT                   {struct node *minus = createnode("Minus","");
                                                                                $$ = addchild(minus,$2);}

                |               NOT Expr                                        {struct node *not = createnode("Not","");
                                                                                $$ = addchild(not,$2);}


                |               ID LPAR ExprOp4 RPAR                            {struct node *id1 = createnode("Id",$1);
                                                                                struct node *call = createnode("Call","");
                                                                                addchild(call, id1);
                                                                                addchild(call, $3);
                                                                                addbro(id1, $3); 
                                                                                $$ = call;}

                |               ID LPAR RPAR                                    {struct node *id1 = createnode("Id",$1);
                                                                                struct node *call = createnode("Call","");
                                                                                addchild(call, id1);
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
             
    ;


%%
struct node* createnode(char *type, char *value){
    node *new = (node *)malloc(sizeof(node));
    if(new==NULL){
        return NULL;
    }
    new->type = type;
    new->value = value;
    new->nchildren = 0;
    new->dad = NULL;
    new->bros = NULL;
    return new;
}

struct node* addchild(struct node* dad, struct node* child){
    if (dad == NULL || child == NULL){
       return NULL;
    }
    dad->childs[dad->nchildren] = child;
    dad->nchildren++;
    child->dad = dad;
    node *aux = child->bros;
    while (aux != NULL){
        aux->dad = dad;
        dad->childs[dad->nchildren] = aux;
        dad->nchildren++;
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

void printtree(struct node *head, int level){
    int currentlevel=0;
    if (head == NULL){
        return;
    }
    while (currentlevel++<level){
        printf("..");
    }
    if (strcmp(head->value, "") != 0){
         printf("%s(%s)\n", head->type, head->value);
        
    }
    else{
       printf("%s\n", head->type);
    }
    for (int j = 0; j < head->nchildren; j++){
        printtree(head->childs[j], level + 1);
    }
    free(head); //funçao recursiva, vai libertar cada nó depois de o printar
}

void printtreeAnnotations(struct node *head, int level){
    int currentlevel=0;
        if (head == NULL){
            return;
        }
        while (currentlevel++<level){
            printf("..");
        }
        
        if (strcmp(head->value, "") != 0){
            if(head->note != NULL){
                printf("%s(%s) - %s\n", head->type, head->value, head->note);
            
            }
            else{
                printf("%s(%s)\n", head->type, head->value);   
            }
            
        }
        else{
            if(head->note != NULL){
                printf("%s - %s\n", head->type, head->note);
                
            }
            else{printf("%s\n", head->type);}
        }
        for (int j = 0; j < head->nchildren; j++){
            printtreeAnnotations(head->childs[j], level + 1);
        }
        if(head){free(head);}
         //funçao recursiva, vai libertar cada nó depois de o printar
}

struct nodetg* insertGlobal(char* name, char* type, char* params){
    struct nodetg* aux = globalTable;

    while(aux->next!=NULL){
        if(aux->name != NULL && strcmp(aux->next->name, name)==0){
            if(aux->type != NULL && strcmp(aux->next->type, type)==0){
                if(aux->params != NULL && strcmp(aux->next->params, params)==0){
                    return aux->next;
                }
                else{
                    return NULL;
                }
            }
        }
        aux=aux->next;
    }
    struct nodetg* res = (nodetg*)malloc(sizeof(nodetg));
    res->name = name;
    res->type = type;
    res->params = params;
    res->nexttf = NULL;
    res->next = NULL;
    aux->next = res;
    return res;
}

void startGlobalTable(){
    globalTable = (nodetg*)malloc(sizeof(nodetg));
    globalTable->type = (char*)malloc(64*sizeof(char));
    globalTable->type = "===== Global Symbol Table =====";
    
    insertGlobal("putchar", "int", "int");
    insertGlobal("getchar", "int", "void");
    
}


void startFunctionT(struct nodetg* nglobal){
    
    char* functH = (char*)malloc(256*sizeof(char));
    sprintf(functH, "===== Function %s Symbol Table =====", nglobal->name);
    struct nodetf* newN = (nodetf*)malloc(sizeof(nodetf));
    newN->type = (char*)malloc(264*sizeof(char));
    strcpy(newN->type, functH);
    newN->params = 0,
    nglobal->nexttf = newN;


    struct nodetf* returnN = (nodetf*)malloc(sizeof(nodetf));
    returnN->name = (char*)malloc(256*sizeof(char));
    returnN->name = "return";
    returnN->type = strdup(nglobal->type);

    returnN->params=0;
    newN->next = returnN;
    
}

void insertFunctionT(char* name, char *type, int params, struct nodetf* nodefunc){
    struct nodetf* aux = nodefunc;
    
    while(aux->next!=NULL){
        if (aux->name != NULL && strcmp(aux->next->name, name)==0){
            return;
        }
        aux=aux->next;
    }
    aux=nodefunc;
    while(aux->next!=NULL){
        aux = aux->next;
    }
    struct nodetf* res = (nodetf*)malloc(sizeof(nodetf));
    
    res->name = name;
    
    res->type = type;
    res->params = params;
    res->next = NULL;
    aux->next = res;
    

}

char * generateParams(struct node* head){

    char *params = (char*)malloc(512*sizeof(char));
    struct node* aux = head->childs[0];
   
    while(aux!=NULL){
        if(strlen(params)>0){
            strcat(params,",");
        }
        if(strcmp(aux->childs[0]->type, "Char")==0){
            strcat(params, "char");
        }
        if(strcmp(aux->childs[0]->type, "Int")==0){
            strcat(params, "int");
        }
        if(strcmp(aux->childs[0]->type, "Void")==0){
            strcat(params, "void");
        }
        if(strcmp(aux->childs[0]->type, "Short")==0){
            strcat(params, "short");
        }
        if(strcmp(aux->childs[0]->type, "Double")==0){
            strcat(params, "double");
        }
        aux=aux->bros;
    }
    return params;
}
void insertFunctionBody(struct node* head, struct nodetg* nodeGlobal){
    
    struct node* aux = head;

    if(strcmp(aux->type, "Declaration")==0){
        
        char *type = strdup(aux->childs[0]->type);
        type[0] = type[0]+32;
        insertFunctionT( aux->childs[1]->value, type, 0, nodeGlobal->nexttf);
    }

    aux = aux->childs[0];
    while(aux!=NULL){
        
        insertFunctionBody(aux, nodeGlobal);
        aux=aux->bros;
    }

}

void declarationCheck(struct node* head){
    char *value = head->childs[0]->bros->value;
    char *type = strdup(head->childs[0]->type);
    type[0]=type[0]+32;

    insertGlobal( value, type, "");
}

void funcdeclarationCheck(struct node* head){
    char *value = head->childs[0]->bros->value;
    char *type = strdup(head->childs[0]->type);
    type[0]=type[0]+32;
    //maybe erro
    insertGlobal( value ,type, generateParams(head->childs[2]));

}

void insertParams(struct node* nodeAST, struct nodetg* nodeGlobal){
    struct node* aux = nodeAST->childs[0];
    while(aux!=NULL){
        char* type = strdup(aux->childs[0]->type);
        type[0]=type[0]+32;
        if(aux->childs[0]->bros != NULL){
            insertFunctionT(aux->childs[1]->value, type,  1, nodeGlobal->nexttf);
        }
        aux = aux->bros;
    }

}

void funcdefinitionCheck(struct node* head){
    char *value = head->childs[0]->bros->value;
    char *type = strdup(head->childs[0]->type);
    type[0]=type[0]+32;
    //maybe erro
    struct nodetg* newN = insertGlobal(value,type,  generateParams(head->childs[2]));
    
    startFunctionT(newN);
    insertParams(head->childs[2], newN);
    insertFunctionBody(head->childs[3], newN);

}



void generateTables(){
    struct node* aux = head;
    while (aux!=NULL){
        if(strcmp(aux->type, "Program")==0){
            startGlobalTable();

            aux = aux->childs[0];
        }
        else{
           
            if(strcmp(aux->type, "FuncDeclaration")==0){
                
                funcdeclarationCheck(aux);
            }
            if(strcmp(aux->type, "FuncDefinition")==0){
                funcdefinitionCheck(aux);
            }
            else{
               
                declarationCheck(aux);
            }
            aux=aux->bros;
        }
    }

}

void printfuncTable(struct nodetf* nodeF){
    struct nodetf* aux = nodeF;
    while(aux!=NULL){
        if(aux->name!=NULL){
            if(aux->params == 0){
                printf("%s\t%s\n", aux->name, aux->type);
            }
            else{
                printf("%s\t%s\tparam\n", aux->name, aux->type);
            }
        }
        else{
            printf("%s\n", aux->type);
        }
        aux=aux->next;
    }
    printf("\n");
}
struct nodetf* searchTable(char* name){
    struct nodetg* aux = globalTable;
    char* string = (char*)malloc(256*sizeof(char));
    sprintf(string, "===== Function %s Symbol Table =====", name);
    while(aux!=NULL){
        if(aux->nexttf!=NULL){
            if(strcmp(string, aux->nexttf->type)==0){
                return aux->nexttf;
            }
        }
        aux = aux->next;
    }
    
    return NULL;
}

char* searchId(struct nodetf* functions, struct node* head){
    
    struct nodetf* aux = functions;
    
    //printf("comecei\n");
    //printf("HEAD VALUE %s\n", head->value);
    //printf("À procura na função %s\n", functions->type);

    while(aux!=NULL){
        if(aux->name){
            if(strcmp(aux->name, head->value)==0){
                puts(aux->name);
                printf("return bem");
                return strdup(aux->type);
            }
        }
        aux = aux->next;
    }
    
    printf("return null\n");
    return NULL;
}

char* findTableAndAnnotate(struct node* head){
    
    if(head!=NULL){
        struct nodetg* finder= globalTable;
        struct nodetf* auxF;
        char* varName = head->value;

        char* tabName = (char*)malloc(256*sizeof(char));
        sprintf(tabName, "===== Function %s Symbol Table =====", currentF);
        while(finder!=NULL){
            if(finder->nexttf!=NULL){
                auxF = finder->nexttf;
                if(strcmp(currentF,"")!=0){
                    if (strcmp(finder->nexttf->type, tabName)==0){
                        while(auxF){
                            if(auxF->name){
                                if(strcmp(auxF->name, varName)==0){
                                    head->note = auxF->type;
                                }
                            }
                            auxF = auxF->next;
                        }
                    }
                
                } 
            }
            finder = finder->next;
        }
    }
    return NULL;

}

void annotate(struct node* head){
    if(head == NULL){
        return;
    }
    else if((strcmp(head->type, "Program")==0)|| (strcmp(head->type,"FuncBody")==0)){
        annotate(head->childs[0]);
        return;
    }

    else if(strcmp(head->type, "IntLit")==0){
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("int"); 
    }
    else if(strcmp(head->type, "ChrLit")==0){
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("int");
    }
    else if(strcmp(head->type, "RealLit")==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("double");
    }

    else if(strcmp(head->type, "BitWiseAnd")==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("int");
    }
    else if(strcmp(head->type, "BitWiseOr")==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("int");
        return;
    }
    else if(strcmp(head->type, "BitWiseXor")==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("int");
        return;
    }
    else if(strcmp(head->type, "And")==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("int");
        return;
    }
    else if(strcmp(head->type, "Or")==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        head->note = strdup("int");
        return;
    }
    else if(strcmp(head->type, "Eq")==0 || strcmp(head->type, "Ne")==0 || strcmp(head->type, "Mod")==0 || strcmp(head->type, "Le")==0 || strcmp(head->type, "Ge")==0 || strcmp(head->type, "Lt")==0 || strcmp(head->type, "Gt")==0 ){
        annotate(head->childs[0]);
        head->note= (char*)malloc(64*sizeof(char));
        head->note = strdup("int");
    }
    
    else if(strcmp(head->type, "Call") ==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        if(head->childs[0]->note!=NULL){
        head->note = strdup(head->childs[0]->note);
        }
    }
    

    else if(strcmp(head->type, "Store") ==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        if(head->childs[0]->note!=NULL){
            head->note = strdup(head->childs[0]->note);
        }
    }
    
    else if(strcmp(head->type, "Comma") ==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        if(head->childs[1]->note !=NULL){
        head->note = strdup(head->childs[1]->note);
        }
    }

    else if(strcmp(head->type, "Minus") ==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        if(head->childs[0]->note!=NULL){
            head->note = strdup(head->childs[0]->note);
        }
    }
    else if(strcmp(head->type, "Plus") ==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        if(head->childs[0]->note!=NULL){
            head->note = strdup(head->childs[0]->note);
        }
        
    }
    else if(strcmp(head->type, "Not") ==0){
        annotate(head->childs[0]);
        head->note = (char*)malloc(64*sizeof(char));
        head->note = "int";
    }
    else if(strcmp(head->type, "FuncDefinition")==0){
        currentF = strdup(head->childs[1]->value);
        annotate(head->childs[2]);
        
        
        //current = searchTable(head->childs[1]->value);
        
        //printf("%s\n", current->type);
    }

    else if(strcmp(head->type, "Id")==0){
        findTableAndAnnotate(head);
        //res = searchId(current, head);
        //if(res!=NULL){
        //head->note = strdup(res);   
        //}
    }
    
    else{
        if(head->childs[0]!=NULL){
            annotate(head->childs[0]);
        }
    }
    
    if(head->bros!=NULL){
        annotate(head->bros);
    }
    
}





void printglobaltable(){
    struct nodetg* aux = globalTable;
    while(aux!=NULL){
        if(aux->name!=NULL){
            printf("%s\t%s", aux->name, aux->type);
            
            if(strcmp(aux->params, "")!=0){
                printf("(%s)",aux->params);
            }
            printf("\n");
        }
        else{
            printf("%s\n",globalTable->type);
        }
        aux = aux->next;
    }
    aux = globalTable;
    printf("\n");
    while(aux!=NULL){
        if (aux->nexttf != NULL){
            printfuncTable(aux->nexttf);
        }
        aux = aux->next;
    }
    
}


int main(int argc, char **argv){
    currentF = (char*)malloc(256*sizeof(char));
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            //lex completo
            flag1 = 1;
            yylex();
        }
        else if (strcmp(argv[1], "-e1") == 0){
            //lex erros
            yylex();
        }

        else if (strcmp(argv[1], "-t") == 0){
            //árvore
            flag2 = 1;
            yyparse();
            if(printtreeflag == 1){
            printtree(head, 0);
            }
        }

        else if (strcmp(argv[1], "-e2") == 0){
            // erros lex e sintaxe
            flag2 = 1;
            yyparse();
        }
        else if(strcmp(argv[1], "-s")==0){
            flag2 = 1;
            
            yyparse();
            generateTables();
            printglobaltable();
            annotate(head);
            if(printtreeflag == 1){
            printtreeAnnotations(head, 0);
            }
            
        }

        else{
        	return 0;
        }
	}
	if (argc == 1){

        //erros lex e sintaxe
        flag2 = 1;
        yyparse();
	}

	return 0;
}


void yyerror(char *msg) {
    printtreeflag = 0;
    printf("Line %d, col %d: %s: %s\n", linha , (int)(coluna-strlen(yytext)) , msg , yytext);
}