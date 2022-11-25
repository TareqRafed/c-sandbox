#include "funcs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void FillArrayRandom(void *arr, int arr_size, int max_rand_val)
{
    srand(time(NULL)); // change seed according to time
    for (int i = 0; i < arr_size; i++)
    {
        ((int *)arr)[i] = 1 + (rand() % max_rand_val);
    }
}

int *FindMinMax(void *buff, void *arr, int arr_size)
{
    int output[] = {((int *)arr)[0], ((int *)arr)[0]};

    for (int i = 0; i < arr_size; i++)
    {
        if (((int *)arr)[i] < output[0])
            output[0] = ((int *)arr)[i];

        if (((int *)arr)[i] > output[1])
            output[1] = ((int *)arr)[i];
    }

    ((int *)buff)[0] = output[0]; // min
    ((int *)buff)[1] = output[1]; // max

    return ((int *)buff);
}

int FindMedian(void *arr, int arr_size)
{
    int sortedArr[arr_size]; // clone array so sorting doesn't affect the original array
    memcpy(sortedArr, arr, (arr_size * sizeof(int)));
    MergeSort(sortedArr, arr_size);

    return sortedArr[arr_size / 2];
}

// Utility for Merge sort

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
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
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// DRIVER
// typecasts to allow modifications for sorting later
void MergeSort(void *arr, int arr_size)
{
    mergeSort(arr, 0, arr_size - 1);
}