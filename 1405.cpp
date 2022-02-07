1405. 最长快乐字符串
如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。

给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：

s 是一个尽可能长的快乐字符串。
s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
s 中只含有 'a'、'b' 、'c' 三种字母。
如果不存在这样的字符串 s ，请返回一个空字符串 ""。

 
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        int strMap[3]={a,b,c};
        char strEle[3]={'a','b','c'};
        while(true)
        {
            for(int i=0;i<3;++i)
            {
                for(int j=i+1;j<3;++j)
                {
                    if(strMap[i]<strMap[j])
                    {
                        int temp=strMap[i];
                        strMap[i]=strMap[j];
                        strMap[j]=temp;
                        char tempStr=strEle[i];
                        strEle[i]=strEle[j];
                        strEle[j]=tempStr;
                    }
                }
            }
            if(res.size()>0)
            {
                if(res[res.size()-1]==strEle[0])
                {
                    --strMap[1];
                    res=res+strEle[1];

                }
            }
            res=res+strEle[0];
            --strMap[0];
            if(strMap[0]>1)
            {
                res=res+strEle[0];
                --strMap[0];
            }
            if(strMap[1]==0&&strMap[2]==0)
                break;
        }
        // cout<<strEle[0]<<" "<<strEle[1]<<" "<<strEle[2]<<endl;
        // cout<<strMap[0]<<" "<<strMap[1]<<" "<<strMap[2]<<endl;
        return res;
    }
};