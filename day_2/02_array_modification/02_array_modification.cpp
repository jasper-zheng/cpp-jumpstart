
#include <iostream>
#include <vector>

using namespace std;

void printArray(int arr[], int length);
void printVector(vector<int> &vec);

int main() {
    
    int myNums[50]; // we can use array
    vector<int> myVectorNums; // or vector, both fine. But for vector we don't need to define the size
    
    // initialising out array/vector
    for (int i = 0; i < 50; i++){
        if (i % 4 == 0){
            myNums[i] = 0;
            myVectorNums.push_back(0);
        } else {
            myNums[i] = i;
            myVectorNums.push_back(i);
        }
    }
    
    int length = sizeof(myNums)/sizeof(myNums[0]);
    printArray(myNums, length); // use array
    
    printVector(myVectorNums);  // use vector
    
    
    return 0;
}


void printArray(int arr[], int length){
    cout << "array:\n";
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printVector(vector<int> &vec){
    cout << "vector:\n";
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}

