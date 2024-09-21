/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* ans = new Node(arr[0]);
        Node* prev = ans;
        int n = arr.size();
        for(int i=1;i<n;i++){
            Node* temp = new Node(arr[i]);
            prev->next = temp;
            prev = temp;
        }
        
        return ans;
    }
};