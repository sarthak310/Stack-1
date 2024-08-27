//time: O(3n) ~ O(n)
//space: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> stk;
        int i = 0;
        int n = nums.size();
        vector<int> result(n, -1);
        while(i < n) {
            if(stk.empty() || nums[i] <= stk.top().first) {
                stk.push({nums[i], i});
            }
            else {
                while(!stk.empty() && nums[i] > stk.top().first) {
                    result[stk.top().second] = nums[i];
                    stk.pop();
                }
                stk.push({nums[i], i});
            }
            i++;
        }
        i = 0;
        while(i < n) {
            if(nums[i] > stk.top().first) {
                while(!stk.empty() && nums[i] > stk.top().first) {
                    result[stk.top().second] = nums[i];
                    stk.pop();
                }
            }
            i++;
        }
        return result;
    }
};