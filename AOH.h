//
// Created by Luis on 06/12/2023.
//

#ifndef ALGORITMOSDEORDENACAO_AOH_H
#define ALGORITMOSDEORDENACAO_AOH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <filesystem>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include <chrono>
#define endl '\n'
#endif //ALGORITMOSDEORDENACAO_AOH_H

class AOH{
private:

public:
    long long qtd_comp = 0;// quantidade de comparacoes realizadas pelo algoritmo

    //Função checa se o vetor é crescente
    bool check(vector<int> &vetor){
        for(int i = 1; i < vetor.size();i++){
            if(vetor[i] < vetor[i -1]) return false;
        }
        return true;
    }

    AOH(vector<int> &vetor){
        bool crescente = check(vetor);
        int tamanho = vetor.size();

        if(crescente){
            InsertionSort(tamanho,vetor,qtd_comp);
        }else{
            HeapSort(vetor,tamanho,qtd_comp);
        }
    }
};