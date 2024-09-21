// class DLLNode {
//   public:
//     int data;
//     DLLNode *next;
//     DLLNode *prev;

//     DLLNode(int val) {
//         data = val;
//         this->next = NULL;
//         this->prev = NULL;
//     }
// };
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        
        DLLNode* ans = temp;
        DLLNode* last = NULL;
        while(temp!=NULL){
            DLLNode* first = temp;
            DLLNode* second = temp->prev;
            first->next = second;
            first->prev = last;
            temp = second;
            last = first;
        }
        
        return ans;
    }
};