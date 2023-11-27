//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include <chrono>
using namespace std;

vector<int> lerDoArquivo(const string &nomeArquivo) {
    vector<int> meuVetor;
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        int valor;
        while (arquivo >> valor) {
            meuVetor.push_back(valor);
        }

        arquivo.close();
        cout << "Elementos lidos com sucesso do arquivo " << nomeArquivo << endl;
    } else {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
    }

    return meuVetor;
}


int main() {
    int choice;
    //n é escolhido arbitrariamente
    int n = 100;

    cout << "Escolha o tipo de vetor que deseja ordenar:" << endl;
    cout << "1. Vetor aleatório" << endl;
    cout << "2. Vetor crescente" << endl;
    cout << "3. Vetor decrescente" << endl;
    cout << "Escolha: ";
    cin >> choice;

    vector<int> arr;
    string s;

    switch (choice) {
        case 1:
            cout << "Lendo vetor aleatório..." << endl;
            s = "vetorAleatorio" + to_string(n) + "Nums.txt";
            arr = lerDoArquivo(s);
            break;
        case 2:
            cout << "Lendo vetor crescente..." << endl;
            s = "vetorCrescente" + to_string(n) + "Nums.txt";
            arr = lerDoArquivo(s);
            break;
        case 3:
            cout << "Lendo vetor decrescente..." << endl;
            arr = lerDoArquivo(s);
            break;
        default:
            cout << "Escolha inválida. Tente novamente." << endl;
    }

    cout << "Vetor lido com Sucesso: ";
    cout << endl;

    do {
        cout << "Escolha um método de ordenação:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Merge Sort" << endl;
        cout << "4. Heap Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "0. Sair" << endl;

        cout << "Escolha: ";
        cin >> choice;
        auto start = chrono::high_resolution_clock::now();
        auto finish = chrono::high_resolution_clock::now();
        switch (choice) {
            case 1:
                cout << "Executando Bubble Sort..." << endl;
                start = chrono::high_resolution_clock::now();
                BubbleSort(arr.size(), arr);
                finish = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << " nanosegundos" << endl;
                break;
            case 2:
                cout << "Executando Insertion Sort..." << endl;
                // sorter.insertionSort(arr);  // Chame o método correspondente
                break;
            case 3:
                cout << "Executando Merge Sort..." << endl;
                // sorter.mergeSort(arr, 0, arr.size() - 1);  // Chame o método correspondente
                break;
            case 4:
                cout << "Executando Heap Sort..." << endl;
                // sorter.heapSort(arr);  // Chame o método correspondente
                break;
            case 5:
                cout << "Executando Quick Sort..." << endl;
                // sorter.quickSort(arr, 0, arr.size() - 1);  // Chame o método correspondente
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Escolha inválida. Tente novamente." << endl;
        }

    } while (choice != 0);
}