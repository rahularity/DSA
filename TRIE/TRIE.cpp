#include <iostream>
using namespace std;

class Trie{

	public: 
		unordered_map<char, Trie*> children;
		bool isEnd;
		Trie(){
			this->isEnd = false;
		}
			
};

void InsertNode(Trie* root, string word){

	Trie* currRoot = root;
	for(char c : word){
		if(currRoot->children.find(c) == currRoot->children.end()){
			Trie* newNode = new Trie();
			currRoot->children[c] = newNode;
		}
		currRoot = currRoot->children[c];
	}
	
	currRoot->isEnd = true;
	
}

bool FindWord(Trie* root, string word){
	
	Trie* currRoot = root;
	
	for(char c : word){
		if(currRoot->children.find(c) == currRoot->children.end())
			return false;
		currRoot = currRoot->children[c];
	}
	
	return currRoot->isEnd;
	
}

int main(){

	return 0;
	
}





