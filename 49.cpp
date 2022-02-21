49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> wordMap;
        for(auto i:strs)
        {
            string word;
            for(auto j=0;j<26;++j)
                word=word+'0';
            for(auto j:i)
            {
                word[j-'a']=word[j-'a']+1;
            }
            wordMap[word].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i=wordMap.begin();i!=wordMap.end();++i)
        {
            res.push_back(i->second);
        }
        return res;
    }
};