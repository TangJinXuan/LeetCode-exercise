给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 Solution class:

Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果
 

class Solution {
private:
    vector<int> numbs;
    vector<int> rands;
public:
    Solution(vector<int>& nums) {
        numbs=nums;
        rands=nums;
    }
    
    vector<int> reset() {
        // rands=numbs;
        return numbs;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < rands.size(); ++i) {
            int j = i + rand() % (rands.size() - i);
            swap(rands[i], rands[j]);
        }
        return rands;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */