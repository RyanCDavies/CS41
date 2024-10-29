#include <iostream>

class ArrayBasedQueue{
    public:
    const int maxSize = 10;

    int holds10[10];
    int count = 0;
    int front = 0;
    int back = 0;

    //enqueue value at back of queue
    void enqueue(int n){
        if (count < maxSize){
            holds10[back] = n;
            //checking to see if back has reached the end
            if (back >= maxSize){
                back = 0;
            }
            else{
                back++;
            }
            count++;
        }
        //output error to console if full
        else{
            std::cout << "Queue is full" << std::endl;
        }
    }

    //dequeue value at front of queue
    int dequeue(){
        if (count != 0){
            int temp = holds10[front];
            //checking to see if front has reached the end
            if (front >= maxSize){
                front = 0;
            }
            else{
                front++;
            }
            count--;
            return temp;
        }
        //dont return and output error to console
        else{
            std::cout << "Nothing in queue" << std::endl;
            return -1;
        }        
    }

    //check if queue is empty via count
    bool isEmpty(){
        if (count == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    char yn = 'y';
    int in = 0;
    std::cout << std::boolalpha;
    ArrayBasedQueue myQueue;
        while (yn == 'y'){
            //check if want to enqueue
            std::cout << "enqueue? (y/n) \n";
            std::cin >> yn;
            if (yn == 'y'){
                std::cout << "type int to enqueue \n";
                std::cin >> in;
                myQueue.enqueue(in);
            }
            //check if want to dequeue
            std::cout << "dequeue? (y/n) \n";
            std::cin >> yn;
            if (yn == 'y'){
                std::cout << myQueue.dequeue() << std::endl;
            }
            //check if empty
            std::cout << "Is empty? " << myQueue.isEmpty() << std::endl;

            //check if want to continue
            std::cout << "continue? (y/n) ";
            std::cin >> yn;
            std::cout << std::endl;
        }

    return 0;
}