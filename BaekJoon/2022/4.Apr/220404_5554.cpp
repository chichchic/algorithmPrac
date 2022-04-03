#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int total_time = 0, time_input;
  for (int i = 0; i < 4; i++)
  {
    cin >> time_input;
    total_time += time_input;
  }
  cout << total_time / 60 << '\n'
       << total_time % 60;

  return 0;
}