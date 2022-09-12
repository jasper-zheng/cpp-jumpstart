
#include <iostream>
#include <vector>
using namespace std;

const int x_dim = 3; // the x dimension of the grid
const int y_dim = 3; // the y dimension of the grid

int grid[y_dim][x_dim];

void initialiseGrid();
void showGrid();
bool checkInput(int x, int y);

int main() {
    
    initialiseGrid();
    showGrid();
    
    // game will last for 9 turns since we have a 3x3 grid (x_dim * y_dim)
    for (int i = 0; i < x_dim * y_dim; i++){
        int x = -1;
        int y = -1;
        int marker = i % 2 + 1;
        // marker: 1 for player 1, 2 for player 2;
        // % is a modulo operator, returns the remainder of a division
        // if i is an even number, it's player1's turn, we turn the marker to 1
        // if i is an odd number, it's player2's turn, we turn the marker to 2
        
        while (checkInput(x, y)){
            if (marker == 1){
                cout << "Player x \n";
            } else {
                cout << "Player o \n";
            }
            cout << "enter row: ";
            cin >> y;
            cout << "enter column: ";
            cin >> x;
        }
        grid[y-1][x-1] = marker;
        showGrid();
    }
}

void initialiseGrid(){
    for (int y = 0; y < y_dim; y++){
        for (int x = 0; x < x_dim; x++){
            grid[y][x] = 0;
        }
    }
}

void showGrid(){
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
    if (x == -1 and y == -1){
        return true;
    } else {
        if (x <= 0 or x > x_dim or y <= 0 or y > y_dim){
            cout << "row number should between 0 and " << y_dim << "\n";
            cout << "column number should between 0 and " << x_dim << "\n\n";
            return true;
        } else if (grid[y-1][x-1] != 0){
            cout << "row "<< y << " column " << x << " already taken\n\n";
            return true;
        } else {
            return false;
        }
    }
}


