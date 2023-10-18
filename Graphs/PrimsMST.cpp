#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using node = pair<int, int>;

// Tree with the minimum sum of edge weights is called MST
// For V vertices there will be exactly V-1 edges in a MST


void prims(vector<node>* G, vector<bool>& vis, vector<pair<node,int>>& parent){
    int V = vis.size();
    priority_queue<pair<node, int>, vector<pair<node, int>>, greater<pair<node,int>>> pq;

    // edgeWeight, node
    pq.push({{0,0}, -1});
    while(!pq.empty()){
        int vertex = pq.top().first.second;
        int weight = pq.top().first.first;
        int parent_node = pq.top().second;
        pq.pop();

        // cout << vertex << " ";
        if(vis[vertex])
            continue;

        vis[vertex] = true;

        cout << "adj of " << vertex << " are : ";
        // no relaxation step is required, minheap will take care of taking the min edge out
        // visited array is required for not considering a vertex twice (for not making a cycle)
        for(auto& adj : G[vertex]){
            int adjVertex = adj.first;
            int adjWeight = adj.second;
            cout << adjVertex << ", ";

            if(!vis[adjVertex]){
                pq.push({{adjWeight, adjVertex}, vertex});
            }
        }
        cout << "\n";

        parent.push_back({{parent_node, vertex}, weight});

    }
}

int main(){

    int V=7;
    vector<node>* G = new vector<node>[V];
    vector<bool> vis(V, false);
    vector<pair<node, int>> parent;

    G[0].push_back({1,1});
    G[1].push_back({0,1});
    G[1].push_back({2,3});
    G[2].push_back({1,3});
    G[0].push_back({4,5});
    G[4].push_back({0,5});
    G[0].push_back({3,8});
    G[3].push_back({0,8});
    G[2].push_back({3,2});
    G[3].push_back({2,2});
    G[3].push_back({4,3});
    G[4].push_back({3,3});
    G[4].push_back({5,1});
    G[5].push_back({4,1});
    G[4].push_back({6,1});
    G[6].push_back({4,1});
    G[5].push_back({6,2});
    G[6].push_back({5,2});

    prims(G, vis, parent);

    for(auto& x : parent){
        cout << x.first.first << " -> " << x.first.second << " : " << x.second << "\n";
    }



}

