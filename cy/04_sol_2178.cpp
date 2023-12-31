/* BFS */
/*
#include <stdio.h>
#include <queue>
#include <iostream>
int map[101][101];
bool gone[101][101] = {false, };
int count[101][101] = {0, };
int n, m;
void bfs(int x, int y)
{
    gone[x][y] = true;
    std::queue<std::pair<int, int>> queue;
    queue.push(std::make_pair(x, y));
    count[x][y]++;
    while(!queue.empty())
    {
        int a = queue.front().first;    //x
        int b = queue.front().second;   //y
        queue.pop();
        for(int i = 0; i < 4; i++)
        {
            int x_dir[4] = {-1, 1, 0, 0};
            int y_dir[4] = {0, 0, -1, 1};
            int x_move = a + x_dir[i];
            int y_move = b + y_dir[i];
            if ( (0 <= x_move && x_move < n) && (0 <= y_move && y_move < m) && !gone[x_move][y_move] && map[x_move][y_move] == 1 )
            {
                gone[x_move][y_move] = true;
                queue.push(std::make_pair(x_move, y_move));
                count[x_move][y_move] = count[a][b] + 1;
            }
        }
    }
}

int main(void)
{

    std::cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    bfs(0, 0);
    printf("%d", count[n-1][m-1]);
}
*/

/* DFS */
/*
#include <stdio.h>
#include <iostream>
#define MAX_DEPTH 10001
int map[101][101];
int min = MAX_DEPTH;
int x_dir[4] = {1, 0, -1, 0};
int y_dir[4] = {0, 1, 0, -1};
int gone[101][101];
int n, m;
void dfs(int x, int y, int depth)
{
    if(x < 0 || y < 0 || x >= n || y >= m)
    {
        return;
    }
    if(x == n - 1 && y == m - 1)
    {
        if(min > depth)
        {
            min = depth;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        int x_move = x + x_dir[i];
        int y_move = y + y_dir[i];
        if(gone[x_move][y_move] == 0 && map[x_move][y_move] == 1)
        {
            gone[x_move][y_move] = 1;
            dfs(x_move, y_move, depth + 1);
            gone[x_move][y_move] = 0;
        }
    }
}

int main(void)
{

    std::cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    dfs(0, 0, 1);
    printf("%d", min);
}
*/