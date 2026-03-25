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
    // TODO
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
            }
        }
    }
}
void mergeInsertionSort(int arr[], int l, int r)
{
    // TODO
}
void merge(int arr[], int l, int m, int r)
{
    // TODO
}
void mergeSort(int arr[], int l, int r)
{
    // TODO
}
int partition(int *vals, int low, int high)
{
    // TODO
}
void quickSort(int *numbers, int low, int high)
{
    // TODO
}
