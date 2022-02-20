1647. 字符频次唯一的最小删除次数
如果字符串 s 中 不存在 两个不同字符 频次 相同的情况，就称 s 是 优质字符串 。

给你一个字符串 s，返回使 s 成为 优质字符串 需要删除的 最小 字符数。

字符串中字符的 频次 是该字符在字符串中的出现次数。例如，在字符串 "aab" 中，'a' 的频次是 2，而 'b' 的频次是 1 。
class Solution {
public:
    int minDeletions(string s) {
        int charMap[26]={0};
        for(auto i:s)
            charMap[i-'a']++;
        unordered_map<int,int> freqChar;
        for(int i=0;i<26;++i)
        {
            if(charMap[i]!=0)
                freqChar[charMap[i]]++;
        }
        int res(0);
        for(auto i=freqChar.begin();i!=freqChar.end();++i)
        {
            if(i->second>1)
            {
                int num=i->second-1;
                freqChar[i->first]=1;
                int freq=i->first;
                for(int j=0;j<num;++j)
                {
                    while(freqChar.find(freq) != freqChar.end()&&freq>0)
                    {
                        --freq;
                    }
                    if(freq==0)
                        res=res+i->first-freq;
                    else
                    {
                        freqChar[freq]=1;
                        res=res+i->first-freq;
                    }
                }
            }
        }
        return res;
    }
};