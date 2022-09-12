
#include <iostream>
#include <vector>
using namespace std;

bool checkInput(int x, int y);


class Grid {
    
private:
    int x_dim; // the x dimension of the grid
    int y_dim; // the y dimension of the grid
    vector<vector<int> >grid;
    
public:
    Grid(int x, int y){
        x_dim = x;
        y_dim = y;
        
        // the grid:
        // 0 for empty
        // 1 for "x" - player 1
        // 2 for "o" - player 2
        
        initialiseGrid(x_dim, y_dim);
    }
    
    void initialiseGrid(int x_dim, int y_dim){
        for (int y = 0; y < y_dim; y++){
            vector<int> row;
            for (int x = 0; x < x_dim; x++){
                row.push_back(0);
            }
            grid.push_back(row);
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
    
    bool isGameOver(){
        int checks[] = {checkRowCrossed(),checkDiagonalCrossed(),checkColumnCrossed()};
        for (int i = 0; i<3; i++){
            switch(checks[i]) {
                case 0:
                    break;
                case 1:
                    cout << "player x win\n";
                    return true;
                case 2:
                    cout << "player o win\n";
                    return true;
            }
        }
        bool noEmptyGrid = true;
        for (int y = 0; y < y_dim; y++){
            for (int x = 0; x < x_dim; x++){
                if (grid[y][x] == 0){
                    noEmptyGrid = false;
                }
            }
        }
        if (noEmptyGrid){
            cout << "draw\n";
        }
        return noEmptyGrid;
    }
    int checkRowCrossed(){
        for (int i = 0; i < y_dim; i++){
            if (grid[i][0] == grid[i][1] and grid[i][1] == grid[i][2] and grid[i][0] != 0){
                return grid[i][0];
            }
        }
        return 0;
    }
    int checkColumnCrossed(){
        for (int i = 0; i < x_dim; i++){
            if (grid[0][i] == grid[1][i] and grid[1][i] == grid[2][i] and grid[0][i] != 0){
                return grid[0][i];
            }
        }
        return 0;
    }
    int checkDiagonalCrossed(){
        if (grid[1][1] != 0){
            if (grid[0][0] == grid[2][2] and grid[1][1] == grid[2][2]){
                return grid[0][0];
            } else if (grid[0][2] == grid[2][0] and grid[1][1] == grid[2][0]){
                return grid[0][0];
            }
        }
        return 0;
    }
    
    bool checkInput(int x, int y){
        if (x == -255 and y == -255){
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
    
    void placeMarker(int x, int y, int marker){
        grid[y-1][x-1] = marker;
    }
};




class Interaction {
private:
    int marker;
    char marker_char;
public:
    Interaction(int marker_in){
        marker = marker_in;
        if (marker_in == 1){
            marker_char = 'x';
        } else {
            marker_char = 'o';
        }
    }
    void playersMove(Grid &grid){
        int x = -255, y = -255;
        while(grid.checkInput(x, y)){
            cout << "player " << marker_char << ":\nenter row: ";
            cin >> y;
            cout << "enter column: ";
            cin >> x;
        }
        grid.placeMarker(x, y, marker);
    }
};



int main() {
    
    Grid grid1(3, 3);
    grid1.showGrid();
    
    Interaction player1(1);
    Interaction player2(2);
    
    int round = 0;
    while(!grid1.isGameOver()){
        if (round%2 == 0){
            player1.playersMove(grid1);
            
        } else{
            player2.playersMove(grid1);
        }
        grid1.showGrid();
        round+=1;
    }

}

