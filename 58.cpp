// 58. 最后一个单词的长度
// 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

// 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(" ") + 1);  
        int index=s.rfind(' ');
        return s.size()-index-1;
    }
};