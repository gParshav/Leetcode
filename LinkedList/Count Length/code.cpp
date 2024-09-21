// struct Node
// {
//     int data;
//     Node* next;
//     Node(int x) {  data = x;  next = NULL; }
// }; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        int ans = 0;
        struct Node* temp = head;
        while(temp!=NULL){
            ans++;
            temp = temp->next;
        }
        return ans;
    }
};