135. 分发糖果
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

 
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size());
        candy[0]=1;
        int downStep(0);
        for(int i=1;i<ratings.size();++i)
        {
            if(ratings[i-1]<ratings[i])
            {
                candy[i]=candy[i-1]+1;
            }
            else
            {
                candy[i]=1;
            }
        }
        
        for(int i=1;i<ratings.size();++i)
        {
            if(ratings[ratings.size()-1-i]>ratings[ratings.size()-i])
            {
                candy[ratings.size()-1-i]=max(candy[ratings.size()-1-i],candy[ratings.size()-i]+1);
            }
        }
        int res(0);
        for(auto i:candy)
        {
            res+=i;
        }
        return res;
    }
};