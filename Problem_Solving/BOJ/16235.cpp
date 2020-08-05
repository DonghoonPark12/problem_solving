#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;
int i, j;

int n, m, k;

typedef struct _g {
    int y;
    deque<int> dq;
}G;

G arr[10][10];

int wy[10][10];

int solve();

int main()
{
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> wy[i][j];
            arr[i][j].y = 5;
        }
    }

    int x, y, Y;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> Y;
        arr[y][x].dq.push_back(Y); //weak
    }

    cout << solve();

    return 0;
}

int solve()
{
    int cnt = 0;
    while (k--)
    {
        //봄 : 양분 시식

        /*if ()
        {

        }
        else
        {

        }*/

        //여름 : 죽은 나무 --> 양분


        //가을 : 번식


        //겨율 : 양분 추가


    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cnt += arr[i][j].dq.size();
        }
    }

    return cnt;
}