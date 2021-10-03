482. 密钥格式化
有一个密钥字符串 S ，只包含字母，数字以及 '-'（破折号）。其中， N 个 '-' 将字符串分成了 N+1 组。

给你一个数字 K，请你重新格式化字符串，使每个分组恰好包含 K 个字符。特别地，第一个分组包含的字符个数必须小于等于 K，但至少要包含 1 个字符。两个分组之间需要用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。

给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。

 
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int i(0);
        string res="";
        int count(0);
        for(i=s.size()-1;i>-1;--i)
        {
            if(count==k)
            {
                res.push_back('-');
                count=0;
            }
            if(s[i]>='a'&&s[i]<='z')
            {
                s[i]=s[i]-32;
                res.push_back(s[i]);
                ++count;
            }
            else if(s[i]!='-')
            {
                res.push_back(s[i]);
                ++count;
            }
            // cout<<i<<endl;
        }
        if(res.back()=='-')
            res.pop_back();
        reverse(res.begin(),res.end());
        // cout<<data<<endl;
        // int aver=data.size()/k;
        // // cout<<aver<<" aver"<<endl;
        // int left=data.size()%k;
        // string res(data,0,left);
        // // cout<<res<<"111";
        // if(left!=0&&aver!=0)
        //     res=res+'-';
        // for(i=0;i<aver;++i)
        // {
        //     if(i!=0)
        //         res=res+'-';
        //     for(int j=0;j<k;++j)
        //     {
        //         // cout<<(left+i*k+j)<<"    "<<s[left+i*aver+j]<<endl;
        //         res=res+data[left+i*k+j];
        //     }
        // }
        // // if(res[0]=='-')
        // //     res.erase(0,1);
        return res;
    }
};