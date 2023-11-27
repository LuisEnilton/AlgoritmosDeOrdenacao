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

// s é o nome do algoritmo de ordenação e n é o tamanho do vetor
void escreverTempo(int n,const string& s, long long tempo){
    string name = s + to_string(n) + "Nums.txt";
    ofstream arquivo(name, ios::app);
    if (arquivo.is_open()) {
        arquivo << tempo << "\n";
        arquivo.close();
        cout << "Tempo escrito com sucesso no arquivo " << name << endl;
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }

}


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
    cout << "1. Vetor aleatorio" << endl;
    cout << "2. Vetor crescente" << endl;
    cout << "3. Vetor decrescente" << endl;
    cout << "Escolha: ";
    cin >> choice;

    vector<int> arr;
    string s;
    cout << endl;
    switch (choice) {
        case 1:
            cout << "Lendo vetor aleatorio..." << endl;
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
        cout << "Escolha um metodo de ordenacao:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Merge Sort" << endl;
        cout << "4. Heap Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "0. Sair" << endl;

        cout << "Escolha: ";
        cin >> choice;
        auto inicio = chrono::high_resolution_clock::now();
        auto final = chrono::high_resolution_clock::now();

        long long tempo;

        switch (choice) {
            case 1:
                cout << "Executando Bubble Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                BubbleSort(arr.size(), arr);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count() << " nanosegundos" << endl;
                escreverTempo(n, "BubbleSort", tempo);
                break;
            case 2:
                cout << "Executando Insertion Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                InsertionSort(arr.size(), arr);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count() << " nanosegundos" << endl;
                escreverTempo(n, "InsertionSort", tempo);
                break;
            case 3:
                cout << "Executando Merge Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                MergeSort(0, arr.size() - 1, arr);

                break;
            case 4:
                cout << "Executando Heap Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                HeapSort(arr, arr.size());
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count() << " nanosegundos" << endl;
                escreverTempo(n, "HeapSort", tempo);
                break;
            case 5:
                cout << "Executando Quick Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                QuickSort(0, arr.size() - 1, arr);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count() << " nanosegundos" << endl;
                escreverTempo(n, "QuickSort", tempo);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Escolha inválida. Tente novamente." << endl;
        }
    cout << endl;
    } while (choice != 0);
}