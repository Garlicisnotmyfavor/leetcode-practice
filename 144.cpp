/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //前序就是先root，再左再右
        vector<int> result;
        if(root != nullptr) result.push_back(root->val);
        else return result;
        if(root->left != nullptr){
            vector<int> temp = preorderTraversal(root->left);
            for(int i=0; i<temp.size(); i++){
                result.push_back(temp[i]);
            }
        }
        if(root->right != nullptr){
            vector<int> temp = preorderTraversal(root->right);
            for(int i=0; i<temp.size(); i++){
                result.push_back(temp[i]);
            }
        }
        return result;
    }
};