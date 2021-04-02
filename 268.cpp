class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumOfNum = n * (n+1) / 2;
        
        for(auto it = nums.begin(); it != nums.end(); it++)
            sumOfNum -= *it;
        
        return sumOfNum;
    }
};