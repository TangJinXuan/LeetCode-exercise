334. 递增的三元子序列
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left(nums[0]),right(nums[nums.size()-1]);
        int n=nums.size();
        int leftEle[n];
        int rightEle[n];
        leftEle[0]=left;
        rightEle[n-1]=right;
        for(int i=1;i<n-1;++i)
        {
            if(left>nums[i])
            {
                left=nums[i];
            }
            leftEle[i]=left;
        }
        for(int i=n-2;i>=0;--i)
        {
            if(right<nums[i])
            {
                right=nums[i];
            }
            rightEle[i]=right;
        }
        for(int i=1;i<n-1;++i)
        {
            if(leftEle[i-1]<nums[i]&&rightEle[i+1]>nums[i])
                return true;
        }
        return false;
    }
};