#include <iostream>

using namespace std;

int bechu[53][53] = {};
bool injup = false;
int t, m, n, k;

void girung(int x, int y)
{
    if(x < 0 || y < 0 || x >= m || y >= n)
    {
        return;
    }

    if(bechu[x][y] == 1)
    {
        injup = true;
        bechu[x][y] = 0;
        girung(x-1, y);
        girung(x, y-1);
        girung(x+1, y);
        girung(x,y+1);
    }
    else
    {
        return;
    }
}

int main()
{
    cin >> t;
    while(t--)
    {
        fill(&bechu[0][0], &bechu[52][53], 0);
        int ans = 0;
        int tempi, tempj;
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> tempi >> tempj;
            bechu[tempi][tempj] = 1;
        }


        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                injup = false;
                girung(i,j);
                if(injup) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

