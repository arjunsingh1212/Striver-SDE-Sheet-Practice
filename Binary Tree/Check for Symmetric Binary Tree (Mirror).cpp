/* https://practice.geeksforgeeks.org/problems/symmetric-tree/1 */

/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

bool symmetric(struct Node* root1,struct Node*root2)
{
    if(root1==NULL && root2==NULL) return true;
    if(root1!=NULL && root2!=NULL && root1->data==root2->data)
    {
        return symmetric(root1->left,root2->right) && symmetric(root1->right,root2->left);
    }
    return false;
 }


// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
	// Code here
	if(!root) return true;
	if(root->left==NULL && root->right==NULL) return true; //Both NULL
	return symmetric(root->left,root->right);

}