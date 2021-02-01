/* https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1 */

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root==NULL) return ans; 
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            ans.push_back(s1.top()->data);
            if(s1.top()->right)
            s2.push(s1.top()->right);
            if(s1.top()->left)
            s2.push(s1.top()->left);
            s1.pop();
        }
        while(!s2.empty())
        {
            ans.push_back(s2.top()->data);
            if(s2.top()->left)
            s1.push(s2.top()->left);
            if(s2.top()->right)
            s1.push(s2.top()->right);
            s2.pop();
        }
    }
    return ans;
}
