class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      stack<int> st;
      for(int i=0;i<(int)nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            return true;
        }
      }  
      return false;
    }
};