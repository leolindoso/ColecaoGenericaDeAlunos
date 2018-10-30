#ifndef CofoAluno_C_INCLUDED
#define CofoAluno_C_INCLUDED
#include "CofoAluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

//CRIA COLEÇÃO SE COFO É VAZIO
cofo *cofoCreate(int max){
    cofo *c;
    if(max > 0){
        c = (cofo*)malloc(sizeof(cofo));
        if(c != NULL){
            c->vet = (void**)malloc(sizeof(void*)*max);
            if(c->vet != NULL){
                c->max = max;
                c->elm = 0;
                return c;
            }
        }
    }
    return NULL;
}
//DESTROI A COLEÇÃO SE NAO APRESENTA NENHUM ELEMENTO
int cofoDestroy(cofo *c){
    if(c!= NULL){
        if(c->elm == 0){
            if(c->vet != NULL){
                printf("Não tem elementos\n");
                free(c->vet);
                c->max = 0;
            }
            c = NULL;
            free(c);
            return 1;
        }
    }
    return 0;
}
//INSERE ALUNO NA COLEÇÃO SE AINDA HÁ ESPAÇO
int cofoInsert(cofo *c, void *x){
    if(c != NULL){
        if (c->elm <= c->max-1){
            c->vet[c->elm] = x;
            c->elm++;
            for(int i =0;i < c->elm;i++){
                //printf("%d\t",c->vet[i]);
            }
            printf("\n");
            printf("Numero de Elementos: %d\n",c->elm);
            return 1;
        }else{
            printf("O Vetor ja está cheio!\n");
        }
        return 0;
    }
    return 0;
}
//PROCURA ALUNO NA COLEÇÃO A PARTIR DA CHAVE
void *cofoQuery(cofo *c,void* key,int (*cmp)(void*,void*)){
    int i = 0, achou = FALSE;
    if(c != NULL){
        if(c->elm > 0){
            if(c->vet != NULL){
                for(i = 0;i < c->elm;i++){
                    achou = cmp(key,c->vet[i]);
                    if(achou == TRUE){
                        printf("O elemento está no cofo!\n");
                        return c->vet[i];
                    }else{
                        //printf("O elemento não está no cofo!\n");
                    }
                }
            }
        }
    }
    return NULL;
}
//REMOVE O ULTIMO ELEMENTO DA COLEÇÃO
void *cofoRemoveLast(cofo *c){
    void *k;
    if(c != NULL){
        if(c->elm >0){
            if(c->vet != NULL){
                k = c->vet[c->elm-1];
                c->elm--;
                return k;
            }
        }
    }
    return NULL;
}
//REMOVE ELEMENTO SELECIONADO A PARTIR DA COMPARAÇÃO DA CHAVE
void *cofoRemove(cofo *c,void *key,int (*cmp)(void*,void*)){
    void *k;
    aluno *a;
    int achou = FALSE, i;
    if(c != NULL){
        if(c->elm > 0){
            for(i = 0;i < c->elm;i++){
                achou = cmp(key,c->vet[i]);
                if(achou == TRUE){
                    a = (aluno*)c->vet[i];
                    printf("O aluno %s foi removido!\n",a->nome);
                    c->elm--;
                    return a;
                }else{
                    //printf("O elemento não está no cofo!\n");
                }
            }
        }
    }
    return NULL;
}
//CRIA ALUNO
aluno *alunoCreate(long int cpf,char *nome,int idade){
    aluno *a;
    a = (aluno*)malloc(sizeof(aluno));
    if(a != NULL){
        a->CPF = cpf;
        a->idade = idade;
        strcpy(a->nome,nome);
        return a;
    }
    return NULL;
}

//COMPARA O CPF DO ALUNO COM A CHAVE ENVIADA
int CmpCPFAluno(void *a, void *b){
    long *pa;
    aluno *pb;
    pa = (long*)a;
    pb = (aluno*)b;
    if(pb->CPF == *pa){
        return TRUE;
    }
    return FALSE;
}

//COMPARA NOME DO ALUNO COM A CHAVE ENVIADA
int CmpNomeAluno(void *a, void*b){
    char *pa;
    aluno *pb;
    pa = (char*)a;
    pb = (aluno*)b;
    if(strcmp(pb->nome,pa) == 0){
        return TRUE;
    }
    return FALSE;
}

#endif


