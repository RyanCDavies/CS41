#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
    char input[10];
    float number = 0;

   while ( cin >> input){
        if (isdigit(input[0])){
            number = strtof(input, 0);
            cout << number*2 << "\n";
        }
        else{
            cout << input << "\n";
        }
   };

   return 0;
}