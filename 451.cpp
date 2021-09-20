// 451. 根据字符出现频率排序
// 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
typedef pair<char, int> PAIR;
class Solution {
public:

    static bool cmp(const PAIR& a,const PAIR& b)
    {
        return a.second>b.second;
    }    
    string frequencySort(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();++i)
        {
            m[s[i]]++;
        }
        vector<PAIR> vec(m.begin(), m.end());
        sort(vec.begin(),vec.end(),cmp);
        string res="";
        for(auto i:vec)
        {
            for(int j=0;j<i.second;++j)
            {
                res+=i.first;
            }
        }
        return res;
    }
};