#include<iostream>
#include<cstdlib>
#include<ctime>
#include<exception>
#include<windows.h>
using namespace std;



void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


COORD getxy(){
	CONSOLE_SCREEN_BUFFER_INFO t;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&t);
	return t.dwCursorPosition;
	}
void setxy(COORD set_pos){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),set_pos);
}


class Constraints : public exception {

public:

	const char * what (){
		return "You can only add number from 1-3";
		}
	const char * what(bool flag){
		return "\nInvalid Input\n\n ";
	}	
};
using namespace std;


int singleplayer(){
	COORD position;
	int n=0,comp=0;
	char ch;
	bool flag=true;
    system("cls");
    gotoxy(45,15);

while(flag){

	try{
	    cout<<"Do you want to start ?(y/n)  ";
	    cin>>ch;
        system("cls");
        
		if(ch!='y' && ch!='n'){
	        Constraints p;
	        throw p;
	    }
	    flag=false;
    }catch(Constraints p){
	    cout<<p.what(flag);
	}

}

	if(ch=='y'){
		while(1){
			cout<<"\n\n";
			position=getxy();
			cout<<"Player :";
			cin>>n;
		 flag=true;
		
		    while(flag){
			  try{
			    if((n-comp>3 || n-comp<1)&&comp!=20){
				    Constraints s;
					throw s;
		        }
			    flag=false;
				
				}catch(Constraints s){
					setxy(position);
					cout<<s.what()<<"\n\nPlayer :"<<"   \b\b\b";
					cin>>n;
				}
	        }
			
			if(n<21){
				comp=n+(4-(n%4));
				cout<<"\nComputer :"<<comp;
			}
			else{
				if(n==21)
				cout<<"\nComputer is the winner,Better Luck next time";
			    else
			    cout<<"\nDont try to be smart ,You have lost :P";
			    break;
			}
		}
    }else{
        srand(time(NULL));
		comp=(rand()%3)+1;
	    cout<<"\nComputer :"<<comp;
	     
		while(1){
	        cout<<"\n\n";
	        position=getxy();
			cout<<"Player :";
	    	cin>>n;
	    	flag=true;
	    	while(flag){
	      	    try{
				    if(n-comp>3 || n-comp<1){
					Constraints s;
					throw s;
				    }
				    flag=false;
				}catch(Constraints s){
					setxy(position);
					cout<<s.what()<<"\n\nPlayer :"<<"   \b\b\b";
					cin>>n;
				}
			}
	    	if(n>=21){
	    		if(n==21)
				cout<<"\nComputer is the winner,Better Luck next time";
			    else
			    cout<<"\nDont try to be smart ,You have lost :P";
			    break;
			    }
			    
	    	
			if(n%4==0){
	    		srand(time(NULL));
		        comp=n+(rand()%3)+1;
			}else
				comp=n+(4-(n%4));	
			
			if(comp>=21){
			    cout<<"\nComputer :21\n\nComputer lost,You are the winner :D";
			    break;
		    }
		    cout<<"\nComputer :"<<comp;
		}
	}
}
	

