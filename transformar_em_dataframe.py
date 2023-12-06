import os as os
import pandas as pd
import csv as csv

# calcula a média referente ao tempo de execução e à quantidade de comparações de um dado algoritmo
def media_arquivo(caminho_arquivo):
    
    valores_arquivo = []

    with open(caminho_arquivo, 'r') as f:
        for linha in f:
            lista = linha.rstrip("\n").split(" ")
            lista_inteira = [int(item) for item in lista]
            valores_arquivo.append(lista_inteira)

    tempos_arquivo = [valores[0] for valores in valores_arquivo]
    qtds_arquivo = [valores[1] for valores in valores_arquivo]

    return [sum(tempos_arquivo)/len(tempos_arquivo), sum(qtds_arquivo)/len(qtds_arquivo)]


# cria um arquivo csv para cada tamanho de vetor de entrada
def gerar_matriz(diretorios):

    # matriz de dados que posteriormente será transformada em um DataFrame
    matriz_medias_diretorios = []

    # percorre cada um dos diretorios passados como parâmetro
    for diretorio in diretorios:
        inteiros = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

        arquivos = os.listdir(diretorio)

        tamanho_entrada = 0

        i = 0
        for c in diretorio:
            if c in inteiros:
                tamanho_entrada = int(diretorio[i:])
                break
            i+=1

        # percorre cada um dos arquivos do diretorio
        for arquivo in arquivos:

            # nomeia o algoritmo com base no nome do arquivo 
            algoritmo = ""
            if arquivo.find("BubbleSort") != -1:
                algoritmo = "BubbleSort"
            elif arquivo.find("InsertionSort") != -1:
                algoritmo = "InsertionSort"
            elif arquivo.find("MergeSort") != -1:
                algoritmo = "MergeSort"
            elif arquivo.find("QuickSort") != -1:
                algoritmo = "QuickSort"
            elif arquivo.find("HeapSort") != -1:
                algoritmo = "HeapSort"

            # print("Arquivo: "+arquivo+" - Algoritmo: "+algoritmo)

            # nomeia o tipo de ordenação do vetor de entrada com base, também, no nome do arquivo
            ordenacao_vetor_entrada = ""
            if arquivo.find("Aleatorio") != -1:
                ordenacao_vetor_entrada = "Aleatorio"
            elif arquivo.find("Crescente") != -1:
                ordenacao_vetor_entrada = "Crescente"
            elif arquivo.find("Descrescente") != -1:
                ordenacao_vetor_entrada = "Decrescente"

            # termina de registrar os dados de uma medição
            medias_valores = media_arquivo(str(diretorio) + '/' + str(arquivo))
            media_tempos = medias_valores[0]
            media_qtds = medias_valores[1]

            # registra os dados na matriz
            matriz_medias_diretorios.append([algoritmo, tamanho_entrada, ordenacao_vetor_entrada, media_tempos, media_qtds])

    return matriz_medias_diretorios

# gera o DataFrame a partir da matriz de dados gerada por gerar_matriz()
def gerar_df(nomes_diretorios):

    matriz_resultante = gerar_matriz(nomes_diretorios)

    columns = ["Algoritmo", "Tamanho da entrada", "Ordenação da entrada", "Media dos tempos", "Media das comparações"]
    df = pd.DataFrame(data = matriz_resultante, columns = columns)

    # print(df)

    return df
