LCP 18. 早餐组合
小扣在秋日市集选择了一家早餐摊位，一维整型数组 staple 中记录了每种主食的价格，一维整型数组 drinks 中记录了每种饮料的价格。小扣的计划选择一份主食和一款饮料，且花费不超过 x 元。请返回小扣共有多少种购买方案。

注意：答案需要以 1e9 + 7 (1000000007) 为底取模，如：计算初始结果为：1000000008，请返回 1

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(),staple.end());
        sort(drinks.begin(),drinks.end());
        int res(0);
        int i(0),j(drinks.size()-1);
        while(i<staple.size()&&j>=0)
        {
            if(staple[i]+drinks[j]<=x)
            {
                i++;
                res=(res+j+1)%(1000000007);
            }
            else
                --j;
        }
        return res;
    }
};