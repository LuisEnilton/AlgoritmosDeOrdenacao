//
// Created by Luis on 27/11/2023.
//
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

using namespace std;
namespace fs = std::filesystem;

vector<string> cond = {"Aleatorio", "Crescente", "Descrescente"};

// s é o nome do algoritmo de ordenação e n é o tamanho do vetor
void escreverTempo(int n, const string &s, long long tempo, long long qtd, int choice) {
    string diretorio = "resultadosVetores" + to_string(n);
        if (!fs::exists(diretorio)) {
            fs::create_directory(diretorio);
        }
    string name = diretorio + '/' + s + cond[choice] + to_string(n) + "Nums.txt";
    ofstream arquivo(name, ios::app);
    if (arquivo.is_open()) {
        arquivo << tempo << " " << qtd << "\n";
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
    int n = 200000;

    cout << "Escolha o tipo de vetor que deseja ordenar:" << endl;
    cout << "1. Vetor aleatorio" << endl;
    cout << "2. Vetor crescente" << endl;
    cout << "3. Vetor decrescente" << endl;
    cout << "Escolha: ";
    cin >> choice;

    vector<int> arr;
    string s;
    string diretorio = "vetores" + to_string(n);
    cout << endl;
    switch (choice) {
        case 1:
            cout << "Lendo vetor aleatorio..." << endl;
            s = diretorio + "/vetorAleatorio" + to_string(n) + "Nums.txt";
            arr = lerDoArquivo(s);
            break;
        case 2:
            cout << "Lendo vetor crescente..." << endl;
            s = diretorio + "/vetorCrescente" + to_string(n) + "Nums.txt";
            arr = lerDoArquivo(s);
            break;
        case 3:
            cout << "Lendo vetor decrescente..." << endl;
            s = diretorio + "/vetorDecrescente" + to_string(n) + "Nums.txt";
            arr = lerDoArquivo(s);
            break;
        default:
            cout << "Escolha inválida. Tente novamente." << endl;
    }

    int ordem = choice;

    cout << "Vetor lido com Sucesso: ";
    cout << endl;
    vector<int> aux = arr;
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
        arr = aux;
        long long tempo;
        long long qtd = 0;
        switch (choice) {

            case 1:
                cout << "Executando Bubble Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                BubbleSort(arr.size(), arr, qtd);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count()
                     << " nanosegundos" << endl;
                escreverTempo(n, "BubbleSort", tempo, qtd, ordem - 1);
                break;
            case 2:
                cout << "Executando Insertion Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                InsertionSort(arr.size(), arr, qtd);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count()
                     << " nanosegundos" << endl;
                escreverTempo(n, "InsertionSort", tempo, qtd, ordem - 1);
                break;
            case 3:
                cout << "Executando Merge Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                MergeSort(0, arr.size() - 1, arr, qtd);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count()
                     << " nanosegundos" << endl;
                escreverTempo(n, "MergeSort", tempo, qtd, ordem - 1);
                break;
            case 4:
                cout << "Executando Heap Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                HeapSort(arr, arr.size(),qtd);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count()
                     << " nanosegundos" << endl;
                escreverTempo(n, "HeapSort", tempo, qtd, ordem - 1);
                break;
            case 5:
                cout << "Executando Quick Sort..." << endl;
                inicio = chrono::high_resolution_clock::now();
                QuickSort(0, arr.size() - 1, arr, qtd);
                final = chrono::high_resolution_clock::now();
                tempo = chrono::duration_cast<chrono::nanoseconds>(final - inicio).count();
                cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(final - inicio).count()
                     << " nanosegundos" << endl;
                escreverTempo(n, "QuickSort", tempo, qtd, ordem - 1);
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