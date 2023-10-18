#include<iostream>
#include<queue>
using namespace std;


// topological sort BFS manner
// Also find if a directed graph has a cycle or not

void findIndegree(vector<int>* g, vector<int>& indegree, int v){
	for(int i=0 ; i<v ; i++){
		for(auto adj : g[i]){
			indegree[adj]++;
		}
	}
}

void topologicalSort(vector<int>* g, int v){
	
	vector<int> indegree(v,0);
	findIndegree(g, indegree, v);
	
	queue<int> q;
	
	for(int i=0 ; i<indegree.size() ; i++){
		if(indegree[i] == 0)
			q.push(i);
	}
	
	int countVertices = 0;
	while(!q.empty()){
		
		int currVertex = q.front();
		cout << currVertex << " ";
		q.pop();
		countVertices++;
		
		for(auto& adj : g[currVertex]){
			if(--indegree[adj] == 0){
				q.push(adj);
			}
		}
	}
	
	if(countVertices != v){
		cout << "There is a cycle in this Directed graph\n";
	}
}

void createGraph(vector<int>* g){}

int main(){
	
	int v = 10;
	vector<int>* g = new vector<int>[v];
	createGraph(g);
	topologicalSort(g, v);
	
}

