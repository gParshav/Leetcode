/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        int ans = 1e5;
        while(root!=NULL){
            ans = min(ans, root->data);
            root=root->left;
        }
        
        return ans;
    }
};