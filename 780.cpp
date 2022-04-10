780. 到达终点
给定四个整数 sx , sy ，tx 和 ty，如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，则返回 true，否则返回 false。

从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx<=tx&&sy<=ty)
        {
            if(tx<ty)
            {
                if(ty%tx>=sy)
                {
                    ty=ty%tx;
                }
                else
                {
                    if(tx==sx && ty%tx == sy%tx)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if(tx>ty)
            {
                if(tx%ty>=sx)
                {
                    tx=tx%ty;
                }
                else
                {
                    if(ty==sy && tx%ty == sx%ty)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(sx==tx&&sy==ty)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};