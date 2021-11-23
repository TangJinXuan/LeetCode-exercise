423. 从英文中重建数字
给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。

 
class Solution {
public:
    string originalDigits(string s) {
        // one
        // three
        unordered_map<char,int> strNum;
        for(auto i:s)
        {
            strNum[i]++;
        }
        string res="";
        int resNum[10];
        for(int i=0;i<10;++i)
        {
            resNum[i]=0;
        }
        for(int i=0;i<strNum['z'];++i)
        {
            resNum[0]++;
            strNum['e']--;
            strNum['r']--;
            strNum['o']--;
        }
        for(int i=0;i<strNum['w'];++i)
        {
            resNum[2]++;
            strNum['t']--;
            strNum['o']--;
        }
        for(int i=0;i<strNum['g'];++i)
        {
            resNum[8]++;
            strNum['e']--;
            strNum['i']--;
            strNum['h']--;
            strNum['t']--;
        }
        for(int i=0;i<strNum['x'];++i)
        {
            resNum[6]++;
            strNum['s']--;
            strNum['i']--;
        }
        for(int i=0;i<strNum['s'];++i)
        {
            resNum[7]++;
            strNum['e']-=2;
            strNum['v']--;
            strNum['n']--;
        }
        for(int i=0;i<strNum['v'];++i)
        {
            resNum[5]++;
            strNum['f']--;
            strNum['i']--;
            strNum['e']--;
        }
        for(int i=0;i<strNum['f'];++i)
        {
            resNum[4]++;
            strNum['o']--;
            strNum['u']--;
            strNum['r']--;
        }
        for(int i=0;i<strNum['i'];++i)
        {
            resNum[9]++;
            strNum['n']-=2;
            strNum['e']--;
        }
        for(int i=0;i<strNum['n'];++i)
        {
            resNum[1]++;
            strNum['o']--;
            strNum['e']--;
        }
        for(int i=0;i<strNum['t'];++i)
        {
            resNum[3]++;
        }
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<resNum[i];++j)
            {
                char resTemp='0'+i;
                res=res+resTemp;
            }
        }
        return res;
    }
};