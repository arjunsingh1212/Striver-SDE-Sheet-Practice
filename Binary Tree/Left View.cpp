/* https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1 */

/* A binary tree node

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
 
 void left_view(Node* root,int curr_level,int &maxlevel,vector<int> &ans)
 {
     if(root==NULL) return;
     if(curr_level>maxlevel)
     {
         ans.push_back(root->data);
         maxlevel=curr_level;
     }
     left_view(root->left,curr_level+1,maxlevel,ans);
     left_view(root->right,curr_level+1,maxlevel,ans);
 }

// A wrapper over leftViewUtil()
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   int maxlevel=0;
   left_view(root,1,maxlevel,ans);
   return ans;
}
