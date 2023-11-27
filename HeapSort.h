//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#ifndef ALGORITMOSDEORDENACAO_HEAPSORT_H
#define ALGORITMOSDEORDENACAO_HEAPSORT_H

#endif //ALGORITMOSDEORDENACAO_HEAPSORT_H
using namespace std;

class HeapSort {

private:

public:


     HeapSort(vector<int> &arr, int size) {
            construir_heap(arr, size);
            for (int i = 0; i < size; i++) {
                swap((arr[0]), (arr[size - 1 - i]));
                refazHeapMax(arr, 0, size - 1 - i);
            }
    }

    void refazHeapMax(vector<int> &arr, int index, int tamanho) {
        int maior = index;
        int esquerda = 2 * index + 1;
        int direita = 2 * index + 2;
        if (esquerda < tamanho && arr[esquerda] > arr[maior]) {
            maior = esquerda;
        }
        if (direita < tamanho && arr[direita] > arr[maior]) {
            maior = direita;
        }
        if (maior != index) {
            swap((arr[index]), (arr[maior]));
            refazHeapMax(arr, maior, tamanho);
        }

    }

    void construir_heap(vector<int> &arr, int size) {
        for (int i = size - 1; i >= 0; i--) {
            refazHeapMax(arr, i, size);
        }
    }


};