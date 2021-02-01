/* https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1# */

//Structure of binary tree
/*struct Node
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
// function should print the topView of the binary tree



void printTop(Node *root, int dist, int level, auto &map)
{
    // base case: empty tree
    if (root == nullptr)
        return;
 
    // if the current level is less than the maximum level seen so far
    // for the same horizontal distance, or if the horizontal distance
    // is seen for the first time, update the map
    if (map.find(dist) == map.end() || level < map[dist].second)
    {
        // update value and level for current distance
        map[dist] = { root->data, level };
    }
 
    // recur for the left subtree by decreasing horizontal distance and
    // increasing level by 1
    printTop(root->left, dist - 1, level + 1, map);
 
    // recur for the right subtree by increasing both level and
    // horizontal distance by 1
    printTop(root->right, dist + 1, level + 1, map);
}


void topView(struct Node *root)
{
    //Your code here
    map<int, pair<int, int>> map;
 
    // perform preorder traversal on the tree and fill the map
    printTop(root, 0, 0, map);
 
    // traverse the map and print the top view
    for (auto it: map) {
        cout << it.second.first << " ";
    }
}
