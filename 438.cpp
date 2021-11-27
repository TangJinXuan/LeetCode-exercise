438. 找到字符串中所有字母异位词
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        int chMap[26];
        int diff(0);
        vector<int> res;
        for(int i=0;i<26;++i)
            chMap[i]=0;
        for(auto i:p)
            chMap[i-'a']++;
        for(int i=0;i<p.size();++i)
            chMap[s[i]-'a']--;
        for(int i=0;i<26;++i)
            if(chMap[i]!=0)
                diff=diff+abs(chMap[i]);
        if(diff==0)
            res.push_back(0);
        for(int i=p.size();i<s.size();++i)
        {
            if(chMap[s[i]-'a']>0)
            {
                diff--;
            }
            else
            {
                diff++;
            }
            chMap[s[i]-'a']--;
            if(chMap[s[i-p.size()]-'a']>=0)
            {
                diff++;
            }
            else
            {
                diff--;
            }
            chMap[s[i-p.size()]-'a']++;
            // for(int i=0;i<6;++i)
            //     cout<<chMap[i]<<" ";
            // cout<<diff<<endl;
            if(diff==0)
                res.push_back(i-p.size()+1);
        }
        return res;
    }
};