// 1636. 按照频率将数组升序排序
// 给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。 

// 请你返回排序后的数组。

 
typedef pair<int, int> PAIR;

class Solution {
public:
    static bool cmp(const PAIR& a,const PAIR& b)
    {
        if(a.second==b.second)
            return a.first>b.first;
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();++i)
        {
            m[nums[i]]++;
        }
        vector<PAIR> vec(m.begin(), m.end());
        sort(vec.begin(),vec.end(),cmp);
        vector<int> res;
        for(auto i:vec)
        {
            for(int j=0;j<i.second;++j)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};