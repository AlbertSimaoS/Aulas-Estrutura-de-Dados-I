#include <stdio.h>
#include <stdlib.h>

void calculoVantagens(float numeroHoras, float salarioHora, float numeroFilhos, float valorPorFilho, float *salarioBruto, float *salarioFamilia, float *vantagens) {
    *salarioBruto = numeroHoras * salarioHora;
    *salarioFamilia = numeroFilhos * valorPorFilho;
    *vantagens = *salarioBruto + *salarioFamilia;
}

void calculoDeducoes(float salarioBruto, float taxaIR, float *INSS, float *IPRF, float *deducoes) {
    *INSS = salarioBruto * 0.08;
    *IPRF = salarioBruto * taxaIR;
    *deducoes = *INSS + *IPRF;
}

int main() {
    float numeroHoras, salarioHora, numeroFilhos, valorPorFilho, taxaIR;
    float salarioBruto, salarioFamilia, vantagens, INSS, IPRF, deducoes;

    printf("Informe o numero de horas de trabalho: ");
    scanf("%f", &numeroHoras);

    printf("Informe o salario por hora: ");
    scanf("%f", &salarioHora);

    printf("Informe a quantidade de filhos: ");
    scanf("%f", &numeroFilhos);

    printf("Informe o valor por filho: ");
    scanf("%f", &valorPorFilho);

    printf("Informe o valor da taxa IR: ");
    scanf("%f", &taxaIR);


    calculoVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho, &salarioBruto, &salarioFamilia, &vantagens);

    calculoDeducoes(salarioBruto, taxaIR, &INSS, &IPRF, &deducoes);

    printf("Vantagens: %.2f \n", vantagens);
    printf("Deducoes: %.2f \n", deducoes);

    system("pause");
}
