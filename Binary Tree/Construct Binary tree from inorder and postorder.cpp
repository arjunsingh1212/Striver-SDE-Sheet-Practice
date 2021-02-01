/* https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1 */

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

Node* buildTreeHelper(int* in, int* post, int inS, int inE, int postS, int postE)
{
    if(inS>inE) return NULL;
    
    int rootData=post[postE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==rootData)
        {
            rootIndex=i;
            break;
        }
    }
    int left_inS,left_inE,left_postS,left_postE,right_inS,right_inE,right_postS,right_postE;
    left_inS=inS;
    left_inE=rootIndex-1;
    left_postS=postS;
    left_postE=left_inE-left_inS+left_postS;
    right_inS=rootIndex+1;
    right_inE=inE;
    right_postS=left_postE+1;
    right_postE=postE-1;
    Node* root=new Node(rootData);
    root->left=buildTreeHelper(in,post,left_inS,left_inE,left_postS,left_postE);
    root->right=buildTreeHelper(in,post,right_inS,right_inE,right_postS,right_postE);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    Node* root=buildTreeHelper(in, post, 0, n-1, 0, n-1);
    return root;
}
