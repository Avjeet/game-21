#include"multiplayer.cpp"
int main(){
	    int choice;
		gotoxy(50,15);
		cout<<"THE 21 GAME";
		Sleep(3000);
	system("cls");
		
        gotoxy(50,14);
        cout<<"Loading";
	for(int i=1;i<=10;i++){
		gotoxy(58+(i%3+1),14);
		cout<<".";
		gotoxy(36+i*3,15);
		cout<<"___";
		gotoxy(67,15);
		cout<<(i)*10<<"%";
		Sleep(i*100);
	}
	system("cls");
	cout<<"Instruction :-\n\n\n->It is a simple IQ based game. \n\n->The game will start from 0. \n\n3.)Each player has to increase the number by either 1,2 or 3.\n\n4.)The first player to say 21 loses.\n\n\t";
	system("pause");
	
	system("cls");
	gotoxy(35,10);
	cout<<"MODES :-";
	gotoxy(40,13);
	cout<<"1.)Player Vs Player   2.)Player Vs Computer ";
	cin>>choice;
	switch(choice){
		case 1:{
			multiplayer();
			break;
		}
		
		case 2:{
			singleplayer();
			break;
		}
		default:
			{
				system("cls");
				gotoxy(45,15);
				cout<<"Invalid Input";
			}
	}
	
	}
