391. 完美矩形
给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。

如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
typedef pair<int,int> keypair;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<keypair ,int> recMap;
        int minx=INT_MAX;int miny=INT_MAX;int maxx=INT_MIN;int maxy=INT_MIN;
        int squa(0);
        for(auto i:rectangles)
        {
            minx=min(minx,i[0]);
            miny=min(miny,i[1]);
            maxx=max(maxx,i[2]);
            maxy=max(maxy,i[3]);
            keypair temp1=make_pair(i[0],i[1]);
            keypair temp3=make_pair(i[0],i[3]);
            keypair temp2=make_pair(i[2],i[3]);
            keypair temp4=make_pair(i[2],i[1]);
            recMap[temp1]++;
            recMap[temp2]++;
            recMap[temp3]++;
            recMap[temp4]++;
            squa=squa+(i[2]-i[0])*(i[3]-i[1]);
        }
        vector<keypair> point;
        if((maxx-minx)*(maxy-miny)!=squa)
            return false;
        int count(0);
        for(auto i=recMap.begin();i!=recMap.end();++i)
        {
            cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
            if(i->second==1)
            {
                if(i->first.first==minx||i->first.first==maxx)
                {
                    // cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
                    if(i->first.second==miny||i->first.second==maxy)
                        ++count;
                    else
                        return false;
                }
                else
                    return false;
            }
            else if(i->second!=2&&i->second!=4)
                return false;
        }
        cout<<count<<endl;
        if(count==4)
            return true;
        return false;
    }
};