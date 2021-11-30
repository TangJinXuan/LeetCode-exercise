1446. 连续字符
给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。

 
class Solution {
public:
    int maxPower(string s) {
        int res(0);
        char countChar=s[0];
        int countNum(0);
        for(auto i:s)
        {
            if(i==countChar)
                ++countNum;
            else
            {
                if(res<countNum)
                    res=countNum;
                countNum=1;
                countChar=i;
            }
        }
        if(res<countNum)
            res=countNum;
        return res;
    }
};