219. 存在重复元素 II
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> kMap;
        for(int i=0;i<nums.size();++i)
        {
            cout<<i<<" "<<nums[i]<<endl;
            if(i > k)
                kMap[nums[i-k-1]]--;
            if(kMap[nums[i]]!=0)
                return true;
                // cout<<kMap[nums[i]]<<endl;
            kMap[nums[i]]++;
        }
        return false;
    }
};