#include <stdio.h>

// Função para realizar a ordenação por inserção
void insertionSort(int arr[], int n, long long int *trocas, long long int *comparacoes)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Realiza comparações e trocas que envolvem elementos do vetor
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            (*trocas)++;
            (*comparacoes)++;
        }

        arr[j + 1] = key;
    }
}

// Função para realizar a ordenação por merge sort
void merge(int arr[], int left, int middle, int right, long long int *trocas, long long int *comparacoes)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Cria vetores temporários para a divisão
    int L[n1], R[n2];

    // Copia os dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    // Realiza a mesclagem dos vetores temporários de volta para arr[]
    while (i < n1 && j < n2)
    {
        // Realiza comparações e trocas que envolvem elementos do vetor
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        (*trocas)++;
        (*comparacoes)++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        (*trocas)++;
        (*comparacoes)++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        (*trocas)++;
        (*comparacoes)++;
    }
}

int main()
{
    int numero_de_vetores; // número de vetores
    scanf("%d", &numero_de_vetores);

    int vetor_de_tamanhos[Q]; // tamanho de cada vetor
    // for() para ler o tamanho de cada vetor separados por espaço
    for (int i = 0; i < numero_de_vetores; i++)
    {
        scanf("%d", &vetor_de_tamanhos[i]);
    }

    for (int i = 0; i < numero_de_vetores; i++)
    {
        int tamanho_do_vetor = vetor_de_tamanhos[i];
        int matrix_de_vetores[i][tamanho_do_vetor];
        int copia_da_matrix_para_insertion[i][tamanho_do_vetor];
        for (int j = 0; j < tamanho_do_vetor; j++)
        {
            scanf("%d", &matrix_de_vetores[i][j]);
            copia_da_matrix_para_insertion[i][j] = matrix_de_vetores[i][j];
        }
    }
    for (int i = 0; i < Q; i++)
    {
        long long int trocas_insertion = 0;
        long long int comparacoes_insertion = 0;
        long long int trocas_merge = 0;
        long long int comparacoes_merge = 0;

        // Ordena o vetor usando o método de inserção
        insertionSort(copia_da_matrix_para_insertion, tamanho_do_vetor, &trocas_insertion, &comparacoes_insertion);

        // Ordena o vetor usando o método de merge sort
        int copia_merge[N];
        for (int j = 0; j < N; j++)
        {
            copia_merge[j] = vetor[j];
        }
        int left = 0;
        int right = N - 1;

        void mergeSort(int copia_merge[], int left, int right, long long int *trocas, long long int *comparacoes)
        {
            if (left < right)
            {
                int middle = left + (right - left) / 2;
                mergeSort(copia_merge, left, middle, trocas, comparacoes);
                mergeSort(copia_merge, middle + 1, right, trocas, comparacoes);
                merge(copia_merge, left, middle, right, trocas, comparacoes);
            }
        }
        mergeSort(copia_merge, left, right, &trocas_merge, &comparacoes_merge);

        // Imprime os resultados
        printf("I %d %lld %lld\n", N, trocas_insertion, comparacoes_insertion);
        printf("M %d %lld %lld\n", N, trocas_merge, comparacoes_merge);
    }

    return 0;
}
