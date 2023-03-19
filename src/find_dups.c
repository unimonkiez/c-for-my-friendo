#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *arr, size_t size)
{
    int i, j, k;
    int s1 = size / 2;
    int s2 = size - s1;

    /* It will create two temporary arrays */
    int *left_arr = (int *)malloc(s1 * sizeof(int));
    int *right_arr = (int *)malloc(s2 * sizeof(int));

    /* It will copy data from arr to temporary arrays */
    for (i = 0; i < s1; i++)
        left_arr[i] = arr[i];

    for (j = 0; j < s2; j++)
        right_arr[j] = arr[s1 + j];

    i = 0, j = 0;
    k = 0;
    while (i < s1 && j < s2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    /* Copying the items of left_arr[] that have been left */
    while (i < s1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    /* Copying the items of right_arr[] that have been left */
    while (j < s2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    free(left_arr);
    free(right_arr);
}

void print_dups(int const *nums, const size_t size)
{
    size_t i = 0;

    int *nums_sorted = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        nums_sorted[i] = nums[i];
    }
    MergeSort(nums_sorted, size);

    printf("The dups are:\n");
    for (i = 1; i < size; i++)
    {
        if (nums_sorted[i] == nums_sorted[i - 1])
        {

            printf("%d\n", nums_sorted[i]);
        }
    }

    free(nums_sorted);
}

int main()
{
    int nums[] = {1, 24, 3, 3, 5, 7, 8, 10, 10, 2};

    print_dups(nums, sizeof(nums) / sizeof(int));

    return 0;
}
