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
        
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            int k = st.size();
            for(int i=0;i<k;i++){
                TreeNode* temp = st.top();
                st.pop();
                if(temp!=NULL){
                    ans.push_back(temp->val);
                    if(temp->right!=NULL){
                        st.push(temp->right);
                    }

                    if(temp->left!=NULL){
                        st.push(temp->left);
                    }
                }
                
            } 
            
            
        }

        return ans;


    }
};