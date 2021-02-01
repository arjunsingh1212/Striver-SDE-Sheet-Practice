/* https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<vector<int>> q;  //v[0] is time frame, v[1] is index row v[2] is index column
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2) q.push({0,i,j});
            }
        }
        while(!q.empty())
        {
            vector<int> v=q.front();
            q.pop();
            ans=max(ans,v[0]);
            if(v[1]-1>=0 && grid[v[1]-1][v[2]]==1) 
            {
                grid[v[1]-1][v[2]]=2;
                q.push({v[0]+1,v[1]-1,v[2]});
            }
            if(v[2]-1>=0 && grid[v[1]][v[2]-1]==1) 
            {
                grid[v[1]][v[2]-1]=2;
                q.push({v[0]+1,v[1],v[2]-1});
            }
            if(v[1]+1<grid.size() && grid[v[1]+1][v[2]]==1) 
            {
                grid[v[1]+1][v[2]]=2;
                q.push({v[0]+1,v[1]+1,v[2]});
            }
            if(v[2]+1<grid[0].size() && grid[v[1]][v[2]+1]==1) 
            {
                grid[v[1]][v[2]+1]=2;
                q.push({v[0]+1,v[1],v[2]+1});
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) ans=-1;
            }
        }
        return ans;
    }
};