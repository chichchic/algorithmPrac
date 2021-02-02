//dfs
/*
#include <iostream>
#include <algorithm>

using namespace std;

int board[27][27];
bool check[27][27] = {};
int ans = 0;
int ansCnt[1000];
int n;

void checking(int x, int y)
{
	if(check[x][y]) return;
	check[x][y] = true;
	if(board[x][y] == 0)
		return;


	ansCnt[ans]++;

		if(x+1 < n)
			checking(x+1,y);
		if(y+1 < n)
			checking(x,y+1);
		if(x-1 >= 0)
			checking(x-1,y);
		if(y-1 >= 0)
			checking(x,y-1);
}

int main() {


	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%1d", &board[i][j]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(board[i][j] != 0 && !check[i][j])
			{
				ans++;
				checking(i, j);
			}
			else check[i][j] = true;

	cout << ans << '\n';
	sort(&ansCnt[1], &ansCnt[ans+1]);
	for(int i = 1; i <= ans; i++)
		cout << ansCnt[i] << '\n';
	return 0;
}
*/

//bfs
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int board[26][26];
queue<pair<int, int>> que;
bool check[26][26] = {};

int n;
int ans = 0;
int ansArr[1000];

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%1d", &board[i][j]);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!check[i][j] && board[i][j] == 1)
      {
        ans++;
        que.push(make_pair(i, j));
        while (!que.empty())
        {
          int x = que.front().first;
          int y = que.front().second;

          que.pop();
          if (check[x][y] || board[x][y] == 0)
            continue;
          check[x][y] = true;
          ansArr[ans]++;
          if (x + 1 < n)
            que.push(make_pair(x + 1, y));
          if (y + 1 < n)
            que.push(make_pair(x, y + 1));
          if (x - 1 >= 0)
            que.push(make_pair(x - 1, y));
          if (y - 1 >= 0)
            que.push(make_pair(x, y - 1));
        }
      }
      else
        check[i][j] = true;
    }
  }

  cout << ans << '\n';
  sort(&ansArr[1], &ansArr[ans + 1]);
  for (int i = 1; i <= ans; i++)
    cout << ansArr[i] << '\n';
  return 0;
}