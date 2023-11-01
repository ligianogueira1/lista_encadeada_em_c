#include "listadinalu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria(ListaAluno *la) { la->inicio = NULL; }

int vazia(ListaAluno *la) {
  if (la->inicio == NULL)
    return 1;
  return 0;
}

int tamanho(ListaAluno *la) {
  int tamanho = 0;
  No *aux = la->inicio;
  while (aux != NULL) {
    tamanho++;
    aux = aux->prox;
  }
  return tamanho;
}

int buscaAlunoPos(ListaAluno *la, int posicao, Aluno *alunoEncontrado) {
  No *aux = la->inicio;
  int pos = 0;

  while (aux != NULL) {
    if (pos == posicao) {
      *alunoEncontrado = aux->dado;
      return 1;
    }
    pos++;
    aux = aux->prox;
  }

  return 0;
}

void buscaAlunoPorNome(ListaAluno *la, const char nome[]) {
  No *aux = la->inicio;
  int encontrados = 0;

  while (aux != NULL) {
    if (strcmp(aux->dado.nome, nome) == 0) {
      printf("\nAluno encontrado:\n");
      printf("\nMatrícula: %d\n", aux->dado.matricula);
      printf("Nome: %s\n", aux->dado.nome);
      printf("Nota 1: %.2f\n", aux->dado.nota1);
      printf("Nota 2: %.2f\n", aux->dado.nota2);
      encontrados++;
    }

    aux = aux->prox;
  }

  if (encontrados == 0) {
    printf("\nNenhum aluno encontrado com o nome: %s\n", nome);
  }
}

int buscaAlunoPorMatricula(ListaAluno *la, int matricula,
                           Aluno *alunoEncontrado) {
  No *aux = la->inicio;
  int encontrado = 0;

  while (aux != NULL) {
    if (aux->dado.matricula == matricula) {
      printf("Aluno encontrado:\n");
      printf("Matrícula: %d\n", aux->dado.matricula);
      printf("Nome: %s\n", aux->dado.nome);
      printf("Nota 1: %.2f\n", aux->dado.nota1);
      printf("Nota 2: %.2f\n", aux->dado.nota2);
      encontrado = 1;
    }

    aux = aux->prox;
  }

  return encontrado;
}

int buscaPosicaoMat(ListaAluno *la, int matricula, Aluno *alunoEncontrado) {
  No *aux = la->inicio;
  int encontrado = 0;

  while (aux != NULL) {
    if (aux->dado.matricula == matricula) {
      *alunoEncontrado = aux->dado;
      encontrado = 1;
      break;
    }

    aux = aux->prox;
  }

  if (!encontrado) {
    printf("Nenhum aluno encontrado com a matrícula: %d\n", matricula);
  }

  return encontrado;
}

int insereFinal(ListaAluno *la, Aluno novoAluno) {
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) {
    return 0;
  }

  novo->dado = novoAluno;

  if (vazia(la)) {
    novo->prox = NULL;
    la->inicio = novo;
  } else {
    No *aux = la->inicio;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
    novo->prox = NULL;
  }
  return 1;
}

int inserePosicaoLista(ListaAluno *la, Aluno novoAluno, int posicao) {
  if (posicao < 0 || posicao > tamanho(la)) {
    return 0;
  }

  No *novoNo = (No *)malloc(sizeof(No));
  if (novoNo == NULL) {
    return 0;
  }

  novoNo->dado = novoAluno;

  if (posicao == 0) {
    novoNo->prox = la->inicio;
    la->inicio = novoNo;
  } else {
    No *anterior = la->inicio;
    for (int i = 0; i < posicao - 1; i++) {
      anterior = anterior->prox;
    }

    novoNo->prox = anterior->prox;
    anterior->prox = novoNo;
  }

  return 1;
}

int insereOrdenado(ListaAluno *la, int matricula, const char nome[],
                   float nota1, float nota2) {
  No *novoNo = (No *)malloc(sizeof(No));
  if (novoNo == NULL) {
    return 0;
  }

  novoNo->dado.matricula = matricula;
  strcpy(novoNo->dado.nome, nome);
  novoNo->dado.nota1 = nota1;
  novoNo->dado.nota2 = nota2;

  if (vazia(la) || matricula < la->inicio->dado.matricula) {
    novoNo->prox = la->inicio;
    la->inicio = novoNo;
    return 1;
  } else {
    No *anterior = la->inicio;
    No *atual = la->inicio->prox;

    while (atual != NULL && matricula > atual->dado.matricula) {
      anterior = atual;
      atual = atual->prox;
    }

    novoNo->prox = anterior->prox;
    anterior->prox = novoNo;
    return 1;
  }
}

int removeAlunoMat(ListaAluno *la, int matricula) {
  if (vazia(la))
    return 0;

  Aluno alunoEncontrado;

  int pos = buscaPosicaoMat(la, matricula, &alunoEncontrado);

  if (pos == -1)
    return 0;

  if (pos == 0) {
    No *temp = la->inicio;
    la->inicio = la->inicio->prox;
    free(temp);
    return 1;
  }

  No *aux = la->inicio;
  for (int i = 0; i < pos - 1; i++) {
    aux = aux->prox;
  }
  No *temp = aux->prox;
  aux->prox = aux->prox->prox;
  free(temp);
  return 1;
}

int removeAlunoPosicao(ListaAluno *la, int posicao) {
  if (posicao < 0 || posicao >= tamanho(la)) {
    return 0;
  }

  No *alvo;
  if (posicao == 0) {
    alvo = la->inicio;
    la->inicio = alvo->prox;
  } else {
    No *anterior = la->inicio;
    int i;
    for (i = 0; i < posicao - 1; i++) {
      anterior = anterior->prox;
    }
    alvo = anterior->prox;
    anterior->prox = alvo->prox;
  }

  free(alvo);
  return 1;
}

void exibirAlunos(ListaAluno *la) {

  No *aux = la->inicio;

  if (aux == NULL) {
    printf("\nA lista está vazia.\n");
    return;
  }

  printf("\n*** Lista de Alunos: ***\n");

  while (aux != NULL) {
    printf("\nMatrícula: %d\n", aux->dado.matricula);
    printf("Nome: %s\n", aux->dado.nome);
    printf("Nota 1: %.2f\n", aux->dado.nota1);
    printf("Nota 2: %.2f\n", aux->dado.nota2);

    aux = aux->prox;
  }
}
