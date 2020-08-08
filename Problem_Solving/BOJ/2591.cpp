#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

//#define MAX(i, j) ( ((i) > (j)) ? (i) : (j) )
//#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int n, m;
char map[51][51];
bool visited[51][51];

const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

struct INFO
{
    int y, x, d;
};

int bfs(int i, int j) //y, x
{
    int dist = 0;
    queue<INFO> q;
    q.push({ i, j, 0 });
    visited[i][j] = true;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (visited[ny][nx] || map[ny][nx] == 'W') continue;

            q.push({ ny, nx, d + 1 });
            visited[ny][nx] = true;
            dist = max(dist, d + 1);
        }
    }
    return dist;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L')
            {
                memset(visited, false, sizeof(visited));
                ans = max(ans, bfs(i, j));
            }
        }
    }
    printf("%d ", ans);
    return 0;
}