#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  auto cur_time = time(nullptr);
  struct tm *time_st = gmtime(&cur_time);
  cout << time_st->tm_year + 1900 << '\n'
       << time_st->tm_mon + 1 << '\n'
       << time_st->tm_mday;

  return 0;
}