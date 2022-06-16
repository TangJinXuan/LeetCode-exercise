890. 查找和替换模式
你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto i:words)
        {
            char visited[26];
            char cmap[26];
            bool judge=true;
            for(int j=0;j<26;++j)
            {
                visited[j]='0';
                cmap[j]='0';
            }
            for(int j=0;j<pattern.size();++j)
            {
                if(cmap[pattern[j]-'a']=='0'&&visited[i[j]-'a']=='0')
                {
                    cmap[pattern[j]-'a']=i[j];
                    visited[i[j]-'a']='1';
                }
                else if(cmap[pattern[j]-'a']=='0'&&visited[i[j]-'a']=='1')
                {
                    judge=false;
                    break;
                }
                else if(cmap[pattern[j]-'a']!=i[j])
                {
                    judge=false;
                    break;
                }
            }
            if(judge)
                res.push_back(i);
        }
        return res;
    }
};