//time: O(2n) ~ O(n)
//space: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int i = 0;
        int n = temperatures.size();
        vector<int> result(n, 0);
        while(i < n) {
            if(stk.empty() || temperatures[i] <= stk.top().first) {
                stk.push({temperatures[i], i});
            }
            else {
                while(!stk.empty() && temperatures[i] > stk.top().first) {
                    result[stk.top().second] = i - (stk.top().second);
                    stk.pop();
                }
                stk.push({temperatures[i], i});
            }
            i++;
        }
        return result;
    }
};