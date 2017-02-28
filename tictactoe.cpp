// initialization of variables

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
 
using namespace std;

char position1= '-';
char position2= '-';
char position3= '-';
char position4= '-';
char position5= '-';
char position6= '-';
char position7= '-';
char position8= '-';
char position9= '-';

char computerSymbol= 'X';
char playerSymbol= '0';

void refreshDisplay()
{
	cout << "\n";
	cout << "      " << "-------------" <<"\n";
	cout << "      " << "| "<< position1 << " | " << position2 << " | " << position3 <<" |" << "\n";
	cout <<	"      " << "-------------" <<"\n";
	cout << "      " << "| "<< position4 << " | " << position5 << " | " << position6 <<" |" << "\n";
	cout <<	"      " << "-------------" <<"\n";
	cout << "      " << "| "<< position7 << " | " << position8 << " | " << position9 <<" |" << "\n";
	cout <<	"      " << "-------------" <<"\n";
}

bool adjustPosition( int position, char symbol )
{
	bool positionAdjusted= false;
	
	switch( position)
	{
		case 1:
			if( position1=='-' )
			{
				position1= symbol;
				positionAdjusted= true;
			}
			break;
		case 2:
		    if( position2=='-' )
			{
				position2= symbol;
				positionAdjusted= true;
			}
			break;
		case 3:
			if( position3=='-' )
			{
				position3= symbol;
				positionAdjusted= true;
			}
			break;
		case 4:
		    if( position4=='-' )
			{
				position4= symbol;
				positionAdjusted= true;
			}
			break;
		case 5:
			if( position5=='-' )
			{
				position5= symbol;
				positionAdjusted= true;
			}
			break;
		case 6:
		    if( position6=='-' )
			{
				position6= symbol;
				positionAdjusted= true;
			}
			break;
		case 7:
			if( position7=='-' )
			{
				position7= symbol;
				positionAdjusted= true;
			}
			break;
		case 8:
            if( position8=='-' )
			{
				position8= symbol;
				positionAdjusted= true;
			}
			break;
		case 9:
	        if( position9=='-' )
			{
				position9= symbol;
				positionAdjusted= true;
			}
			break;
		default:
			cout << "Invalid option selected!" << "\n";
			break;								
	}
	
	return( positionAdjusted );
}

int generateRandomNumber()
{
	srand(time(NULL));
	int number= rand() %9+1;
	return (number);
}

int makeComputerSelection( char symbol )
{
	int choice= 0;
    bool validSelection= false;

	if( ( position2==symbol && position3==symbol ) 
		|| ( position4==symbol && position7==symbol ) 
		|| ( position5==symbol && position9==symbol ) )
	{
		validSelection= adjustPosition( 1, computerSymbol );
		if( validSelection )
		{
			choice=1;
		}
	}
	else if( ( position1==symbol && position3==symbol ) 
		|| ( position5==symbol && position8==symbol ) )
	{
		validSelection= adjustPosition( 2, computerSymbol );
		if( validSelection )
		{
			choice=2;
		}
	}
	else if( ( position1==symbol && position2==symbol ) 
		|| ( position6==symbol && position9==symbol ) 
		|| ( position5==symbol && position7==symbol ) )
	{
		validSelection= adjustPosition( 3, computerSymbol );
		if( validSelection )
		{
			choice=3;
		}
	}
	else if( ( position1==symbol && position7==symbol ) 
		|| ( position5==symbol && position6==symbol ) )
	{
		validSelection= adjustPosition( 4, computerSymbol );
		if( validSelection )
		{
			choice=4;
		}
	}
	else if( ( position1==symbol && position9==symbol ) 
		|| ( position3==symbol && position7==symbol ) 
		|| ( position2==symbol && position8==symbol )
		|| ( position4==symbol && position6==symbol ) )
	{
		validSelection= adjustPosition( 5, computerSymbol );
		if( validSelection )
		{
			choice=5;
		}
	}
	else if( ( position3==symbol && position9==symbol ) 
		|| ( position4==symbol && position5==symbol ) )
	{
		validSelection= adjustPosition( 6, computerSymbol );
		if( validSelection )
		{
			choice=6;
		}
	}
	else if( ( position1==symbol && position4==symbol ) 
		|| ( position6==symbol && position9==symbol ) 
		|| ( position3==symbol && position5==symbol ) )
	{
		validSelection= adjustPosition( 7, computerSymbol );
		if( validSelection )
		{
			choice=7;
		}
	}
	else if( ( position2==symbol && position5==symbol ) 
		|| ( position7==symbol && position9==symbol ) )
	{
		validSelection= adjustPosition( 8, computerSymbol );
		if( validSelection )
		{
			choice=8;
		}
	}
	else if( ( position1==symbol && position5==symbol ) 
		|| ( position3==symbol && position6==symbol ) 
		|| ( position7==symbol && position8==symbol ) )
	{
		validSelection= adjustPosition( 9, computerSymbol );
		if( validSelection )
		{
			choice=9;
		}
	}		
	
	return (choice);			
}

