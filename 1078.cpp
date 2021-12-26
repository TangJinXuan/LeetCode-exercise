1078. Bigram 分词
给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。

对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

 
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        int pos=text.find(first+" "+second);
        int size=first.size()+second.size()+2;
        vector<string> res;
        while(pos!=-1)
        {
            if(pos>0)
            {
                if(text[pos-1]!=' ')
                {
                    pos=text.find(first+" "+second,pos+1);
                    continue;
                }
            }
            if(pos+size<text.size())
            {
                if(text[pos+size-1]!=' ')
                {
                    pos=text.find(first+" "+second,pos+1);
                    continue;
                }
            }
            if(pos+size>=text.size())
                break;
            int pos1=text.find(" ",pos+size);
            if(pos1==-1)
            {
                res.push_back(text.substr(pos+size));
                break;
            }
            else
                res.push_back(text.substr(pos+size,pos1-pos-size));
            pos=text.find(first+" "+second,pos+1);
        }
        return res;
    }
};