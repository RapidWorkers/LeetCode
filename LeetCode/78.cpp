class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        
        solution.push_back(vector<int>());//empty set is always subset of all set
        
        for(int i = 0; i < nums.size(); i++){
            dfs(nums, vector<int>(), solution, i);
        }
        
        return solution;
    }
    
    void dfs(vector<int>& nums, vector<int> subset, vector<vector<int>> &result, int idx){
        cout << "Current idx = " << idx << endl;
        subset.push_back(nums[idx]);
        result.push_back(subset);
        for(int i = idx + 1; i < nums.size(); i++){
            dfs(nums, subset, result, i);
        }
        
    }
};
