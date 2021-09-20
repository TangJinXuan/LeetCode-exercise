// 162. 寻找峰值
// 峰值元素是指其值严格大于左右相邻值的元素。

// 给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

// 你可以假设 nums[-1] = nums[n] = -∞ 。

// 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

class Solution {
public:
    static int searchHigh(vector<int>& nums,int left,int right)
    {
        int mid=(left+right)/2;
        if(mid==0)
        {
            if(nums[mid]>nums[mid+1])
                return mid;
            else
                return searchHigh(nums,mid,right);
        }
        if(mid==nums.size()-1)
        {
            if(nums[mid]>nums[mid-1])
                return mid;
            else
                return searchHigh(nums,mid,right);
        }
        if(nums[mid-1]>nums[mid])
            return searchHigh(nums,left,mid);
        else if(nums[mid+1]<nums[mid])
            return mid;
        else
            return searchHigh(nums,mid,right);
        
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int left=-1;
        int right=n;
        if(n<2)
            return 0;
        // while(left<right)
        // {
        //     if(nums[mid-1]>nums[mid])
        //     {
        //         right=mid;
        //         mid=(left+right)/2;
        //     }    
        //     else if(nums)
        // }
        // for(int i=1;i<nums.size()-1;++i)
        // {
        //     if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
        //         return i;
        // }
        return searchHigh(nums,left,right);
    }
};