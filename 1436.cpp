1436. 旅行终点站
给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> depart;
        vector<string> dest;
        for(auto i: paths)
        {
            depart.push_back(i[0]);
            dest.push_back(i[1]);
        }
        for(auto i:dest)
        {
            bool judge=true;
            for(auto j:depart)
            {
                if(i==j)
                    judge=false;
            }
            if(judge)
                return i;
        }
        return "";
    }
};