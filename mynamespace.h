//
// Created by Mohamed reyad on 16/03/2023.
//

#pragma once
#include <chrono>
#include <iostream>
using namespace std;

namespace sortlib {

    template<class T>
    void generateRandomArray(T* arr, int size) {
        srand(time(nullptr));
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;         // generates a random number between 0 and 99
        }
    }

    template<class T>
    void insertionSort(T *arr, int n) {
        for (int i = 1, j; i < n; ++i) {
            T temp = arr[i];
            for (j = i; j > 0 && temp < arr[j - 1]; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
    }
    template<class T>
    void selectionSort(T data[], int n) {
        for (int i = 0, least, j; i < n - 1; ++i) {
            least = i;
            for (j = i + 1; j < n; j++) {
                if (data[least] > data[j]) {
                    least = j;
                }
            }
            swap(data[least], data[i]);
        }
    }

    template<class T>
    void bubbleSort(T arr[], int n) {
        bool flag = true;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    flag = false;
                    swap(arr[j + 1], arr[j]);
                }
            }
            if (flag) {
                break;
            }
        }
    }

    template <class T>
    void merge(T arr[], int start, int mid, int end) {
        int left = start, right = mid+1, k = 0;
        T temp[end-start+1];

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];
            } else {
                temp[k++] = arr[right++];
            }
        }
        while (left <= mid) {
            temp[k++] = arr[left++];
        }
        while (right <= end) {
            temp[k++] = arr[right++];
        }
        for (int i = start; i <= end; i++) {
            arr[i] = temp[i-start];
        }
    }

    template <typename T>
    void mergeSort(T arr[], int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }

    template<class T>
    void print(T arr[], int n) {
        int c = 0;
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
            c++;
        }
        cout << "\n";
        cout << "number of elements = " << c << "\n";
    }

}