class Solution {
public:
    int reverse(int x) {
        unsigned int r = 0;
        
        int sign = (x >= 0) ? 0 : 1;
        
        unsigned int t = (x >= 0) ? x : ~(unsigned int)x+1;
        //cout << t << endl;
        
        while(t > 0)
        {
            //cout << r << endl;
            if(r >= 214748365)
            {
                r = 0;
                break;   
            }
            else if(r >= 214748364)
            {
                if(sign)
                {
                    if(t % 10 > 8)
                    {
                        r = 0;
                        break;
                    }
                }
                else
                {
                    if(t % 10 > 7)
                    {
                        r = 0;
                        break;
                    }
                }
            }
            
            r = r * 10 + t % 10;
            t /= 10;
        }
        
        x = r;
        
        return (!sign)?x:-x;
    }
};
