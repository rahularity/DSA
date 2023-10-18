#include<iostream>
#include<queue>
using namespace std;

// Time complexity: O(E.log(V))
using Edge = pair<int,int>;


vector<int> Dijkstras(vector<Edge> G[], int v, int source){
    // min heap
    priority_queue<Edge, vector<Edge>, greater<>> pq;

    vector<int> distance(v,1e9);
    distance[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){

        int currDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        for(auto& adj : G[currentNode]){
            int adjNode = adj.first;
            int edgeWeight = adj.second;
            if(distance[adjNode] > currDist + edgeWeight){
                distance[adjNode] = currDist + edgeWeight;
                pq.push({distance[adjNode], adjNode});
            }
        }

    }

    return distance;

}

int main(){

    int v = 8;
    vector<Edge> G[v];
    int source = 0;



}