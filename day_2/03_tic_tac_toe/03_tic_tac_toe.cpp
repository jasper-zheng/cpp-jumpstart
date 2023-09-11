
#include <iostream>
#include <vector>
using namespace std;

const int x_dim = 3; // the x dimension of the grid
const int y_dim = 3; // the y dimension of the grid

int grid[y_dim][x_dim]; // grid: 0 for empty; 1 for player x; 2 for player o;
int marker; // marker: 1 for player x, 2 for player o;

void initialiseGrid();
void showGrid();
bool checkInput(int x, int y);

int main() {
    
    int x,y;
    initialiseGrid();
    showGrid();
    
    // game will last for 9 turns since we have a 3x3 grid (x_dim * y_dim)
    for (int i = 0; i < x_dim * y_dim; i++){
        
        marker = i % 2 + 1;
        
        while (true) {
            if (marker == 1){
                cout << "Player x \n";
            } else {
                cout << "Player o \n";
            }
            cout << "enter row: ";
            cin >> y;
            cout << "enter column: ";
            cin >> x;
            
            if (checkInput(x, y)){
                break;
            }
        }
        grid[y-1][x-1] = marker;
        showGrid();
    }
}

void initialiseGrid(){
    // initialise the grid to zeros.
    for (int y = 0; y < y_dim; y++){
        for (int x = 0; x < x_dim; x++){
            grid[y][x] = 0;
        }
    }
}

void showGrid(){
    // print the grid according to the integers in the array
    for (int y = 0; y < y_dim; y++){
        for (int x = 0; x < x_dim; x++){
            switch(grid[y][x]) {
                case 0:
                    cout << "[ ]";
                    break;
                case 1:
                    cout << " x ";
                    break;
                case 2:
                    cout << " o ";
                    break;
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

bool checkInput(int x, int y){

    // we check if the row/column number is within the range
    // and check if the cell is taken
    if (x <= 0 or x > x_dim or y <= 0 or y > y_dim){
        cout << "row number should between 0 and " << y_dim << "\n";
        cout << "column number should between 0 and " << x_dim << "\n\n";
        return false;
    } else if (grid[y-1][x-1] != 0){
        cout << "row "<< y << " column " << x << " already taken\n\n";
        return false;
    } else {
        return true;
    }
    
}


