/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Node { 
public: 
    int data; 
    Node* next; 
}; 
int n;
Node *create(int n)
{ 
    Node* p,*head;
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            head = new Node();
            p=head;
        }
        else
        {
            p->next = new Node();
            p=p->next;
        }
        cin>>p->data;
    }
    p->next=NULL;
    return(head);
}

Node* getNode(int data) 
{ 
    Node* newNode = new Node(); 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
}
void push(struct Node** headrf, int new_data) 
{ 
    struct Node* new_node = new Node(); 
    new_node->data  = new_data; 
    new_node->next = (*headrf); 
    (*headrf)    = new_node; 
} 
void insert(Node** curr, int pos, int data) 
{ 
    if (pos < 1 || pos > n + 1) 
        {
            if(pos==0)
            {
                push(curr,data);
                return;
            }
        }
    else { 
        while (pos--) { 
  
            if (pos == 0) { 
  
                Node* temp = getNode(data); 
                temp->next = *curr; 
                *curr = temp; 
            } 
            else
              curr = &(*curr)->next; 
        } 
        n++; 
    } 
} 
void Delete(struct Node **headrf, int pos) 
{  
   if (*headrf == NULL) 
      return; 
  
   struct Node* temp = *headrf; 
  
    if (pos == 0) 
    { 
        *headrf = temp->next;   
        free(temp);           
        return; 
    } 
    for (int i=0; temp!=NULL && i<pos-1; i++)
         temp = temp->next; 
    if (temp == NULL || temp->next == NULL) 
         return; 
    struct Node *next = temp->next->next; 

    free(temp->next);  
  
    temp->next = next;  
} 
void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        cout << " " << head->data; 
        head = head->next; 
    } 
    cout << endl; 
}

Node *reverse(Node* head) 
    { 
        
        Node* curr = head; 
        Node *prev = NULL, *next = NULL; 
  
        while (curr != NULL) { 
            next = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = next; 
        } 
        head = prev; 
        return(head);
    } 

int main()
{
    cin>>n;
    Node* head;
    head=create(n);
    printList(head);
    insert(&head,2,12);
    printList(head);
    //indexing different in insert and delete to match the ques  
    Delete(&head,5);
    printList(head);
    head=reverse(head);
    printList(head);
    return 0;
}
