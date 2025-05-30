#include <stdio.h>
#include <stdlib.h>
float salarioBruto, salarioFamilia, vantagens
, INSS, IPRF, deducoes;

void calculoVantagens(float numeroHoras, float salarioHora, float numeroFilhos, float valorPorFilho){
    salarioBruto = numeroHoras * salarioHora;
    salarioFamilia = numeroFilhos * valorPorFilho;
    vantagens = salarioBruto + salarioFamilia;
}
void calculoDeducoes(float taxaIR){
    INSS = salarioBruto * 0.08;
    IPRF = salarioBruto * taxaIR;
    deducoes = INSS + IPRF;
}

int main(){
    float numeroHoras, salarioHora, numeroFilhos, valorPorFilho, taxaIR;
    printf("Informe o Horas de trabalho: ");
    scanf("%f", &numeroHoras);

    printf("Informe o Salario por horas: ");
    scanf("%f", &salarioHora);

    printf("Informe a quantidade de filhos: ");
    scanf("%f", &numeroFilhos);

    printf("Informe o valor por filho: ");
    scanf("%f", &valorPorFilho);

    printf("Informe o valor da taxa IR: ");
    scanf("%f", &taxaIR);

    calculoVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho);
    calculoDeducoes(taxaIR);

    printf("VANTAGEM: %.2f \n", vantagens);
    printf("Dedu��es: %.2f \n", deducoes);

    system("pause");





}
