#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    PILHA *pi = NULL;

    pi = criaPilha();

    int x;
    ALUNO al_consulta, al1, al2, al3;

    al1.matricula = 100;
    al1.n1 = 8.3;
    al1.n2 = 8.4;
    al1.n3 = 8.5;

    al2.matricula = 110;
    al2.n1 = 7.3;
    al2.n2 = 7.4;
    al2.n3 = 7.5;

    al3.matricula = 120;
    al3.n1 = 6.3;
    al3.n2 = 6.4;
    al3.n3 = 6.5;


    x = tamanhoPilha(pi);
    printf("\nO tamanho da pilha e: %d", x);

    x = pilhaCheia(pi);
    if(x)
        printf("\nA Pilha esta cheia!");
    else
        printf("\nA Pilha nao esta cheia.");

    x = pilhaVazia(pi);
    if(x)
        printf("\nA Pilha esta vazia!");
    else
        printf("\nA Pilha nao esta vazia.");

    x = inserePilha(pi, al1);
    if(x)
        printf("\nElemento %d inserido com sucesso!", x);
    else
        printf("\nErro, elemento nao inserido.");

    x = inserePilha(pi, al2);
    if(x)
        printf("\nElemento %d inserido com sucesso!", x);
    else
        printf("\nErro, elemento nao inserido.");

    x = inserePilha(pi, al3);
    if(x)
        printf("\nElemento %d inserido com sucesso!", x);
    else
        printf("\nErro, elemento nao inserido.");

    x = tamanhoPilha(pi);
    printf("\nO tamanho da pilha e: %d", x);

    x = acessaTopoPilha(pi, &al_consulta);
    if(x)
    {
        printf("\nConsulta realizada com sucesso:");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1:    %.2f", al_consulta.n1);
        printf("\nNota 2:    %.2f", al_consulta.n2);
        printf("\nNota 3:    %.2f", al_consulta.n3);
    }
    else
            printf("\nErro, consulta nao realizada.");

    x = removePilha(pi);
    if(x)
        printf("\nElemento %d removido com sucesso!", x);
    else
        printf("\nErro, elemento nao removido.");


     x = acessaTopoPilha(pi, &al_consulta);
    if(x)
    {
        printf("\nConsulta realizada com sucesso:");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1:    %.2f", al_consulta.n1);
        printf("\nNota 2:    %.2f", al_consulta.n2);
        printf("\nNota 3:    %.2f", al_consulta.n3);
    }
    else
            printf("\nErro, consulta nao realizada.");

    liberaPilha(pi);

}
