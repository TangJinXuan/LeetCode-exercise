268. 丢失的数字
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> numMap;
        for(int i:nums)
        {
            numMap[i]=1;
        }
        int i(0);
        while(true)
        {
            if(numMap[i]==0)
                return i;
            ++i;
        }
        return i;
    }
};