//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
  Node *reverse(Node *head) {
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL) {
      Node *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }

    return prev;
  }
  Node *compute(Node *head) {

    head = reverse(head);

    int mx = head->data;
    Node *tp = head;

    while (tp->next != NULL) {
      mx = max(mx, tp->next->data);
      if (mx != tp->next->data)
        tp->next = tp->next->next;
      else
        tp=tp->next;
    }

    head = reverse(head);

    return head;
  }
};


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends