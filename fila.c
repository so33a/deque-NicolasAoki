e#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisNovo = f->maisAntigo = NULL;
  return f;
}

void inserir(FILA f, int e) {
  if(f->maisAntigo == NULL) {
    f->maisAntigo = f->maisNovo = novoNo(e, NULL);
  } else {
    f->maisNovo->next = novoNo(e, NULL);
    f->maisNovo = f->maisNovo->next;
  }
}

int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisAntigo->item;
  t = f->maisAntigo;
  f->maisAntigo = f->maisAntigo->next;
 
  if(f->maisAntigo == NULL)
    f->maisNovo = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->maisNovo == NULL) || (f->maisAntigo == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->maisAntigo; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}

void insereComeco(FILA f, int e){
   if(f->maisAntigo == NULL){
        f->maisAntigo = f->maisNovo = novoNo(e, NULL);
   }else{

	link aux = f->maisAntigo;
 	f->maisAntigo = novoNo(e,aux);
	
   }
}
void insereFim(FILA f, int e){
   f->maisNovo->next = novoNo(e, NULL);
   f->maisNovo = f->maisNovo->next;
}
void removeComeco(FILA f){
   link aux = f->maisAntigo;
   f->maisAntigo = f->maisAntigo->next;
   free(aux);
}
void removeFim(FILA f){
   link aux = f->maisAntigo;
   if(aux != f->maisNovo){
	do{
	    aux = aux->next;
	}while(aux->next != f->maisNovo);
      
      f->maisNovo = aux;
      free(aux->next);
      f->maisNovo->next = NULL;
      
   }else{
	printf("so tem 1 elemento");
   }
}
