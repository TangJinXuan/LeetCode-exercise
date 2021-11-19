594. 最长和谐子序列
和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。

现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。

数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。

 
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> numMap;
        for(auto i:nums)
        {
            numMap[i]++;
        }
        int res(-1);
        int prev(0);
        for(auto i=numMap.begin();i!=numMap.end();++i)
        {
            if(res==-1)
            {
                res=0;
                prev=i->first;
                continue;
            }
            // cout<<i->first<<" "<<prev<<endl;
            if(i->first-1==prev)
            {
                res=max(res,i->second+numMap[prev]);
                // cout<<i->second<<" |||  "<<numMap[prev]<<endl;
            }
            prev=i->first;
        }
        return res;
    }
};