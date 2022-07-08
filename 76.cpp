76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

class Solution {
public:
    bool judgeWindow(int(&a)[52],int(&b)[52])
    {
        for(int i=0;i<52;++i)
        {
            // cout<<
            if(a[i]<b[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int charnum[52]={0};
        int targetnum[52]={0};
        for(auto i:t)
        {
            if(i>='a'&&i<='z')
            {
                targetnum[i-'a']++;
            }
            else
            {
                targetnum[i-'A'+26]++;
            }
        }
        int left(0),right(0);
        int resl(-1),resr(s.size());
        while(right<s.size()){
            if(s[right]>='a'&&s[right]<='z')
            {
                charnum[s[right]-'a']++;
            }
            else
            {
                charnum[s[right]-'A'+26]++;
            }
            while(judgeWindow(charnum, targetnum)){
                if(s[left]>='a'&&s[left]<='z')
                {
                    charnum[s[left]-'a']--;
                }
                else
                {
                    charnum[s[left]-'A'+26]--;
                }
                ++left;
                if(resr-resl>right-left)
                {
                    resr=right;
                    resl=left;
                }
            }
            ++right;
        }
        // cout<<resl<<" "<<resr;
        if(resl==-1)
            return "";
        return s.substr(resl-1,resr-resl+2);
    }
};