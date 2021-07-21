//idea from the book 979-11-89909-17-8
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            result[i] = result[i-1] * nums[i-1];
        }
        
        int p = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            result[i] = result[i] * p;
            p = p * nums[i];
        }
        
        return result;
    }
};
