#include <iostream>

#define MAX_VIDEO 100001
#define MAX_DP 30

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, K, M;
  cin >> N >> K >> M;

  int *first_video_number = (int *)malloc(MAX_VIDEO * sizeof(int));
  for (int i = 0; i < N; ++i)
  {
    cin >> first_video_number[i];
  }

  int **next = (int **)malloc(MAX_VIDEO * sizeof(int *));
  for (int i = 0; i < MAX_VIDEO; i++)
  {
    next[i] = (int *)malloc(MAX_DP * sizeof(int));
  }
  for (int i = 1; i <= K; ++i)
  {
    cin >> next[i][0];
  }
  for (int j = 1; j < MAX_DP; ++j)
  {
    for (int i = 1; i <= K; ++i)
    {
      next[i][j] = next[next[i][j - 1]][j - 1];
    }
  }

  for (int i = 0; i < N; ++i)
  {
    for (int j = MAX_DP - 1; j >= 0; j--)
    {
      if ((M - 1) & (1 << j))
      {
        first_video_number[i] = next[first_video_number[i]][j];
      }
    }
    cout << first_video_number[i] << ' ';
  }

  return 0;
}