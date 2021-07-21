class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev;
        for(int i = 1; i < nums.size(); i++){
            prev = nums[i-1];
            if(prev == nums[i]) {
                //cout << "removing " << nums[i] << endl;
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};
