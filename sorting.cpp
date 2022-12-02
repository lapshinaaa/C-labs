#include <iostream>
#include <chrono>


template <typename T>
void bubbleSort(T *arr, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray - 1; i++)   // iterating over each element except for the last one
    {
        for (int j = 0; j < sizeOfArray - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template <typename T>
void selectionSort(T *arr, int sizeOfArray)
{
    int minimum_value;

    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        minimum_value = i;

        for (int j = i + 1; j < sizeOfArray; j++)  // comparing our minimum element to all the other array elements
        {
            if (arr[j] < arr[minimum_value])
            {
                minimum_value = j;
            }
        }

        if (minimum_value != i)  // checking if the minimum value is not the smallest anymore
        {
            int temp = arr[i];  // creating a temporary value to swap elements
            arr[i] = arr[minimum_value];
            arr[minimum_value] = temp;
        }
    }

    using namespace std::chrono_literals;
}


template <typename T>
void insertionSort(T *arr, int sizeOfArray)
{
    int newElement;
    int indexOfElem;

    for (int i = 1; i < sizeOfArray; i++)
    {
        newElement = arr[i];
        indexOfElem = i - 1;   // index of the previous element

        while (indexOfElem >= 0 && arr[indexOfElem] > newElement) // swapping until elements are sorted
        {
            arr[indexOfElem + 1] = arr[indexOfElem];
            indexOfElem = indexOfElem - 1;
        }
        arr[indexOfElem + 1] = newElement;
    }
}



int main()
{
    int arr[100000];
//
//    for (int i = 0; i < 100000; i++)   // generating arrays of random integers
//    {
//        arr[i] = rand()%10000;
//    }

    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);

    // measuring runtime of each of the selected functions
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();  // starting the clock

    //bubbleSort(arr, sizeOfArray);
    //selectionSort(arr, sizeOfArray);    // performing one of the functions here
    insertionSort(arr, sizeOfArray);

    auto t2 = high_resolution_clock::now();  // stopping the clock

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";

    for (int element: arr)  // iterating over the sorted erray to print out the final result
    {
        std::cout<<element<<" ";
    }

    return 0;
}