//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "GerarVetores.h"

using namespace std;

// Função para escrever os elementos de um vetor em um arquivo de texto
void escreverEmArquivo(const string &nomeArquivo, const vector<int> &meuVetor) {
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        for (const auto &elemento: meuVetor) {
            arquivo << elemento << "\n";
        }

        arquivo.close();
        cout << "Elementos escritos com sucesso no arquivo " << nomeArquivo << endl;
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }
}

// Função para ler os valores de um arquivo de texto e armazená-los em um vetor
vector<int> lerDeArquivo(const string &nomeArquivo) {
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
    int n;
    for(n = 100; n <=500;n+=100){
        GerarVetores gerarVetores;
        vector<int> vetorCrescente = gerarVetores.crescente(n);
        vector<int> vetorAleatorio = gerarVetores.aleatorio(n);
        vector<int> vetorDecrescente = gerarVetores.decrescente(n);
        //Escrever os vetores em arquivos
        string s = "vetorAleatorio" + to_string(n) + "Nums.txt";
        escreverEmArquivo(s, vetorAleatorio);
        s = "vetorCrescente" + to_string(n) + "Nums.txt";
        escreverEmArquivo(s, vetorCrescente);
        s = "vetorDecrescente" + to_string(n) + "Nums.txt";
        escreverEmArquivo(s, vetorDecrescente);
    }

    return 0;
}