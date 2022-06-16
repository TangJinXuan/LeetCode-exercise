435. 无重叠区间
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
class Solution {
public:
    static bool compare(const vector<int> &a,const vector<int>&b)
    {
        if(a[1]<b[1])
            return true;
        else
            return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int right(intervals[0][1]);
        int res(0);
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0]<right)
            {
                ++res;
            }
            else
            {
                right=intervals[i][1];
            }
        }
        return res;
    }
};