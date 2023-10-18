#include<iostream>
#include<set>

using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, string& currentPath){

    vis[row][col] = 1;
    int R = grid.size();
    int C = grid[0].size();

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    vector<string> dir = {"U", "D", "L", "R"};

    for(int i=0 ; i<4 ; i++){
        int newR = row + dx[i];
        int newC = col + dy[i];

        string currDir = dir[i];

        if(newR >= 0 && newR < R && newC >= 0 && newC < C && vis[newR][newC] == 0 && grid[newR][newC] == 1){
            currentPath += currDir;
            dfs(grid, vis, newR, newC, currentPath);            
        }
    }

}

int countDistinctIslands(vector<vector<int>>& grid) {
    
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> vis(row, vector<int>(col, 0));

    set<string> distinctIslands;

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(grid[i][j] == 1 && vis[i][j] == 0){
                string currentPath = "S";
                dfs(grid, vis, i, j, currentPath);
                distinctIslands.insert(currentPath);
            }
        }
    }
    return distinctIslands.size();
}



int main(){

    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1 },
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1}
    };

    int ans = countDistinctIslands(grid);
    cout << ans << "\n";

}