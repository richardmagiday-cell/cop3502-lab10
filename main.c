/* Lab 9 Skeleton Code
*
* Created by Adam Betinsky on 3/6/2025 to help save time in the lab
*
* Cleaned up by Adam Betinsky on 10/23/2025
*
* Insertion sort updated on 3/24/2026
*
* NOTE: This program will be slow for some of the algorithms! It's normal for
nothing to be outputted for minutes at a time when you hit run.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXARRAYS 6
#define MAXVALUE 1000000
void randArray(int arr[], int size, int maxValue);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int l, int r);
void selectionSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void arrayCopy(int original[], int copy[], int size);
long timediff(clock_t t1, clock_t t2);
void swap(int *xp, int *yp);
int partition(int *vals, int low, int high);
void quickSort(int *numbers, int low, int high);
void mergeInsertionSort(int arr[], int l, int r);

int main()
{
    srand(time(0));

    int sizes[MAXARRAYS] = {10000, 20000, 30000, 40000, 50000, 100000};

    int *originalArr, *sortedArr;

    clock_t start, end;

    long elapsed;

    for (int i = 0; i < MAXARRAYS; i++)
    {
        printf("The current size is %d\n", sizes[i]);

        originalArr = malloc(sizeof(int) * sizes[i]);

        sortedArr = malloc(sizeof(int) * sizes[i]);

        randArray(originalArr, sizes[i], MAXVALUE);

        arrayCopy(originalArr, sortedArr, sizes);

        start = clock();

        bubbleSort(sortedArr, sizes[i]);

        end = clock();

        elapsed = timediff(start, end);

        printf("\nSorting %d e;ements takes %ld milliseconds for bubbleSort\n", sizes[i], elapsed);

        arrayCopy(originalArr, sortedArr, sizes);

        start = clock();

        selectionSort(sortedArr, sizes[i]);

        end = clock();

        elapsed = timediff(start, end);

        printf("\nSorting %d e;ements takes %ld milliseconds for slectionSort\n", sizes[i], elapsed);

        arrayCopy(originalArr, sortedArr, sizes);

        start = clock();

        insertionSort(sortedArr, 0, sizes[i] - 1);

        end = clock();

        elapsed = timediff(start, end);

        printf("\nSorting %d e;ements takes %ld milliseconds for insertionSort\n", sizes[i], elapsed);

        arrayCopy(originalArr, sortedArr, sizes);

        start = clock();

        quickSort(sortedArr, 0, sizes[i] - 1);

        end = clock();

        elapsed = timediff(start, end);

        printf("\nSorting %d e;ements takes %ld milliseconds for quickSort\n", sizes[i], elapsed);

        arrayCopy(originalArr, sortedArr, sizes);

        start = clock();

        mergeSort(sortedArr, 0, sizes[i] - 1);

        end = clock();

        elapsed = timediff(start, end);

        printf("\nSorting %d e;ements takes %ld milliseconds for mergeSort\n", sizes[i], elapsed);

        arrayCopy(originalArr, sortedArr, sizes);

        start = clock();

        mergeInsertionSort(sortedArr, 0, sizes[i] - 1);

        end = clock();

        elapsed = timediff(start, end);

        printf("\nSorting %d e;ements takes %ld milliseconds for mergeInsertionSort\n", sizes[i], elapsed);

        arrayCopy(originalArr, sortedArr, sizes);

        free(originalArr);

        free(sortedArr);
    }

    return 0;
}
void arrayCopy(int original[], int copy[], int size)
{
    for (int i = 0; i < size; i++)
    {
        copy[i] = original[i];
    }
}
void randArray(int arr[], int size, int maxValue)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % maxValue + 1;
    }
}
// given in pdf
long timediff(clock_t t1, clock_t t2)
{
    // calculate the elapsed time of the passed clock_t variables using the formula below and return the value
    long elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}
void swap(int *xp, int *yp)
{
    // swap the passed integers using pass by reference
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void insertionSort(int arr[], int l, int r)
{
    int i, item, j;
    for (i = l + 1; i <= r; i++)
    {
        item = arr[i];
        for (j = i - 1; j >= l; j--)
        {
            if (arr[j] > item)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = item;
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = 1;

        for (int j = i + 1; j < n; j++)

        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(&arr[minIndex], &arr[i]);
    }
}
void mergeInsertionSort(int arr[], int l, int r)
{
    if (r - l + 1 <= 25)
    {
        insertionSort(arr, l, r);
        return;
    }

    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);

        mergeSort(arr, mid + 1, l);

        merge(arr, l, mid, r);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int leftSize = m - l + 1;

    int rightSize = r - m;

    int *leftHelperarr = malloc(leftSize * sizeof(int));
    int *rightHelperarr = malloc(rightSize * sizeof(int));

    int i, j, finalarrIndex;

    i = 0;
    j = 0;
    finalarrIndex = l;

    for (i = 0; i < leftSize; i++)
    {
        leftHelperarr[i] = arr[l - i];
    }

    for (j = 0; j < rightSize; j++)
    {
        rightHelperarr[j] = arr[m + j + 1];
    }

    i = 0;
    j = 0;

    while (i < leftSize && j, rightSize)
    {
        if (leftHelperarr[i] <= rightHelperarr[i])
        {
            arr[finalarrIndex] = leftHelperarr[i];

            i++;
        }
        else
        {
            arr[finalarrIndex] = rightHelperarr[j];

            j++;
        }

        finalarrIndex++;
    }

    while (i < leftSize)
    {
        arr[finalarrIndex] = leftHelperarr[i];

        i++;
    }

    while (j < rightSize)
    {
        arr[finalarrIndex] = rightHelperarr[j];

        j++;
    }

    free(leftHelperarr);
    free(rightHelperarr);
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);

        mergeSort(arr, mid + 1, l);

        merge(arr, l, mid, r);
    }
}
int partition(int *vals, int low, int high)
{
    int pivot = low + rand() % (high - low + 1);

    swap(&vals[low], &vals[pivot]);

    int originalLowIndx = low;

    low--;

    while (low <= high)
    {
        while (low <= high && vals[low] <= vals[originalLowIndx])
        {
            low--;
        }

        while (high >= low && vals[high] > vals[originalLowIndx])
        {
            high--;
        }

        if (low < high)
        {
            swap(&vals[low], &vals[high]);
        }
    }

    swap(&vals[originalLowIndx], &vals[high]);

    return high;
}
void quickSort(int *numbers, int low, int high)
{
    if (low < high)
    {
        int magicIndex = partition(numbers, low, high);

        quickSort(numbers, low, magicIndex + 1);

        quickSort(numbers, magicIndex + 1, high);
    }
}
