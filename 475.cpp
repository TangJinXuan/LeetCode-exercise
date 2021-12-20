475. 供暖器
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int index(0);
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int left(heaters[0]),right(heaters[0]);
        // int maxright=heaters[-1];
        int res(0);
        // int ans = 0;
        // for (int i = 0, j = 0; i < houses.size(); i++) {
        //     int curDistance = abs(houses[i] - heaters[j]);
        //     while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
        //         j++;
        //         curDistance = min(curDistance, abs(houses[i] - heaters[j]));
        //     }
        //     ans = max(ans, curDistance);
        //     cout<<ans<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<houses.size();++i)
        {
            // cout<<left<<" "<<right<<" "<<houses[i]<<" ";
            if(houses[i]<=left)
            {
                int dis=abs(left-houses[i]);
                // cout<<dis<<" ";
                res=max(res,left-houses[i]);
            }
            else if(houses[i]<right)
            {
                int temp=min(abs(right-houses[i]),abs(houses[i]-left));
                res=max(res,temp);
            }
            else
            {
                if(index<heaters.size()-1)
                {
                    while(index<heaters.size()-1&&heaters[index]<=houses[i])
                    {
                        ++index;
                        left=right;
                        right=heaters[index];
                    }
                    int temp=min(abs(right-houses[i]),abs(houses[i]-left));
                    res=max(res,temp);
                }
                else
                {
                    left=right;
                    res=max(res,abs(houses[i]-right));
                }
            }
            // cout<<res<<" "<<endl;
        }
        cout<<endl;
        return res;
    }
};