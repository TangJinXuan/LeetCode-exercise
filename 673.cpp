// 673. 最长递增子序列的个数
// 给定一个未排序的整数数组，找到最长递增子序列的个数。
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int*lastElement=new int[nums.size()];
        int*maxLength=new int[nums.size()];
        int*maxNumber=new int[nums.size()];
        for(int i=0;i<nums.size();++i)
        {
            maxLength[i]=1;
            maxNumber[i]=1;
            for(int j=0;j<i;++j)
            {
                // if(nums[i]==7)
                //     cout<<nums[i]<<" "<<nums[j]<<endl;
                if(nums[i]>nums[j])
                {
                    // cout<<"test1";
                    // if(nums[i]==7)
                    // {
                    //     cout<<maxLength[i]<<" "<<maxLength[j]<<" ";
                    //     cout<<maxNumber[i]<<" "<<maxNumber[j]<<endl;

                    // }
                    if(maxLength[i]<maxLength[j]+1)
                    {
                        maxNumber[i]=maxNumber[j];
                        maxLength[i]=maxLength[j]+1;
                    }
                    else if(maxLength[i]==maxLength[j]+1)
                    {
                        maxNumber[i]+=maxNumber[j];
                    }
                }
                // else
                // {
                //     if(maxLength[i]==maxLength[j])
                //     {
                //         maxNumber[i]+=1;
                //     }
                // }
            }
        }
        int res(0);
        int resMaxLength(1);
        for(int i=0;i<nums.size();++i)
        {
            if(maxLength[i]>resMaxLength)
            {
                res=maxNumber[i];
                resMaxLength=maxLength[i];
            }
            else if(maxLength[i]==resMaxLength)
                res+=maxNumber[i];
        }
        // for(int i=0;i<nums.size();++i)
        // {
        //     cout<<maxLength[i]<<" ";
        //     cout<<maxNumber[i]<<endl;
        // }
        return res;
    }
};