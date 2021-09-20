// 470. 用 Rand7() 实现 Rand10()
// 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

// 不要使用系统的 Math.random() 方法。

 
class Solution {
public:
    int rand10() {
        int res1(1);
        while(res1==1)
        {
            res1=rand7();
        }
        res1=res1%2;
        // cout<<res1<<endl;
        int res2(6);
        while(res2>5)
        {
            res2=rand7();
        }
        return res1*5+res2;
    }
};