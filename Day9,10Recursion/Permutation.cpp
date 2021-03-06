//TC: O(N!) * O(N) 
 // SC: O(N) + O(N)
  
  vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> mp(nums.size(),0);
        func(ds,ans,mp,nums);
        return ans;
    }
    void func(vector<int>&ds,vector<vector<int>>&ans,vector<int>&mp,vector<int>&nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
                mp[i] = 1;
                ds.push_back(nums[i]);
                func(ds,ans,mp,nums);
                ds.pop_back();
                mp[i] = 0; 
            }
        }
    }

       ---------OR---------
 // TC: O(N!) * O(N)
 // SC: auxilary space
  
      vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0,ans,nums);
        return ans;
    }
    void func(int index,vector<vector<int>>&ans,vector<int>&nums){
        if(index==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]); //swapping for every position
            func(index+1,ans,nums);
            swap(nums[index],nums[i]); //reswap
        }
    }
