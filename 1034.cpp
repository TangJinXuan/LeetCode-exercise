1034. 边界着色
给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color 。网格中的每个值表示该位置处的网格块的颜色。

当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一 连通分量 。

连通分量的边界 是指连通分量中的所有与不在分量中的网格块相邻（四个方向上）的所有网格块，或者在网格的边界上（第一行/列或最后一行/列）的所有网格块。

请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色，并返回最终的网格 grid 。
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                visited[i][j]=0;
            }
        }
        int currentColor=grid[row][col];
        queue<pair<int,int>> task;
        task.push(make_pair(row,col));
        // cout<<"test";
        visited[row][col]=1;
        while(!task.empty())
        {
            pair<int,int> current=task.front();
            task.pop();
            int row1=current.first;
            int col1=current.second;
            // cout<<row1<<" "<<col1<<endl;
            int count(0);
            grid[row1][col1]=color;
            if(row1<m-1)
            {
                if(visited[row1+1][col1]==1)
                    ++count;
                else if(grid[row1+1][col1]==currentColor)
                {
                    ++count;
                    if(visited[row1+1][col1]==0)
                    {
                        visited[row1+1][col1]=1;
                        task.push(make_pair(row1+1,col1));
                        // grid[row1+1][col1]=color;
                    }
                }
            }
            if(row1>0)
            {
                if(visited[row1-1][col1]==1)
                    ++count;
                else if(grid[row1-1][col1]==currentColor)
                {
                    ++count;
                    if(visited[row1-1][col1]==0)
                    {
                        visited[row1-1][col1]=1;
                        task.push(make_pair(row1-1,col1));
                        // grid[row1-1][col1]=color;
                    }
                }
            }
            if(col1<n-1)
            {
                if(visited[row1][col1+1]==1)
                    ++count;
                else if(grid[row1][col1+1]==currentColor)
                {
                    ++count;
                    if(visited[row1][col1+1]==0)
                    {
                        visited[row1][col1+1]=1;
                        task.push(make_pair(row1,col1+1));
                        // grid[row1][col1+1]=color;
                    }
                }
            }
            if(col1>0)
            {
                if(visited[row1][col1-1]==1)
                    ++count;
                else if(grid[row1][col1-1]==currentColor)
                {
                    ++count;
                    if(visited[row1][col1-1]==0)
                    {
                        visited[row1][col1-1]=1;
                        task.push(make_pair(row1,col1-1));
                        // grid[row1][col1-1]=color;
                    }
                }
            }
            // cout<<count<<endl;
            if(count==4)
            {
                grid[row1][col1]=currentColor;
                // cout<<grid[row1][col1]<<endl;
            }
        }
        return grid;
    }
};