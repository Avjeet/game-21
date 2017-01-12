#include<string>
#include"singleplayer.cpp"


int multiplayer(){
	char pl_1[20],pl_2[20];
	COORD POS;
	int n1=0,n2=0;
	bool flag;
	system("cls");
	fflush(stdin);
	gotoxy(45,15);
	cout<<"Player 1 - Name:- ";
	gets(pl_1);
	system("cls");
	gotoxy(45,17);
	cout<<"Player 2 - Name:- ";
	gets(pl_2);
	system("cls");
	while(1){
	    cout<<"\n";
		POS=getxy();
		cout<<pl_1<<" :";
		cin>>n1;
		flag=true;
		while(flag){
		    try{
			    
			    if(n1-n2>3 ||  n1-n2<1){
					Constraints r;
					throw r;
                }
	        
	           flag=false;
            }catch(Constraints r){
            	setxy(POS);
        	cout<<r.what()<<"\n\n"<<pl_1<<" :   \b\b\b";
        	cin>>n1;
            }
		}
		if(n1>=21){
			cout<<endl<<pl_2<<" is winner!!";
			break;
		}			
		
		cout<<"\n";
		POS=getxy();
		cout<<pl_2<<" :";
		cin>>n2;
		flag=true;
		while(flag){
		    try{
				
	    		if(n2-n1>3 || n2-n1<1){
	    			Constraints r;
	    			throw r;
	    		}
	    		flag=false;
	    	}catch(Constraints r){
	    		setxy(POS);
	    		cout<<r.what()<<"\n\n"<<pl_2<<" :   \b\b\b";
	    		cin>>n2;
			}
		}
	    
		if(n2>=21){
			cout<<endl<<pl_1<<" is winner";
			break;
		}
	}
}
