406. 根据身高重建队列
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

 
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]))
                return true;
            return false;
        });
        vector<vector<int>> res;
        for(auto i:people)
        {
            if(i[1]>=res.size())
                res.push_back(i);
            else 
                res.insert(res.begin()+i[1], i);
        }
        // cout<<people[0][1];
        return res;
    }
};