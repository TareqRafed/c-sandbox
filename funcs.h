#ifndef FUNCS
#define FUNCS

/**
 * @brief fills array with random values between 0 and max_rand_val
 *
 * @param arr
 * @param arr_size
 * @param max_rand_val
 */
void FillArrayRandom(void *arr, int arr_size, int max_rand_val);

/**
 * @brief returns two elements [int min, int max]
 *
 * @param buff
 * @param arr
 * @param arr_size
 * @return int*
 */
int *FindMinMax(void *buff, void *arr, int arr_size);

/**
 * @brief returns median of array
 *
 * @param arr
 * @param arr_size
 * @return int
 */
int FindMedian(void *arr, int arr_size);

/**
 * @brief return average of array
 *
 * @param arr
 * @param arr_size
 * @return int
 */
int FindAvg(void *arr, int arr_size);

/**
 * @brief modify array to be sorted
 *
 * @param arr
 * @param arr_size
 * @return void
 */
void MergeSort(void *arr, int arr_size);

#endif