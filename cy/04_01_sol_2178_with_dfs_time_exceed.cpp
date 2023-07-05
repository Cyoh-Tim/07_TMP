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