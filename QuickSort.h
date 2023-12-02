//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#ifndef ALGORITMOSDEORDENACAO_QUICKSORT_H
#define ALGORITMOSDEORDENACAO_QUICKSORT_H

#endif //ALGORITMOSDEORDENACAO_QUICKSORT_H
using namespace std;

class QuickSort {

    private:

    public:
    long long qtd_comp = 0;// quantidade de comparacoes realizadas pelo algoritmo

    int ParticaoLomutos(int index_i, int index_f, vector<int> &vetor){

        int index_pivot = index_f;
        int i  = index_i - 1;
        for(int j = index_i; j < index_f; j++){
            qtd_comp++;
            if(vetor[j] <= vetor[index_pivot]){
                i++;
                int aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
        int aux = vetor[i+1];
        vetor[i+1] = vetor[index_f];
        vetor[index_f] = aux;

        return i+1;
    }

    int particao_r(vector<int> &vetor, int low, int high)
    {
        // Gera um numero aleatório entre low .. high
        srand(time(NULL));
        int random = low + rand() % (high - low);

        // Swap A[random] with A[high]
        swap(vetor[random], vetor[high]);

        return ParticaoLomutos( low, high,vetor);
    }

     QuickSort(int index_i, int index_f, vector<int> &vetor, long long &qtd){

        if(index_i < index_f){
            int index_pivot = particao_r(vetor,index_i,index_f);
            QuickSort(index_i, index_pivot - 1, vetor,qtd);
            QuickSort(index_pivot + 1, index_f, vetor,qtd);
        }
        qtd = qtd_comp;
    }
};


