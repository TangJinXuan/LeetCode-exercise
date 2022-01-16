1220. 统计元音字母序列的数目
给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
每个元音 'a' 后面都只能跟着 'e'
每个元音 'e' 后面只能跟着 'a' 或者是 'i'
每个元音 'i' 后面 不能 再跟着另一个 'i'
每个元音 'o' 后面只能跟着 'i' 或者是 'u'
每个元音 'u' 后面只能跟着 'a'
由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。
class Solution {
public:
    int countVowelPermutation(int n) {
        int num[5]={1,2,4,2,1};
        long resMap[5][n];
        resMap[0][0]=1;
        resMap[1][0]=1;
        resMap[2][0]=1;
        resMap[3][0]=1;
        resMap[4][0]=1;
        for(int i=1;i<n;++i)
        {
            resMap[0][i]=(resMap[1][i-1]+resMap[2][i-1]+resMap[4][i-1])%(int(pow(10,9))+7);
            resMap[1][i]=(resMap[0][i-1]+resMap[2][i-1])%(int(pow(10,9))+7);
            resMap[2][i]=(resMap[1][i-1]+resMap[3][i-1])%(int(pow(10,9))+7);
            resMap[3][i]=(resMap[2][i-1])%(int(pow(10,9))+7);
            resMap[4][i]=(resMap[2][i-1]+resMap[3][i-1])%(int(pow(10,9))+7);
        }
        return (resMap[0][n-1]+resMap[1][n-1]+resMap[2][n-1]+resMap[3][n-1]+resMap[4][n-1])%(int(pow(10,9))+7);
    }
};