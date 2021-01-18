/* https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 */

void generatePaths(int m[MAX][MAX],string s,vector<string> &ans,int x,int y,int n,vector<vector<bool>> &visited)
{
    
    if(x==n || y==n || x==-1 || y==-1) return;
    if(m[x][y]==0) return;
    if(x==n-1 && y==n-1) 
    {
        ans.push_back(s);
    }
    visited[x][y]=true;
    
    if(!visited[x+1][y])
    generatePaths(m,s+'D',ans,x+1,y,n,visited);
    if(!visited[x][y+1])
    generatePaths(m,s+'R',ans,x,y+1,n,visited);
    if(x-1!=-1 && !visited[x-1][y])
    generatePaths(m,s+'U',ans,x-1,y,n,visited);
    if(y-1!=-1 && !visited[x][y-1])
    generatePaths(m,s+'L',ans,x,y-1,n,visited);
    
    visited[x][y]=false;
}
vector<string> findPath(int m[MAX][MAX], int n) {
    // Your code goes here
    string s="";
    int x=0,y=0;
    vector<string> ans;
    vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
    if(m[0][0]==0) return ans;
    generatePaths(m,s,ans,x,y,n,visited);
    sort(ans.begin(),ans.end());
    return ans;
}
