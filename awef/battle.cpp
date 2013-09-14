#include "battle.h"
#include <iostream>
#include <Windows.h>
#include "functions.h"
#include < string> // includes things that makes string variables usable.

using namespace std;

    //default constructor
	BATTLE::BATTLE()
	{
	 m_mLevel = 1;
	 m_mHealth = 10;
     m_mAttack = 1;
	 m_mArmour = 0;
	}

    //overloaded constructor
    BATTLE::BATTLE(unsigned short Level,unsigned short Health,unsigned short Attack,unsigned short Armour)
	{
	 m_mLevel = 1;
	 m_mHealth = 10;
     m_mAttack = 1;
	 m_mArmour = 0;

	 SetLevel(Level);
	 SetHealth(Health);
	 SetAttack(Attack);
	 SetArmour(Armour);
	}

	unsigned short BATTLE::GetLevel()
	{
     
	 return m_mLevel;
	}

	void BATTLE::SetLevel(unsigned short Level)
	{
     m_mLevel = Level;
	}

	unsigned short BATTLE::GetHealth()
	{
     
	 return m_mHealth;
	}

	void BATTLE::SetHealth(unsigned short Health)
	{
     m_mHealth = Health;
	}

     unsigned short BATTLE::GetAttack()
	{
     
	 return m_mAttack;
	}

	void BATTLE::SetAttack(unsigned short Attack)
	{
     m_mAttack = Attack;
	}

	     unsigned short BATTLE::GetArmour()
	{
     
	 return m_mArmour;
	}

	void BATTLE::SetArmour(unsigned short Armour)
	{
     m_mArmour = Armour;
	}

    bool  BATTLE::ifDead()
	{
     if(m_mHealth == 0)
	 {
      return true;
	 }
	 else if(m_mHealth < 0)
	 {
      return true;
	 }
	 else
	 {
      return false;
	 }
	}

	void BATTLE::Fight(short Attack)
	{
	 SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0f );
     system("cls");
	 char commandx = ' ';
     while(true)
	 {
		 switch(1)
		 {
		  case 1:
			  {
    cout << "                                                      x" <<endl ;
	cout << "                                                       xx"<<endl ;
	cout << "               _     _                                  xxx"<<endl ;
	cout << "              / )   / }                                   xx"<<endl ;
 	cout << "            /  )  /  }      _____________                 xx"<<endl ;
	cout << "        ____(   )_(   }    _/             }                 xx"<<endl ;
	cout << "      _/              \___/                }                 Xx"<<endl ;
 	cout << "    /   0                                  }                 x"<<endl ;
 	cout << "   /                                        }               XX"<<endl ;
	cout << "   /                                          }             XX"<<endl ;
 	cout << " (x                                           }         XXXX"<<endl ;
	cout << "   -\                                          }     XXXXXX"<<endl ;
 	cout << "    -                                        }  XXXXXX"<<endl ;
	cout << "     \-----#                                }XXXXX"<<endl ;
	cout << "            # #___             ___  ________}" <<endl ;
	cout << "             # #  #___________}  # #"<<endl ;
	cout << "               ++                 ++"<<endl ;
	cout << "A Level "<< m_mLevel << " rat" <<endl;

	break;
			  }

		 }

	 while(true)
	 {
	  cout << "What would you like to do? (H) for help :" ;
	  cin >> commandx;
	  if(commandx == 'a')
	  {
	   cout << "You attacked for " << Attack << endl;	
	   m_mHealth -=Attack;
	   Sleep(2000);
	   cout << "The rat attacked you for " << m_mAttack <<endl ;

	  }
	  else if(commandx == 'h')
	  {
		  cout << "Enter A for attack." <<endl ;
	  }
	  else
	  {
		  cout << "invalid command" <<endl ;
		  commandx = 'h';
	  }
	 }

	 }
	}


	
	void BATTLE::Fight2(short Attack,short Armour,short x,short y)
	{

     string creature = "";
	   switch(randomizeFunc(4))
	   {
	    case 0:
	     {
	      creature = " Giant Rat ";
		  break;
		 }
	    case 1:
	     {
	      creature = " Goblin ";
		  break;
		 }
	    case 2:
	     {
	      creature = " Skeleton ";
		  break;
		 }
	    case 3:
	     {
	      creature = " Mad wizard ";
		  break;
		 }
	    case 4:
	     {
	      creature = " Giant bat ";
		  break;
		 }
	   }

	 char commandx = ' ';
	 cout << "A Level "<< m_mLevel << creature <<  "appears!\n" <<endl;

	 while(true)
	 {
		 		  GotoXY_1(2,21);
	  cout << "What would you like to do? (H) for help :" ;
	  cin >> commandx;
	  if(commandx == 'a')
	  {
	   if(Attack >m_mArmour)
	   {
	   cout << "You attacked for " << Attack-m_mArmour << endl;	
	   m_mHealth -=Attack-m_mArmour;
	   if(ifDead() == true)
	   {
       cout << "the creautre is dead";
	   Sleep(2000);
	   delThing(x,y);
	      system("cls");
	   	  DrawLevel();
		  
	   break;
	   }
	   }
	   else if(Attack == m_mArmour || Attack < m_mArmour)
	   {
	     cout << "The attack was unsuccesfull." ;
	   }
	   Sleep(2000);
	   if(m_mAttack > Armour)
	   {
	   cout << "The" << creature << "attacked you for " << m_mAttack-Armour <<endl ;
	   Sleep(2000);
	   system("cls");
	   	  DrawLevel();
	   }
	   else if(m_mAttack < Armour || m_mAttack == Armour)
	   {
	   cout << "The" << creature << "'s attack was unsuccesfull "  <<endl ;
	   Sleep(2000);
	   system("cls");
	   	  DrawLevel();
	   }
	  }
	  else if(commandx == 'h')
	  {
		  cout << "Enter A for attack." <<endl ;
	  }
	  else
	  {
		  cout << "invalid command" <<endl ;
		  commandx = 'h';
	  }
	 }

	 
	}