// 36. 有效的数独
// 请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
// 数独部分空格内已填入了数字，空白格用 '.' 表示。

// 注意：

// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int* count=new int[9];
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                count[j]=0;
            }
            for(int j=0;j<9;++j)
            {
                // cout<<board[i][j]<<" ";
                if(board[i][j]=='.')
                    continue;
                // cout<<board[i][j]-'0'<<" "<<board[i][j]<<endl;
                if(count[board[i][j]-'1']==0)
                    count[board[i][j]-'1']=1;
                else
                    return false;
            }
            // cout<<endl;
        }
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                count[j]=0;
            }
            for(int j=0;j<9;++j)
            {
                // cout<<board[j][i]<<" ";
                if(board[j][i]=='.')
                    continue;
                if(count[board[j][i]-'1']==0)
                    count[board[j][i]-'1']=1;
                else
                    return false;
            }
        }
        for(int xm=0;xm<3;++xm)
        {
            for(int ym=0;ym<3;++ym)
            {
                for(int j=0;j<9;++j)
                {
                    count[j]=0;
                }
                for(int i=0;i<3;++i)
                {
                    for(int j=0;j<3;++j)
                    {
                        // cout<<board[i][j]<<" ";
                        if(board[i+xm*3][j+ym*3]=='.')
                            continue;
                        if(count[board[i+xm*3][j+ym*3]-'1']==0)
                            count[board[i+xm*3][j+ym*3]-'1']=1;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};