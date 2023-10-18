#include<iostream>
using namespace std;

void dfs(vector<vector<int>>& G, int node, int v, vector<bool>& vis){
    vis[node] = true;
    for(auto& adj : G[node]){
        if(!vis[adj]){
            dfs(G, adj, v, vis);
        }
    }
}

int numberOfProvince(vector<vector<int>>& G, int v){

    int totalProvinces = 0;
    vector<bool> vis(v, false);
    for(int i=0 ; i<v ; i++){
        if(!vis[i]){
            totalProvinces++;
            dfs(G, i, v, vis);
        }
    }

    return totalProvinces;

}

