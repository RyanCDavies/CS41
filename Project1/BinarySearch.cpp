#include <iostream>

int BinarySearch(int Array[], int Length, int value) {
    int upper = Length - 1;
    int lower = 0;
    int middle = 0;
    while (upper >= lower) {
        middle = lower + ((upper - lower) / 2);
        //if middle value is equal to selected value, return index of that value
        if (Array[middle] == value) {
            return middle;
        }
        //if middle value is less than selected value, middle becomes new lower value
        else if (Array[middle] < value) {
            lower = middle + 1;
        }
        //if middle value is greater than searched value, middle becomes new upper value
        else {
            upper = middle - 1;
        }
    }
    //return -1 if no valid index with that value
    return -1;
}

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int value = 0;
    std::cout << "input value to search for: ";
    std::cin >> value;

    std::cout << "index is " << BinarySearch(arr, 10, value);

    return 0;
}