// 371. 两整数之和
// 给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int temp=1;
        unsigned int lefta=(unsigned int)a;
        unsigned int rightb=(unsigned int)b;
        bool addOne=0;
        bool left=false;
        bool right=false;
        unsigned int res=0;
        for(int i=0;i<32;++i)
        {
            if((a&temp)==temp)
                left=true;
            else
                left=false;
            if((b&temp)==temp)
                right=true;
            else
                right=false;
            // cout<<left<<" "<<" "<<(b&temp)" "<<right<<endl;
            if(left&&right)
            {
                if(addOne)
                {
                    res=res|temp;
                }
                addOne=true;
            }
            else if(left||right)
            {
                if(!addOne)
                {
                    res=res|temp;
                }
            }
            else
            {
                if(addOne)
                {
                    addOne=false;
                    res=res|temp;
                }
            }
            temp=temp<<1;
            // cout<<res<<endl;
        }
        // if(addOne&&)
        //     res=res|temp;
        return int(res);
    }
};