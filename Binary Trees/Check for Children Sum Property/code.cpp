/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    bool check(Node *root){
        if(root==NULL){
            return true;
        }
        
        
        bool lc = check(root->left);
        bool rc = check(root->right);
        bool self = true;
        if(root!=NULL && root->left!=NULL && root->right!=NULL){
            if(root->data != root->left->data+root->right->data){
                self = false;    
            }
        }
        
        else if(root!=NULL && root->left!=NULL && root->right==NULL){
            if(root->data != root->left->data){
                self = false;    
            }
        }
        
        else if(root!=NULL && root->left==NULL && root->right!=NULL){
            if(root->data != root->right->data){
                self = false;    
            }
        }
        
        return lc && rc && self;
        
    }
    
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     return check(root);
    }
    
};