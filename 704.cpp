// 704. 二分查找
// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left(0),right(nums.size()-1);
        if(nums.size()==0)
            return -1;
        else if(nums.size()==1)
            if(nums[0]==target)
                return 0;
            else 
                return -1;
        // else if(nums.size()==2)
        //     if(nums[0]==target)
        //         return 0;
        //     else if(nums[1]==target)
        //         return 1;
        //     else 
        //         return -1;
        while(left+1<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<target)
                left=mid;
            else if(nums[mid]>target)
                right=mid;
            else
                return mid;
        }
        if(left+1==right)
            if(nums[right]==target)
                return right;
            else if(nums[left]==target)
                return left;
            else
                return -1;
        return -1;
    }
};