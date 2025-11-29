#include<stdio.h>
#include<string.h>
char board[3][3];
//function to print the board and place the move
void printboard(int row, int col,int player)
{
    printf("\n");
    if(player==1)
    {
	  board[row][col]='X';
    }
    else
    {
    	board[row][col]='O';
	}
	for(int  i=0;i<3;i++)
	{
		printf("  %c| %c |%c",board[i][0],board[i][1],board[i][2]);
		if(i!=2)
		{
			printf("\n---+---+---\n");
		}
	}
	printf("\n");
}
//function to check if row and col value is valid
int checkvalue(int row ,int col)
{
	if(row<0||row>=3||col<0||col>=3)
    {
    	printf("Invalid input... Try Again.\n");
    	return 0;
	}
	else
	{
		return 1;
	}
}
//Function to check if a box is empty
int boxempty(char board[3][3],int row,int col)
{
	if(!(board[row][col]=='X'||board[row][col]=='O'))
	{
		return 1;
	}
	return 0;
}
//function to check the winner 
char checkwinner(char board[3][3],int player,int row,int col)
{
	
	//check winner from row wise//
	for(int i=0;i<3;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
		}
	}
	//check winner from column wise //
	for(int i=0;i<3;i++)
	{
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]!=' ')
		{
			return board[0][i];
			
		}
 }
	//check winner diagonally (1) //
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' ')
	{
		return board[0][0];
	}
	//check winner digonally (2)//
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=' ')
	{
		return board[0][2];
	}
    return 0;//no winner yet
}

int main ()
{

	char player1[20],player2[20];
	int player=1;
	int check;
	int row,col;
	char winner;
	//initialize board with empty spaces
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=' ';
		}
	}
	//get player names
	printf("\t\tWelcome to Tic Tac Toe Game.. \n\n");
	printf("Enter name Player X : ");
	scanf("%s",&player1);
	printf("\n\nEnter name Player O : ");
	scanf("%s",&player2);
	// game loop for max 9 moves
	for(int i=0;i<9;i++)
	{
	    do
		{
			// show turn
		if(player==1)
		{
			printf("\n\n%s ( X ) turns",player1);
		}
		else
		{	
		    printf("\n\n%s ( O ) turns",player2);
		}
		// Input move 
		printf("\n\nEnter value of row and column (0,1,2):");
		scanf("%d%d",&row,&col);
		check=checkvalue(row,col);
		if(check==1&&boxempty(board,row,col)==1)
		{
			printboard(row,col,player);
		    winner=checkwinner(board,player,row,col);
		if(winner=='X'||winner=='O')
		break;
		
		    player=(player==1)?2:1;
		    break;
        }
        else if(boxempty(board,row,col)==0)
        {
        	printf("Box already filled..Try Again\n");
		    
		}
		check=0;
		}
		while(check==0);
	    //if winner found,break loop early
	    if(winner=='X'||winner=='O')
	    break;
	}
// final result
	if(winner=='X')
	{
		printf("\n\nplayer %s (X) win the game.....\n\n congrats",player1);
	}
	else if(winner=='O')
	{
		printf("\n\nplayer %s (O) win the game.....\n\n congrats",player2);
	}
	else
	{
		printf("\n\noops.. Its a draw\n\nTry Again"); 
	}
	return 0;
}
