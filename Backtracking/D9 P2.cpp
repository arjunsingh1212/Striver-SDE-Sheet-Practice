/* https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1 */

pair<bool,pair<int,int>> zeroPresent(int grid[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==0) return {true,{i,j}};
        }
    }
    return {false,{-1,-1}};
}
bool isSafe(int grid[N][N], int x, int y, int v)
{
    for(int i=0;i<N;i++)
    {
        if(grid[i][y]==v) return false;
        if(grid[x][i]==v) return false;
    }
    int box_row_start=x-x%3;
    int box_row_end=box_row_start+2;
    int box_col_start=y-y%3;
    int box_col_end=box_col_start+2;
   
    for(int i=box_row_start;i<=box_row_end;i++)
    {
        for(int j=box_col_start;j<=box_col_end;j++)
        {
            if(grid[i][j]==v) return false;
        }
    }
    return true;
}
bool SolveSudoku(int grid[N][N])  
{ 
    // Your code here
    pair<bool,pair<int,int>> temp=zeroPresent(grid);
    if(temp.first==false) return true;
    int x,y;
    x=temp.second.first;
    y=temp.second.second;
    
    for(int v=1;v<10;v++)
    {
        if(!isSafe(grid,x,y,v)) continue;
        grid[x][y]=v;
        if(SolveSudoku(grid)) return true;
        grid[x][y]=0;
    }
    
    return false;
}

void printGrid (int grid[N][N]) 
{
    // Your code here 
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" ";
        }
    }
}