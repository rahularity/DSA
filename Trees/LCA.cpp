#include <iostream>
using namespace std;

class Tree{
    public:
        int val;
        Tree* left;
        Tree* right;

        Tree(int val) : val(val), left(nullptr), right(nullptr){}

};

Tree* LCA(Tree* root, int val1, int val2){
	
	if(!root) return nullptr;
	
	if(root->val == val1 || root->val == val2){
		return root;
	}
	
	Tree* left = LCA(root->left, val1, val2);
	Tree* right = LCA(root->right, val1, val2);
	
	if(left && right)
		return root;
	
	if(left)
		return left;
	
	return right;
	
}

int main(){

	return 0;
	
}





