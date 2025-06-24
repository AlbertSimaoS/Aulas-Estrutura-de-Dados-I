#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaContato.h"

int main()
{
    Lista *li = criaLista();//cria a lista
    if (li == NULL)
        abortaPrograma();

    lerListaSalva(li); //carregar contatos do arquivo

    int esc = 0, id = 0;
    char nome[60];

    //menu
    do
    {
        printf("=========================================");
        printf("\n\tLista de Contatos\n");
        printf("=========================================");


        printf("\n\n1 - Inserir novo contato;");
        printf("\n2 - Relatorio de contatos(todos);");
        printf("\n3 - Relatorio individual(via ID);");
        printf("\n4 - Relatorio individual(via Nome);");
        printf("\n5 - Editar contato(via ID);");
        printf("\n6 - Excluir contato(via ID);");
        printf("\n7 - Encerrar e salvar programa;");
        printf("\n\nEscolha: ");
        scanf("%d", &esc);
        system("cls");

        switch(esc)
        {
            case 1:
                printf("=========================================");
                printf("\n\tInserir novo contato\n");
                printf("=========================================");
                printf("\n\n");
                modoEdicao = 0; //define que coletaDados sera usada para inserção(pede ID)

                CLIENTE cl;
                do {
                    printf("ID (para averiguar se existe): ");
                    scanf("%d", &cl.ID);
                    getchar();
                    if (confInsert(li, cl.ID)) {
                        printf("ERRO: Ja existe um contato com o ID %d. Tente outro.\n\n", cl.ID);
                    }
                } while (confInsert(li, cl.ID));

                system("cls");
                printf("=========================================");
                printf("\n\tInserir novo contato\n");
                printf("=========================================");
                printf("\n\n");

                CLIENTE dados = coletaDados(); // coleta os dados

                int x = inserirContato(li, dados);
                if (x)
                    printf("\nContato inserido com sucesso!\n\n");
                system("pause");
                break;
            case 2:
                printf("=========================================");
                printf("\n\tRelatorio de contatos(todos)\n");
                printf("=========================================");
                printf("\n\n");
                listarContatos(li);
                system("pause");
                break;
            case 3:
                printf("=========================================");
                printf("\n\tRelatorio individual(via ID)\n");
                printf("=========================================");
                printf("\n\n");
                printf("Qual o ID: ");
                scanf("%d", &id);
                listarIndividualID(li, id);
                system("pause");
                break;
            case 4:
                printf("=========================================");
                printf("\n\tRelatorio individual(via Nome)\n");
                printf("=========================================");
                printf("\n\n");
                printf("Nome: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                listarIndividualNome(li, nome);
                system("pause");
                break;
            case 5:
                printf("=========================================");
                printf("\n\tEditar contato(via ID)\n");
                printf("=========================================");
                printf("\n\n");
                printf("Qual o ID(para averiguar se existe): ");
                scanf("%d", &id);
                getchar();

                if (!confInsert(li, id))
                {
                    printf("Contato com ID %d nao encontrado.\n", id);
                } else
                {
                    modoEdicao = 1; //define que coletaDados sera usada para edição(mantem ID)
                    editarContato(li, id); // Só passa o ID agora
                }
                system("pause");
                break;
            case 6:
                printf("=========================================");
                printf("\n\tExcluir contato(via ID)\n");
                printf("=========================================");
                printf("\n\n");
                printf("Qual o ID(para averiguar se existe): ");
                scanf("%d", &id);
                getchar();

                if (!confInsert(li, id))
                {
                    printf("Contato com ID %d nao encontrado.\n", id);
                } else
                {
                   removerContato(li, id);
                }
                system("pause");
                break;
            case 7:
                printf("=========================================");
                printf("\n\tEncerrar e salvar programa\n");
                printf("=========================================");
                printf("\n\n");
                salvarPrograma(li);
                break;
            default:
                printf("Opcao invalida!\n\n");
                system("pause");
                break;
        }
            system("cls");
    } while(esc != 7);

    return 0;
}
