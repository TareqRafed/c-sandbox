#include <stdio.h>
#include "funcs.h"

int main()
{
    int arr_size = 500000;
    int max_rand_val = 10000;
    int arr[arr_size];

    FillArrayRandom(arr, arr_size, max_rand_val);

    int minMax[2];
    FindMinMax(minMax, arr, arr_size);

    printf("\n min value: %d, max value: %d \n", minMax[0], minMax[1]);
    printf("\n median value: %d \n", FindMedian(arr, arr_size));

    return 0;
}