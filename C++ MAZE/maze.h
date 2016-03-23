#include<iostream.h>



#ifndef _MAZE_H
#define _MAZE_H

#define MAX 100



class Maze{

private:


int	stack[MAX][2];		//stack
int full;
	
public:
	
		Maze();
	bool push(int x,int y);
	bool pop();
	int get(int xy);

	bool is_full();
	bool is_empty();
	
};



#endif
