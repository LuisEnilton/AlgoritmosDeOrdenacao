//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#ifndef ALGORITMOSDEORDENACAO_INSERTIONSORT_H
#define ALGORITMOSDEORDENACAO_INSERTIONSORT_H

#endif //ALGORITMOSDEORDENACAO_INSERTIONSORT_H
using namespace std;

class InsertionSort {

private:

public:
    long long qtd_comp = 0;// quantidade de comparacoes realizadas pelo algoritmo

    InsertionSort(int tamanho, vector<int> &vetor, long long &qtd) {

        for (int i = 1; i < tamanho; i++) { // comeca em 1, pois compara o vetor[i] com o anterior (vetor[j])
            int item = vetor[i];
            int j = i - 1;

            qtd_comp++;
            while (j >= 0 && vetor[j] > item) { // enquanto j for >= 0 e o vetor[j] imediatamente anterior for menor que o item(vetor[i])
                qtd_comp++;
                vetor[j + 1] = vetor[j]; // preenche a posicao original do item(vetor[i]) com o vetor[j] do momento
                j = j - 1; // atualiza j
            }
            vetor[j +1] = item; // atualiza a posicao do item para a posicao imediatamente posterior ao vetor[j] comparado por ultimo
        }
        qtd = qtd_comp;
    }
};