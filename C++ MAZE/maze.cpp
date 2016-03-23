#include<iostream.h>
#include<fstream.h>
#include "maze.h"



/********************************************************************/
/*						DEFAULT CONSTRUCTOR							*/
/********************************************************************/


Maze::Maze(){

full=0;//EMPTY

/****MAKE STACK EMPTY****/

for(int i=0;i<MAX;i++) 
{
	for(int j=0;j<2;j++)

		stack[i][j]=NULL;

}


}


//END - DEFAULT CONSTRUCTOR
/*********************************PUSH*******************************/
bool Maze::push(int x,int y){

if(is_full()==false)
{
	stack[full][0]=x;
	stack[full][1]=y;
	full++;
	return true;
}

else  {cout<<"\nStack is full.";return false;}

}
/************************************POP*******************************/

bool Maze::pop(){

if(!is_empty())
{

	full--;
	return true;
}
else return false;


}

/************************************IS_FULL*****************************/

bool Maze::is_full(){

	
	if(full==MAX) return true;
	
	else return false;

}

/************************************IS_EMPTY****************************/
bool Maze::is_empty(){

	if(full!=0) return false;

	else return true;
}


/*********************************GET***********************************/

int Maze::get(int xy){

	return stack[full-1][xy];
}



/********************************************************************/
/*								SOLVE								*/
/********************************************************************/

int check_right(int x,int y);
int check_left(int x,int y);
int check_down(int x,int y);
int check_up(int x,int y);
void visited(int x,int y,int count);
bool check_all_directions(int x,int y,int t); //check all directions for t (ex:t=0 look for road) 

//GLOBAL VARIABLE
int maze_array[MAX][MAX];
Maze A;//Construct a stack
int mx,my;
main()
{

	int i,j,sx,sy;
	int move_num=0,movement[MAX][2];
	bool success=false;
	int direction=0;

	mx=my=sx=sy=0;
	
	
/********************READ INPUT FILE**************************/
	int input;

	ifstream  Maze_input;

	Maze_input.open("input.txt");

	Maze_input >> input;

	mx=input;
	
	Maze_input >> input;

	my=input;

	Maze_input >> input;

	sx=input;

	Maze_input >> input;

	sy=input;
	
	
	//READ MAZE FROM FILE
	
	for(i=0;i<mx;i++) 
	{
		for(j=0;j<my;j++)
		{
		
		Maze_input >> input;

		maze_array[i][j]=input;
		
		}
	
	}
	
Maze_input.close();
/***********************************END - READ***************************************/


/*****************************PRINT (VARIABLES )*************************************/
	
cout<<"MAZE  (x,y) : ("<<mx<<","<<my<<")\n";//MAZE bounds
cout<<"Start (x,y) : ("<<sx<<","<<sy<<")\n";//Start Coordinates
	

//MAZE
cout<<"\nMAZE :\n";
	
for(i=0;i<mx;i++)
{
	cout<<"\n";

	for(j=0;j<my;j++)

	cout<<maze_array[i][j]<<" ";	

}

/***************************END - PRINT (VARIABLES)*********************************/


/***********************************SOLVE MAZE**************************************/

	

visited(sx,sy,3);


if(maze_array[sx][sy]!=2) // Check Start Coodinates
{

direction=1;
cout<<"\n";

	while(direction!=0)

	{
		cout<<"\n"<<sx<<","<<sy;
		movement[move_num][0]=sx;
		movement[move_num][1]=sy;
		move_num++;

		if( check_all_directions(sx,sy,2) )
		{
		
		sx=A.get(0);
		sy=A.get(1);
		direction=0;
		success=true;
		cout<<"\n"<<sx<<","<<sy;				
		
		movement[move_num][0]=sx;
		movement[move_num][1]=sy;
		move_num++;

		}
		
		else if( check_all_directions(sx,sy,0) ) //Check for clear path
		{
				
		
		sx=A.get(0);
		sy=A.get(1);
		visited(sx,sy,3);			
		
		}


		
		else if(A.pop())
		{	
			
			sx=A.get(0);
			sy=A.get(1);
				
				
		}
		
		

		else direction=0;
			

		
		
		

	};

}

else cout<<"Your 'Start' coordinates are 'Exit' coordinates of Maze!";

if(success) cout<<"\nExit found at ("<<sx<<","<<sy<<")"<<"   :"<<move_num;
else cout<<"Maze Solve failed - There is no exit";
/******************************END - SOLVE MAZE*******************************/

ofstream Maze_output;
Maze_output.open("output.txt");
Maze_output<<move_num;

for(i=0;i<move_num;i++)
{

Maze_output<<"\n"<<movement[i][0]<<" "<<movement[i][1];

}

Maze_output.close();



return 0;
}

/**********************************************************************************/
/*								END OF MAIN                                       */
/**********************************************************************************/


/******************************************MAIN FUNCTIONS***********************/


int check_right(int x,int y)//RIGHT
{

return maze_array[x+1][y];

}

int check_left(int x,int y)//LEFT
{

return maze_array[x-1][y];

}

int check_up(int x,int y)//UP
{

return maze_array[x][y-1];

}

int check_down(int x,int y)//DOWN
{

return maze_array[x][y+1];

}

void visited(int x,int y,int count)//VISITED
{
maze_array[x][y]=count;
}


bool check_all_directions(int x,int y,int t)
{
	bool suc=false;

	int c=0;

		
		if(check_right(x,y)==t && x+1<mx && x+1>=0)
		{
			A.push(x+1,y);suc=true;c++;visited(x+1,y,3);
		}
		if(check_down(x,y)==t && y+1<my && y+1>=0)
		{
			if(c>0) {A.push(x,y);}visited(x,y+1,3);A.push(x,y+1);suc=true;c++;
		}
		if(check_left(x,y)==t && x-1<mx && x-1>=0)
		{
			if(c>0) {A.push(x,y);}visited(x-1,y,3);A.push(x-1,y);suc=true;c++;
		}
		if(check_up(x,y)==t && y-1<mx && y-1>=0)
		{
			if(c>0) {A.push(x,y);}visited(x,y-1,3);A.push(x,y-1);suc=true;c++;
		}

		
return suc;
}
