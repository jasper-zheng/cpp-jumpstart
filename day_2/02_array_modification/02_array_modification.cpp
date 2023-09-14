
#include <iostream>
#include <vector>

using namespace std;

void printArray(int arr[], int length);
// Header

int main() {
    
    int myNums[50]; // initialise 50 places, and one address
    
    
    for (int i = 0; i < 50; i++){
        if (i % 4 == 0){
            myNums[i] = 0;
        } else {
            myNums[i] = i;
        }
    }
    
    int length = sizeof(myNums)/sizeof(myNums[0]);
    
    printArray(myNums, length);
    
    return 0;
}


void printArray(int arr[], int length){
    
    cout << "array:\n";
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
}

