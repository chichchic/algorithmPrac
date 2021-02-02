#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long  n, cnt = 1, temp;
    vector<int> input;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    for(int i = 0; i < n-1; i++)
    {
        if(input[i] > input[i+1]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}