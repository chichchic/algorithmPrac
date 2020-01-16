#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{

    int n;
    int ans = 0;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    pair<int, int> dp[1001];

    dp[0] = make_pair(0, 0);

    for(int i = 0; i <= n; i++)
    {
        int j = i;
        int maxtemp = 0;
        for( ; j > 0; j--)
        {
            if(dp[j].second < a[i])
            {
                maxtemp = max(maxtemp, dp[j].first + a[i]);
                dp[i+1] = make_pair(maxtemp, a[i]);
                ans = max(maxtemp, ans);
            }
        }
    }

    cout << ans << endl;
    return 0;
}