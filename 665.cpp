665. 非递减数列
给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

 
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int temp(-1);
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]>nums[i+1])
            {
                if(temp==-1)
                {
                    temp=i;
                    if(i==0||nums[i-1]<=nums[i+1])
                        continue;
                    else if(i==nums.size()-2||nums[i]<=nums[i+2])
                        continue;
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return true;
    }
};