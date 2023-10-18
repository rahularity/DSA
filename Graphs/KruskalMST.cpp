#include<iostream>
#include<algorithm>
using namespace std;
using node = pair<int,int>;

class DisjointSet{

    int totalNodes;
    vector<int> parent;
    vector<int> size;

    public:
    DisjointSet(int totalNodes): totalNodes(totalNodes){
        parent.resize(totalNodes);
        size.resize(totalNodes);
        for(int i=0 ; i<parent.size() ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    void _union(int node1, int node2){

        int rootNode1 = _find(node1);
        int rootNode2 = _find(node2);

        if(rootNode1 == rootNode2)
            return;

        // smaller size tree come under larger size
        if(size[rootNode1] > size[rootNode2]){
            parent[rootNode2] = rootNode1;
            // size of bigger tree got even bigger
            size[rootNode1] += size[rootNode2];
        } 
        else {
            parent[rootNode1] = rootNode2;
            // size of bigger tree got even bigger
            size[rootNode2] += size[rootNode1];
        }
            
    }

    int _find(int node){

        if(parent[node] == node)
            return node;

        return parent[node] = _find(parent[node]);

    }

};

class Edge{
    public:
    int u,v,w;
    Edge(int u, int v, int w) : u(u), v(v), w(w){

    }
};

class Comparator{
    public:
    bool operator()(Edge*& e1, Edge*& e2){
        return e1->w < e2->w;
    }
};

int main(){

    int V = 7;
    vector<node> G[V];
    vector<Edge*> edgeList;
    DisjointSet* ds = new DisjointSet(V);

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

    // make edge list
    for(int i=0 ; i<V ; i++){
        for(auto& adj : G[i]){
            int u = i;
            int v = adj.first;
            int w = adj.second;

            edgeList.push_back(new Edge(u, v, w));
        }
    }

    sort(edgeList.begin(), edgeList.end(), Comparator());
    vector<pair<node, int>> parent; // {{from, to}, weight}

    for(Edge* edge : edgeList){
        int u = edge->u;
        int v = edge->v;
        int w = edge->w;

        // add the edge if it is not making a cycle
        if(ds->_find(u) != ds->_find(v)){
            parent.push_back({{u, v}, w});
            ds->_union(u,v);
        }
        if(parent.size() > V-1){
            break;
        }
    }

    for(auto& x : parent){
        cout << x.first.first << " -> " << x.first.second << " : " << x.second << "\n";
    }


    return 0;

}
