#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaContato.h"

// Variável global usada para definir se a coletaDados() será usada em modo de edição (1) ou inserção (0)
extern int modoEdicao = 0;

// Estrutura do nó da lista encadeada
struct elemento {
    CLIENTE dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

// Cria e inicializa a lista dinâmica
Lista *criaLista() {
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL; // lista começa vazia
    return li;
}

// Encerra o programa em caso de erro grave
void abortaPrograma() {
    printf("ERRO! Lista nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("pause");
    exit(1);
}

// Verifica se já existe um contato com o ID especificado
int confInsert(Lista *li, int idBuscado) {
    if (li == NULL)
        return 0;

    ELEM *atual = *li;
    while (atual != NULL) {
        if (atual->dados.ID == idBuscado)
            return 1; // ID encontrado
        atual = atual->prox;
    }
    return 0; // ID não encontrado
}

// Insere um novo contato de forma ordenada por ID
int inserirContato(Lista *li, CLIENTE cl) {
    if (li == NULL)
        abortaPrograma();

    if (confInsert(li, cl.ID)) {
        printf("ERRO: Já existe um contato com o ID %d.\n", cl.ID);
        return 0;
    }

    ELEM *novo = (ELEM *) malloc(sizeof(ELEM));
    if (novo == NULL)
        return 0;

    novo->dados = cl;
    novo->prox = NULL;

    // Inserção no início da lista
    if (*li == NULL || cl.ID < (*li)->dados.ID) {
        novo->prox = *li;
        *li = novo;
    } else {
        ELEM *ant = *li;
        ELEM *atual = (*li)->prox;
        while (atual != NULL && atual->dados.ID < cl.ID) {
            ant = atual;
            atual = atual->prox;
        }
        novo->prox = atual;
        ant->prox = novo;
    }
    return 1;
}

// Coleta dados do usuário para preencher um contato
CLIENTE coletaDados() {
    CLIENTE cl;

    if (!modoEdicao) { // Em inserção, solicita ID, em Edição não solicita
        printf("ID: ");
        scanf("%d", &cl.ID);
        getchar(); // Limpa o '\n' do buffer
    }

    // Coleta os demais campos
    printf("Nome: ");
    fgets(cl.nome, sizeof(cl.nome), stdin);

    printf("Empresa: ");
    fgets(cl.empresa, sizeof(cl.empresa), stdin);

    printf("Departamento: ");
    fgets(cl.departamento, sizeof(cl.departamento), stdin);

    printf("Telefone: ");
    fgets(cl.telefone, sizeof(cl.telefone), stdin);

    printf("Celular: ");
    fgets(cl.celular, sizeof(cl.celular), stdin);

    printf("Email: ");
    fgets(cl.email, sizeof(cl.email), stdin);

    return cl;
}

// Lista todos os contatos armazenados na lista, ordenados automaticamente por causa do Insert
void listarContatos(Lista *li) {
    if (*li == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    ELEM *atual = *li;
    while (atual != NULL) {
        CLIENTE cl = atual->dados;
        printf("ID: %d\n", cl.ID);
        printf("Nome: %s", cl.nome);
        printf("Empresa: %s", cl.empresa);
        printf("Departamento: %s", cl.departamento);
        printf("Telefone: %s", cl.telefone);
        printf("Celular: %s", cl.celular);
        printf("Email: %s\n", cl.email);
        atual = atual->prox;
    }
}

// Lista um contato específico pelo ID
void listarIndividualID(Lista *li, int ID) {
    if (li == NULL)
        abortaPrograma();

    ELEM *no = *li;
    while (no != NULL && no->dados.ID != ID)
        no = no->prox;

    if (no == NULL)
        printf("\nContato com ID %d não encontrado.\n", ID);
    else {
        CLIENTE cl = no->dados;
        printf("---------------------------\n");
        printf("Contato com ID: %d\n", cl.ID);
        printf("---------------------------\n");
        printf("Nome: %s", cl.nome);
        printf("Empresa: %s", cl.empresa);
        printf("Departamento: %s", cl.departamento);
        printf("Telefone: %s", cl.telefone);
        printf("Celular: %s", cl.celular);
        printf("Email: %s\n", cl.email);
    }
}

// Torna todos os caracteres da string em minúsculos
void Minuscula(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

// Lista contatos pelo nome (pode haver mais de um com o mesmo nome)
void listarIndividualNome(Lista *li, char *nome) {
    if (li == NULL)
        abortaPrograma();

    char nomeBusca[60];
    strncpy(nomeBusca, nome, 60);//copia a string de 'nome' para 'nomeBusca'
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; //encontra o \n
    Minuscula(nomeBusca);//transforma toda a string em minuscula

    ELEM *no = *li;
    int encontrado = 0;
    while (no != NULL) {
        char nomeAtual[60];
        strncpy(nomeAtual, no->dados.nome, 60);
        nomeAtual[strcspn(nomeAtual, "\n")] = '\0';
        Minuscula(nomeAtual);//transforma o nome que esta analisando em minusculo, para comparar corretamente

        if (strcmp(nomeAtual, nomeBusca) == 0) {//'strcmp' verifica se as strings são extamente iguais, se sim retorna 0
            CLIENTE cl = no->dados;
            printf("---------------------------\n");
            printf("Contato com Nome: %s", cl.nome);
            printf("---------------------------\n");
            printf("ID: %d\n", cl.ID);
            printf("Empresa: %s", cl.empresa);
            printf("Departamento: %s", cl.departamento);
            printf("Telefone: %s", cl.telefone);
            printf("Celular: %s", cl.celular);
            printf("Email: %s\n", cl.email);
            printf("\n");
            encontrado = 1;
        }
        no = no->prox;
    }

    if (!encontrado)
        printf("Contato com nome '%s' nao encontrado.\n", nomeBusca);//encontrado (1), não encontrado (0)
}

// Edita os dados de um contato existente
int editarContato(Lista *li, int ID_editar) {
    if (li == NULL)
        abortaPrograma();

    ELEM *no = *li;
    while (no != NULL && no->dados.ID != ID_editar)
        no = no->prox;

    CLIENTE *antigo = &no->dados;

    // Exibe dados atuais
    printf("\n=========================================");
    printf("\nDados atuais do contato (ID %d):\n", antigo->ID);
    printf("=========================================\n");
    printf("Nome:        %s", antigo->nome);
    printf("Empresa:     %s", antigo->empresa);
    printf("Departamento:%s", antigo->departamento);
    printf("Telefone:    %s", antigo->telefone);
    printf("Celular:     %s", antigo->celular);
    printf("Email:       %s", antigo->email);

    char opc;
    printf("\n\nDeseja realmente editar este contato? (S/N): ");
    scanf(" %c", &opc);
    getchar();

    if (opc != 's' && opc != 'S') {
        printf("\nEdicao cancelada.\n");
        return 0;
    }

    printf("\nInforme os novos dados:\n");
    CLIENTE novos = coletaDados();
    novos.ID = antigo->ID; // mantém o ID original

    // Atualiza os dados
    strcpy(antigo->nome, novos.nome);
    strcpy(antigo->empresa, novos.empresa);
    strcpy(antigo->departamento, novos.departamento);
    strcpy(antigo->telefone, novos.telefone);
    strcpy(antigo->celular, novos.celular);
    strcpy(antigo->email, novos.email);

    printf("\nContato atualizado com sucesso!\n");
    return 1;
}

// Remove um contato da lista a partir do ID
void removerContato(Lista *li, int ID) {
    if (li == NULL)
        abortaPrograma();

    ELEM *ant = NULL, *no = *li;
    while (no != NULL && no->dados.ID != ID) {
        ant = no;
        no = no->prox;
    }

    CLIENTE *antigo = &no->dados;

    // Exibe dados para confirmação
    printf("\n=========================================");
    printf("\nDados atuais do contato (ID %d):\n", antigo->ID);
    printf("=========================================\n");
    printf("Nome:        %s", antigo->nome);
    printf("Empresa:     %s", antigo->empresa);
    printf("Departamento:%s", antigo->departamento);
    printf("Telefone:    %s", antigo->telefone);
    printf("Celular:     %s", antigo->celular);
    printf("Email:       %s", antigo->email);

    char opc;
    printf("\n\nDeseja realmente remover este contato? (S/N): ");
    scanf(" %c", &opc);
    getchar();

    if (opc != 's' && opc != 'S') {
        printf("\nRemocao cancelada.\n");
        return 0;
    }

    // Remove o nó da lista
    if (ant == NULL) {
        *li = no->prox;
    } else {
        ant->prox = no->prox;
    }

    int idRemovido = no->dados.ID;
    free(no);
    system("cls");
    printf("Contato com ID: %d, removido com sucesso...\n\n", idRemovido);
}

// Salva a lista de contatos em arquivo binário
void salvarPrograma(Lista *li) {
    FILE *f = fopen("arquivo.txt", "wb");//salva os contatos em 'arquivo'
    if (f == NULL) {
        printf("Erro na abertura para salvar.\n");
        system("pause");
        exit(1);
    }

    ELEM *atual = *li;
    while (atual != NULL) {
        fwrite(&(atual->dados), sizeof(CLIENTE), 1, f);
        atual = atual->prox;
    }

    fclose(f);
    printf("Contatos salvos com sucesso!\n\n");
    printf("Encerrando o programa...\n");
    system("pause");
    apagaLista(li);//apos salvo, libera a memória
}

// Libera toda a memória alocada pela lista
void apagaLista(Lista *li) {
    if (li != NULL) {
        ELEM *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

// Lê contatos previamente salvos no arquivo binário
void lerListaSalva(Lista *li) {
    FILE *f = fopen("arquivo.txt", "rb");
    if (f == NULL) {
        printf("Nenhum arquivo salvo encontrado!\n");
        system("pause");
        system("cls");
        return;
    }

    CLIENTE temp;
    int qtd = 0;
    while (fread(&temp, sizeof(CLIENTE), 1, f) == 1) {
        inserirContato(li, temp);
        qtd++;
    }

    fclose(f);
    printf("%d Contatos carregados.\n\n", qtd);
    system("pause");
    system("cls");
}
