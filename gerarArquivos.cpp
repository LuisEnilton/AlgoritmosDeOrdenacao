//
// Created by Luis on 27/11/2023.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>
#include "GerarVetores.h"

using namespace std;
namespace fs = std::filesystem;

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

    vector<int> comprimentos = {100, 1000, 5000, 30000, 50000, 100000, 150000, 200000};
    for (int n: comprimentos) {
        string diretorio = "vetores" + to_string(n);
        if (!fs::exists(diretorio)) {
            fs::create_directory(diretorio);
        }

        GerarVetores gerarVetores;
        vector<int> vetorCrescente = gerarVetores.crescente(n);
        vector<int> vetorAleatorio = gerarVetores.aleatorio(n);
        vector<int> vetorDecrescente = gerarVetores.decrescente(n);
        //Escrever os vetores em arquivos
        string s = diretorio + "/vetorAleatorio" + to_string(n) + "Nums.txt";
        escreverEmArquivo(s, vetorAleatorio);
        s = diretorio + "/vetorCrescente" + to_string(n) + "Nums.txt";
        escreverEmArquivo(s, vetorCrescente);
        s = diretorio + "/vetorDecrescente" + to_string(n) + "Nums.txt";
        escreverEmArquivo(s, vetorDecrescente);
    }

    return 0;
}