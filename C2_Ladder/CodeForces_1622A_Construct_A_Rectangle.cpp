#include <bits/stdc++.h>
using namespace std;

bool isRectange(vector<int> &nums)
{
    bool isIt = false;
    for (int i = 0; i < 3; i++)
    {
        isIt |= (nums[i] == (nums[(i + 1) % 3] + nums[(i + 2) % 3]));
    }
    for (int i = 0; i < 3; i++)
    {
        if (nums[i] % 2 == 0)
        {
            isIt |= (nums[(i + 1) % 3] == nums[(i + 2) % 3]);
        }
    }

    return isIt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> nums(3, 0);
        for (int i = 0; i < 3; i++)
        {
            cin >> nums[i];
        }

        bool isIt = isRectange(nums);
        
        cout << (isIt ? "YES\n" : "NO\n");
    }
    return 0;
}