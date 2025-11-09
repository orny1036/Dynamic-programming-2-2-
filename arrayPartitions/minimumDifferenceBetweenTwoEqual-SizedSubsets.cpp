class Solution {
public:
    void generateSum(int idx, int count, int sum, vector<int>& nums, vector<vector<int>>&sums)
    {
        if(idx == nums.size())
        {
            sums[count].push_back(sum);
            return;
        }
        generateSum(idx+1, count, sum, nums, sums);
        generateSum(idx+1, count+1, sum+nums[idx], nums, sums);
    }
    int minimumDifference(vector<int>& nums) {
     
     int arraySize = nums.size();
     int halfSize = arraySize/2;
     vector<int>left(nums.begin(), nums.begin()+halfSize);
     vector<int>right(nums.begin()+halfSize, nums.end());
     int totalSum = accumulate(nums.begin(), nums.end(), 0);
     vector<vector<int>>rightSum(halfSize+1), leftSum(halfSize+1);
     
     generateSum(0, 0, 0, left, leftSum);
     generateSum(0, 0, 0, right, rightSum);

     int ans = INT_MAX;
     
     for(auto& v: rightSum)
     {
         sort(v.begin(), v.end());
     }
     

     for(int k = 0; k<=halfSize; ++k)
     {
           for(int x : leftSum[k])
           {
            int target = totalSum/2 - x;
            auto &temp = rightSum[halfSize-k];
            auto y = lower_bound(temp.begin(), temp.end(), target);
            if(y != temp.end())
            {
                ans =  min (ans, abs(totalSum - 2*(x + (*y))));
            }
            if(y != temp.begin())
            {
                ans  = min(ans, abs(totalSum - 2*(x + *prev(y))));
            }
           }
     }
        return ans;
    }
};
