/* https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1 */

class Solution{
public:
    
    bool safe(vector<vector<int>> &v, int n, int x, int y)
    {
        for(int i=y;i>=0;i--)
        {
            if(v[x][i]==1) return false;
        }
        int i=x,j=y;
        while(i>=0 && j>=0)
        {
            if(v[i][j]==1) return false;
            i--;
            j--;
        }
        i=x,j=y;
        while(j>=0 && i<=n-1)
        {
            if(v[i][j]==1)  return false;
            i++;
            j--;
        }
        return true;
    }
    
    
    void allPlaced(vector<vector<int>> &ans,vector<vector<int>> &v,int n,int col)
    {
        if(col>=n)
        {
            vector<int> temp(n);
            for(int y=0;y<n;y++)
            {
                for(int x=0;x<n;x++)
                {
                    if(v[x][y]==1)
                    {
                        temp[y]=x+1;
                    }
                }
            }
            ans.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            if(safe(v,n,i,col))
            {
                v[i][col]=1;
                allPlaced(ans,v,n,col+1);
                v[i][col]=0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> v(n,vector<int>(n));
            v[i][0]=1;
            allPlaced(ans,v,n,1);
            v[i][0]=0;
        }
        return ans;
    }
};