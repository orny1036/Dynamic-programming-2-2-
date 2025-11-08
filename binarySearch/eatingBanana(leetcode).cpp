class Solution {
public:
    
    bool isValid(int m, int h, vector<int>& piles)
    {
         int required_h = 0;
         for(int pile: piles)
         {  
            if(required_h > h)break;
            if(pile % m == 0)
            required_h+=pile/m;
            else
            required_h+=(pile/m)+1;
         }
         return required_h<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(), piles.end());
        int low = 1, high = piles.back();
        int ans = h;
        while(low<=high)
        {
            int m = (low+high)/2;
            if(isValid(m, h, piles))
            {
                high = m - 1;
                ans = m;
            }
            else
            {
                low = m + 1;
            }
        }
        return ans;
    }
};
