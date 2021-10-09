187. 重复的DNA序列
所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> dic;
        vector<string>res;
        if(s.size()<10)
            return res;
        for(int i=0;i<s.size()-9;++i)
        {
            string newSubString=s.substr(i,10);
            dic[newSubString]++;
            // cout<<newSubString<<endl;
            if(dic[newSubString]==2)
                res.push_back(newSubString);
        }
        return res;
    }
};