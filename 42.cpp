42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftdp[n];
        int rightdp[n];
        for(int i=0;i<n;++i)
        {
            // cout<<i<<endl;
            if(i==0)
            {
                rightdp[n-1]=height[n-1];
                leftdp[i]=height[0];
            }
            else
            {
                rightdp[n-i-1]=max(rightdp[n-i],height[n-i-1]);
                leftdp[i]=max(leftdp[i-1],height[i]);
            }
        }
        int res(0);
        for(int i=0;i<n;++i)
        {
            res=res+min(leftdp[i],rightdp[i])-height[i];
        }
        return res;
    }
};