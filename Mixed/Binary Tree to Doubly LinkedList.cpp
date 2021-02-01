/* https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1 */

/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

Node* inOrderPredecessor(Node* root)
{
    root=root->left;
    while(root->right)
    {
        root=root->right;
    }
    return root;
}

Node* inOrderSuccessor(Node* root)
{
    root=root->right;
    while(root->left)
    {
        root=root->left;
    }
    return root;
}

Node* helper(Node *root)
{
    if(root==NULL) return root;
    if(root->left)
    {
        Node* inPre=inOrderPredecessor(root);
        helper(root->left);
        inPre->right=root;
        root->left=inPre;
    }
    if(root->right)
    {
        Node* inSucc=inOrderSuccessor(root);
        helper(root->right);
        inSucc->left=root;
        root->right=inSucc;
    }
    return root;
}


// This function should return head to the DLL

Node * bToDLL(Node *root)
{
    // your code here
    root=helper(root);
    while(root->left)
    {
        root=root->left;
    }
    return root;
}

