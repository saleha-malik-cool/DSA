class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans =0;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            int freq = it.second;
            if(freq > n/2){
                ans = it.first;
            }
        }
        return ans;
        
    }
};