#include <stdio.h>

// Função para realizar a ordenação por inserção
void insertionSort(int arr[], int n, long long int *trocas, long long int *comparacoes) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Realiza comparações e trocas envolvendo elementos do vetor
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*trocas)++;
            (*comparacoes)++;
        }
    }
}

// Função para realizar a ordenação por merge sort
void merge(int arr[], int left, int middle, int right, long long int *trocas, long long int *comparacoes) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Cria vetores temporários para a divisão
    int L[n1], R[n2];

    // Copia os dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    // Realiza a mesclagem dos vetores temporários de volta para arr[]
    while (i < n1 && j < n2) {
        // Realiza comparações e trocas envolvendo elementos do vetor
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*trocas)++;
        (*comparacoes)++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*trocas)++;
        (*comparacoes)++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*trocas)++;
        (*comparacoes)++;
    }
}

int main() {
    int Q;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int N;
        scanf("%d", &N);

        int vetor[N];
        long long int trocas_insertion = 0;
        long long int comparacoes_insertion = 0;
        long long int trocas_merge = 0;
        long long int comparacoes_merge = 0;

        // Leitura dos valores do vetor e ordenação usando os métodos especificados
        for (int i = 0; i < N; i++) {
            scanf("%d", &vetor[i]);
        }

        // Ordenação por inserção
        int copia_insertion[N];
        for (int i = 0; i < N; i++) {
            copia_insertion[i] = vetor[i];
        }
        insertionSort(copia_insertion, N, &trocas_insertion, &comparacoes_insertion);

        // Ordenação por merge sort
        int copia_merge[N];
        for (int i = 0; i < N; i++) {
            copia_merge[i] = vetor[i];
        }
        int left = 0;
        int right = N - 1;

        void mergeSort(int copia_merge[], int left, int right, long long int *trocas, long long int *comparacoes) {
            if (left < right) {
                int middle = left + (right - left) / 2;
                mergeSort(copia_merge, left, middle, trocas, comparacoes);
                mergeSort(copia_merge, middle + 1, right, trocas, comparacoes);
                merge(copia_merge, left, middle, right, trocas, comparacoes);
            }
        }
        mergeSort(copia_merge, left, right, &trocas_merge, &comparacoes_merge);

        // Imprime os resultados após ordenação de cada vetor
        printf("I %d %lld %lld\n", N, trocas_insertion, comparacoes_insertion);
        printf("M %d %lld %lld\n", N, trocas_merge, comparacoes_merge);
    }

    return 0;
}
