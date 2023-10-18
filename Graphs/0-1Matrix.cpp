#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
        int row;
        int col;
        int distance;

        
        Node(int row, int col, int distance){
            this->row = row;
            this->col = col;
            this->distance = distance;
        }
};

vector<vector<int>> findNearest0( vector<vector<int>>& matrix ){

    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> visited(row, vector<int>(col, 0));
    vector<vector<int>> distance(row, vector<int>(col, 0));

    // empty queue
    queue<Node*> q;

    // insert the 0s in the queue with distance as 0
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(matrix[i][j] == 0){
                visited[i][j] = 1;
                Node* node = new Node(i, j, 0);
                q.push(node);
            }
        }
    }

    // bfs
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        int currX = node->row;
        int currY = node->col;
        int currDist = node->distance;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};

        for(int i=0 ; i<4 ; i++){
            int nX = currX + dx[i];
            int nY = currY + dy[i];

            if(nX >= 0 && nX < row && nY >= 0 && nY < col && visited[nX][nY] == 0){

                q.push(new Node(nX, nY, currDist+1));
                visited[nX][nY] = 1;
                distance[nX][nY] = currDist+1;

            }
        }

    }

    return distance;

}


int main(){

    vector<vector<int>> matrix = {
        {0,0,1},
        {1,1,1},
        {1,1,1}
    };

    vector<vector<int>> ans = findNearest0(matrix);

    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[0].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}