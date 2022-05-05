#include<stdio.h>
#include<stdlib.h>

struct arv
{
    int inf;
    struct arv* esq;
    struct arv* dir;    
};

typedef struct  arv Arv;

Arv* abb_cria(){
    return NULL;
}
Arv* abb_insere(Arv* a, int v){
    if(a==NULL){
    a = (Arv*)malloc(sizeof(Arv));
    a->inf= v;
    a->esq= NULL;
    a->dir= NULL;
    }

    else if (v>a->inf)
    {
       a= abb_insere(a->dir, v);
    }
    else if (v< a->inf)
    {
        a= abb_insere(a->esq, v);
    }
    
}


int main(){

    Arv* av= abb_cria();
    av = abb_insere(av, 10);
    av = abb_insere(av, 5);

}