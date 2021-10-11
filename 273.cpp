273. 整数转换英文表示
将非负整数 num 转换为其对应的英文表示。
0 <= num <= 2^31 - 1

class Solution {
public:
    string singleToWord(int num)
    {
        string res;
        switch(num)
        {
            case 1:res="One";break;
            case 2:res="Two";break;
            case 3:res="Three";break;
            case 4:res="Four";break;
            case 5:res="Five";break;
            case 6:res="Six";break;
            case 7:res="Seven";break;
            case 8:res="Eight";break;
            case 9:res="Nine";break;
            case 10:res="Ten";break;
            case 11:res="Eleven";break;
            case 12:res="Twelve";break;
            case 13:res="Thirteen";break;
            case 14:res="Fourteen";break;
            case 15:res="Fifteen";break;
            case 16:res="Sixteen";break;
            case 17:res="Seventeen";break;
            case 18:res="Eighteen";break;
            case 19:res="Nineteen";break;
            default:
            {
                if(num>19&&num<30)
                {
                    res="Twenty";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
                else if(num>29&&num<40)
                {
                    res="Thirty";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
                else if(num>39&&num<50)
                {
                    res="Forty";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
                else if(num>49&&num<60)
                {
                    res="Fifty";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
                else if(num>59&&num<70)
                {
                    res="Sixty";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
                else if(num>69&&num<80)
                {
                    res="Seventy";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
                else if(num>79&&num<90)
                {
                    res="Eighty";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
                else if(num>89&&num<100)
                {
                    res="Ninety";
                    if(num%10!=0)
                        res=res+" "+singleToWord(num%10);
                }
            }
        }
        return res;
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        vector<string> resSeg;
        vector<int> splitNum;
        while(num>0)
        {
            splitNum.push_back(int(num%1000));
            num=num/1000;
            // cout<<num<<endl;
        }
        for(int i=0;i<splitNum.size();++i)
        {
            // cout<<splitNum[i]<<" "<<i<<endl;
            string tempStr="";
            if(splitNum[i]>=100)
                tempStr=singleToWord(splitNum[i]/100)+" Hundred";
            string tempRestStr=singleToWord(splitNum[i]%100);
            if(tempRestStr!=""&&tempStr!="")
                tempStr=tempStr+" ";
            tempStr=tempStr+tempRestStr;
            // cout<<tempStr<<endl;
            resSeg.push_back(tempStr);
        }
        int size=resSeg.size();
        string res=resSeg[0];
        // cout<<res<<endl;
        if(size>1)
        {
            if(res!=""&&resSeg[1]!="")
                res=" "+res;
            if(resSeg[1]!="")
                res=" Thousand"+res;
            res=resSeg[1]+res;
        // cout<<res<<endl;
        }
        if(size>2)
        {
            if(res!=""&&resSeg[2]!="")
                res=" "+res;
            if(resSeg[2]!="")
                res=" Million"+res;
            res=resSeg[2]+res;
        // cout<<res<<endl;
        }
        if(size>3)
        {
            if(res!="")
                res=" "+res;
            res=resSeg[3]+" Billion"+res;
        // cout<<res<<endl;
        }
        return res;
    }
};