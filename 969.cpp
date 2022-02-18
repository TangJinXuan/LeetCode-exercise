969. 煎饼排序
给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

一次煎饼翻转的执行过程如下：

选择一个整数 k ，1 <= k <= arr.length
反转子数组 arr[0...k-1]（下标从 0 开始）
例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，得到 arr = [1,2,3,4] 。

以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for(int i=arr.size()-1;i>=0;--i)
        {
            for(int j=i;j>=0;--j)
            {
                if(arr[j]==i+1)
                {
                    res.push_back(j+1);
                    res.push_back(i+1);
                    reverse(arr.begin(),arr.begin()+j+1);
                    // for(auto k:arr)
                    //     cout<<k<<" ";
                    // cout<<endl;
                    reverse(arr.begin(),arr.begin()+i+1);
                    // for(auto k:arr)
                    //     cout<<k<<" ";
                    // cout<<endl;
                    break;
                }
            }
        }
        // for(auto k:arr)
        //     cout<<k<<" ";
        return res;
    }
};