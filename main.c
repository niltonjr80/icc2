#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SELECTION(int *arr, int arr_length)
{

    // minimum_element é o ponteiro com menor valor daquela interação
    // current_element é o ponteiro do primeiro item do array na esquerda naquela interação
    // compare_element é o ponteiro referente aos elementos que estão sendo coparados com o current element

    int *minimum_element = NULL, *current_element = NULL, *compare_element = NULL;

    for (current_element = arr; current_element < arr + arr_length - 1; current_element++)
    {
        minimum_element = current_element;

        for (compare_element = current_element + 1; compare_element < arr + arr_length; compare_element++)
        {
            printf("C %d %d\n", minimum_element - arr, compare_element - arr);

            if (*compare_element < *minimum_element)
            {
                minimum_element = compare_element;
            }
        }
        if (minimum_element != current_element)
        {
            swap(minimum_element, current_element);
            printf("T %d %d\n", current_element - arr, minimum_element - arr);
        }
    }

    int *ptr = NULL;
    for (ptr = arr; ptr < arr + arr_length; ptr++)
    {
        printf("%d ", *ptr);
    }
    printf("\n");
};

void BUBBLE(int *arr, int arr_length)
{

    // referencia é o ponteiro do valor de referência, que vai ser comparado com  o próximo
    // compare é o próximo
    // atual é o ponteiro do último valor com quem a comparação vai ser feita, depois dele está organizado

    int *atual = NULL, *referencia = NULL, *compare = NULL;
    bool trocou; // variável sentinela que indica se houve troca na iteração

    for (atual = arr + arr_length - 1; atual > arr; atual--)
    {
        trocou = false; // inicializa a variável sentinela como falsa
        for (referencia = arr; referencia < atual; referencia++)
        {
            compare = referencia + 1;
            printf("C %d %d\n", referencia - arr, compare - arr);

            if (*referencia > *compare)
            {
                swap(referencia, compare);
                printf("T %d %d\n", referencia - arr, compare - arr);
                trocou = true; // atribui o valor verdadeiro à variável sentinela
            }
        }
        // Se a variável sentinela é falsa, significa que o array já está ordenado e pode parar o laço
        if (!trocou)
        {
            break;
        }
    }

    int *ptr = NULL;
    for (ptr = arr; ptr < arr + arr_length; ptr++)
    {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main()
{
    int arr_length;
    char option[20];

    scanf("%20s", option);

    scanf("%d", &arr_length);
    int arr[arr_length];

    for (int i = 0; i < arr_length; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (strcmp("selecao", option) == 0)
    {
        SELECTION(arr, arr_length);
    }
    else
    {
        BUBBLE(arr, arr_length);
    }

    return 0;
}