//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#ifndef ALGORITMOSDEORDENACAO_BUBBLESORT_H
#define ALGORITMOSDEORDENACAO_BUBBLESORT_H

#endif //ALGORITMOSDEORDENACAO_BUBBLESORT_H
using namespace std;

class BubbleSort {

private:

public:
    long long qtd_comp = 0;// quantidade de comparacoes realizadas pelo algoritmo

    BubbleSort(int tamanho, vector<int> &vetor, long long &qtd) {
        for (int i = 0; i < tamanho - 1; i++) { // tamanho - 1 em virtude do vetor ser 0 indexado
            for (int j = 0; j < tamanho - 1 - i; j++) { // realiza 1 iteracao a menos a cada incremento de i
                qtd_comp++;
                if (vetor[j] > vetor[j + 1]) {
                    int aux = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = aux;
                }
            }
        }
        qtd = qtd_comp;
    }
};