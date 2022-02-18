1984. 学生分数的最小差值
给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分数。另给你一个整数 k 。

从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值 达到 最小化 。

返回可能的 最小差值 。

 
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res(INT_MAX);
        for(int i=0;i+k-1<nums.size();++i)
        {
            res=min(res,nums[i+k-1]-nums[i]);
        }
        return res;
    }
};