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
    bool isPalindrome(ListNode* head) {
        
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        int low = 0, high = arr.size()-1;
        while(low<high){
            if(arr[low]!=arr[high]){
                return false;
            }

            low++;
            high--;
        }

        return true;

    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* middle;
        while(slow!=NULL && fast!=NULL){
            
            fast = fast->next;
            if(fast==NULL){
                // This means its an odd sized linked list
                break;
                
            }
            slow = slow->next;
            fast = fast->next;
        }

        middle = slow;
        // Middle is sorted
        // You need to reverse the LL from middle uptil the end of the LL
        ListNode *prev = NULL, *curr = middle, *front;
        while(curr!=NULL){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        ListNode *head1 = head, *head2 = prev;
        while(head1!=NULL && head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        return true;

    }
};