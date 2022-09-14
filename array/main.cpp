
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int myNums[] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int i = 4; i < 10; i=i+2){
        cout << myNums[i] << "  ";
    }
    
    return 0;
}

