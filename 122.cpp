122. 买卖股票的最佳时机 II
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int> dpmin(prices.size());
        // vector<int> dpmax(prices.size());
        // dpmin[0]=prices[0];
        // dpmax[prices.size()-1]=prices[prices.size()-1];
        // for(int i=1;i<prices.size();++i)
        // {
        //     dpmin[i]=min(dpmin[i-1],prices[i]);
        //     dpmax[prices.size()-1-i]=max(dpmax[prices.size()-i],prices[prices.size()-1-i]);
        // }
        // int res(0);
        // for(int i=0;i<prices.size();++i)
        // {
        //     res=max(res,dpmax[i]-dpmin[i]);
        // }
        // return res;
        int res(0);
        for(int i=1;i<prices.size();++i)
        {
            if(prices[i]-prices[i-1]>0)
                res+=(prices[i]-prices[i-1]);
        }
        return res;
    }
};