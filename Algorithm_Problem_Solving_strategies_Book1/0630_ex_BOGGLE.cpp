#include <iostream>
#include <string>

using namespace std;

bool exist = false;

void bruteHasWord(const char input[][10], int remain_cnt, const string word, 
                string combine, int x, int y, const int input_size)
{
    if(remain_cnt == 0)
    {
        cout << combine << endl;
        if(combine == word)
        {
            exist = true;
        }
        return;
    }

    combine += input[x][y];
    if(x-1 >= 0)
        bruteHasWord(input, remain_cnt-1, word, combine, x-1, y, input_size);
    if(x-1 >= 0 && y-1 >= 0)
        bruteHasWord(input, remain_cnt-1, word, combine, x-1, y-1, input_size);
    if(y-1 >= 0)
        bruteHasWord(input, remain_cnt-1, word, combine, x, y-1, input_size);
    if(x+1 < input_size)
        bruteHasWord(input, remain_cnt-1, word, combine, x+1, y, input_size);
    if(y+1 < input_size)
        bruteHasWord(input, remain_cnt-1, word, combine, x, y+1, input_size);
    if(y-1 >= 0 && x+1 < input_size)
        bruteHasWord(input, remain_cnt-1, word, combine, x+1, y-1, input_size);
    if(y+1 < input_size && x+1 < input_size)
        bruteHasWord(input, remain_cnt-1, word, combine, x+1, y+1, input_size);
    if(y+1 < input_size && x-1 >= 0)
        bruteHasWord(input, remain_cnt-1, word, combine, x-1, y+1, input_size);
}

const int index_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int index_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool hasWord(int x, int y, char input[][10], const int input_size, const string word)
{
    if(x < 0 || x >= input_size || y < 0 || y >= input_size) return false;
    if(input[x][y] != word[0]) return false;
    if(word.size() == 1) return true;

    for(int i = 0; i < 8; i++)
    {
        if(hasWord(x+index_x[i], y+index_y[i], input, input_size, word.substr(1)))
            return true;
    } 
    return false;
}

int main()
{
    int input_size;
    char input[10][10];
    string word;
    string blank = "";
    cin >> input_size >> word;

    for(int i = 0; i < input_size; i++)
    {
        for(int j = 0; j < input_size; j++)
        {
            cin >> input[i][j];
        }
    }

    for(int i = 0; i < input_size; i++)
    {
        for(int j = 0; j < input_size; j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }

    /* 
    //brute방식에서 사용
    for(int i = 0; i < input_size; i++)
    {
        for(int j = 0; j < input_size; j++)
        {
             bruteHasWord(input, word.size(), word, blank, i, j, input_size);          
        }
    }
    */

   for(int i = 0; i < input_size; i++)
    {
        for(int j = 0; j < input_size; j++)
        {
            if(hasWord(i, j, input, input_size, word))
            {
                exist = true;
            }          
        }
    }

    if(!exist)
        cout << "Can't find that word" << endl;
    else
        cout << "We found it" << endl;

    return 0;
}

/*
// input example
pretty
u r l p m
x p r e t
g i a e t
x t n z y
x o q r s
 */