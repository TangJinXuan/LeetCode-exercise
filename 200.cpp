200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> island;
        int res(0);
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]=='1')
                {
                    island.push(make_pair(i,j));
                    grid[i][j]='0';
                    ++res;
                }
                while(!island.empty())
                {
                    pair<int,int> temp=island.front();
                    island.pop();
                    int row=temp.first;
                    int col=temp.second;
                    // cout<<row<<" "<<col<<endl;
                    if(row>0)
                        if(grid[row-1][col]=='1')
                        {
                            island.push(make_pair(row-1,col));
                            grid[row-1][col]='0';
                        }
                    if(row<grid.size()-1)
                        if(grid[row+1][col]=='1')
                        {
                            island.push(make_pair(row+1,col));
                            grid[row+1][col]='0';
                        }
                    if(col>0)
                        if(grid[row][col-1]=='1')
                        {
                            island.push(make_pair(row,col-1));
                            grid[row][col-1]='0';
                        }
                    if(col<grid[0].size()-1)
                        if(grid[row][col+1]=='1')
                        {
                            island.push(make_pair(row,col+1));
                            grid[row][col+1]='0';
                        }
                }
            }
        }
        return res;
    }
};