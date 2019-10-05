#ifndef CofoAluno_H_INCLUDED
#define CofoAluno_H_INCLUDED
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

//CRIA ESTRUTURA DO TIPO ALUNO
typedef struct _aluno_{
    long int CPF;
    char nome[60];
    int idade;
}aluno;

//CRIA ESTRUTURA DO TIPO COLEÇÃO
typedef struct _cofo_{
    int max;
    void **vet;
    int elm;
}cofo;

//HEADERS DA COLEÇÃO
cofo *cofoCreate(int max);
int cofoDestroy(cofo *c);
int cofoInsert(cofo *c, void *x);
void *cofoQuery(cofo *c,void* key,int (*cmp)(void*,void*));
void *cofoRemoveLast(cofo *c);
aluno *alunoCreate(long int cpf,char *nome,int idade);
void *cofoRemove(cofo *c,void *key,int (*cmp)(void*,void*));

//HEADERS DO ALUNO
int CmpCPFAluno(void *a, void *b);
int CmpNomeAluno(void *a, void*b);

#endif