int selectFirstAvailablePlace()
{
	int choice= 0;
	bool validSelection= false;
	
	for( int i=1; i<=9; i++ )
	{
		validSelection= adjustPosition( i, computerSymbol );
		if( validSelection )
		{
			choice= i;
			break;
		}
	}
	
	return (choice);
}

bool checkSuccess( char symbol )
{
	bool success= false;

	if( ( position1==symbol && position2==symbol && position3==symbol )
		|| ( position4==symbol && position5==symbol && position6==symbol )
		|| ( position7==symbol && position8==symbol && position9==symbol )
		|| ( position1==symbol && position5==symbol && position9==symbol ) 
		|| ( position3==symbol && position5==symbol && position7==symbol )
		|| ( position1==symbol && position4==symbol && position7==symbol )
		|| ( position2==symbol && position5==symbol && position8==symbol )
		|| ( position3==symbol && position6==symbol && position9==symbol ))
	{
		success= true;
	}
	
	return( success );
}

int main ()
{
	cout <<  "Welcome to tic-tac-toe" << "\n";
	cout <<  "Enter position in the 3x3 grid where you would like to enter 0 "<< "\n";
	refreshDisplay();
	
	cout << "Computer take your turn: "; 
	int selection= generateRandomNumber();
	cout << selection;
	
	adjustPosition( selection, computerSymbol );
	refreshDisplay();
	 	
	bool gameContinue= true;
	bool playerTurn= true;
	
	while( gameContinue )
	{
		if( playerTurn )
		{
		    cout << "\n" << "Player take your turn: ";
			cin >> selection;
	
			bool adjusted= adjustPosition( selection, playerSymbol );
			if( selection<=0 || selection>9 || ( !adjusted ) )
			{
				cout << "\n" << "Invalid choice - try again.";
			}
			else
			{
				refreshDisplay();
				playerTurn= false;
			}
		}
		else
		{
			cout << "\n" << "Computer take your turn: ";
			selection= makeComputerSelection( computerSymbol );
			if( selection==0 )
			{
				selection= makeComputerSelection( playerSymbol );
			}
			if( selection==0 )
			{
				selection= selectFirstAvailablePlace();
			}
			cout << selection;
			
			refreshDisplay();
			playerTurn= true;
		}
		
		string message= "";

		if( checkSuccess( playerSymbol ) )
		{
			gameContinue= false;
			message= "Player wins!!!!";
		}
		else if( checkSuccess( computerSymbol ) )
		{
			gameContinue= false;
			message= "Computer wins!!!!";
		}
		else
		{
			if( position1!='-' && position2!='-' && position3!='-' 
				&& position4!='-' && position5!='-' && position6!='-' 
				&& position7!='-' && position8!='-' && position9!='-' )
			{
				gameContinue= false;
				message= "TIE!!!!";
			}
		}
		
		if( !gameContinue )
		{
			cout<< "\n" << "********************************************";
			cout<< "\n" <<  message << "\n";
		}
	}
  
  return 0;
}
