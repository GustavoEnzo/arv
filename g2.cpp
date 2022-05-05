#include<stdio.h>
#include<stdlib.h>


struct noArv{
    int valor;
    struct noArv* esquerda;
    struct noArv* direita;
};

typedef struct noArv Arv;


void imprimeEmOrdem(Arv* raiz){
    if(raiz != NULL){
      imprimeEmOrdem(raiz->esquerda);
      printf("%d ",raiz->valor);
      imprimeEmOrdem(raiz->direita);
    }
}

Arv* criar(valor){

    Arv* raiz = malloc(sizeof(Arv));
    raiz->valor = valor;
    raiz->esquerda = NULL; 
    raiz->direita = NULL;
    
    return raiz;
}


void add(Arv *raiz, int valor)
{
	if(valor < raiz->valor)
	{
		if(raiz->esquerda == NULL)
			raiz->esquerda = criar(valor);
		else
			add(raiz->esquerda,valor);
	}
	else
	{
		if(raiz->direita == NULL)
			raiz->direita = criar(valor);
		else
			add(raiz->direita,valor);
	}
}



void rem(Arv *raiz, int valor)
{
	Arv *filho = raiz;
	Arv *pai;
	do{
		pai = filho;
		if(valor < filho->valor)
			filho = filho->esquerda;
		else if(valor > filho->valor)
			filho = filho->direita;	
	}while(filho!=NULL && filho->valor != valor);

	if(filho != NULL){ 
		if(filho->esquerda == NULL && filho->direita == NULL){ 
			printf("%d é no da folha\n",valor);
			if(pai->esquerda == filho) pai->esquerda = NULL;
			if(pai->direita == filho) pai->direita = NULL;
		}
		if(filho->esquerda != NULL && filho->direita == NULL){ 
			printf("%d tem um filho a esquerda\n",valor);
			if(pai->esquerda == filho) pai->esquerda = filho->esquerda;
			if(pai->direita == filho) pai->direita = filho->esquerda;
		}
		if(filho->esquerda == NULL && filho->direita != NULL){ 
			printf("%d tem um filho a direita\n",valor);
			if(pai->esquerda == filho) pai->esquerda = filho->direita;
			if(pai->direita == filho) pai->direita = filho->direita;
		}
		if(filho->esquerda != NULL && filho->direita != NULL) 
		{
			printf("%d tem dois filhos\n",valor);
			if(filho->esquerda->direita==NULL){
				filho->valor = filho->esquerda->valor;
				filho->esquerda = NULL;
			}else{
				Arv *p = filho->esquerda;
				Arv *aux = p;
				while(p->direita != NULL){
					aux = p;
					p = p->direita;
				}
				aux->direita = NULL;
				filho->valor = p->valor;
			}
		}
	}
}

int altura (Arv *raiz) {
   if (root == NULL) 
      return -1;
   else {
      int alte = altura (raiz->esquerda);   //não consegui imprimir corretamente a altura, e não identifiquei o erro, peço desculpas
      int altd = altura (raiz->direita);
      if (alte < altd) return he + 1;
      else return hd + 1;
   }
}

int maiorNum(Arv *raiz) {
    if (raiz->direita != NULL) {
        return maiorNum(raiz->direita);
    } else {
        return raiz->valor;
    }
}

int contaNos (Arv *raiz) { 
    if (raiz == NULL) return 0;
    else {          
      return contaNos(raiz->esquerda) + contaNos(raiz->direita) + 1;   
    }
} 

void main(){
  Arv* root = criar(7);

  add(root,1);
  add(root,2);
  add(root,3);  
  add(root,4);
  add(root,5);
  add(root,6);
  add(root,7); 


  rem(root,5);
  rem(root,7);
  rem(root,7);

  printf("Arvore: \n");
  imprimeEmOrdem(root);

  printf("\nAltura da Arvore e:\n%i", altura(root));

  printf("\nO maior numero e:\n%i",maiorNum(root));

  printf("\nA quantidade de nos e:\n%i\n",contaNos(root));

  return 0;



}