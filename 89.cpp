class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> grayList;
        
        int maxNum = 1;
        for(int i = 0; i < n; i++)//get power of 2 to set max
            maxNum *= 2;
        
        int gray;
        
        for(int i = 0; i < maxNum; i++){//integer to gray conversion?
            gray = i ^ (i >> 1);
            grayList.push_back(gray);
        }
        
        return grayList;
    }
};
