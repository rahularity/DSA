//  Used to detect negative weight cycle in Directed Graphs
//  Time Complexity : O(V.E)

#include<iostream>
using namespace std;

class Edge{

    public:
        int src;
        int dest;
        int weight;

    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight){}

};

int main(){

    vector<Edge> Graph;
    int v;
    int S;

    vector<int> distance(v, 1e9);
    distance[S] = 0;

    for(int i=0 ; i<=v ; i++){
        for(auto& edge : Graph){
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // Relaxation condition
            if(distance[src] != 1e9 && distance[src] + weight < distance[dest]){
                distance[dest] = distance[src] + weight;
                
                // check for negative cycle
                if(i == v){
                    cout << "There is a negative cycle.";
                }
            }
        }
    }

}