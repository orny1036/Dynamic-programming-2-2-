#include <bits/stdc++.h>
using namespace std;

int find_max_length(int mid, int k, vector<int>&ribbons)
{
    int ct = 0;
    for(int i = ribbons.size()-1; i>=0; --i)
    {
        if(ribbons[i]<mid)break;
           ct+=ribbons[i]/mid;
    }
    return ct;
}

int main()
{
    vector<int>ribbons = {5, 9, 7};
    int k = 4;
    sort(ribbons.begin(), ribbons.end());
    int low = 1, high = ribbons.back();
    int ans = 0;
    while(low<=high)
    {
        int mid = (low+high)/2;

    if(find_max_length(mid, k, ribbons)>=k)
        {
            low = mid+1;
            ans = mid;
        }
        else
            high = mid-1;

    }
    cout << "Maximum length: "<< ans << endl;
    return 0;
}
