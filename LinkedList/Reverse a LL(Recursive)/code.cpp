/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* temp, ListNode* prev){

        if(temp==NULL){
            return;
        }

        
        ListNode* temp2 = temp->next;
        temp->next = prev;
        reverse(temp2, temp);
    }

    ListNode* reverseList(ListNode* head) {
        
        ListNode* temp = head;
        if(head==NULL){
            return NULL;
        }
        while(temp->next!=NULL){
            temp = temp->next;
        }

        reverse(head, NULL);
        return temp;

    }
};



class Solution {
public:
    ListNode* reverse(ListNode* temp){
        if(temp==NULL || temp->next==NULL){
            return temp;
        }

        ListNode* front = temp->next;
        ListNode* newHead = reverse(temp->next);
        front->next = temp;
        temp->next = NULL;
        return newHead;


    }


    ListNode* reverseList(ListNode* head) {

        return reverse(head);

    }
};