#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
  int answer = 0;
  priority_queue<int> pq;
  for (int i = 0; i < scoville.size(); i++)
  {
    pq.push(-scoville[i]);
  }
  int count = 0;
  while (pq.size() > 1)
  {
    if (-pq.top() >= K)
    {
      break;
    }
    int first = -pq.top();
    pq.pop();
    int second = -pq.top();
    pq.pop();
    int mix = -(first + 2 * second);
    pq.push(mix);
    count++;
  }
  if (-pq.top() >= K)
  {
    return count;
  }
  return -1;
}