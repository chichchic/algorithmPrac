#include <iostream>

using namespace std;

int main()
{
    int n, m, big, ans = 1;
    bool find = false;
    cin >> n >> m;
    
    int input[53][53];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%1d", &input[i][j]);
        }
    }
    
    big = (n < m) ? n : m;
    for(int i = big-1; i > 0; i--)
    {
        for(int j = 0; j < m-i; j++)
        {
            for(int k = 0; k < n-i; k++)
            {
                if(input[k][j] == input[k+i][j] && input[k][j+i] == input[k+i][j+i] && 
                    input[k][j] == input[k+i][j+i])
                {
                    ans = i+1;
                    find = true;
                    break;
                }
            }
            if(find) break;
        }
        if(find) break;
    }
    cout << ans*ans << endl;

    return 0;
}