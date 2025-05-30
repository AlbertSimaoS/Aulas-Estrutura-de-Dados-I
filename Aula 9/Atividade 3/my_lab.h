//cria um alias para a struct
typedef struct conta Conta;

//cria uma nova conta e atribui a ela os valores x, y e z
Conta *criaValores(float x, float y, float z);

//libera a mem�ria alocada para uma conta
void liberaValores(Conta *c);

//opera��es com a struct Conta (resultado armazenado em z)
void soma(Conta *c);
void subtrai(Conta *c);
void multiplica(Conta *c);
void divide(Conta *c);

//menu
void menu(char escolha);
