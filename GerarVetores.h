//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#ifndef ALGORITMOSDEORDENACAO_GERARVETORES_H
#define ALGORITMOSDEORDENACAO_GERARVETORES_H

#endif //ALGORITMOSDEORDENACAO_GERARVETORES_H
using namespace std;

class GerarVetores {
private:

public:
     vector<int> aleatorio(int &n) {
        vector<int> vetor;
        random_device rd;
        mt19937 g(rd());
        for (int i = 1; i <= n; i++) {
            vetor.push_back(i);
        }
        shuffle(vetor.begin(), vetor.end(), g);
        return vetor;
    }

    vector<int>  decrescente(int &n) {
        vector<int> vetor;
        for (int i = n; i >= 1; i--) {
            vetor.push_back(i);
        }
        return vetor;
    }

    vector<int>  crescente(int &n) {
        vector<int> vetor;
        for (int i = 1; i <= n; i++) {
            vetor.push_back(i);
        }
        return vetor;
    }


};