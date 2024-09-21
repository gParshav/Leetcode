/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*, int> mp;
        ListNode* temp = head;
        while(temp!=NULL){
            mp[temp]++;
            if(mp[temp]==2){
                return true;
            }
            temp = temp->next;
        }

        return false;

    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(slow!=NULL && fast!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast==NULL){
                return false;
            }
            fast = fast->next;
            if(slow==fast){
                return true;
            }
        }

        return false;

    }
};