#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

int mx[4] ={ 0, 0, 1, -1 };
int my[4] ={ 1, -1, 0, 0 };
int ans = 0;
int n, m;
int input[501][501];
bool check[501][501];


void tetromino2(int x, int y)
{
    if (x+1 < n && y + 2 < m)
    {
        int candi = input[x][y] + input[x][y+1] + input[x][y+2] + input[x+1][y+1];
        ans = max(ans, candi);
    }

    if (y+1 < m && x + 2 < n)
    {
        int candi = input[x][y] + input[x+1][y] + input[x+1][y+1] + input[x+2][y];
        ans = max(ans, candi);
    }
    if (x-1 >= 0 && y + 2 < m)
    {
        int candi = input[x][y] + input[x][y+1] + input[x][y+2] + input[x-1][y+1];
        ans = max(ans, candi);
    }
    if (x-1 >= 0 && x+1 < n && y + 1 < m)
    {
        int candi = input[x][y] + input[x-1][y+1] + input[x][y+1] + input[x+1][y+1];
        ans = max(ans, candi);
    }
}

void tetromino(int blockSize, int x, int y, int total)
{
    if (blockSize >= 4)
    {
        ans = max(ans, total);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextX = x+mx[i];
        int nextY = y+my[i];
        if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m && !check[nextX][nextY])
        {
            check[nextX][nextY] = true;
            tetromino(blockSize+1, nextX, nextY, total+input[nextX][nextY]);
            check[nextX][nextY] = false;
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &input[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[i][j] = true;
            tetromino(1, i, j, input[i][j]);
            check[i][j] = false;
            tetromino2(i, j);
        }
    }
    cout << ans;
    return 0;
}