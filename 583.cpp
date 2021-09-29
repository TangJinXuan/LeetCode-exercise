// 583. 两个字符串的删除操作
// 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i=0;i<=m;++i)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=n;++j)
        {
            dp[0][j]=j;
        }
        // cout<<"test";
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                // cout<<dp[i][j]<<" ";
            }
            //  cout<<endl;
        }
        // for(int i=0;i<=m;++i)
        // {
        //     for(int j=0;j<=n;++j)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
    }
};