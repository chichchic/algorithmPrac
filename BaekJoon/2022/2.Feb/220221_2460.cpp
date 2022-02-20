#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int answer = 0;
  int cur = 0;
  for (int i = 0; i < 10; i++)
  {
    int boarder, alighter;
    cin >> boarder >> alighter;
    cur += (alighter - boarder);
    answer = max(answer, cur);
  }
  cout << answer;

  return 0;
}