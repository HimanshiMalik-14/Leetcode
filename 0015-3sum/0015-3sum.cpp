// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//        int n=nums.size();
//         set<vector<int>> st;
//         for(int i=0;i<n;i++){
// set<int> hashset;
// for(int j=i+1;j<n;j++){
//     int third=-(nums[i]+nums[j]);
//     if(hashset.find(third)!=hashset.end()){
//         vector<int> temp={nums[i],nums[j],third};
//         sort(temp.begin(),temp.end());
//         st.insert(temp);
//   }
//   hashset.insert(nums[j]);
// }
//         }

// vector<vector<int>> ans(st.begin(),st.end());
// return ans;
//     }
// };



// optimal solution earlier one got TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // Step 3: Two pointer approach
            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    // Need a bigger sum
                    left++;
                }
                else if (sum > 0) {
                    // Need a smaller sum
                    right--;
                }
                else {
                    // Found a valid triplet
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};