166. 分数到小数
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long zhengshu=(long long)numerator/(long long)denominator;
        long long orig=(long long)numerator;
        long long divider=(long long)denominator;
        string res="";
        if(orig==0)
            return "0";
        if((orig<0)^(divider<0))
            res=res+"-";
        // cout<<res<<endl;
        // cout<<labs(zhengshu)<<endl;
        res=res+to_string(labs(zhengshu));
        // cout<<res;
        if(orig%divider==0)
            return res;
        else
            res=res+".";
        vector<int>left;
        vector<int>resNum;
        long long remain=labs(orig%divider);
        divider=labs(divider);
        remain*=10;
        if(remain%divider==0)
        {
            res=res+to_string(remain/divider);
            return res;
        }
        left.push_back(remain%divider);
        resNum.push_back(remain/divider);
        remain=remain%divider;
        bool judge=true;
        while(judge)
        {
            remain*=10;
            int resNow=remain/divider;
            remain=remain%divider;
            // cout<<remain<<" "<<resNow<<endl;
            if(remain!=0)
            {
                for(int i=0;i<left.size();++i)
                {
                    if(left[i]==remain&&resNum[i]==resNow)
                    {
                        for(int j=0;j<i;++j)
                        {
                            res=res+to_string(resNum[j]);
                        }
                        res=res+"(";
                        for(int j=i;j<left.size();++j)
                        {
                            res=res+to_string(resNum[j]);
                        }
                        res=res+")";
                        judge=false;
                        break;
                    }
                }
                left.push_back(remain);
                resNum.push_back(resNow);
            }
            else
            {
                for(int j=0;j<left.size();++j)
                {
                    res=res+to_string(resNum[j]);
                }
                res=res+to_string(resNow);
                judge=false;
            }
            
        }

        return res;
    }
};