// 面试题 17.14. 最小K个数
// 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
// 实际上这里应该用最大堆较好，另外模仿快速排序可实现O(n)
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res(arr.begin(),arr.begin()+k);
        return res;
    }
};
