/*

배열을 함수의 인자로 사용할 때 pass by value 하고자 할 경우
struct를 사용하여 옮기면 된다.

(Struct는 pass by value, Array는 pass by reference)
*/

#include <iostream>

using namespace std;

int ans;

struct Board_{
    int x[21][21];
};

int findMax(int board[][21], int size)
{
    int temp = 0;
    for(int i = 0; i < size; i ++)
    {
        for(int j = 0; j < size; j++)
        {
            if(temp < board[i][j])
                temp = board[i][j];
        }
    }
    return temp;
}

Board_ left_move(Board_ board, int size)
{
    
    for(int i = 0; i < size; i++)
    {
        int temp = board.x[i][0];
        int index = 0;
        for(int j = 1; j < size; j++)
        {
            if(board.x[i][j] == 0)
                continue;
            if(temp == 0)
            {
                temp = board.x[i][j];
                board.x[i][index] = temp;
                board.x[i][j] = 0;
            }
            else
            {
                if(temp == board.x[i][j])
                {
                    board.x[i][index++] = temp * 2;
                    board.x[i][j] = 0;
                    temp = 0;
                }
                else
                {
                    temp = board.x[i][j];
                    board.x[i][j] = 0;
                    board.x[i][++index] = temp;
                }
            }
        }
    }
    return board;
}

Board_ right_move(Board_ board, int size)
{

    for(int i = 0; i < size; i++)
    {
        int temp = board.x[i][size - 1];
        int index = size - 1;
        for(int j = size - 2; j >= 0; j--)
        {
            if(board.x[i][j] == 0)
                continue;
            if(temp == 0)
            {
                temp = board.x[i][j];
                board.x[i][index] = temp;
                board.x[i][j] = 0;
            }
            else
            {
                if(temp == board.x[i][j])
                {
                    board.x[i][index--] = temp * 2;
                    board.x[i][j] = 0;
                    temp = 0;
                }
                else
                {
                    temp = board.x[i][j];
                    board.x[i][j] = 0;
                    board.x[i][--index] = temp;
                }
            }
        }
    }
    return board;
}

Board_ up_move(Board_ board, int size)
{

    for(int j = 0; j < size; j++)
    {
        int temp = board.x[0][j];
        int index = 0;
        for(int i = 1; i < size; i++)
        {
            if(board.x[i][j] == 0)
                continue;
            if(temp == 0)
            {
                temp = board.x[i][j];
                board.x[index][j] = temp;
                board.x[i][j] = 0;
            }
            else
            {
                if(temp == board.x[i][j])
                {
                    board.x[index++][j] = temp * 2;
                    board.x[i][j] = 0;
                    temp = 0;
                }
                else
                {
                    temp = board.x[i][j];
                    board.x[i][j] = 0;
                    board.x[++index][j] = temp;
                }
            }
        }
    }
    return board;
}

Board_ down_move(Board_ board, int size)
{

    for(int j = 0; j < size; j++)
    {
        int temp = board.x[size - 1][j];
        int index = size-1;
        for(int i = size - 2; i >= 0; i--)
        {
            if(board.x[i][j] == 0)
                continue;
            if(temp == 0)
            {
                temp = board.x[i][j];
                board.x[index][j] = temp;
                board.x[i][j] = 0;
            }
            else
            {
                if(temp == board.x[i][j])
                {
                    board.x[index--][j] = temp * 2;
                    board.x[i][j] = 0;
                    temp = 0;
                }
                else
                {
                    temp = board.x[i][j];
                    board.x[i][j] = 0;
                    board.x[--index][j] = temp;
                }
            }
        }
    }

    return board;
}

void searchMax(Board_ board, int size, int deep)
{
    if(deep == 5)
    {
        int temp = findMax(board.x, size);
        if(ans < temp)
            ans = temp;
    }
    else
    {
        Board_ result;
        result = left_move(board, size);
        searchMax(result, size, deep + 1);
        result = right_move(board, size);
        searchMax(result, size, deep + 1);
        result = up_move(board, size);
        searchMax(result, size, deep + 1);
        result = down_move(board, size);
        searchMax(result, size, deep + 1);
        
    }

}

int main()
{
    int size;
    cin >> size;
    Board_ board;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cin >> board.x[i][j];
        }
    }
  
    searchMax(board, size, 0);

    cout << ans << endl;
    
}

