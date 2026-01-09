
//  1339. Maximum Product of Splitted Binary Tree

#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
const int MOD= 1e9 + 7;
    long long totalSum=0;
    long long maxPro=0;
    //calculating sum of whole tree
    long long totalSumOfTree(TreeNode* root){
        if(!root) return 0;
        int sum= (root->val)+ totalSumOfTree(root->left)+ totalSumOfTree(root->right);
        return sum;
    }
    //traversing the whole tree to calculate the
    //sum of all subtrees
    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long left= dfs(root->left);
        long long right= dfs(root->right);
        long long subTreeSum= root->val+ left+ right;
        long long product= subTreeSum*(totalSum- subTreeSum);
        maxPro= max(maxPro,product);
        return subTreeSum;

    }
    int maxProduct(TreeNode* root) {
        //total sum
        totalSum= totalSumOfTree(root);
        //subtree sum
        //and their products
        dfs(root);
        //return it with mod
        return maxPro%MOD;
    }

//Approach->dfs traversal of binary tree
//TC->0(n), no. of nodes
//SC->0(h) recursive stack space