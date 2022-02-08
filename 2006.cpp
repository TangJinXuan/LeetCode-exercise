2006. 差的绝对值为 K 的数对数目
给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> numMap;
        for(auto i:nums)
        {
            numMap[i]++;
        }
        int res(0);
        for(auto i=numMap.begin();i!=numMap.end();++i)
        {
            int temp=i->first;
            // cout<<i->first<<" "<<i->second<<endl;
            // res=res+i->second*numMap[temp+k];
            if(numMap.find(temp+k)!=numMap.end())
                res=res+numMap[temp+k]*i->second;
        }
        return res;
    }
};