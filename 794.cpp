794. 有效的井字游戏
用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。

该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
class Solution {
public:
    bool judge(int numMap[3][3],int color)
    {
        bool count=false;
        for(int i=0;i<3;++i)
        {
            if(numMap[i][0]==color&&numMap[i][1]==color&&numMap[i][2]==color)
                count=true;
            if(numMap[0][i]==color&&numMap[1][i]==color&&numMap[2][i]==color)
                count=true;
        }
        if(numMap[0][0]==color&&numMap[1][1]==color&&numMap[2][2]==color)
            count=true;
        if(numMap[2][0]==color&&numMap[1][1]==color&&numMap[0][2]==color)
            count=true;
        return count;
    }
    bool validTicTacToe(vector<string>& board) {
        int numMap[3][3];
        int countX(0),countO(0);
        for(auto i=0;i<3;++i)
        {
            for(auto j=0;j<3;++j)
            {
                if(board[i][j]=='X')
                {
                    countX++;
                    numMap[i][j]=1;
                }
                else if(board[i][j]=='O')
                {
                    countO++;
                    numMap[i][j]=0;
                }
                else
                {
                    numMap[i][j]=2;
                }
            }
        }
        if(countX==countO)
        {
            bool resX=judge(numMap,1);
            bool resO=judge(numMap,0);
            // cout<<resX<<resO<<" "<<!resX&&!resO;
            if(resX)
                return false;
            return true;
        }
        if(countX-countO==1)
        {
            bool resX=judge(numMap,1);
            bool resO=judge(numMap,0);
            // cout<<resX<<resO<<" "<<!resX&&!resO;
            if(resO)
                return false;
            return true;
        }
        return false;
    }
};