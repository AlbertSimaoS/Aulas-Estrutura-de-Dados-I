int modoEdicao;

typedef struct cliente
{
    int ID;
    char nome[60];
    char empresa[60];
    char departamento[60];
    char telefone[20];
    char celular[20];
    char email[60];
}CLIENTE;

typedef struct elemento* Lista;

Lista *criaLista();

void abortaPrograma();

int inserirContato(Lista *li, CLIENTE cl);

int confInsert(Lista *li, int idBuscado);

CLIENTE coletaDados();

void listarContatos(Lista *li);

void listarIndividualID(Lista *li, int ID);

void listarIndividualNome(Lista *li, char *nome);

void toMinuscula(char *str);

int editarContato(Lista *li, int ID_para_editar);

void removerContato(Lista *li, int ID);

void salvarPrograma(Lista *li);

void apagaLista(Lista *li);

void lerListaSalva(Lista *li);
