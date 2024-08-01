#!/bin/bash

if [ ! -d "./results" ]; then
    mkdir ./results
fi

# Loop para criar 10 arquivos CSV diferentes
for version in {1..10}; do
    # Nome do arquivo de saída com versão
    csv_file="./results/results-PC1-V${version}-1000rows.csv"

    # Cabeçalho do CSV
    echo "Threads,Execution Time" > $csv_file

    # Loop sobre o número de threads
    for threads in {1..16}; do
        output=$(OMP_NUM_THREADS=$threads ./src/5.1-matrix-mult-parallel.exec 1000)

        # Escrever no arquivo CSV
        echo "$threads,\"$output\"" >> $csv_file
    done
done
