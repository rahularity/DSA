#include<iostream>
using namespace std;

class UnionFind{

    int totalNodes;
    vector<int> parent;
    vector<int> size;

    public:
    UnionFind(int totalNodes): totalNodes(totalNodes){
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

int main(){

    int totalNodes = 10;
    UnionFind* uf = new UnionFind(totalNodes);

    uf->_union(1,2);
    uf->_union(5,6);
    uf->_union(8,9);
    uf->_union(2,4);
    uf->_union(3,4);

    // root of 1,2,3,4 should be same
    cout << "root of 1 is : " << uf->_find(1) << "\n";
    cout << "root of 2 is : " << uf->_find(2) << "\n";
    cout << "root of 3 is : " << uf->_find(3) << "\n";
    cout << "root of 4 is : " << uf->_find(4) << "\n";
    cout << "root of 8 is : " << uf->_find(8) << "\n";
    cout << "root of 9 is : " << uf->_find(8) << "\n\n";

    uf->_union(9,3);
    cout << "root of 1 is : " << uf->_find(1) << "\n";
    cout << "root of 2 is : " << uf->_find(2) << "\n";
    cout << "root of 3 is : " << uf->_find(3) << "\n";
    cout << "root of 4 is : " << uf->_find(4) << "\n";
    cout << "root of 8 is : " << uf->_find(8) << "\n";
    cout << "root of 9 is : " << uf->_find(9) << "\n";


}