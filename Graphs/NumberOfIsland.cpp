// Number of Island === Number of connected components

#include<iostream>
using namespace std;

void dfs(vector<vector<int>>& matrix, int cellRow, int cellCol, int row, int col){
    matrix[cellRow][cellCol] = 2;

    int dirX[] = {-1, 1, 0, 0};
    int dirY[] = {0, 0, -1, 1};

    // goto all 4 directions and check for island
    for(int i = 0 ; i<4 ; i++){
        int newRow = cellRow + dirX[i];
        int newCol = cellCol + dirY[i];

        if(newRow >= 0 && newRow < row && newCol >=0 && newCol < col && matrix[newRow][newCol] == 1){
            dfs(matrix, newRow, newCol, row, col);
        }
    }
}

int numberOfIsland(vector<vector<int>> matrix){

    int row = matrix.size();
    int col = matrix[0].size();

    int islandsCount = 0;

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(matrix[i][j] == 1){
                islandsCount++;
                dfs(matrix, i, j, row, col);
            }
        }
    }

    return islandsCount;

}

int main(){

}
