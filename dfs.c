const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

void	dfs(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 콜백 방지 ?
		if (nx < 0 || width <= nx || ny < 0 || height <= ny)
			continue;
		
		if (visited[nx][ny])
			continue;

		dfs(nx, ny);
	}
}