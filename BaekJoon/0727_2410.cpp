#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<long long> twok;

long long cnt_mek(long long input)
{
    vector<long long> dp(input+1, 0);
    dp[0] = 1;
    for(int i = 0; i < twok.size(); i++)
    {
        for(int j = twok.at(i); j <= input; j++)
        {
            dp[j] = (dp[j] + dp[j - twok[i]]) % 1000000000;
        }
    }
    return dp[input];
}

int main()
{
    long long temp = 1;
    long long input;
    cin >> input;

    while(temp <= input)
    {
        twok.push_back(temp);
        temp *= 2;
    }

    cout << cnt_mek(input) << endl;

    return 0;
}