540. 有序数组中的单一元素
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left(0),right(nums.size()-1);
        while(left<right)
        {
            int mid=(left+right)/2;
            if(mid%2!=0)
            {
                if(nums[mid-1]==nums[mid])
                    left=mid+1;
                else
                    right=mid-2;
            }
            else
            {
                if(nums[mid+1]!=nums[mid])
                    right=mid-1;
                else
                    left=mid+2;
            }
            // cout<<mid<<" "<<nums[mid]<<endl;
        }
        return nums[left];
    }
};