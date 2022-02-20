253. 会议室 II
给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

 
class Solution {
public:
    static bool cmp(vector<int>a, vector<int> b){
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>> conf;
        sort(intervals.begin(),intervals.end(),cmp);
        int res(0);
        for(auto i:intervals)
        {
            int begin(i[0]);
            // cout<<begin<<" ";
            if(!conf.empty())
            {
                // cout<<conf.top();
                while(!conf.empty()&&conf.top()<=begin)
                {
                    conf.pop();
                }
            }
            conf.push(i[1]);
            int sizeNow=conf.size();
            res=max(res,sizeNow);
        }
        return res;
    }
    // 法二
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int nums = intervals.size();
        int start[nums], end[nums], index = 0;
        for (const auto & m : intervals) {
            start[index] = m[0];
            end[index++] = m[1];
        }
        std::sort(start, start + nums);
        std::sort(end,     end + nums);
        int i = 0, j = 0, total = 0;
        while (i < nums) {
            if (start[i] < end[j]) total++;
            else j++;
            i++;
        }
        return total;
    }
};