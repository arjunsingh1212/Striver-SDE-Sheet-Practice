

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        ans=inorderTraversal(root->left);
        ans.push_back(root->val);
        ans=inorderTraversal(root->right);
        return ans;
    }
};


//Iterative


// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node *root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node *curr = root;
 
    // if the current node is null and the stack is also empty, we're done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}