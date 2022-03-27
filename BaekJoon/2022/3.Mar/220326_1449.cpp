#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<bool> pipe(2002, true);
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++)
  {
    int hole;
    cin >> hole;
    pipe[hole * 2 - 1] = false;
    pipe[hole * 2] = false;
    pipe[hole * 2 + 1] = false;
  }
  int answer = 0;
  for (int i = 1; i <= 2001; i++)
  {
    if (!pipe[i])
    {
      for (int j = 0; j < l * 2 + 1; j++)
      {
        pipe[i + j] = true;
      }
      answer++;
    }
  }
  cout << answer;
  return 0;
}