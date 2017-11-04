#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define M 10
#define N 10

struct Node 
{
	int x, y, dist;
};

// Possible movements from a cell (diagonal movemente permited)
int row[] = { -1, 0, 0, 1};
int col[] = { 0, -1, 1, 0};

bool isValid(int mat[][N], bool visited[][N], int row, int col)
{
	return (row >= 0) && (row < M) && (col >= 0) && (col < N) 
		&& mat[row][col] && !visited[row][col];
}

void Pathfinder(int mat[][N], int i, int j, int x, int y)
{
	bool visited[M][N];
	
	memset(visited, false, sizeof visited);
	
	queue<Node> q;

	visited[i][j] = true;
	q.push({i, j, 0});

	int min_dist = -1;
	
	while (!q.empty()) 
	{
		Node node = q.front();
		q.pop();
		
		int n = node.x, m = node.y, dist = node.dist;

		if (n == x && m == y) 
		{
			min_dist = dist;
			break;
		}

		for (int k = 0; k < 4; k++) 
		{
			if (isValid(mat, visited, n + row[k], m + col[k])) 
			{
				visited[n + row[k]][m + col[k]] = true;
				q.push({ n + row[k], m + col[k], dist + 1 });
			}
		}
	}

	if (min_dist > -1)
		cout << "The shortest path from source to destination has length " << min_dist;
	else
		cout << "Destination can't be reached";
}

int main()
{
	int mat[M][N] = 
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	};
	
	Pathfinder(mat, 0, 0, 1, 5);

	return 0;
}
