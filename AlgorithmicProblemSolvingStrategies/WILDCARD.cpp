#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int ALPHA = 26 + 2;
const int QM = 26;
const int WILD = 27;

class Trie_node
{
private:
  bool endFlag;
  bool hasWildCard;
  Trie_node *characters[ALPHA];

public:
  Trie_node()
  {
    endFlag = false;
    hasWildCard = false;
    for (int i = 0; i < ALPHA; i++)
    {
      characters[i] = nullptr;
    }
  }

  ~Trie_node()
  {
    for (int i = 0; i < ALPHA; i++)
    {
      if (characters[i] != nullptr)
      {
        delete characters[i];
      }
    }
  }

  void insert(const char *str)
  {
    if (*str == '\0')
    {
      endFlag = true;
      return;
    }
    int cursor;
    if (*str == '?')
    {
      cursor = QM;
    }
    else if (*str == '*')
    {
      cursor = WILD;
    }
    else
    {
      cursor = *str - 'a';
    }

    if (characters[cursor] == nullptr)
    {
      characters[cursor] = new Trie_node();
    }
    characters[cursor]->insert(str + 1);
  }

  bool find(const char *str)
  {
    if (*str == '\0')
    {
      if (endFlag)
        return true;
      if (characters[WILD] != nullptr)
        return characters[WILD]->find(str + 1);
      return false;
    }
    int cursor = *str - 'a';

    if (hasWildCard && characters[cursor] != nullptr)
    {
      return find(str + 1) || characters[cursor]->find(str + 1);
    }

    if (hasWildCard)
    {
      return find(str + 1);
    }

    if (characters[cursor] != nullptr)
    {
      return characters[cursor]->find(str + 1);
    }

    if (characters[WILD] != nullptr)
    {
      characters[WILD]->hasWildCard = true;
      bool ret2 = characters[WILD]->find(str + 1);
      characters[WILD]->hasWildCard = false;
      return ret1 || ret2;
    }

    if (characters[QM] != nullptr)
    {
      return characters[QM]->find(str + 1);
    }

    return false;
  }
};

int main()
{
  freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--)
  {
    int n;
    string w;

    cin >> w;
    Trie_node wildStr;
    wildStr.insert(w.c_str());

    cin >> n;
    string fileName;
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
      cin >> fileName;
      if (wildStr.find(fileName.c_str()))
      {
        res.push_back(fileName);
      }
    }
    sort(res.begin(), res.end());
    for (string str : res)
    {
      cout << str << '\n';
    }
  }

  return 0;
}