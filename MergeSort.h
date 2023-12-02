//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#ifndef ALGORITMOSDEORDENACAO_MERGESORT_H
#define ALGORITMOSDEORDENACAO_MERGESORT_H

#endif //ALGORITMOSDEORDENACAO_MERGESORT_H
using namespace std;

class MergeSort {

private:

public:

    void Merge(int index_i, int index_m, int index_f, vector<int> &vetor) {
        int tamanho_esq = index_m - index_i + 1;
        int tamanho_dir = index_f - index_m;

        // Cria vetores tempor�rios para os vetores retornados pelos filhos da esquerda e da direita
        //respectivamente
        vector<int> vetor_esq(tamanho_esq);
        vector<int> vetor_dir(tamanho_dir);

        // Copia os valores do vetor original, estes alterados pelo filho da esquerda e pelo da direita
        for (int i = 0; i < tamanho_esq; i++)
            vetor_esq[i] = vetor[index_i + i];
        for (int j = 0; j < tamanho_dir; j++)
            vetor_dir[j] = vetor[index_m + 1 + j];

        int i = 0, j = 0;
        int k = index_i;

        // Percorre os valores dos vetores da esquerda e da direita e os ordena de volta no vetor original
        while (i < tamanho_esq && j < tamanho_dir) {
            if (vetor_esq[i] <= vetor_dir[j]) {
                vetor[k] = vetor_esq[i];
                i++;
            } else {
                vetor[k] = vetor_dir[j];
                j++;
            }
            k++;
        }

        // Se o vetor da esquerda for maior que o da direita, os valores restantes s�o ordenados
        while (i < tamanho_esq) {
            vetor[k] = vetor_esq[i];
            i++;
            k++;
        }

        // Se o vetor da direita for maior que o da direita, os valores restantes s�o ordenados
        while (j < tamanho_dir) {
            vetor[k] = vetor_dir[j];
            j++;
            k++;
        }

    }

    // algoritmo MergeSort utilizando Divisao e Conquista
    MergeSort(int index_i, int index_f, vector<int> vetor) {

        if (index_i < index_f) {

            int index_m = (index_i + index_f) / 2;
            MergeSort(index_i, index_m, vetor);
            MergeSort(index_m + 1, index_f, vetor);
            Merge(index_i, index_m, index_f, vetor);
        }
    }
};