43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

 
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int addPlus;
        string res="";
        int tempMul=(num1[num1.size()-1]-'0')*(num2[num2.size()-1]-'0');
        addPlus=tempMul/10;
        res=res+char(tempMul%10+'0');
        while(addPlus!=-1)
        {
            int tempRes=addPlus;
            int countSum=res.size();
            int i(0),j(countSum-i);
            if(j>=num2.size())
            {
                j=num2.size()-1;
                i=countSum-j;
            }
            if(i>=num1.size())
                break;
            while(i<=countSum&&i<num1.size()&&j>=0)
            {
                int tempMul=(num1[num1.size()-1-i]-'0')*(num2[num2.size()-1-j]-'0');
                // cout<<i<<" "<<j<<" "<<tempMul<<endl;
                tempRes+=tempMul;
                ++i;
                --j;
            }
            // cout<<i<<j<<" ";
            // cout<<addPlus<<" ";
            // cout<<tempRes<<endl;
            addPlus=tempRes/10;
            // if(i==num1.size()-1&&j==num2.size()-1)
            //     addPlus=-1;
            res=char(tempRes%10+'0')+res;
        }
        if(addPlus!=0)
            res=char(addPlus%10+'0')+res;
        return res;
    }
};