54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int turnNum=min(m/2,n/2);
        vector<int> res;
        for(int i=0;i<turnNum;++i)
        {
            for(int j=i;j<n-i;++j)
            {
                res.push_back(matrix[i][j]);
            }
            for(int j=i+1;j<m-i;++j)
            {
                res.push_back(matrix[j][n-i-1]);
            }
            for(int j=n-i-2;j>=i;--j)
            {
                res.push_back(matrix[m-i-1][j]);
            }
            for(int j=m-i-2;j>i;--j)
            {
                res.push_back(matrix[j][i]);
            }
        }
        int leftNum=m*n-res.size();
        cout<<leftNum;
        if(leftNum>n-2*turnNum)
        {
            for(int j=turnNum;j<n-turnNum;++j)
            {
                res.push_back(matrix[turnNum][j]);
            }
            leftNum=leftNum-n+2*turnNum;
        }
        else
        {
            for(int j=turnNum;j<turnNum+leftNum;++j)
            {
                res.push_back(matrix[turnNum][j]);
            }
            return res;
        }
        if(leftNum>m-2*turnNum-1)
        {
            for(int j=turnNum+1;j<m-turnNum;++j)
            {
                res.push_back(matrix[j][n-turnNum-1]);
            }
            leftNum=leftNum-m+2*turnNum+1;
        }
        else
        {
            for(int j=turnNum+1;j<turnNum+1+leftNum;++j)
            {
                res.push_back(matrix[j][n-turnNum-1]);
            }
            return res;
        }
        if(leftNum>n-2*turnNum-1)
        {
            for(int j=n-turnNum-2;j>=turnNum;--j)
            {
                res.push_back(matrix[m-turnNum-1][j]);
            }
            leftNum=leftNum-n+2*turnNum+1;
        }
        else
        {
            for(int j=n-turnNum-2;j>n-turnNum-leftNum-2;--j)
            {
                res.push_back(matrix[m-turnNum-1][j]);
            }
            return res;
        }
        for(int j=m-turnNum-2;j>=m-turnNum-2-leftNum;--j)
        {
            res.push_back(matrix[j][turnNum]);
        }
        return res;
    }
};