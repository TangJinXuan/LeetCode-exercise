29. 两数相除
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)
            return INT_MAX;
        int sign=1;
        if(dividend>0^divisor>0)
            sign=-1;
        long long dividendNow=(long long)abs(dividend);
        divisor=abs(divisor);
        vector<long long>divisorArray;
        long long divisorNow(divisor);
        while(dividendNow>=divisorNow)
        {
            divisorArray.push_back(divisorNow);
            divisorNow+=divisorNow;
        }
        int res(0);
        while(!divisorArray.empty())
        {
            divisorNow=divisorArray.back();
            divisorArray.pop_back();
            // cout<<divisorNow<<" "<<dividend<<endl;
            if(divisorNow<=dividendNow)
            {
                if(sign==1)
                    res=res+res+1;
                else
                    res=res+res-1;
                dividendNow=dividendNow-divisorNow;
            }
            else
                res=res+res;
        }
        return res;
    }
};