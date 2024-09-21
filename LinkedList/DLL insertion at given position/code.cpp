/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node* temp = head;
   for(int i=0;i<pos;i++){
       temp = temp->next;
   }
   
   
   Node* curr = new Node(data);
   Node* temp2 = temp->next;
   
   temp->next = curr;
   curr->prev  = temp;
   curr->next = temp2;
   
   if(temp2!=NULL){
       temp2->prev = curr;
   }
   
}