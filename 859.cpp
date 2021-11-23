859. 亲密字符串
给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。

交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。

例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        unordered_map<char,int> charMap;
        int left(-1),right(-1);
        for(int i=0;i<s.size();++i)
        {
            charMap[s[i]]++;
            if(s[i]!=goal[i])
            {
                if(left==-1)
                    left=i;
                else if(right==-1)
                {
                    if(s[i]==goal[left]&&s[left]==goal[i])
                    {
                        right=i;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                    return false;
            }
        }
        if(right==-1&&left!=-1)
            return false;
        if(left==right)
        {
            for(auto i=charMap.begin();i!=charMap.end();++i)
            {
                if(i->second>1)
                    return true;
            }
            return false;
        }
        return true;
    }
};