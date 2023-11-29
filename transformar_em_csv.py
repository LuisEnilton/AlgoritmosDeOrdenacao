def txt_to_csv(filename, n):
    # Lista para armazenar os números e médias
    data = []

   
        # Cria o nome do arquivo
    file_prefix = filename.split('.')[0]

        # Lê o arquivo e calcula a média dos tempos
    with open(filename, 'r') as file:
        numbers = [float(line.strip()) for line in file]
        avg_time = sum(numbers) / len(numbers)

        # Adiciona uma tupla à lista com o número e a média dos tempos
    data.append((n, avg_time))

    # Escreve os dados no arquivo CSV
    with open(f'{file_prefix}_output.csv', 'w') as csv_file:
        # Escreve o cabeçalho
        csv_file.write('Number,Average\n')

        # Escreve os dados
        for row in data:
            csv_file.write(f'{row[0]},{row[1]}\n')

# Exemplo de uso
tipos = [ "Bubble", "Insertion", "Merge", "Quick", "Selection"]
for tipo in tipos:
  for x in range(100, 200,100):
    txt_to_csv(f"{tipo}Sort{x}Nums.txt", x)

