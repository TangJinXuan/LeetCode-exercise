1380. 矩阵中的幸运数
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
 
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int rowMax[m],colMax[n];
        for(int i=0;i<m;++i)
        {
            int temp=INT_MAX;
            rowMax[i]=m+1;
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]<temp)
                {
                    temp=matrix[i][j];
                    rowMax[i]=j;
                }
            }
            // cout<<rowMax[i]<<" ";
        }
        // cout<<endl;
        for(int i=0;i<n;++i)
        {
            colMax[i]=0;
            int temp=0;
            for(int j=0;j<m;++j)
            {
                if(matrix[j][i]>temp)
                {
                    temp=matrix[j][i];
                    colMax[i]=j;
                }
            }
            // cout<<colMax[i]<<" ";
        }
        // cout<<"test";
        vector<int> res;
        for(int i=0;i<m;++i)
        {
            // cout<<i<<" ";
            if(colMax[rowMax[i]]==i)
                res.push_back(matrix[i][rowMax[i]]);
        }
        return res;
    }
};