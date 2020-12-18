#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define ALPHABET 'z' - 'a' + 1

using namespace std;

class Trie
{
public:
  bool isEnd;
  int childNum;
  Trie *child[ALPHABET];

  Trie()
  {
    isEnd = false;
    childNum = 0;
    for (int i = 0; i < ALPHABET; i++)
    {
      child[i] = nullptr;
    }
  }

  ~Trie()
  {
    for (int i = 0; i < ALPHABET; i++)
    {
      if (child[i] != nullptr)
        delete child[i];
    }
  }

  void insert(string str)
  {
    if (str == "")
    {
      isEnd = true;
      return;
    }
    int index = str[0] - 'a';
    if (child[index] == nullptr)
    {
      childNum++;
      child[index] = new Trie();
    }
    child[index]->insert(str.substr(1));
  }

  int count(int typing, bool isFirst)
  {
    if (isEnd && childNum == 0)
      return typing;
    int output = 0;
    for (int i = 0; i < ALPHABET; i++)
    {
      if (child[i] != nullptr)
      {
        if (isFirst)
          output += child[i]->count(typing, false);
        else if (childNum > 1 || isEnd)
          output += child[i]->count(typing + 1, false);
        else
          output += child[i]->count(typing, false);
      }
    }
    if (isEnd)
      output += typing;
    return output;
  }
};

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n)
  {
    Trie dictionary;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
    {
      cin >> str[i];
      dictionary.insert(str[i]);
    }

    cout << fixed;
    cout.precision(2);
    cout << dictionary.count(1, true) / (double)n << '\n';
  }

  return 0;
}