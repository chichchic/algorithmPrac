#include <string>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> stringToSec(string timestamp)
{
  pair<int, int> result(0, 0);
  result.second += stoi(timestamp.substr(11, 2)) * 1000 * 60 * 60;
  result.second += stoi(timestamp.substr(14, 2)) * 1000 * 60;
  result.second += stoi(timestamp.substr(17, 2)) * 1000;
  result.second += stoi(timestamp.substr(20, 3));
  result.first = result.second;
  result.first -= (int)(stof(timestamp.substr(24)) * 1000 - 1);
  return result;
}

int solution(vector<string> lines)
{
  int answer = 0;
  vector<pair<int, int>> times;
  for (int i = 0; i < lines.size(); i++)
  {
    times.push_back(stringToSec(lines[i]));
  }
  for (int i = 0; i < lines.size(); i++)
  {
    int curEnd = times[i].second + 1000;
    int process = 1;
    for (int j = i + 1; j < lines.size(); j++)
    {
      if (times[j].first < curEnd)
        process++;
    }
    answer = max(answer, process);
  }
  return answer;
}