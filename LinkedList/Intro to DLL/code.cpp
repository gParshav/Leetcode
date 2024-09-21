/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* last = head;
        int n = arr.size();
        for(int i=1;i<n;i++){
            Node* curr = new Node(arr[i]);
            last->next = curr;
            curr->prev = last;
            last = curr;
            
        }
        return head;
    }
};