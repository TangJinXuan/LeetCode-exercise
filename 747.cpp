747. 至少是其他数字两倍的最大数
给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。

请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。

 
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int firstMax(-1),secondMax(-1),res(-1);
        for(int i=0;i<nums.size();++i)
        {
            int tempCom=nums[i];
            if(tempCom>firstMax)
            {
                int temp=firstMax;
                firstMax=tempCom;
                res=i;
                tempCom=temp;
            }
            if(tempCom>secondMax)
            {
                secondMax=tempCom;
            }
        }
        if(firstMax>=secondMax*2)
            return res;
        return -1;
    }
};