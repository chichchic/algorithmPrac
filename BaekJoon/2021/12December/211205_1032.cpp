#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> str(n);
  for (int i = 0; i < n; i++)
  {
    cin >> str[i];
  }

  string answer = str[0];
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < answer.size(); j++)
    {
      if (str[i][j] != answer[j])
      {
        answer[j] = '?';
      }
    }
  }
  cout << answer;
  return 0;
}