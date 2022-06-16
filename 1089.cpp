1089. 复写零
给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int left(0),right(0);
        vector<int>res(arr.size());
        while(right<arr.size())
        {
            if(arr[left]==0)
            {
                res[right]=arr[left];
                if(right+1<arr.size())
                    res[right+1]=arr[left];
                right+=2;
            }
            else
            {
                res[right]=arr[left];
                right++;
            }
            ++left;
        }
        for(int i=0;i<arr.size();++i)
        {
            arr[i]=res[i];
        }
    }
};