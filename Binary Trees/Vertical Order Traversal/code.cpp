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
    struct CompareTreeNode {
        bool operator()(const pair<int, TreeNode*>& lhs, const pair<int, TreeNode*>& rhs) const {
            return lhs.second->val > rhs.second->val;
        }
    };

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()){
            priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>, CompareTreeNode> pq;
            queue<pair<int, TreeNode*>> temp = q;
            while(!temp.empty()){
                int y = temp.front().first;
                TreeNode* curr = temp.front().second;
                temp.pop();
                pq.push({y, curr});
            }

            while(!pq.empty()){
                int y = pq.top().first;
                TreeNode* curr = pq.top().second;
                pq.pop();
                mp[y].push_back(curr->val);
            }
           int k = q.size();
           for(int i=0;i<k;i++){
                int y = q.front().first;
                TreeNode* temp = q.front().second;
                q.pop();
                if(temp->left!=NULL){
                    q.push({y-1, temp->left});
                }

                if(temp->right!=NULL){
                    q.push({y+1, temp->right});
                }
           } 
        }

        for(auto it : mp){
            vector<int> temp = it.second;
            ans.push_back(temp);
        }

        return ans;
    }
};