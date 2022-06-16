929. 独特的电子邮件地址
每个 有效电子邮件地址 都由一个 本地名 和一个 域名 组成，以 '@' 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个 '.' 或 '+' 。

例如，在 alice@leetcode.com中， alice 是 本地名 ，而 leetcode.com 是 域名 。
如果在电子邮件地址的 本地名 部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名中没有点的同一地址。请注意，此规则 不适用于域名 。

例如，“alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。
如果在 本地名 中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件。同样，此规则 不适用于域名 。

例如 m.y+name@email.com 将转发到 my@email.com。
可以同时使用这两个规则。

给你一个字符串数组 emails，我们会向每个 emails[i] 发送一封电子邮件。返回实际收到邮件的不同地址数目。

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> strMap;
        for(auto i:emails)
        {
            int judge=0;
            string temp="";
            for(auto j:i)
            {
                if(judge==0)
                {
                    if(j=='+')
                        judge=1;
                    else if(j=='@')
                    {
                        judge=2;
                        temp=temp+j;
                    }
                    else if(j!='.')
                    {
                        temp=temp+j;
                    }
                }
                else if(judge==1)
                {
                    if(j=='@')
                    {
                        judge=2;
                        temp=temp+j;
                    }
                }
                else
                {
                    temp=temp+j;
                }
            }
            strMap[temp]=1;
        }
        return strMap.size();
    }
};

// regex r("(?:\\.)(?=.*@)|(?:\\+.*)(?=@)");    // ?:的意思是非捕获分组，不会保存匹配的值，?=的意思是零宽正向先行断言，表示后面接这玩意，发现老有人问这个
// class Solution {
// public:
//     int numUniqueEmails(vector<string>& emails) {
//         unordered_set<string> dict;
//         for (auto& i : emails) dict.insert(regex_replace(i, r, ""));
//         return dict.size();
//     }
// };