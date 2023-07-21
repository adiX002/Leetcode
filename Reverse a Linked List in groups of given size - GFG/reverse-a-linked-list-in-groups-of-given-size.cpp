//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    node *rev(node *start)
    {
        if(!start || !start->next)
            return start;
        node *temp=start;
        node *ans=NULL;
        while(start)
        {
            temp=start;
            start=start->next;
            temp->next=ans;
            ans=temp;
        }
        return ans;
        
    }
    struct node *reverse (struct node *head, int k)
    { 
        node *ans=NULL;
        node *start=NULL;
        node *temp=head;
        node *curr=head;
        while(head)
        {
            start=head;
            curr=head;
            for(int i=1;i<k && curr->next;i++)
            {
                curr=curr->next;
            }
            head=curr->next;
            curr->next=NULL;
            start=rev(start);
            if(!ans)
                ans=start;
            else
            {
            temp=ans;
            while(temp->next)
                temp=temp->next;
            temp->next=start;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends