#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para ordenação por inserção
void insertionSort(int arr[], int n, long long int *trocas, long long int *comparacoes) {
    // Implementação do insertion sort aqui
}

// Função para ordenação por merge sort
void merge(int arr[], int left, int middle, int right, long long int *trocas, long long int *comparacoes) {
    // Implementação do merge sort aqui
}

int main() {
    // Diretório onde estão os arquivos de entrada
    const char *diretorio = "caminho/para/a/pasta/";

    // Itera pelos arquivos .in na pasta
    for (int i = 1; i <= 11; i++) {
        char arquivo_entrada[256];
        sprintf(arquivo_entrada, "%sinput%d.in", diretorio, i);

        // Abre o arquivo de entrada
        FILE *arquivo = fopen(arquivo_entrada, "r");
        if (arquivo == NULL) {
            fprintf(stderr, "Não foi possível abrir o arquivo %s\n", arquivo_entrada);
            continue;
        }

        // Leitura dos dados do arquivo de entrada
        int Q;
        fscanf(arquivo, "%d", &Q);

        for (int q = 0; q < Q; q++) {
            int N;
            fscanf(arquivo, "%d", &N);

            int vetor[N];
            long long int trocas_insertion = 0;
            long long int comparacoes_insertion = 0;
            long long int trocas_merge = 0;
            long long int comparacoes_merge = 0;

            for (int j = 0; j < N; j++) {
                fscanf(arquivo, "%d", &vetor[j]);
            }

            // Ordenação por inserção
            int copia_insertion[N];
            for (int j = 0; j < N; j++) {
                copia_insertion[j] = vetor[j];
            }
            insertionSort(copia_insertion, N, &trocas_insertion, &comparacoes_insertion);

            // Ordenação por merge sort
            int copia_merge[N];
            for (int j = 0; j < N; j++) {
                copia_merge[j] = vetor[j];
            }
            int left = 0;
            int right = N - 1;

            // Chamada à função de ordenação por merge sort aqui

            // Impressão dos resultados para o arquivo de saída
            char arquivo_saida[256];
            sprintf(arquivo_saida, "%soutput%d.out", diretorio, i);

            FILE *saida = fopen(arquivo_saida, "w");
            if (saida == NULL) {
                fprintf(stderr, "Não foi possível criar o arquivo de saída %s\n", arquivo_saida);
                fclose(arquivo);
                continue;
            }

            fprintf(saida, "I %d %lld %lld\n", N, trocas_insertion, comparacoes_insertion);
            fprintf(saida, "M %d %lld %lld\n", N, trocas_merge, comparacoes_merge);

            fclose(saida);
        }

        fclose(arquivo);
    }

    return 0;
}
