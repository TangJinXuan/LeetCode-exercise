397. 整数替换
给定一个正整数 n ，你可以做如下操作：

如果 n 是偶数，则用 n / 2替换 n 。
如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
n 变为 1 所需的最小替换次数是多少？
class Solution {
public:
    int integerReplacement(int n) {
        if (n==INT_MAX)
            return 32;
        if(n==1)
            return 0;
        if(n%2==0)
            return 1+integerReplacement(n/2);
        else
            return 1+min(integerReplacement(n+1),integerReplacement(n-1));
    }
};