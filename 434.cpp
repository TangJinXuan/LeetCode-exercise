434. 字符串中的单词数
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

class Solution {
public:
    int countSegments(string s) {
        int res(0);
        int indexNow(-1);
        int indexPre(-1);
        while(s.find(" ",indexNow+1)!=string::npos)
        {
            indexNow=s.find(" ",indexNow+1);
            // cout<<indexNow<<" "<<indexPre<<endl;
            if(indexNow-1>indexPre)
            {
                ++res;
            }
            indexPre=indexNow;
        }
        // cout<<res;
        if(indexNow+1<s.size()&&s[indexNow+1]!=' ')
            ++res;
        return res;
    }
};