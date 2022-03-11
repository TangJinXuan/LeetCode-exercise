8. 字符串转换整数 (atoi)
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
class Solution {
public:
    int myAtoi(string s) {
        int pos(1);
        // cout<<INT_MIN;
        int res(0);
        bool judge(true);
        // bool secondJudge(true);
        for(auto i:s)
        {
            if(i=='-'&&judge)
            {
                pos=-1;
                judge=false;
            }
            else if(i=='+'&&judge)
            {
                judge=false;
            }
            else if(i>='0'&&i<='9')
            {
                judge=false;
                int temp=i-'0';
                if(pos==1)
                {
                    if(INT_MAX/10<res)
                        return INT_MAX;
                    else if(INT_MAX/10==res&&INT_MAX%10<=temp)
                        return INT_MAX;
                    else
                        res=res*10+temp;
                }
                else
                {
                    // cout<<res<<endl;
                    if(INT_MIN/10>(-1)*res)
                        return INT_MIN;
                    else if(INT_MIN/10==res*(-1)&&INT_MIN%10>=temp*(-1))
                        return INT_MIN;
                    else
                        res=res*10+temp;
                }
            }
            else if(i!=' ')
                break;
            else
            {
                if(!judge)
                    break;
            }
        }
        return res*pos;
    }
};