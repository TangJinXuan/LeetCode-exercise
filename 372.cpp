372. 超级次方
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a=a%1337;
        int resFinal(1);
        int index(a);
        for(int i=b.size()-1;i>=0;--i)
        {
            int res(1);
            for(int j=0;j<b[i];++j)
            {
                res=(res*index)%1337;
            }
            resFinal=(resFinal*res)%1337;
            for(int j=b[i];j<10;++j)
            {
                res=(res*index)%1337;
            }
            index=res;
        }
        return resFinal;
    }
};