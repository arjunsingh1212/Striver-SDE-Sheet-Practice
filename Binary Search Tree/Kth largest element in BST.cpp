/* https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1 */

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

void helper(Node* root,int &k,int &ans) //Reverse Inorder Traversal
{
    if(!root) return;
    helper(root->right,k,ans);
    k--;
    if(k==0) ans=root->data;
    helper(root->left,k,ans);
}


// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int K)
{
    //Your code here
    int ans=-1;
    helper(root,K,ans);
    return ans;
}