
#include <iostream>
using namespace std;

int main() {

    string name;
    cout << "Enter a name: ";
    getline(cin, name);
    
    int age;
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    
    return 0;
    
}
