#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() 
{
    // Initialize the vector with 100,000 integers in descending order
    vector<int> numbers(10000);
    for (int i = 0; i < 10000; ++i)
        numbers[i] = 10000 - i;

    auto startTime = chrono::high_resolution_clock::now();

    bubbleSort(numbers);

    auto endTime = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
    cout << "Bubble Sort Execution Time: " << duration.count() << " microseconds\n";

    cout << "First 10 integers: ";
    for (int i = 0; i < 10; ++i)
        cout << numbers[i] << " ";

    cout << "\nLast 10 integers: ";
    for (int i = 9990; i < 10000; ++i)
        cout << numbers[i] << " ";

    return 0;
}
