// 68. 文本左右对齐
// 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

// 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

// 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

// 文本的最后一行应为左对齐，且单词之间不插入额外的空格。

// 说明:

// 单词是指由非空格字符组成的字符序列。
// 每个单词的长度大于 0，小于等于 maxWidth。
// 输入单词数组 words 至少包含一个单词。
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> results;
        vector<string> temp;
        int length=-1;
        for(auto i:words)
        {
            int temp_length=i.size();
            if(temp_length+length+1>maxWidth)
            {
                string res="";
                if(temp.size()>1)
                {
                    int num=(maxWidth-length)/(temp.size()-1)+1;
                    int left=(maxWidth-length)%(temp.size()-1);
                    // cout<<length<<" "<<(temp.size()-1)<<" "<<num<<" "<<left<<endl;
                    for(int j=0;j<temp.size()-1;++j)
                    {
                        res=res+temp[j];
                        int numSpace=num;
                        // cout<<left<<endl;
                        if(left>0)
                        {
                            numSpace+=1;
                            left--;
                        }    
                        for(int k=0;k<numSpace;++k)
                        {
                            res=res+" ";
                        }
                    }
                    res=res+temp[temp.size()-1];
                }
                else
                {
                    res=temp[0];
                    for(int i=1;i<temp.size();++i)
                    {
                        res=res+" "+temp[i];
                    }
                    while(res.size()<maxWidth)
                    {
                        res=res+" ";
                    }
                }
                results.push_back(res);
                temp.clear();
                temp.push_back(i);
                length=temp_length;
            }
            else
            {
                temp.push_back(i);
                length=temp_length+length+1;
            }
        }
        string res=temp[0];
        for(int i=1;i<temp.size();++i)
        {
            res=res+" "+temp[i];
        }
        while(res.size()<maxWidth)
        {
            res=res+" ";
        }
        results.push_back(res);
        return results;
    }
};