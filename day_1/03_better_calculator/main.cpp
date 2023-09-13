
#include <iostream>
using namespace std;

// don't forget to initialise your functions!
double calculate(double input1, double input2, string op);

// Header file

int main() {
    
    string op = ""; //operator
    double num1, num2;
    
    while(true){
        cout << "First number:\t";
        cin >> num1;
        
        while(true) {
            cout << "Operation: \t\t";
            cin >> op;
            
            if(op == "ac"){
                cout << "\nCleared\n\n";
                break;
            }
            cout << "Second number:\t";
            cin >> num2;
            num1 = calculate(num1, num2, op);
        }
    }
}



double calculate(double input1, double input2, string op){
    // we take two input numbers, check the operation type, then return the result
    
    double result = 0.0;
    
    if (op == "+"){
        result = input1 + input2;
        cout << input1 << op << input2 << "=" << result << "\n\n";
    } else if (op == "-"){
        result = input1 - input2;
        cout << input1 << op << input2 << "=" << result << "\n\n";
    } else if (op == "/"){
        result = input1 / input2;
        cout << input1 << op << input2 << "=" << result << "\n\n";
    } else if (op == "*"){
        result = input1 * input2;
        cout << input1 << op << input2 << "=" << result << "\n\n";
    } else {
        cout << op << " not implemented" << "\n\n";
        cout << result << endl;
        result = input1;
    }
    return result;
}





