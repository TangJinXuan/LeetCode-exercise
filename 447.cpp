// 447. 回旋镖的数量
// 给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组 ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

// 返回平面上所有回旋镖的数量。

 
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int num=points.size();
        // cout<<num<<endl<<endl;
        int res(0);
        // vector<vector<double>> dis(num,vector<double>(num));
        for(int i=0;i<num;++i)
        {
            vector<double> disdic;
            vector<int> disnum;
            for(int j=0;j<num;++j)
            {
                double dis=sqrt(pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2));
                // cout<<points[i][0]-points[j][0]<<" "<<points[i][1]-points[j][1]<<" "<<dis<<endl;
                // if(dis==0.0)
                //     continue;
                vector<double>::iterator iter=find(disdic.begin(),disdic.end(),dis);
                if (iter==disdic.end())
                {
                    disdic.push_back(dis);
                    disnum.push_back(1);
                }
                else
                {
                    disnum[iter-disdic.begin()]++;
                }
            }
            for(int j=0;j<disnum.size();++j)
            {
                res=res+disnum[j]*(disnum[j]-1);
                // cout<<disnum[j]<<" "<<disdic[j]<<endl;
            }
        }
        return res;
    }
};