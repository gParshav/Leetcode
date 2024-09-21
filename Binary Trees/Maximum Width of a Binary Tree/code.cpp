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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<long, TreeNode*>> q;
        q.push({1, root});
        int x = 0;
        long ans = 0;
        while(!q.empty()){
            int k = q.size();
            long mini=1e9, maxi=0;
            long x = q.front().first;
            for(int i=0;i<k;i++){
                long index = q.front().first - x;
                TreeNode* temp = q.front().second;
                q.pop();
                mini = min(index, mini);
                maxi = max(index, maxi);
                long leftIdx = index*2; 
                if(temp->left!=NULL){
                    q.push({leftIdx, temp->left});
                }

                if(temp->right!=NULL){
                    q.push({leftIdx+1, temp->right});
                }

                
            }
            
            ans = max(ans, maxi-mini+1);
            
        }

        return (int)ans;

    }
};