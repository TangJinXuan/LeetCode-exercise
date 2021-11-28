786. 第 K 个最小的素数分数
给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数  组成，且其中所有整数互不相同。

对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。

那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<double> kSmall;
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                if(kSmall.size()<k)
                {
                    kSmall.push((double)arr[i]/(double)arr[j]);
                }
                else
                {
                    double temp=(double)arr[i]/(double)arr[j];
                    if(temp<kSmall.top())
                    {
                        kSmall.pop();
                        kSmall.push(temp);
                        // cout<<kSmall.top()<<" "<<temp<<endl;
                    }
                }
            }
            // cout<<kSmall.size();
        }
        // cout<<kSmall.top();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((double)arr[i]/(double)arr[j]==kSmall.top())
                    return {arr[i],arr[j]};
            }
        }
        return {};
    }
};