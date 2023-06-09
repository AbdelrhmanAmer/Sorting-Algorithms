#include "mynamespace.h"

typedef int my_type;  //to change the data type of elements you only change the datatype here ,
                        // note that double do not work with count sort func and this is normal .

int main() {
    int size;
    cout <<"Enter Array Size: \n";
    cin >> size;

    my_type *arr = new my_type [size];
    arr=sortlib::fill<my_type>(size, 100);

    cout << "your arr elements before sorting: \n\n";
    sortlib::print(arr, size);
            char input;
        cout << "\n\nselect\n1 for insertionSort \n2 for selectionSort \n3 for bubbleSort \n4 for MergeSort\n5 for countSort\n6 for Shell sort\n7 for quick sort\n-->";
        cin >> input;
        switch (input) {
            case '1': {
                auto start = std::chrono::steady_clock::now(); // start measuring time
                sortlib::insertionSort(arr, size);
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

            case '5': {
                auto start = std::chrono::steady_clock::now();
                sortlib::countSort(arr, size);
                auto end = std::chrono::steady_clock::now();
                cout << "\n\nAfter sorting (countSort): \n \n";
                sortlib::print(arr, size);
                auto diff = end - start;
                cout << "\nRunning Time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms" << endl;
                break;
            }
            case '6':{
                 auto start = std::chrono::steady_clock::now();
                sortlib::shellSort(arr,size);
                auto end = std::chrono::steady_clock::now();
                cout << "\n\nAfter sorting (Shell sort): \n \n";
                sortlib::print(arr, size);
                auto diff = end - start;
                cout << "\nRunning Time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms" << endl;
                break;

            }
            case '7': {
                int l=0,h=size;
                auto start = std::chrono::steady_clock::now();
                sortlib::quickSort(arr,l,h);
                auto end = std::chrono::steady_clock::now();
                cout << "\n\nAfter sorting (quickSort): \n \n";
                sortlib::print(arr, size);
                auto diff = end - start;
                cout <<"\nRunning Time: " << std::chrono::duration<double, std::milli>(diff).count() << " ms"<< endl;
                break;
            }
            default:{
                cout <<"not in numbers range \n";
                break;
            }
            }
        }
