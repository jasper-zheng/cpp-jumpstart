
#include <iostream>
using namespace std;

int findLargest(int arr[], int length);
int findLargestNoLoop(int arr[], int length);

int main() {
    

    int scores[] = {10,24,12,21,12,2,42,40,24,41};
    int length = sizeof(scores)/sizeof(scores[0]);
    
    
    int largest = findLargest(scores, length);
    
    cout << largest << "\n";
    return 0;
}

int findLargest(int arr[], int length){
    int currentMax = arr[0];
    for (int i = 0; i < length; i++){
        if (arr[i] > currentMax){
            currentMax = arr[i];
        }
    }
    return currentMax;
}







// bonus:

// Recursion is all you need
// https://www.youtube.com/watch?v=ngCos392W4w

int findLargestNoLoop(int arr[], int length){
    if (length == 1){
        return arr[0];
    } else {
        return max(arr[length - 1], findLargestNoLoop(arr, length - 1));
    }
}

