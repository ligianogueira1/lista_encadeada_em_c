#include "listadinalu.h"
#include <stdio.h>

int main(void) {
  ListaAluno la;
  cria(&la);

  char opcao;
  int valor;
  Aluno novoAluno;

  do {
    printf("\n------------------------------------------------------\n");
    printf("\n--- Menu principal ---\n");
    printf("\n1 - Obter o tamanho da lista\n");
    printf("2 - Obter dados do aluno\n");
    printf("3 - Obter posição do aluno na lista\n");
    printf("4 - Cadastrar novo aluno\n");
    printf("5 - Remover um aluno\n");
    printf("6 - Exibir a lista de alunos\n");
    printf("7 - Sair do programa\n");
    printf("\nDigite uma opção: ");
    scanf(" %c", &opcao);

    switch (opcao) {
    case '1':
      printf("Você escolheu obter o tamanho da lista.\n");

      if (vazia(&la)) {
        printf("\nA lista está vazia.\n");
      } else {
        printf("\nTamanho da lista: %d", tamanho(&la));
      }
      break;

    case '2':
      printf("Você escolheu obter dados do aluno.\n");
      printf("\nPor favor, digite '1' para buscar inserindo a posição, '2' "
             "para nome e '3' para matrícula: ");
      int escolha, posicao, matricula;
      Aluno alunoEncontrado;
      char nome[30];
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("Por favor, informe a posição do aluno: ");
        scanf("%d", &posicao);
        if (buscaAlunoPos(&la, posicao, &alunoEncontrado)) {
          printf("\nAluno encontrado na posição %d:\n", posicao);
          printf("Matrícula: %d\n", alunoEncontrado.matricula);
          printf("Nome: %s\n", alunoEncontrado.nome);
          printf("Nota 1: %.2f\n", alunoEncontrado.nota1);
          printf("Nota 2: %.2f\n", alunoEncontrado.nota2);
        } else
          printf("Nenhum aluno encontrado na posição %d.\n", posicao);
      } else if (escolha == 2) {
        printf("Por favor, informe o nome do aluno: ");
        scanf("%s", nome);
        buscaAlunoPorNome(&la, nome);
      } else {
        printf("Por favor, informe a matrícula do aluno: ");
        scanf("%d", &matricula);
        if (buscaAlunoPorMatricula(&la, matricula, &alunoEncontrado)) {
          printf("\nAluno encontrado com a matrícula %d:\n", matricula);
          printf("Nome: %s\n", alunoEncontrado.nome);
          printf("Nota 1: %.2f\n", alunoEncontrado.nota1);
          printf("Nota 2: %.2f\n", alunoEncontrado.nota2);
        } else {
          printf("Nenhum aluno encontrado com a matrícula %d.\n", matricula);
        }
      }
      break;

    case '3':
      printf("Você escolheu obter a posição do aluno na lista\n");
      printf("\nPor favor, digite a matrícula: ");
      scanf("%d", &matricula);
      printf("Posição do aluno: %d",
             buscaPosicaoMat(&la, matricula, &alunoEncontrado));
      break;

    case '4':
      printf("Você escolheu cadastrar novo aluno.\n");
      printf("\nPor favor, digite '1' para cadastro no final da lista, '2' "
             "para posição especificada e '3' para de forma ordenada: ");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("Informe a matrícula: ");
        scanf("%d", &novoAluno.matricula);
        printf("Informe o nome: ");
        scanf("%s", novoAluno.nome);
        printf("Informe a nota 1: ");
        scanf("%f", &novoAluno.nota1);
        printf("Informe a nota 2: ");
        scanf("%f", &novoAluno.nota2);

        if (insereFinal(&la, novoAluno)) {
          printf("Aluno cadastrado com sucesso!\n");
        } else {
          printf("\nDesculpe, mas a operação falhou.\n");
        }
      } else if (escolha == 2) {
        printf("Por favor, informe a posição: ");
        scanf("%d", &posicao);
        printf("Informe a matrícula: ");
        scanf("%d", &novoAluno.matricula);
        printf("Informe o nome: ");
        scanf("%s", novoAluno.nome);
        printf("Informe a nota 1: ");
        scanf("%f", &novoAluno.nota1);
        printf("Informe a nota 2: ");
        scanf("%f", &novoAluno.nota2);

        if (inserePosicaoLista(&la, novoAluno, posicao)) {
          printf("Aluno cadastrado com sucesso!\n");
        } else {
          printf("\nDesculpe, mas a operação falhou.\n");
        }
      } else {
        printf("Por favor, informe a matrícula: ");
        scanf("%d", &matricula);
        printf("Informe o nome: ");
        scanf("%s", novoAluno.nome);
        printf("Informe a nota 1: ");
        scanf("%f", &novoAluno.nota1);
        printf("Informe a nota 2: ");
        scanf("%f", &novoAluno.nota2);

        if (insereOrdenado(&la, matricula, novoAluno.nome, novoAluno.nota1,
                           novoAluno.nota2)) {
          printf("Aluno cadastrado com sucesso!\n");
        } else {
          printf("\nDesculpe, mas a operação falhou.\n");
        }
      }
      break;

    case '5':
      printf("Você escolheu remover um aluno.\n");
      if (vazia(&la)) {
        printf("\nLista vazia. Não há alunos a serem removidos.\n");
        break;
      }
      printf("Por favor, digite '1' para remover informando a matrícula ou "
             "'2' "
             "para posição: ");
      scanf("%d", &escolha);
      if (escolha == 1) {
        printf("Por favor, informe a matrícula: ");
        scanf("%d", &matricula);
        if (removeAlunoMat(&la, matricula)) {
          printf("Aluno removido com sucesso!\n");
        } else {
          printf("Operação falhou.");
        }
      } else {
        printf("Por favor, informe a posição: ");
        scanf("%d", &posicao);
        if (removeAlunoPosicao(&la, posicao)) {
          printf("Aluno removido com sucesso!\n");
        } else {
          printf("Operação falhou.");
        }
      }
      break;

    case '6':
      exibirAlunos(&la);
      break;

    case '7':
      break;

    default:
      printf("Opção inválida.\n");
    }
  } while (opcao != '7');

  return 0;
}
