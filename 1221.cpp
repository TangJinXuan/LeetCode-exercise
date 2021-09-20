// 1221. 分割平衡字符串
// 在一个 平衡字符串 中，'L' 和 'R' 字符的数量是相同的。

// 给你一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。

// 注意：分割得到的每个字符串都必须是平衡字符串。

// 返回可以通过分割得到的平衡字符串的 最大数量 。

 
class Solution {
public:
    int balancedStringSplit(string s) {
        int count(0);
        int res(0);
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='R')
                ++count;
            else
                --count;
            if(count==0)
                ++res;
        }
        return res;
    }
};