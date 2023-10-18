#include<iostream>
#include<queue>
using namespace std;

// BFS Time Complexity : O(V+2E)
// V = all the vertices will go at least once in the queue
// 2E = all the edges will be considered twice in total because it is bidirectional

void shortestPathInUndirectedGraph(vector<int> G[], int v, int source){

    // using bfs in an undirected graph we can find the shortest distance
    queue<int> q;
    q.push(source);

    vector<int> distance(v, 1e9);
    distance[source] = 0;

    while(!q.empty()){
        int currNode = q.front();
        q.pop();

        for(auto& adj : G[currNode]){
            // relax step
            if(distance[adj] > distance[currNode] + 1){
                distance[adj] = distance[currNode] + 1;
                q.push(adj);
            }
        }
    }

    for(auto it : distance){
        cout << it << " ";
    }

}

int main(){

    int v = 10;
    vector<int> G[v];

}
