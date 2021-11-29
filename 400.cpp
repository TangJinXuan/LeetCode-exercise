400. 第 N 位数字
给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位数字。

 
class Solution {
public:
    int findNthDigit(int n) {
        int index(1);
        int num(1);
        int tempN(n);
        while((long)tempN>(long)index*9*num)
        {
            int temp=index*9*num;
            ++num;
            tempN=tempN-temp;
            index=index*10;
        }
        int res=tempN/num+index-1;
        if(tempN%num!=0)
            ++res;
        // cout<<index<<" ";
        int eleNum=(num-tempN%num)%num;
        // cout<<tempN<<" "<<res<<" "<<eleNum<<endl;
        // cout<<res<<" ";
        for(int i=0;i<eleNum;++i)
        {
            res=res/10;
        }
        res=res%10;
        // cout<<res;
        return res;
    }
};
// class Solution {
// public:
//     int findNthDigit(int n) {
//         int d = 1, count = 9;
//         while (n > (long) d * count) {
//             n -= d * count;
//             d++;
//             count *= 10;
//         }
//         int index = n - 1;
//         int start = (int) pow(10, d - 1);
//         int num = start + index / d;
//         int digitIndex = index % d;
//         int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10;
//         return digit;
//     }
// };
