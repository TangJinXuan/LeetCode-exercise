56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> beginTime;
        vector<int> endTime;
        for(int i=0;i<n;++i)
        {
            beginTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
        }
        sort(beginTime.begin(),beginTime.end());
        sort(endTime.begin(),endTime.end());
        int beginIndex(0),endIndex(0);
        vector<vector<int>> res;
        for(int i=0;i<n;++i)
        {
            int currentTime(beginTime[i]);
            // cout<<currentTime<<endl;
            while(currentTime>endTime[endIndex])
            {
                // cout<<endIndex<<" "<<endTime[endIndex]<<endl;
                if(endIndex==i-1)
                {
                    vector<int> tempRes;
                    tempRes.push_back(beginTime[beginIndex]);
                    tempRes.push_back(endTime[endIndex]);
                    res.push_back(tempRes);
                    beginIndex=i;
                    break;
                }
                else
                {
                    ++endIndex;
                }
            }
        }
        vector<int> tempRes;
        tempRes.push_back(beginTime[beginIndex]);
        tempRes.push_back(endTime[n-1]);
        res.push_back(tempRes);
        return res;
    }
};