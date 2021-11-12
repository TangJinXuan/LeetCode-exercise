375. 猜数字大小 II
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字。
你来猜我选了哪个数字。
如果你猜到正确的数字，就会 赢得游戏 。
如果你猜错了，那么我会告诉你，我选的数字比你的 更大或者更小 ，并且你需要继续猜数。
每当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会 输掉游戏 。
给你一个特定的数字 n ，返回能够 确保你获胜 的最小现金数，不管我选择那个数字 。

 
class Solution {
public:
    int getMoneyAmount(int n) {
                if(n==1)
            return 0;
        //定义矩阵
        int dp[n+1][n+1];
        //初始化“\”
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=INT_MAX;
            }
        }
        //定义基础值dp[i][i]
        for(int i=0;i<=n;i++){
            dp[i][i]=0;
        }

        //按列来，从第2列开始
        for(int j=2;j<=n;j++){
            //按行来，从下往上
            for(int i=j-1;i>=1;i--){
                //算除了两端的每一个分割点
                for(int k=i+1;k<=j-1;k++){
                    dp[i][j]=min(k+max(dp[i][k-1],dp[k+1][j]),dp[i][j]);
                }
                //算两端
                dp[i][j]=min(dp[i][j],i+dp[i+1][j]);
                dp[i][j]=min(dp[i][j],j+dp[i][j-1]);
            }
        }
        return dp[1][n];
    }
};