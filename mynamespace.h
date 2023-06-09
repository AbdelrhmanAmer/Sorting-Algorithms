//
// Created by Mohamed reyad on 16/03/2023.
//

#pragma once
#include <chrono>
#include <iostream>
#include <random>
using namespace std;

namespace sortlib {

    template<class T>
    T* fill(long long size, long long upperLimit){
        T* array = new T[size];
        for (int i = 0; i < size; ++i) {
            long double random_double = 65 + ( long double)rand() / (( long double)RAND_MAX / (122 - 65));
            array[i] = random_double ;
        }
        return array;
    }

    template<class T>
    void insertionSort(T *arr, int n) {
        for (int i = 1, j; i < n; ++i) {
            T temp = arr[i];
            for (j = i; j > 0 && temp < arr[j - 1]; j--) {     // check if the current value is greater than the value before
                arr[j] = arr[j - 1];                         // if the value before is bigger than the current value then shift your array
            }
            arr[j] = temp;                // assign the variable temp what ever its value to the arr[j] which could be shifted or not .. based on the condition above
        }
    }
    template<class T>
    void selectionSort(T data[], int n) {
        for (int i = 0, least, j; i < n - 1; ++i) {
            least = i;    // assign the index of i to be the least
            for (j = i + 1; j < n; j++) {
                if (data[least] > data[j]) {      // if the value of index least is greater than an element then swap them
                    least = j;                   // exchange the indexes if arr[j] is less than the least
                }
            }
            swap(data[least], data[i]);         //then swap them
        }
    }

    template<class T>
    void bubbleSort(T arr[], int n) {
        bool flag = true;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {     // n-i-1 to decrease the number of rounds as it sorted automatically from the last
                if (arr[j] > arr[j + 1]) {
                    flag = false;                     // check if array is already sorted or not to break the not needed loops
                    swap(arr[j + 1], arr[j]);         // swap the two elements
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
    template <class T>
    void countSort(T arr[], int n)
    {
        // 1 - create frequency array
        T max = *max_element(arr, arr + n);
        T freq[max + 1] ={0};
        int freq_size = sizeof(freq) / sizeof(freq[0]);

        for (int i = 0; i < n; i++)
            freq[arr[i]]++;

        //  2) Add Each number to right of it accumulatively
        for (int i = 1; i < freq_size; i++)
            freq[i] += freq[i - 1];

        // 3- We place the objects in their correct
        // position and decrease the count by one.
        T arr2[n];
        for (int i = 0; i < n; i++)
        {
            arr2[(freq[arr[i]]) - 1] = arr[i];
            freq[arr[i]]--;
        }

        memcpy(arr, arr2, sizeof(arr2));
    }
    template<class T>
void shellSort(T arr[], int n) {
    // Start with a large gap and reduce it
    for (int gap = n/2; gap > 0; gap /= 2) {
                                                // The first gap elements a[0..gap-1] are already in gapped order
                                                // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1){
                                                // add a[i] to the elements that have been gap sorted
            T temp = arr[i];
                                            // shift earlier gap-sorted elements up until the correct location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
                                            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}
    template<class T>
    int partioning(T arr[],int l,int h){
        int pav=arr[l];
        int i=l;
        int j=h;
        while (i<j){
            do {
                i++;
            } while (arr[i]<=pav);
            do {
                j--;
            } while (arr[j]>pav);
            if(i<j){
                swap(arr[i],arr[j]);
            }}
        swap(arr[l],arr[j]);
        return j;
    }
    template<class T>
    void quickSort(T arr[],int l,int h){
        if (l<h) {
            int pav = partioning(arr, l, h);
            quickSort(arr,l,pav);
            quickSort(arr,pav+1,h);
        }
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
