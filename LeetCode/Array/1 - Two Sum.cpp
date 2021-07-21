class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ptrA = 0, ptrB = 1;
        while(ptrA < nums.size())
        {
            for(ptrB = ptrA + 1; ptrB < nums.size(); ptrB++)
            {
                if(nums[ptrA] + nums[ptrB] == target) return vector<int> {ptrA, ptrB};
            }
            ptrA++;
        }
        
        return vector<int>();
        
    }
};
