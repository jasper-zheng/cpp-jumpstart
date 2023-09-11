
#include <iostream>
#include <vector>
using namespace std;


class Grid {
    
private:
    int x_dim; // the x dimension of the grid
    int y_dim; // the y dimension of the grid
    
    // the grid:
    // 0 for empty
    // 1 for "x" - player 1
    // 2 for "o" - player 2
    vector<vector<int> >grid;
    
public:
    //----------------------------------------------
    // this is the class constructor that is going to run when we define a new Grid object
    Grid(int x, int y){
        x_dim = x;
        y_dim = y;
        initialiseGrid(x_dim, y_dim);
    }
    
    //----------------------------------------------
    
    void initialiseGrid(int x_dim, int y_dim){
        for (int y = 0; y < y_dim; y++){
            vector<int> row;
            for (int x = 0; x < x_dim; x++){
                row.push_back(0);
            }
            grid.push_back(row);
        }
    }
    
    //----------------------------------------------
    
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
    
    //----------------------------------------------
    
    bool isGameOver(){
        
        // we are checking on every rows, columns and diagonals to see if there is a winner
        // these three functions return 0 if there's no winner, return 1 or 2 indicating player 1 or 2 has win the game
        int row = checkRowCrossed();
        int col = checkColumnCrossed();
        int dia = checkDiagonalCrossed();
        
        if (row==1 or col==1 or dia==1){
            cout << "player x win\n";
            return true;
        } else if (row==2 or col==2 or dia==2){
            cout << "player o win\n";
            return true;
        }
        
        // next, we check if the grid has no empty space, in that case the game ends with a draw
        for (int y = 0; y < y_dim; y++){
            for (int x = 0; x < x_dim; x++){
                if (grid[y][x] == 0){
                    // if we spot an empty space, return false so that the game is not over
                    return false;
                }
            }
        }
        cout << "draw\n";
        return true;
    }
    
    //----------------------------------------------
    
    int checkRowCrossed(){
        for (int i = 0; i < y_dim; i++){
            int n = 0;
            while (grid[i][n] == grid[i][n+1] and grid[i][n] != 0){
                n += 1;
                if (n == x_dim - 1){
                    // If we find two pairs of matching marks in a row, return with the number at that place.
                    return grid[i][n];
                }
            }
        }
        // If we checked all rows and found nothing, return 0
        return 0;
    }
    int checkColumnCrossed(){
        for (int i = 0; i < x_dim; i++){
            int n = 0;
            while (grid[n][i] == grid[n+1][i] and grid[n][i] != 0){
                n += 1;
                if (n == y_dim - 1){
                    return grid[n][i];
                }
            }
        }
        return 0;
    }
    int checkDiagonalCrossed(){
        int i = 0, n = 0;
        while (grid[i][i] == grid[i+1][i+1] and grid[i][i] != 0){
            i+=1;
            if (i == x_dim - 1){
                return grid[i][i];
            }
        }
        while (grid[n][x_dim-n-1] == grid[n+1][x_dim-n-2] and grid[n][x_dim-n-1] != 0){
            n+=1;
            if (n == x_dim - 1){
                return grid[n][x_dim - n - 1];
            }
        }
        return 0;
    }
    
    //----------------------------------------------
    
    bool checkInput(int x, int y){
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
    
    //----------------------------------------------
    
    void placeMarker(int x, int y, int marker){
        grid[y-1][x-1] = marker;
    }
    
    //----------------------------------------------
    
};





class Player {
private:
    int index;
    char marker_char;
public:
    Player(int marker_in){
        index = marker_in;
        if (marker_in == 1){
            marker_char = 'x';
        } else {
            marker_char = 'o';
        }
    }
    
    // we are having a "&" in front of the variable, means we are passing a reference of the vector, instead of passing a copy of it, so changes made here is reflectd in main()
    void playersMove(Grid &grid){
        int x, y;
        while(true){
            cout << "player " << marker_char << ":\nenter row: ";
            cin >> y;
            cout << "enter column: ";
            cin >> x;
            if(grid.checkInput(x, y)){
                break;
            }
        }
        grid.placeMarker(x, y, index);
    }
};



int main() {

    Grid grid(3, 3);
    Player player1(1);
    Player player2(2);

    int round = 0;
    grid.showGrid();

    while(!grid.isGameOver()){
        if (round%2 == 0){
            player1.playersMove(grid);
        } else{
            player2.playersMove(grid);
        }
        grid.showGrid();
        round += 1;
    }
    return 0;
}





