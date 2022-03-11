剑指 Offer 48. 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        unordered_map<char,int> dic;
        int n=s.size();
        int dp(1);
        int res(1);
        dic[s[0]]=0;
        for(int i=1;i<n;++i)
        {
            // int tempDic=s[i]-'a';
            char tempDic=s[i];
            // if(i==1)
            if(dic.find(tempDic)==dic.end()||i-dic[tempDic]>dp)
                dp=dp+1;
            else
                dp=i-dic[tempDic];
            // cout<<i<<" "<<dic[tempDic]<<" ";
            // cout<<dp<<endl;
            res=max(res,dp);
            dic[tempDic]=i;
        }
        return res;
    }
};