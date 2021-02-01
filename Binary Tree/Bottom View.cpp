/* https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1 */

/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

void printBottom(Node *node, int dist, int level, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // if the current level is more than or equal to the maximum level seen so far
    // for the same horizontal distance or horizontal distance is seen for
    // the first time, update the map
 
    if (level >= map[dist].second)
    {
        // update value and level for the current distance
        map[dist] = { node->data, level };
    }
 
    // recur for the left subtree by decreasing horizontal distance and
    // increasing level by 1
    printBottom(node->left, dist - 1, level + 1, map);
 
    // recur for the right subtree by increasing both level and
    // horizontal distance by 1
    printBottom(node->right, dist + 1, level + 1, map);
}


// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   // Your Code Here
   map<int, pair<int, int>> map;
   printBottom(root, 0, 0, map);
   vector<int> ans;
   for(auto x:map)
   {
       ans.push_back(x.second.first);
   }
   return ans;
}

