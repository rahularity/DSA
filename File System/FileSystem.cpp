#include <iostream>
using namespace std;

// FILE SYSTEM

/*
 *	ls
 *	mkdir
 *	addContentToFile
 *
*/

class FileSystem{

	private:
		struct TrieNode{
			bool isFile;
			string content;
			unordered_map<string, TrieNode*> subFilesOrFolders;
		};
		
		TrieNode* root;
		
		TrieNode* getFolder(TrieNode* root, vector<string>& path){
			
			TrieNode* currentNode = root;
			
			for(auto& folder : path){
				if(currentNode->subFilesOrFolders.find(folder) == currentNode->subFilesOrFolders.end())
					return nullptr;
				currentNode = currentNode->subFilesOrFolders[folder];
			}
			
			return currentNode;
			
		}
		
	public:
	
		FileSystem() : root(new TrieNode()){}

        vector<string> split(string str, char delimeter){
            vector<string> splittedPath;
            int start = 0;
            for(int i=0 ; i<str.size() ; i++){
                if(str[i] == delimeter){
                    splittedPath.push_back(str.substr(start, i-start));
                    start = i;
                }
            }
            if(start != str.size()-1)
                splittedPath.push_back(str.substr(start, str.size()-start));
        }
	
		vector<string> ls(string path){
			
			vector<string> folders = split(path, '/');
			TrieNode* folderContent = getFolder(root, folders);
			
			if(folderContent == nullptr){
				return {};
			}
			
			vector<string> contents;
			
			for(auto content : folderContent->subFilesOrFolders){
				contents.push_back(content.first);
			}
			
			return contents;
	
		}
		
		void mkdir(string path){
			vector<string> folders = split(path, '/');
			
			TrieNode* currentNode = root;
			
			for(auto& folder : folders){
				if(currentNode->subFilesOrFolders.find(folder) == currentNode->subFilesOrFolders.end())
				{
					currentNode->subFilesOrFolders[folder] = new TrieNode();
				}
				currentNode = currentNode->subFilesOrFolders[folder];
			}
			
			currentNode->isFile = false;

		}
		
		void addContentToFile(string content, string path){
			
			vector<string> folders = split(path, '/');
			TrieNode* file = getFolder(root, folders);
			
			if(file && file->isFile){
				file->content += content;
			}
			
			return;
			
		}

	
};


int main(){

	return 0;
	
}


