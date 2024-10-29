#include <iostream>

class DynamicArray{
private:
    //variables
    int size = 0;
    int index = 0;
    int* arr;

public:
    //adds a new value at the end of the array
    void insert(int num){
        //check if array is full
        if (index == size){
            //make new array with bigger size
            int* newArr = new int[size + 1];
            for (int i; i < size; i++){
                newArr[i] = arr[i];
            }
            //replace the old array with the new one
            size++;
            delete [] arr;
            arr = newArr;
        }
        //append new value to end of array
        arr[index] = num;
        index++;
    }
    //print the array to console
    void print(){
        for (int i = 0; i < index; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    //constructor initializes array with user defined size
    DynamicArray(int size){
        arr = new int[size];
        this->size = size;
    }
};

int main(){
    //get user size choice
    int choice;
    std::cout << "What size should the array be? ";
    std::cin >> choice;
    std::cout << std::endl;

    //initialize array object using user size
    DynamicArray myArray(choice);
    while (choice != -1){

        //ask for number to append to array
        std::cout << "Enter number to add to array: ";
        std::cin >> choice;
        std::cout << std::endl;

        //insert user choice into array
        if (choice != -1){
            myArray.insert(choice);
        }
    }
    //print array
    myArray.print();

    return 0;
}