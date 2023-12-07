//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <filesystem>
#include <chrono>
#include "AOH.h"

#define endl '\n'

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

vector<string> cond = {"Aleatorio", "Crescente", "Descrescente"};
vector<int> tamanhos = {100, 1000, 5000, 30000, 50000, 100000, 150000, 200000};

int main() {
    int choice = 1;
    do {

        cout << "Escolha o tipo de vetor que deseja ordenar:" << endl;
        cout << "1. Vetor aleatorio" << endl;
        cout << "2. Vetor crescente" << endl;
        cout << "3. Vetor decrescente" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha: ";
        cin >> choice;

        string tipo = cond[choice - 1];

            cout << "Escolha o tamanho da entrada de vetor que deseja ordenar:" << endl;
            cout << "1. 100" << endl;
            cout << "2. 1000" << endl;
            cout << "3. 5000" << endl;
            cout << "4. 30000" << endl;
            cout << "5. 50000" << endl;
            cout << "6. 100000" << endl;
            cout << "7. 150000" << endl;
            cout << "8. 200000" << endl;
            cout << "Escolha: ";
            cin >> choice;


            int tamanho = tamanhos[choice - 1];
            string diretorio = "vetores" + to_string(tamanho);
            cout << "Lendo vetor " << tipo << " ..." << endl;
            string s = diretorio + "/vetor" + tipo + to_string(tamanho) + "Nums.txt";

            vector<int> aux = lerDoArquivo(s);


            auto inicio = chrono::high_resolution_clock::now();
            auto a = AOH(aux);
            auto fim = chrono::high_resolution_clock::now();
            auto duracao = chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();

            cout << "Tempo de execucao: " << duracao << " nanosegundos" << endl;
            cout << "Quantidade de comparacoes: " << a.qtd_comp << endl;

    } while (choice != 0);

}
