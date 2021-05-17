#include <iostream>

#define MAX_NODE 200001
#define MAX_DP 19

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int M;
  int **next = (int **)malloc(MAX_NODE * sizeof(int *));
  for (int i = 0; i < MAX_NODE; i++)
  {
    next[i] = (int *)malloc(MAX_DP * sizeof(int));
  }
  cin >> M;

  for (int i = 1; i <= M; i++)
  {
    cin >> next[i][0];
  }

  for (int j = 1; j < MAX_DP; ++j)
  {
    for (int i = 1; i <= M; ++i)
    {
      next[i][j] = next[next[i][j - 1]][j - 1];
    }
  }

  int Q;
  cin >> Q;

  while (Q--)
  {
    int N, X;
    cin >> N >> X;
    for (int i = MAX_DP - 1; i >= 0; --i)
    {
      if (N & (1 << i))
      {
        X = next[X][i];
      }
    }
    cout << X << '\n';
  }

  return 0;
}