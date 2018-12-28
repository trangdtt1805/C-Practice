#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

char Matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};

void board()
{
	system("cls");
	cout<<"       Tictactoe\n"<<endl;

	cout<<"Player 1 (X)  -  Player 2 (O)"<<endl<<endl;
	cout<<endl;
	cout<<"           "<<Matrix[0][0]<<"  |  "<<Matrix[0][1] << "  |  " << Matrix[0][2]<<endl;
	cout<<"           " << Matrix[1][0] << "  |  "<<Matrix[1][1]<<"  |  "<<Matrix[1][2]<<endl;
	cout<<"           "<< Matrix[2][0]<<"  |  "<<Matrix[2][1]<<"  |  "<<Matrix[2][2]<<endl;
  }
void Playgame()
{
	board();
	char Player1[20];
	char Player2[20];
	cout<<"Enter Player 1 Name: "; cin>>Player1;
	cout<<"Enter Player 2 Name: "; cin>>Player2;
	//cout<<"\nPlease enter the numberrow_ numbercolum [12]";
    char mark;
    int choice;
    for ( int k = 1; k < 10 ; k ++) {

        if ( k%2 == 0) {
            cout << "Your turn "<<Player1<< endl;
            mark = 'X';
        }
        else {
            cout<<"Your turn "<<Player2<< endl;
            mark = 'O';
        }
        cout << "Please enter your choice" << endl;
        cin >> choice;
        switch(choice)
        {
        	case 1:Matrix[0][0]=mark;
        			board();
        			break;
        	case 2:Matrix[0][1]=mark;
        			board();
        			break;
        	case 3:Matrix[0][2]=mark;
        			board();
        			break;
        	case 4:Matrix[1][0]=mark;
        			board();
        			break;
      	    case 5:Matrix[1][1]=mark;
        			board();
        			break;
        	case 6:Matrix[1][2]=mark;
        			board();
        			break;
        	case 7:Matrix[2][0]=mark;
        			board();
        			break;
        	case 8:Matrix[2][1]=mark;
        			board();
        			break;
        	case 9:Matrix[2][2]=mark;
        			board();
        			break;		
		}	
		if ((Matrix[0][0] == 'X' && Matrix[0][1] == 'X' && Matrix[0][2] == 'X')
		|| (Matrix[1][0] == 'X' && Matrix[1][1] == 'X' && Matrix[1][2] == 'X')
		|| (Matrix[2][0] == 'X' && Matrix[2][1] == 'X' && Matrix[2][2] == 'X')
			|| (Matrix[0][0] == 'X' && Matrix[1][0] == 'X' && Matrix[2][0] == 'X')
			|| (Matrix[0][1] == 'X' && Matrix[1][1] == 'X' && Matrix[2][1] == 'X')
			|| (Matrix[0][2] == 'X' && Matrix[1][2] == 'X' && Matrix[2][2] == 'X')
				|| (Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X')
				|| (Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X')
				|| (Matrix[0][0] != '1' && Matrix[0][1] != '2' && Matrix[0][2] != '3' 
        			&& Matrix[1][0] != '4' && Matrix[1][1] != '5' && Matrix[1][2]!= '6' 
       				&& Matrix[2][0] != '7' && Matrix[2][1] != '8' && Matrix[2][2] != '9'))
    	{
			cout<<Player1<<" Win"; 
			getch();
			//exit(0);
		}
		else if ((Matrix[0][0] == 'O' && Matrix[0][1] == 'O' && Matrix[0][2] == 'O')
			|| (Matrix[1][0] == 'O' && Matrix[1][1] == 'O' && Matrix[1][2] == 'O')
			|| (Matrix[2][0] == 'O' && Matrix[2][1] == 'O' && Matrix[2][2] == 'O')
				|| (Matrix[0][0] == 'O' && Matrix[1][0] == 'O' && Matrix[2][0] == 'O')
				|| (Matrix[0][1] == 'O' && Matrix[1][1] == 'O' && Matrix[2][1] == 'O')
				|| (Matrix[0][2] == 'O' && Matrix[1][2] == 'O' && Matrix[2][2] == 'O')
					|| (Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O')
					|| (Matrix[0][2] == 'O' && Matrix[1][1] == 'O' && Matrix[2][0] == 'O')
					|| (Matrix[0][0] != '1' && Matrix[0][1] != '2' && Matrix[0][2] != '3'
        				&& Matrix[1][0] != '4' && Matrix[1][1] != '5' && Matrix[1][2]!= '6'
       					&& Matrix[2][0] != '7' && Matrix[2][1] != '8' && Matrix[2][2] != '9'))
  		    {
				cout<<Player2<<" Win"; 
				getch();
				//exit(0);
			}
			else {
			cout<<"Game draw!!!";
			}
	}		
}
int main()
{
	cout<<"      Welcome To Tic-tac-toe game! Play with your way!"<<endl;
	cout<<"\nIf you find any problem, please contact dttt@gameloft.com\n"<<endl;
	int chon,chon1;
	string x;
	
	do{
		cout<<"Chose: \n";
		cout<<"1. Play game\n";
		cout<<"2. Exit\n";
		cout<<"chon (1/2): "; cin>>chon;	
		while (chon>2)
	{
		cout<<"Moi ban chon lai: ";
		cin>>chon1;
		chon = chon1;	
	} switch (chon)
		{
			case 1:
				Playgame();
				break;
			case 2:
				exit;
				break;
		}
		cout<<"\nTiep tuc (y/n): ";cin>>x;
		} while(x == "y");	
	
	getch();

}
