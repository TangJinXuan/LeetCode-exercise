1576. 替换所有的问号
给你一个仅包含小写英文字母和 '?' 字符的字符串 s，请你将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复 的字符。

注意：你 不能 修改非 '?' 字符。

题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符。

在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。

 
class Solution {
public:
    string modifyString(string s) {
        if(s[0]=='?')
        {
            if(s.size()>1)
            {
                if(s[1]=='a')
                    s[0]='b';
                else
                    s[0]='a';
            }
            else
                s[0]='a';
        }
        for(int i=1;i<s.size()-1;++i)
        {
            if(s[i]=='?')
            {
                if(s[i-1]=='a')
                {
                    if(s[i+1]=='b')
                    {
                        s[i]='c';
                    }
                    else
                    {
                        s[i]='b';
                    }
                }
                else
                {
                    if(s[i+1]=='a')
                    {
                        if(s[i-1]=='b')
                            s[i]='c';
                        else
                            s[i]='b';
                    }
                    else
                    {
                        s[i]='a';
                    }
                }
            }
        }
        if(s[s.size()-1]=='?')
        {
            if(s.size()>1)
            {
                if(s[s.size()-2]=='a')
                    s[s.size()-1]='b';
                else
                    s[s.size()-1]='a';
            }
            else
                s[s.size()-1]='a';
        }
        return s;
    }
};