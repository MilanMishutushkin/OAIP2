#include <stdio.h>
#include <iostream>
#include "functions.h"
void runMenu()
{
    std::cout << "\nWelcome, choose how would you like to sort array";
    std::cout << "\n1.Bubble sort";
    std::cout << "\n2.Min sort";
    std::cout << "\n3.Insert sort";
    std::cout << "\n4.Shell sort";
    std::cout << "\n5.Hoare sort";
    std::cout << "\n6.Bogosort";
    std::cout << "\n7.Search";
    std::cout << "\nYour choice: ";

}
void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void minSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int k = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[k]) {
                k = j;
            }
        }
        if (k != i) {
            std::swap(array[i], array[k]);
        }
    }
}

void insertSort(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            std::swap(array[j], array[j - 1]);
            j--;
        }
    }
}

void shellSort(int* array, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void hoareSort(int* array, int l, int r) {
    if (l >= r) return;
    int mid = array[(l + r) / 2];
    int i = l, j = r;
    do {
        while (array[i] < mid) i++;
        while (array[j] > mid) j--;
        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) hoareSort(array, l, j);
    if (i < r) hoareSort(array, i, r);
}
bool correct(int* array, int size) {
    while (--size > 0)
        if (array[size - 1] > array[size])
            return false;
    return true;
}
void shuffle(int* array, int size) {
    for (int i = 0; i < size; ++i)
        std::swap(array[i], array[(rand() % size)]);
}


void bogoSort(int* array, int size)
{
    while (!correct(array, size))
        shuffle(array, size);
}



void binarySearch(int* array, int size) {
    shellSort(array, size);
    int search;
    std::cout << "\nInput element: ";
    std::cin >> search;

    int leftBorder = 0, rightBorder = size - 1;
    bool flag = false;

    while (leftBorder <= rightBorder) {
        int mid = leftBorder + (rightBorder - leftBorder) / 2;

        if (array[mid] == search) {
            flag = true;
            std::cout << " \n==========================";
            std::cout << "\n Element has been found.";
            std::cout << " \n==========================\n";
            break;
        }
        else if (array[mid] < search) {
            leftBorder = mid + 1;
        }
        else {
            rightBorder = mid - 1;
        }
    }

    if (!flag) {
        std::cout << " \n==========================";
        std::cout << "\n Element hasn't been found.";
        std::cout << " \n==========================\n";
    }
}

void orderSearch(int* array, int size)
{
    int search;
    int index;
    bool flag = false;
    std::cout << "\nInput element: ";
    std::cin >> search;
    for (int i = 0; i < size; i++)
    {
        if (search == array[i])
        {
            flag = true;
            index = i;
            i = size;
        }
    }
    if (flag)
    {
        std::cout << " \n==========================";
        std::cout << "\n Element has been founded.";
        std::cout << "\n Index: "<<index;
        std::cout << " \n==========================\n";
    }
    else
    {
        std::cout << " \n=============================";
        std::cout << "\n Element hasn't been founded.";
        std::cout << " \n=============================\n";
    }
}

