#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SELECTION(int *arr, int arr_length)
{

    // minimum_element � o ponteiro com menor valor daquela intera��o
    // current_element � o ponteiro do primeiro item do array na esquerda naquela intera��o
    // compare_element � o ponteiro referente aos elementos que est�o sendo coparados com o current element

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
};

void BUBBLE(int *arr, int arr_length)
{
    int *current_element, *compare_element;
    int last_swap_index;

    last_swap_index = arr_length - 1;

    for (current_element = arr; current_element < arr + arr_length - 1; current_element++)
    {
        int current_last_swap_index = -1;

        for (compare_element = arr; compare_element < arr + last_swap_index; compare_element++)
        {
            printf("C %d %d\n", (compare_element - arr), (compare_element - arr + 1));
            if (*compare_element > *(compare_element + 1))
            {
                swap(compare_element, compare_element + 1);
                printf("T %d %d\n", (compare_element - arr), (compare_element - arr + 1));
                current_last_swap_index = compare_element - arr;
            }
        }

        last_swap_index = current_last_swap_index;
    }
}

int main()
{
    int arr_length;
    char option[20];

    scanf("%s", option);

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

    int *ptr = NULL;
    for (ptr = arr; ptr < arr + arr_length; ptr++)
    {
        printf("%d ", *ptr);
    }
    printf("\n");

    return 0;
}
