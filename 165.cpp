// 165. 比较版本号
// 给你两个版本号 version1 和 version2 ，请你比较它们。

// 版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。每个修订号由 多位数字 组成，可能包含 前导零 。每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，以此类推。例如，2.5.33 和 0.1 都是有效的版本号。

// 比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较 忽略任何前导零后的整数值 。也就是说，修订号 1 和修订号 001 相等 。如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。例如，版本 1.0 小于版本 1.1 ，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1 ，0 < 1 。

// 返回规则如下：

// 如果 version1 > version2 返回 1，
// 如果 version1 < version2 返回 -1，
// 除此之外返回 0。
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1=version1.find('.',v1+1);
        int v1_pre(-1);
        bool judge1=true;
        int v2=version2.find('.',v2+1);
        int v2_pre(-1);
        bool judge2=true;
        while(judge1||judge2)
        {
            int v1No,v2No;
            // cout<<v1<<" "<<v2<<endl;
            if(v1!=-1)
            {
                string versionNo1(version1,v1_pre+1,v1-v1_pre-1);
                v1No=stoi(versionNo1);
                v1_pre=v1;
                v1=version1.find('.',v1+1);
            }    
            else if(judge1)
            {
                string versionNo1(version1,v1_pre+1);
                v1No=stoi(versionNo1);
                judge1=false;
            }
            else
            {
                v1No=0;
            }
            if(v2!=-1)
            {
                string versionNo2(version2,v2_pre+1,v2-v2_pre-1);
                // cout<<"test1";
                v2_pre=v2;
                v2=version2.find('.',v2+1); 
                cout<<v2_pre<<" ";
                v2No=stoi(versionNo2);
            }    
            else if(judge2)
            {
                string versionNo2(version2,v2_pre+1);
                v2No=stoi(versionNo2);
                judge2=false;
                cout<<v2_pre<<endl;
            }
            else
            {
                // cout<<"test";
                v2No=0;
            }
            // cout<<v1No<<" "<<v2No<<endl;
            // cout<<v1_pre<<" "<<v2_pre<<endl;
            if(v1No>v2No)
                return 1;
            else if(v1No<v2No)
                return -1;
        }
        return 0;
    }
};