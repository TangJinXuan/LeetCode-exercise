// 524. 通过删除字母匹配到字典里最长单词
// 给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

// 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。


class Solution {
public:
    static bool isLonger(const string &s1, const string &s2)
    {
        return s1.size() > s2.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {

        sort(dictionary.begin(),dictionary.end());
	    stable_sort(dictionary.begin(), dictionary.end(), isLonger);

        for(int i=0;i<dictionary.size();++i)
        {
            int dicNo=0;
            int sNo=0;
            while(dicNo<dictionary[i].size()&&sNo<s.size())
            {
                if(dictionary[i][dicNo]==s[sNo])
                {
                    ++dicNo;
                }
                ++sNo;
            }
            if(dicNo==dictionary[i].size())
            {
                return dictionary[i];
            }
        }
        return "";
    }
};