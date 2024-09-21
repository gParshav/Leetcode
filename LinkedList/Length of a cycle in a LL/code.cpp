// struct Node {
//     int data;
//     struct Node *next;
//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* temp = head;
        unordered_map<Node*, pair<int, int>> mp;
        int curr = 0;
        while(temp!=NULL){
            
            if(mp.find(temp)!=mp.end()){
                pair<int, int> k = mp[temp];
                if(k.first==1){
                    return curr - mp[temp].second+1;    
                }
            }
            
            curr++;
            mp[temp] = {1, curr};
            temp = temp->next;
        }
        
        return 0;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        unordered_map<Node*, int> mp;
        int cnt = 0;
        Node* temp = head;
        while(temp!=NULL){
            
            if(mp.find(temp)!=mp.end()){
                return cnt-mp[temp];
            }
            
            
            mp[temp] = cnt;
            cnt++;
            temp = temp->next;
            
            
        }
        
        return 0;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
        Node* fast = head;
        int k = 0;
        while(slow!=NULL && fast!=NULL){
            
            slow = slow->next;
            fast = fast->next;
            if(fast==NULL){
                return 0;
            }
            
            fast = fast->next;
            if(slow==fast){
                k = 1;
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                
                break;
            }
            
        }
        
        if(slow==NULL || fast==NULL){
            return 0;
        }
        
        Node* temp = slow;
        temp = temp->next;
        int ans = 1;
        while(temp!=slow){
            temp = temp->next;
            ans++;
            
        }
        
        if(k==1){
            return ans;
        }
        return 0;
            
    }
};



class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        
        Node* slow = head;
        Node* fast = head;
        while(slow!=NULL && fast!=NULL){
            
            slow = slow->next;
            fast = fast->next;
            if(fast==NULL){
                return 0;
            }
            
            fast = fast->next;
            if(slow==fast){
                int temp = 1;
                fast = fast->next;
                while(slow!=fast){
                    fast = fast->next;
                    temp++;
                }
                
                return temp;
            }
            
        }
        return 0;
    }
};