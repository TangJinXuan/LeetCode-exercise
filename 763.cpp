763. 划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> charMap;
        int begin[26]={0};
        int end[26]={0};
        for(int i=0;i<26;++i)
        {
            begin[i]=-1;
            end[i]=-1;
        }
        for(int i=0;i<s.size();++i)
        {
            if(begin[s[i]-'a']==-1)
                begin[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        for(int i=0;i<26;++i)
        {
            if(begin[i]!=-1)
                charMap.push_back({begin[i],end[i]});
        }
        sort(charMap.begin(),charMap.end(),[](vector<int>& a,vector<int>& b){return a[0]<b[0];});
        int right(charMap[0][1]);
        int left(0);
        vector<int> res;
        for(int i=1;i<charMap.size();++i)
        {
            if(charMap[i][0]>right)
            {
                res.push_back(right-left+1);
                left=right+1;
                right=charMap[i][1];
            }
            else if(charMap[i][1]>right)
                right=charMap[i][1];
            // cout<<left<<" "<<right<<endl;
        }
        res.push_back(s.size()-left);
        return res;
    }
};