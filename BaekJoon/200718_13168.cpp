#include <iostream>
#include <vector>
#include <string>

using namespace std;
//TODO:
//문제 https://www.acmicpc.net/problem/13168
//힌트 https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F
int main()
{
  freopen("input.txt", "r", stdin);
  int n, ticketPrice;
  cin >> n >> ticketPrice;

  vector<string> city(n);
  for (int i = 0; i < n; i++)
  {
    cin >> city[i];
  }

  return 0;
}