class Solution {
public:
    bool reorderedPowerOf2(int N) {
        //Construct look-up table
        vector<vector<int>> LUT(32);
        int pow_tmp = 1;
        int tmp;
        for(int i = 0; i < 31; i++){
            tmp = pow_tmp;
            if(i < 30) pow_tmp *= 2;
            while(tmp > 0) {
                LUT[i].push_back(tmp % 10);
                tmp /= 10;
            }
            sort(LUT[i].begin(), LUT[i].end());//sort it
        }
        
        //Decompose number digit by digit
        vector<int> decomposed;
        while(N > 0) {
            decomposed.push_back(N % 10);
            N /= 10;
        }
        sort(decomposed.begin(), decomposed.end());
        
        bool isReordered = false;
        
        for(auto it = LUT.begin(); it != LUT.end(); it++){
            if(*it == decomposed) {return true;}
        }
        
        return false;
        
    }
};