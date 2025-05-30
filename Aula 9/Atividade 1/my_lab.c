#include <stdio.h>
#include <stdlib.h>
#include "my_lab.h"

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
