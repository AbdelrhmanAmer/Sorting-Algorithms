#include "mynamespace.h"

int main() {
    int size;
    cout <<"Enter Array Size: \n";
    cin >> size;
    int *arr =new int[size];
    sortlib::generateRandomArray(arr, size);
    cout << "your arr elements before sorting: \n\n";
    sortlib::print(arr, size);
            char input;
        cout << "\n\nselect\n1 for insertionSort \n2 for selectionSort \n3 for bubbleSort \n4 for MergeSort\n";
        cin >> input;
        switch (input) {
            case '1': {
                auto start = std::chrono::steady_clock::now(); // start measuring time
                sortlib::insertionSort<int>(arr, size);
                auto end = std::chrono::steady_clock::now(); // stop measuring time
                cout << "\n\nAfter sorting (insertionSort): \n \n";
                sortlib::print(arr, size);
                auto diff = end - start;
                cout <<"\nRunning Time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms"<< endl;
                break;
            }

            case '2': {
                auto start = std::chrono::steady_clock::now();
                sortlib::selectionSort(arr, size);
                auto end = std::chrono::steady_clock::now();
                cout << "\n\nAfter sorting (selectionSort): \n \n";
                sortlib::print(arr, size);
                auto diff = end - start;
                cout << "\nRunning Time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms"<< endl;
                break;
            }

            case '3': {
                auto start = std::chrono::steady_clock::now();
                sortlib::bubbleSort(arr, size);
                auto end = std::chrono::steady_clock::now();
                cout << "\n\nAfter sorting (bubbleSort): \n \n";
                sortlib::print(arr, size);
                auto diff = end - start;
                cout << "\nRunning Time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms" << endl;
                break;
            }

            case '4': {
                auto start = std::chrono::steady_clock::now();
                sortlib::mergeSort(arr,0,size-1);
                auto end = std::chrono::steady_clock::now();
                cout << "\n\nAfter sorting (MergeSort): \n \n";
                sortlib::print(arr, size);
                auto diff = end - start;
                cout << "\nRunning Time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms" << endl;
                break;
            }

            default:{
                cout <<"not in numbers range \n";
                break;
            }
            }
        }