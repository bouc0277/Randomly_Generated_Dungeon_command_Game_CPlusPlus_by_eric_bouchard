#include <Windows.h>
#include <iostream>
#include "functions.h"
#include "battle.h"
#include <time.h>
#include "player.h"

using namespace std;


int main()
{
	//variables
	short player_x = 2; //player x position
	short player_y = 2; //player y position
	char Collicheck = 0;
	short pxrand = 0;
	short pyrand = 0;
	srand (time(NULL));
	CreateLevel();
    //PLAYER player1(1,1,1,1,1,1,"","","","","");
	PLAYER player1;
	//Player variables


	
	//this sets the players position randomly on the map
	do
	{
     pxrand=randomizeFunc(70);
	 pyrand=randomizeFunc(10);
	}while(Getgrid(pxrand,pyrand,0) != char(32));

	player_x=pxrand;
	player_y=pyrand;

	//keypress loop
	while(true)
	 {

	  //move right
	  if (GetAsyncKeyState(VK_RIGHT))
	   {
		if(Getgrid(player_x+1,player_y,0) == char(0) || Getgrid(player_x+1,player_y,0) == char(32)) //checks if the space is empty
		 {
		  //system("cls");
		  DrawLevel();
		  player_x = player_x+1 ;
		  GotoXY_1(player_x,player_y);
	      SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0f );
		  cout << char(1);
		  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x30  );
		  GotoXY_1(2,20);
		  cout << "                                        " ;
		  GotoXY_1(2,20);
	      cout << "You move East" ;
		  Sleep(5);
		 }
	   }

	  //move left
	  if (GetAsyncKeyState(VK_LEFT))
	   {
		if(Getgrid(player_x-1,player_y,0) == char(0) || Getgrid(player_x-1,player_y,0) == char(32))
		 {
		  //system("cls");
		  DrawLevel();
		  player_x = player_x-1 ;
		  GotoXY_1(player_x,player_y);
	      SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0f );
		  cout << char(1);
		  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x30  );
		  GotoXY_1(2,20);
		  cout << "                                        " ;
		  GotoXY_1(2,20);
	      cout << "You move West" ;
		  Sleep(5);
		 }
	   }

	  //move up
	  if (GetAsyncKeyState(VK_UP))
	   {
	    if(Getgrid(player_x,player_y-1,0) == char(0) || Getgrid(player_x,player_y-1,0) == char(32))
	     {
		  //system("cls");
		  DrawLevel();
		  player_y = player_y-1 ;
		  GotoXY_1(player_x,player_y);
	      SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0f );
		  cout << char(1);
		  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x30  );
		  GotoXY_1(2,20);
		  cout << "                                        " ;
		  GotoXY_1(2,20);
	      cout << "You move South" ;
		  Sleep(5);
		 }
	   }

	  //move down
	  if (GetAsyncKeyState(VK_DOWN))
	   {
		if(Getgrid(player_x,player_y+1,0) == char(0) || Getgrid(player_x,player_y+1,0) == char(32))
		 {
		  //system("cls");
		  DrawLevel();
		  player_y = player_y+1 ;
		  GotoXY_1(player_x,player_y);
	      SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0f );
		  cout << char(1);
		  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x30  );
		  GotoXY_1(2,20);
		  cout << "                                        " ;
		  GotoXY_1(2,20);
	      cout << "You move North" ;
		  Sleep(5);
		 }
	   }

	    if (GetAsyncKeyState(VK_SPACE)) // battle
	     {
	      GotoXY_1(player_x,player_y);
		  if(Getgrid(player_x-1,player_y,0)== char(238))
		  {
		   GotoXY_1(2,20);
	       //cout << "Would you like to attack the creature?" ;
           BATTLE battle1;
		   battle1.Fight2(player1.GetAttack(),player1.GetArmour(),player_x-1,player_y);
		  }
		  else if(Getgrid(player_x+1,player_y,0)== char(238))
		  {
		   GotoXY_1(2,20);
	       cout << "Would you like to attack the creature?" ;
		  }
		  else if(Getgrid(player_x,player_y-1,0)== char(238))
		  {
		   GotoXY_1(2,20);
	       cout << "Would you like to attack the creature?" ;
		  }
		  else if(Getgrid(player_x,player_y+1,0)== char(238))
		  {
		   GotoXY_1(2,20);
	       cout << "Would you like to attack the creature?" ;
		  }
	     }

	    GotoXY_1(50,20);
	    cout << "Level = " <<player1.GetLevel(); 
	    GotoXY_1(50,21);
		cout << "Health = " <<player1.GetHpMax()<< "/ " <<player1.GetHp() ;
		GotoXY_1(50,22);
	    cout << "Attack = " <<player1.GetAttack() ;
		GotoXY_1(50,23);
	    cout << "Armour = " <<player1.GetArmour() ;

	}

 return 0;
}
