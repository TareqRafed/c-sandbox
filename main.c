#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "funcs.h"

/**
 * @brief to compile app make funcs.c is included with gcc
 *
 * you can run in it via these two commands on a linux machine
 *  gcc -o main main.c funcs.c
 *  ./main
 *
 * @return int
 */
int main()
{
    int arr_size = 500000;
    int max_rand_val = 10000;
    int arr[arr_size];

    FillArrayRandom(arr, arr_size, max_rand_val);

    pid_t childA = fork();
    pid_t childB;
    pid_t childC;

    if (childA == 0)
    {
        childB = fork();
        if (childB == 0)
        {
            childC = fork();
            if (childC == 0)
            {
                // c instance
                printf("process c -> \n median value: %d \n", FindMedian(arr, arr_size));
            }
            else
            {
                // b instance
                printf("process b -> \n  max value: %d \n", FindMax(arr, arr_size));
            }
        }
        else
        {
            // a instance
            printf("process a -> \n min value: %d \n", FindMin(arr, arr_size));
        }
    }
    else
    {
        // main func
        printf("main -> \n avg value: %.2f \n", FindAvg(arr, arr_size));
    }

    return 0;
}