33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k=nums[0];
        int left(0),right(nums.size()-1);
        if(target>k)
        {
            while(left<right)
            {
                int mid=(left+right)/2;
                if(nums[mid]<k)
                {
                    right=mid-1;
                }
                else if(nums[mid]<target)
                {
                    left=mid+1;
                }
                else if(nums[mid]>target)
                {
                    right=mid-1;
                }
                else
                    return mid;
            }
        }
        else if(target<k)
        {
            while(left<right)
            {
                int mid=(left+right)/2;
                // cout<<nums[mid];
                if(nums[mid]>=k)
                {
                    left=mid+1;
                }
                else if(nums[mid]<target)
                {
                    left=mid+1;
                }
                else if(nums[mid]>target)
                {
                    right=mid-1;
                }
                else 
                    return mid;
            }
        }
        else
            return 0;
        // cout<<left<<endl;
        if(nums[left]!=target)
            return -1;
        return left;
    }
};