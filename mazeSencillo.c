/* C/C++ program to solve Rat in a Maze problem using
backtracking */
#include<stdio.h>

// Maze size (:
#define N 4 

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N],int xa[2],int ya[2]);

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x,y outside maze) return false
	if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;

	return false;
}

/* This function solves the Maze problem using Backtracking. It mainly
uses solveMazeUtil() to solve the problem. It returns false if no 
path is possible, otherwise return true and prints the path in the
form of 1s. Please note that there may be more than one solutions, 
this function prints one of the feasible solutions.*/
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { {1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int x[2]={1,0};
    int y[2]={0,1};
	if(solveMazeUtil(maze, 0, 0, sol,x,y) == false)
	{
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol);
	return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N],int xa[2],int ya[2])
{
	// if (x,y is goal) return true
	if(x == N-1 && y == N-1)
	{
		sol[x][y] = 1;
		return true;
	}

for(int i=0;i<2;i++)
{
    
int nx=x+xa[i];
int ny=y+ya[i];
	// Check if maze[x][y] is valid
	if(isSafe(maze, nx, ny) == true)
	{
		// mark x,y as part of solution path
		sol[x][y] = 2;

		/* Move forward in x direction */
		if (solveMazeUtil(maze, nx, ny, sol,xa,ya) == true)
			return true;

		

		/* If none of the above movements work then BACKTRACK: 
			unmark x,y as part of solution path */
		sol[x][y] = 0;
		
	} 
}
	return false;
}

// driver program to test above function
int main()
{
	int maze[N][N] = { {1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};

	solveMaze(maze);
	return 0;
}
