260. 只出现一次的数字 III
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 

进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> numMap;
        for(auto i:nums)
        {
            if(numMap.find(i)==numMap.end())
                numMap[i]=1;
            else
                numMap[i]=2;
        }
        vector<int>res;
        for(auto i=numMap.begin();i!=numMap.end();++i)
        {
            if(i->second==1)
                res.push_back(i->first);
        }
        return res;
    }
};