/*
//혼자 못품(틀림)
#include <iostream>

using namespace std;

int coverTile(bool board[][21], const int height, const int width, int blank)
{
    if(blank == 0) return 1;
    int ans = 0;
    for(int i = 0; i <height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(board[i][j]) // 타일을 넣을 수 있으면
            {
                board[i][j] = false;
                if(board[i][j+1] && board[i+1][j] && j+1 < width && i+1 < height)
                {
                    board[i][j+1] = false;
                    board[i+1][j] = false;
                    ans += coverTile(board, height, width, blank-3);
                    board[i][j+1] = true;
                    board[i+1][j] = true;
                }
                if(board[i][j+1] && board[i-1][j] && i >= 0 && j+1 < width)
                {
                    board[i][j+1] = false;
                    board[i-1][j] = false;
                    ans += coverTile(board, height, width, blank-3);
                    board[i][j+1] = true;
                    board[i-1][j] = true;
                }
                if(board[i][j-1] && board[i+1][j] && i < height && j >= 0)
                {
                    board[i][j-1] = false;
                    board[i+1][j] = false;
                    ans += coverTile(board, height, width, blank-3);
                    board[i][j-1] = true;
                    board[i+1][j] = true;
                }
                if(board[i][j-1] && board[i-1][j] && i >= 0 && j >= 0)
                {
                    board[i][j-1] = false;
                    board[i-1][j] = false;
                    ans += coverTile(board, height, width, blank-3);
                    board[i][j-1] = true;
                    board[i-1][j] = true;
                }
                board[i][j] = true;
            }
        }
    }
    return ans;
}
int main()
{
    int test_case, height, width;
    char temp;
    cin >> test_case;
    while(test_case--)
    {
        cin >> height >> width;
        bool board[21][21] ={};
        int blank = 0;
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                cin >> temp;
                if(temp == '.')
                {
                    board[i][j] = true;
                    blank++;
                }
            }
        }
        if(blank % 3 != 0)
        {
            cout << 0 <<endl;
            continue;
        }
        cout << coverTile(board, height, width, blank) << endl;
    }
    return 0;
}
*/

//책 방식
#include <iostream>

using namespace std;

int cntCoverCase(bool board[][21], const int height, const int width)
{
    int first_i = -1, first_j = -1;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(board[i][j])
            {
                first_i = i;
                first_j = j;
                break;
            }
        }
        if(first_i != -1) break;
    }

    if(first_i == -1 || first_j == -1) return 1;
    
    int ans = 0;

    if(board[first_i][first_j+1] && board[first_i+1][first_j+1])
    {
        board[first_i][first_j+1] = false;
        board[first_i+1][first_j+1] = false;
        board[first_i][first_j] = false;
        ans += cntCoverCase(board, height, width);
        board[first_i][first_j+1] = true;
        board[first_i+1][first_j+1] = true;
        board[first_i][first_j] = true;
    }
    if(board[first_i+1][first_j] && board[first_i+1][first_j+1])
    {
        board[first_i+1][first_j] = false;
        board[first_i][first_j] = false;
        board[first_i+1][first_j+1] = false;
        ans += cntCoverCase(board, height, width);
        board[first_i+1][first_j] = true;
        board[first_i][first_j] = true;
        board[first_i+1][first_j+1] = true;
    }
    if(board[first_i+1][first_j] && board[first_i+1][first_j-1])
    {
        board[first_i+1][first_j] = false;
        board[first_i][first_j] = false;
        board[first_i+1][first_j-1] = false;
        ans += cntCoverCase(board, height, width);
        board[first_i+1][first_j] = true;
        board[first_i][first_j] = true;
        board[first_i+1][first_j-1] = true;
    }
    if(board[first_i][first_j+1] && board[first_i+1][first_j])
    {
        board[first_i][first_j+1] = false;
        board[first_i][first_j] = false;
        board[first_i+1][first_j] = false;
        ans += cntCoverCase(board, height, width);
        board[first_i][first_j+1] = true;
        board[first_i][first_j] = true;
        board[first_i+1][first_j] = true;
    }

    return ans;
}

int main()
{
    int test_case, height, width;
    char temp;
    cin >> test_case;
    while(test_case--)
    {
        cin >> height >> width;
        bool board[21][21] = {};
        int blank = 0;
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                cin >> temp;
                if(temp == '.')
                {
                    board[i][j] = true;
                    blank++;
                }
            }
        }
        if(blank % 3 != 0)
        {
            cout << 0 << endl;
            continue;
        }
        cout << cntCoverCase(board, height, width) << endl;
    }
}