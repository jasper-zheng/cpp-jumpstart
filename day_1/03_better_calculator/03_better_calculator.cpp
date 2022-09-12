
#include <iostream>
using namespace std;

// don't forget to initialise your functions as well!
double calculate(double input1, double input2, string op);

int main() {
    
    string op;
    double num1, num2;
    
    while(true){
        cout << "First number:\t";
        cin >> num1;
        cout << "Operation: \t\t";
        cin >> op;
        while(op != "ac"){
            cout << "Second number:\t";
            cin >> num2;
            num1 = calculate(num1, num2, op);
            
            cout << "Operation: \t\t";
            cin >> op;
        }
        cout << "\nCleared\n\n";
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
        result = input1;
    }
    return result;
}





