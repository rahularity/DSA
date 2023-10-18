#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


void insert(TreeNode*& root, int val, int& ans) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }

    if (root->val < val) {
        insert(root->right, val, ans);
    } else {
        ans = root->val;
        insert(root->left, val, ans);
    }
}

vector<int> replaceWithLeastGreaterOnRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    TreeNode* root = nullptr;

    for (int i = n - 1; i >= 0; i--) {
        int ans = -1;
        insert(root, arr[i], ans);
        res[i] = ans;
    }

    return res;
}

int main() {
    vector<int> arr = {6, 3, 9, 8, 10, 2, 1, 15, 7};

    vector<int> res = replaceWithLeastGreaterOnRight(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}