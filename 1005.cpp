1005. K 次取反后最大化的数组和
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

 
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res=accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>> kmin;
        for(int i=0;i<k;++i)
        {
            if(i==nums.size())
                break;
            kmin.push(nums[i]);
            // cout<<nums[i]<<endl;
        }
        for(int i=0;i<k;++i)
        {
            int tempMin=-1*kmin.top();
            // cout<<tempMin<<endl;
            kmin.pop();
            // cout<<kmin.top()<<endl;
            kmin.push(tempMin);
            res=res+tempMin*2;
        }
        return res;
    }
};