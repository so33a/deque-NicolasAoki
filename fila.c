#include <stdio.h>
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
  link aux = novoNo(e,NULL);
  if(f->maisNovo != NULL){
     aux->next = f->maisNovo
     f->maisNovo = aux;
  }else{
    f->maisNovo = aux;
  }
}
void insereFim(FILA f, int e){
  link aux = novoNo(e,NULL);
  if(f->maisAntigo->next == NULL){
    f->maisAntigo->next = f->maisAntigo = aux;
  }
}
void removeComeco(FILA f){
  if(f->maisNovo == NULL)
    printf("fila vazia");
  link t = f->maisNovo;
  f->maisNovo = f->maisNovo->next;
  free(t);
  
}
void removeFim (FILA f){
  if(f->maisAntigo == NULL)
    printf("Fila Vazia");
  link aux = f->maisNovo;
  while(aux->next != NULL)
    aux = aux->next;
 free(aux);
 
}



