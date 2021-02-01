/* https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1 */

/*Complete the function below

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

void helper(Node* root,int &k,int &ans) //Inorder traversal is in Increasing order, so just find the k-th element in that order.
{
    if(!root) return;
    helper(root->left,k,ans);
    k--;
    if(k==0) ans=root->data;
    helper(root->right,k,ans);
}

// Return the Kth smallest element in the given BST 
int KthSmallestElement(Node *root, int K)
{
    //add code here.
    int ans=-1;
    helper(root,K,ans);
    return ans;
}