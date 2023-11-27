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

    int ParticaoLomutos(int index_i, int index_f, vector<int> &vetor){

        int index_pivot = index_f;
        int i  = index_i - 1;
        for(int j = index_i; j < index_f; j++){
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

     QuickSort(int index_i, int index_f, vector<int> &vetor){

        if(index_i < index_f){
            int index_pivot = ParticaoLomutos(index_i, index_f, vetor); // pivot j� ordenado!
            QuickSort(index_i, index_pivot - 1, vetor);
            QuickSort(index_pivot + 1, index_f, vetor);
        }
    }
};