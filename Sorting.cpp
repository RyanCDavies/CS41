#include <iostream>

class BubbleSorting{
    public:
        void BubbleSort(int* arr, int size){
            for (int i = 0; i < size; i++){
                bool swapped = false;
                for (int j = 0; j < (size-1); j++){
                    if (arr[j] > arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                        swapped = true;
                    }
                }
                if (!swapped){
                    return;
                }
            }
        }
};

int main(){
    BubbleSorting spunchbob;
    int* arr = {20, 11, 5, 3, 10};

    spunchbob.BubbleSort(arr, 5);

    std::cout << arr[5];


    return 0;
}