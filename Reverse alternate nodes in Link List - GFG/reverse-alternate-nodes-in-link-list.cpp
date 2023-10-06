//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd==NULL){
            return;
        }
        Node* q=odd;
        Node* prev=NULL;
        Node* next=NULL;
        Node* cur=odd->next;
        int i=0;
        while(q!=NULL){
            i++;
            q=q->next;
        }
        int n=i;
        i=0;
        q=odd;
        while(q!=NULL&&i<n){
            if(i%2!=0){
                if(cur->next==NULL||cur->next->next==NULL){
                    q=q->next;
                    cur->next=prev;
                    prev=cur;
                    i++;
                    continue;
                }
                next=cur->next->next;
                q=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            else{
                cur=q->next;
                if(cur==NULL){
                    q->next=prev;
                    i++;
                    continue;
                }
                Node* temp=cur->next;
                if(temp==NULL){
                    q=q->next;
                    i++;
                    continue;
                }
                q->next=temp;
                q=cur;
            }
            i++;
        }
        // q=odd;
        // while(q!=NULL){
        //     cout<<q->data<<" ";
        //     q=q->next;
        // }
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends