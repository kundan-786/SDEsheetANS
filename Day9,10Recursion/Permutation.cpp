class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> ans;
        recurPer(0,nums,ans);
        return ans;
    }
    
    
  void recurPer(int idx,vector<int>& nums, vector<vector<int>>& ans){
        if(idx==nums.size()-1)
        {ans.push_back(nums);
        return;}
        
      for(int i=idx;i<nums.size();i++){
          swap(nums[idx],nums[i]);
          recurPer(idx+1,nums,ans);
          swap(nums[idx],nums[i]);
      }
        
    }
};