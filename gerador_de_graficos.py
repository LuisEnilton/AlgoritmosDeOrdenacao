import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import os as os
import transformar_em_dataframe as dft


nomes_diretorios = ["resultadosVetores100", "resultadosVetores1000", "resultadosVetores5000",
                        "resultadosVetores30000", "resultadosVetores50000","resultadosVetores100000",
                        "resultadosVetores150000", "resultadosVetores200000"]

df = dft.gerar_df(nomes_diretorios)

def salvar_grafico(diretorio, arquivo, imagem):
    if not os.path.exists(diretorio):
        os.makedirs(diretorio)
    plt.savefig(diretorio+"/"+arquivo)
        

def tempo_e_algoritmo_por_tamanho_da_entrada(df, tamanhos):
    for tamanho in tamanhos:
        df_entrada = df.loc[df["Tamanho da entrada"] == tamanho]
        tempos = {}
        
        for indice, linha in df_entrada.iterrows():
            if linha["Ordenação da entrada"] == "Aleatorio":
                tempos[linha["Algoritmo"]] = int(linha["Media dos tempos"])

        print(tamanho)
        for key, item in tempos.items():
            print(str(key)+" : "+str(item))


        plt.figure()
        sns.barplot(tempos, palette="Set2")
        plt.title("Algoritmo x Tempo de execução para entradas de tamanho "+str(tamanho))

        diretorio = "algoritmoXTempoDeExecucaoPorTamanhoDaEntrada"
        arquivo = "AlgoritmoXTempoDeExecucaoParaEntradasDeTamanho"+str(tamanho)
        salvar_grafico(diretorio, arquivo, plt)


def qtd_de_comparacoes_e_algoritmo_por_tamanho_de_entrada(df, tamanhos):
    for tamanho in tamanhos:
        df_entrada = df.loc[df["Tamanho da entrada"] == tamanho]
        qtds = {}

        for indice, linha in df_entrada.iterrows():
            if linha["Ordenação da entrada"] == "Aleatorio":
                qtds[linha["Algoritmo"]] = int(linha["Media das comparações"])

        print(tamanho)
        for key, item in qtds.items():
            print(str(key)+" : "+str(item))

        plt.figure()
        sns.barplot(qtds, palette="Set2")
        plt.title("Algoritmo x Quantidade de comparações para entradas de tamanho "+str(tamanho))

        diretorio = "algoritmoXComparacoesPorTamanhoDaEntrada"
        arquivo = "AlgoritmoXComparacoesParaEntradasDeTamanho"+str(tamanho)
        salvar_grafico(diretorio, arquivo, plt)


def tempo_e_tamanho_da_entrada_por_algoritmo_por_ordenacao_da_entrada(df, algoritmos, ordenacoes):
    for ordenacao in ordenacoes:
        for algoritmo in algoritmos:
            df_entrada = df.loc[df["Algoritmo"] == algoritmo]
            tempos = {}

            # em picosegundos
            for indice, linha in df_entrada.iterrows():
                if linha["Ordenação da entrada"] == ordenacao:
                    tempos[int(linha["Tamanho da entrada"])] = float(linha["Media dos tempos"])

            print(algoritmo+" : "+ordenacao)
            for key, item in tempos.items():
                print(str(key)+" : "+str(item))

            plt.figure()
            sns.barplot(tempos, palette="Set2")
            plt.title("Tamanho da entrada x Tempo de execução do "+str(algoritmo)+" ("+ordenacao+")")

            diretorio = "tamanhoDaEntradaXTempoDeExecucaoPorAlgoritmo"+str(ordenacao)
            arquivo = "tamanhoDaEntradaXTempoDeExecucaoDo"+str(algoritmo)
            salvar_grafico(diretorio, arquivo, plt)


algoritmos = ["BubbleSort", "InsertionSort", "MergeSort", "HeapSort", "QuickSort"]
tamanhos = [100, 1000, 5000, 30000, 50000, 100000, 150000, 200000]
ordenacoes = ["Aleatorio", "Crescente", "Decrescente"]

tempo_e_algoritmo_por_tamanho_da_entrada(df, tamanhos)
qtd_de_comparacoes_e_algoritmo_por_tamanho_de_entrada(df, tamanhos)
tempo_e_tamanho_da_entrada_por_algoritmo_por_ordenacao_da_entrada(df, algoritmos, ordenacoes)
