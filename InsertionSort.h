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
using namespace  std;
class InsertionSort {

private:

public:

        InsertionSort(int tamanho, vector<int> vetor) {

        for (int i = 1; i < tamanho; i++) { // come�a em 1, pois compara o vetor[i] com o anterior (vetor[j])
            int item = vetor[i];
            int j = i - 1;

            while (j >= 0 && vetor[j] >item) { // enquanto j for >= 0 e o vetor[j] imediatamente anterior for menor que o item(vetor[i])
                vetor[j + 1] = vetor[j]; // preenche a posi��o original do item(vetor[i]) com o vetor[j] do momento
                j = j - 1; // atualiza j
            }
            vetor[j +1] = item; // atualiza a posi��o do item para a posi��o imediatamente posterior ao vetor[j] comparado por �ltimo
        }

    }
};