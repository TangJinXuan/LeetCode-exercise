318. 最大单词长度乘积
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordMap;
        unordered_map<int,int> wordLen;
        for(auto i:words)
        {
            int tempMap(0);
            for(int j=0;j<i.size();++j)
            {
                tempMap=tempMap|(1<<(int)(i[j]-'a'));
                // cout<<(1<<(int)(i[j]-'a'))<<endl;
            }
            wordMap.push_back(tempMap);
            wordLen[tempMap]=max(wordLen[tempMap],(int)i.size());
            // cout<<i<<" "<<tempMap<<" "<<wordLen[tempMap]<<endl;
        }
        int res(0);
        for(int i=0;i<wordMap.size();++i)
        {
            for(int j=i+1;j<wordMap.size();++j)
            {
                // cout<<wordMap[i]<<" "<<wordMap[j]<<" "<<(wordMap[i]&wordMap[j])<<endl;
                if(int(wordMap[i]&wordMap[j])==0)
                {
                    res=max(res,wordLen[wordMap[i]]*wordLen[wordMap[j]]);
                    // cout<<wordLen[wordMap[i]]<<" "<<wordLen[wordMap[j]]<<endl;
                }
            }
        }
        return res;
    }
};