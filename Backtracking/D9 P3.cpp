/* https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1 */

bool safe(bool graph[101][101], int V, vector<int> &colors, int v, int m)
{
    if(v==V) return true;
    int i=1;
    while(1)
    {
        if(i==m+1) return false;
        int flag=0;
        for(int neigh=0;neigh<=V;neigh++)
        {
            if(graph[v][neigh]==1 && colors[neigh]==i) flag=1;
        }
        if(flag==0)
        {
            colors[v]=i;
            if(safe(graph,V,colors,v+1,m)) return true;
            colors[v]=0;
        }
        i++;
    }
}
bool graphColoring(bool graph[101][101], int m, int V) {
    // your code here
    vector<int> colors(V);
    if(safe(graph,V,colors,0,m)) return 1;
    else return 0;
}