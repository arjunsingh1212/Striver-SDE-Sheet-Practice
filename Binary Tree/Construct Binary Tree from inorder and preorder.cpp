/* https://practice.geeksforgeeks.org/problems/construct-tree-1/1 */

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
Node* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE)
{
    if(inS>inE) return NULL;
    
    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==rootData)
        {
            rootIndex=i;
            break;
        }
    }
    int left_inS,left_inE,left_preS,left_preE,right_inS,right_inE,right_preS,right_preE;
    left_inS=inS;
    left_inE=rootIndex-1;
    left_preS=preS+1;
    left_preE=left_inE-left_inS+left_preS; //Due to being of same length as that of left inorder.
    right_inS=rootIndex+1;
    right_inE=inE;
    right_preS=left_preE+1;
    right_preE=preE;
    Node* root=new Node(rootData);
    root->left=buildTreeHelper(in,pre,left_inS,left_inE,left_preS,left_preE);
    root->right=buildTreeHelper(in,pre,right_inS,right_inE,right_preS,right_preE);
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
//add code here.
    Node* root=buildTreeHelper(in, pre, 0, n-1, 0, n-1);
    return root;
}