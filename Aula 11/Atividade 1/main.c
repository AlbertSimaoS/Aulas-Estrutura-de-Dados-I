#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

int main()
{

/*
    int x = 0;
    int matricula = 120, posicao = 2;

    Lista *li = NULL;

    if((li = criaLista()) == NULL)
    {
        abortaPrograma();
    }

    ALUNO al_consulta, al1, al2, al3;

    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;

    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;

    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    x = insereInicio(li, al1);
    if(x)
    {
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    } else
    {
        printf("\nNao foi possivel inserir no inicio.");
    }

    x = insereFinal(li, al2);
    if(x)
    {
        printf("\nAluno %d inserido no final com sucesso!", x);
    } else
    {
        printf("\nNao foi possivel inserir no final.");
    }

    x = insereOrdenado(li, al3);
    if(x)
    {
        printf("\nAluno %d inserido ordenadamentre com sucesso!", x);
    } else
    {
        printf("\nNao foi possivel inserir ordenadamente.");
    }


    x = tamanhoLista(li);
    printf("\nO tamanho da lista e: %d", x);

    if(listaCheia(li))
    {
        printf("\nLista esta cheia!");
    }else
    {
        printf("\nLista nao esta cheia.");
    }

    if(listaVazia(li))
    {
        printf("\nLista esta vazia");
    }else
    {
        printf("\nLista nao esta vazia.");
    }

    x = removeInicio(li);
    if(x)
    {
        printf("\nAluno %d removido do inicio com sucesso!", x);
    } else
    {
        printf("\nNao foi possivel remover do inicio.");
    }

    x = removeFinal(li);
    if(x)
    {
        printf("\nAluno %d removido do final com sucesso!", x);
    } else
    {
        printf("\nNao foi possivel remover do final.");
    }

    x = removeOrdenado(li, matricula);
    if(x)
    {
        printf("\nAluno %d removido ordenadamente com sucesso!", x);
    } else
    {
        printf("\nNao foi possivel remover o aluno.");
    }

    x = consultaPosicao(li, posicao, &al_consulta);
    if(x)
    {
        printf("\n\nConsulta na posicao %d: ", posicao);
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1: %.2f", al_consulta.n1);
        printf("\nNota 2: %.2f", al_consulta.n2);
        printf("\nNota 3: %.2f", al_consulta.n3);
    } else
    {
        printf("\nPosicao %d nao existe.", posicao);
    }

    x = consultaMatricula(li, matricula, &al_consulta);
    if(x)
    {
        printf("\n\nConsulta aluno matriculado");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1: %.2f", al_consulta.n1);
        printf("\nNota 2: %.2f", al_consulta.n2);
        printf("\nNota 3: %.2f", al_consulta.n3);
    } else
    {
        printf("\nMatricula %d nao encontrada.", matricula);
    }


    apagaLista(li);
    */
    Lista *li = NULL;

    if((li = criaLista()) == NULL)
    {
        abortaPrograma();
    }

    int esc = 0, x = 0, matricula = 0;

    ALUNO al_consulta;

    do
    {
       printf("=========================================");
       printf("\n\tLista de Alunos\n");
       printf("=========================================");
       printf("\n\n1 - Incluir de forma ordenada;");
       printf("\n2 - Buscar pela matricula;");
       printf("\n3 - Excluir de forma ordenada;");
       printf("\n4 - Encerrar o programa;");

       printf("\n\nEscolha: ");
       scanf("%d", &esc);
       system("cls");

       switch(esc)
       {
            case 1:
                printf("=========================================");
                printf("\n\tIncluir de forma ordenada\n");
                printf("=========================================");
                printf("\n\n");
                insereOrdenado(li, coletaDados());
                break;
            case 2:
                printf("=========================================");
                printf("\n\tBuscar pela matricula\n");
                printf("=========================================");
                printf("\n\n");
                printf("\n\nQual o numero de matricula: ");
                scanf("%d", &matricula);
                x = consultaMatricula(li, matricula, &al_consulta);
                if(x)
                {
                    printf("\n\nConsulta aluno matriculado:");
                    printf("\nMatricula: %d", al_consulta.matricula);
                    printf("\nNota 1: %.2f", al_consulta.n1);
                    printf("\nNota 2: %.2f", al_consulta.n2);
                    printf("\nNota 3: %.2f", al_consulta.n3);
                } else
                {
                    printf("\nMatricula %d nao encontrada.", matricula);
                }
                printf("\n\n");
                system("pause");
                break;
            case 3:
                printf("=========================================");
                printf("\n\tExcluir de forma ordenada\n");
                printf("=========================================");
                printf("\n\n");
                printf("\n\nQual o numero de matricula: ");
                scanf("%d", &matricula);
                x = removeOrdenado(li, matricula);
                if(x)
                {
                    printf("\nAluno %d removido ordenadamente com sucesso!", x);
                } else
                {
                    printf("\nNao foi possivel remover o aluno.");
                }
                printf("\n\n");
                system("pause");
                break;
            case 4:
                printf("\n  Encerrado...\n\n");
                system("pause");
                apagaLista(li);
                break;
            default:
                printf("Opcao invalida!\n\n");
                system("pause");
                break;
       }
       system("cls");
    }
    while(esc != 4);


}
