#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define max 3

using namespace std;

list <int> list_Student;

void Board(char Matrix[max][max])
{
	system("cls");
	cout<<"       Tictactoe\n"<<endl;

	cout<<"Player 1 (O)  -  Player 2 (X)"<<endl<<endl;
	cout<<endl;
	cout<<Matrix[0][0]<<"  |  "<<Matrix[0][1]<<"  |  "<<Matrix[0][2]<<endl;
	//cout<<"___ _____ ____";
	cout<<endl;
	cout<<Matrix[1][0]<<"  |  "<<Matrix[1][1]<<"  |  "<<Matrix[1][2]<<endl;
	//cout<<"___ _____ ____";
	cout<<endl;
	cout<<Matrix[2][0]<<"  |  "<<Matrix[2][1]<<"  |  "<<Matrix[2][2]<<endl;
}
bool checkEmpty(char Matrix[max][max], int a, int b) 
{
	if (Matrix[a][b] == ' ') return true;
	else return false;
}

int getGameStatus(char Matrix[max][max]) {
	int win = 0;
	if (win == 0) {
		for (int i = 0; i < max; i++) {
			switch (Matrix[i][0])
			{
			case 'X':
				if (Matrix[i][0] == Matrix[i][1] && Matrix[i][1] == Matrix[i][2])
					win = 1;
				break;
			case 'O':
				if (Matrix[i][0] == Matrix[i][1] && Matrix[i][1] == Matrix[i][2])
					win = 2;
				break;
			default:
				break;
			}
		}
		if (win == 0) {
			for (int j = 0; j < max; j++) {
				switch (Matrix[0][j])
				{
				case 'O':
					if (Matrix[0][j] == Matrix[1][j] && Matrix[1][j] == Matrix[2][j])
						win = 1;
					break;
				case 'X':
					if (Matrix[0][j] == Matrix[1][j] && Matrix[1][j] == Matrix[2][j])
						win = 2;
					break;
				default:
					break;
				}
			}
		
		if (win == 0) {
				switch (Matrix[0][0])
				{
				case 'O':
					if (Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])
						win = 1;
					break;
				case 'X':
					if (Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])
						win = 2;
					break;
				default:
					break;
				}	
		if (win == 0)
			switch (Matrix[0][2])
			{
			case 'O':
				if (Matrix[0][2] == Matrix[1][1] && Matrix[2][0] == Matrix[1][1])
					win = 1;
				break;
			case 'X':
				if (Matrix[0][2] == Matrix[1][1] && Matrix[2][0] == Matrix[1][1])
					win = 2;
				break;
			default:
				break;
			}
	}}}
	return win;
}
int PlayGame(char Matrix[max][max], char NamePlayer1[20], char NamePlayer2[20], string check)
{
	int player=1,count=0;
	int number, row, column;
	do
	{
		switch(player)
		{
			case 1: 
				cout<<NamePlayer1<<" enter number: "; cin>>number;
				row = number/10-1;//hàng
				column = number%10-1; //cot
				
				if (checkEmpty(Matrix,row,column) == true) Matrix[row][column] = 'O';
				else
				{
					do
					{
						cout<<"Please enter number: "; cin>>number;
						row = number/10-1;//hàng
						column = number%10-1; //cot
					} while (checkEmpty(Matrix,row,column) == false);
					  Matrix[row][column] = 'X';
				}
				Board(Matrix);
				switch (getGameStatus(Matrix))
				{
				case 1: cout << "PLAYER 1 WIN!!!" << endl;
					check = "win";
					break;
				case 2: cout << "PLAYER 2 WIN!!!" << endl;
					check = "win";
					break;
				default:
					break;
				}	
			if (check =="playing")
			{
				player++;
				count++;
			}
			if (count == 9) {
			cout << "DRAW GAME!!!"<<endl;
			check = "draw";
			break;
			}
				break;
			case 2:
				cout<<NamePlayer2<<" enter number: "; cin>>number;
				row = number/10-1;//hàng
				column = number%10-1; //cot
				if (checkEmpty(Matrix,row,column)) Matrix[row][column] = 'X';
				else
				{
					do
					{
						cout<<"Please enter number: "; cin>>number;
						row = number/10-1;//hàng
						column = number%10-1; //cot
					} while (checkEmpty(Matrix,row,column) == false);
					  Matrix[row][column] = 'O';
				}
				Board(Matrix);
				switch (getGameStatus(Matrix))
				{
				case 1: cout << "PLAYER 1 WIN!!!" << endl;
					check = "win";
					break;
				case 2: cout << "PLAYER 2 WIN!!!" << endl;
					check = "win";
					break;
				default:
					break;
				}		
			if (check =="playing"){
				player--;
				count++;
			}	
				break;						
	}} while (check == "playing");
}
int main()
{
	char Matrix[max][max] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	int choice;
	char NamePlayer1[20], NamePlayer2[20],a;
	string kt="playing";
	cout<<"      Welcome To Tic-tac-toe game! Play with your way!"<<endl;
	cout<<"\nIf you find any problem, please contact dttt@gameloft.com\n"<<endl;
	
	cout<<"Select your mode \n";
	cout<<"1. Play game\n";
	cout<<"2. Exit\n";
	cout<<"You choice (1/2): "; cin>>choice;
	cout<<"Enter your name Player 1: "; cin>>NamePlayer1;
	cout<<"\nEntern your name Player 2: "; cin>>NamePlayer2;	
	do{
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				Matrix[i][j] = ' ';
			}
		}
		switch (choice)
		{
			case 1:
				
				Board(Matrix);
				
				PlayGame(Matrix, NamePlayer1, NamePlayer2,kt);
				break;
			case 2:
				exit;
				break;
		}
		cout<<"ban co muon tiep tuc k (y/n)"; cin>>a;	
	} while ( a=='y' || a == 'Y');
	getch();
}
