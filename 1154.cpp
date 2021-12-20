1154. 一年中的第几天
给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。
class Solution {
public:
    int dayOfYear(string date) {
        // bool runnian=false;
        int res(0);
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));
        int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(year%4==0)
            days[1]=29;
        for(int i=0;i<month-1;++i)
            res+=days[i];
        res+=day;
        // if(month<3)
        // {
        //     switch(month){
        //         case 1:res=day;break;
        //         case 2:res=31+day;break;
        //     }
        // }
        // else if(runnian)
        // {
        //     switch(month){
        //         case 3:res=60+day;break;
        //         case 4:res=91+day;break;
        //         case 5:res=121+day;break;
        //         case 6:res=152+day;break;
        //         case 7:res=182+day;break;
        //         case 8:res=213+day;break;
        //         case 9:res=244+day;break;
        //         case 10:res=274+day;break;
        //         case 11:res=305+day;break;
        //         case 12:res=335+day;break;
        //     }
        // }
        // else
        // {
        //     switch(month){
        //         case 3:res=59+day;break;
        //         case 4:res=90+day;break;
        //         case 5:res=120+day;break;
        //         case 6:res=151+day;break;
        //         case 7:res=181+day;break;
        //         case 8:res=212+day;break;
        //         case 9:res=243+day;break;
        //         case 10:res=273+day;break;
        //         case 11:res=304+day;break;
        //         case 12:res=334+day;break;
        //     }
        // }
        return res;
    }
};