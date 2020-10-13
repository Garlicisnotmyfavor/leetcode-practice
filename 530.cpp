/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void forall(TreeNode* root, vector<int> &all){
        if(root != NULL) all.push_back(root->val);
        if(root->left != NULL) forall(root->left, all);
        if(root->right != NULL) forall(root->right, all);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> all;
        forall(root, all);
        sort(all.begin(), all.end());
        int result = 10000;
        for(int i=0; i<all.size()-1; i++){
            if((all[i+1]-all[i])<result) result = all[i+1]-all[i];
        }
        return result;
    }
};