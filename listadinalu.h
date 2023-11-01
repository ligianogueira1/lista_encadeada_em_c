typedef struct aluno {
  int matricula;
  char nome[30];
  float nota1, nota2;
} Aluno;

typedef struct no {
  Aluno dado;
  struct no *prox;
} No;

typedef struct lista {
  No *inicio;
} ListaAluno;

void cria(ListaAluno *la);
int vazia(ListaAluno *la);
int tamanho(ListaAluno *la);
int buscaAlunoPos(ListaAluno *la, int posicao, Aluno *alunoEncontrado);
void buscaAlunoPorNome(ListaAluno *la, const char nome[]);
int buscaAlunoPorMatricula(ListaAluno *la, int matricula,
                           Aluno *alunoEncontrado);
int buscaPosicaoMat(ListaAluno *la, int matricula, Aluno *alunoEncontrado);
int insereFinal(ListaAluno *la, Aluno novoAluno);
int inserePosicaoLista(ListaAluno *la, Aluno novoAluno, int posicao);
int insereOrdenado(ListaAluno *la, int matricula, const char nome[],
                   float nota1, float nota2);
int removeAlunoMat(ListaAluno *la, int matricula);
int removeAlunoPosicao(ListaAluno *la, int posicao);
void exibirAlunos(ListaAluno *la);
