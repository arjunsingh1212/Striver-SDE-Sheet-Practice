/* https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1 */

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node *merge(Node *a,Node *b)
{
    Node *itr=new Node(0);
    Node *dummy=itr;
    while(a || b)
    {
        if(a==NULL)
        {
            itr->bottom=b;
            b=b->bottom;
        }
        else if(b==NULL)
        {
            itr->bottom=a;
            a=a->bottom;
        }
        else if(a->data<b->data)
        {
            itr->bottom=a;
            a=a->bottom;
        }
        else
        {
            itr->bottom=b;
            b=b->bottom;
        }
        itr=itr->bottom;
    }
    return dummy->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root->next==NULL) return root;
   return merge(root,flatten(root->next));
}