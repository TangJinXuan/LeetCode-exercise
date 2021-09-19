//678. 有效的括号字符串 给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

// 任何左括号 ( 必须有相应的右括号 )。
// 任何右括号 ) 必须有相应的左括号 ( 。
// 左括号 ( 必须在对应的右括号之前 )。
// * 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
// 一个空字符串也被视为有效字符串。
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        vector<int>left;
        vector<int>mul;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
            {
                left.push_back(i);
            }
            else if (s[i]=='*')
            {
                mul.push_back(i);
            }
            else if(s[i]==')')
            {
                if(!left.empty())
                    left.pop_back();
                else if(!mul.empty())
                    mul.pop_back();
                else
                    return false;
            }
        }
        // cout<<left.size()<<" "<<mul.size()<<endl;
        if(left.size()>mul.size())
            return false;
        while(!left.empty())
        {
            int lposition=left.back();
            // cout<<lposition<<" ";
            left.pop_back();
            int mposition=mul.back();
            // cout<<mposition<<endl;
            mul.pop_back();
            if(lposition>mposition)
                return false;
        }
        return true;
    }
};