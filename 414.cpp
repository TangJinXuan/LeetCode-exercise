414. 第三大的数
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // if(nums.size()<3)
        // {
        //     if(nums.size()<2)
        //         return nums[0];
        //     else
        //         return nums[1]>nums[0]?nums[1]:nums[0];
        // }
        // priority_queue<int,vector<int>,greater<int> > small_heap;
        // for(int i=0;i<3;++i)
        //     small_heap.push(nums[i]);
        // for(int i=3;i<nums.size();++i)
        // {
        //     cout<<small_heap.top()<<small_heap.size()<<endl;
        //     if(small_heap.top()<nums[i])
        //     {
        //         small_heap.pop();
        //         small_heap.push(nums[i]);
        //     }
        // }
        // return small_heap.top();
        int *a = nullptr, *b = nullptr, *c = nullptr;
        for (int &num : nums) {
            if (a == nullptr || num > *a) {
                c = b;
                b = a;
                a = &num;
            } else if (*a > num && (b == nullptr || num > *b)) {
                c = b;
                b = &num;
            } else if (b != nullptr && *b > num && (c == nullptr || num > *c)) {
                c = &num;
            }
        }
        return c == nullptr ? *a : *c;

    }
};