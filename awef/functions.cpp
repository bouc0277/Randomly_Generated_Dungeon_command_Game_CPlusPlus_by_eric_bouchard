#include "functions.h"
#include <Windows.h>
#include <iostream>
#include <time.h>

using namespace std;

char grid[80][25];
short CreatureCount = 0;

int randomizeFunc(int randomize) // creates a function with a parameter that accepets an integer and has the name of randomize. 
 {

  return rand() % randomize + 1; // randomizes from 1 to the accepted value from main then returns it.
 }


 short Xrand = randomizeFunc(70);
 short Yrand = randomizeFunc(14);

int CreateCoridor(int Xpos, int Ypos,short dir)
{
  if(dir ==0)
  {
  for(int i=Xpos;i <70; ++i)
  {
	  if(grid[i+1][Ypos] == char(176) || grid[i+1][Ypos] == H_WALL)
	  {
	  if(grid[Xpos][Ypos-2] ==  TR_CORNER)
	  {
       grid[Xpos][Ypos] = NOTIN;
       grid[i+1][Ypos] = NOTIN;
	   //create a revers loop if the i+1 != H_WALL to erase the coridor.
	  }
	  }
	  else if(grid[i+1][Ypos] == TL_CORNER)
	  {
		  	  if(grid[Xpos][Ypos-2] ==  TR_CORNER)
	  {
		  grid[i][Ypos] = NOTIN;
		  grid[i][Ypos+1] = NOTIN;
		  grid[i+1][Ypos+1] = NOTIN;
		  return 0;
			  }
	  }
	  	  else if(grid[i+1][Ypos] == BR_CORNER)
	  {
		  	  if(grid[Xpos][Ypos-2] ==  TR_CORNER)
	  {
		  grid[i][Ypos] = NOTIN;
		  grid[i][Ypos-1] = NOTIN;
		  grid[i+1][Ypos-1] = NOTIN;
		  return 0;
			  }
	  }
	  else
	  {
		  //grid[i+1][Ypos] = char(1);

		  return 0;
	  }
  }
  }

  return 0;
}

int CreateCoridor2(int Xpos, int Ypos,short dir)
{
  if(dir ==0)
  {
  for(int i=Xpos;i <70; ++i)
  {
	    for(int i=Ypos;i <25; ++i)
  {
	  if(grid[Xpos][i+1] == char(176) || grid[Xpos][i+1] == V_WALL)
	  {
	  if(grid[Xpos+1][Ypos] ==  BL_CORNER)
	  {
       grid[Xpos][Ypos] = NOTIN;
       grid[Xpos][i+1] = NOTIN;
	   //create a revers loop if the i+1 != H_WALL to erase the coridor.
	  }
	  }
	  else
	  {
		  //grid[i+1][Ypos] = char(1);

		  return 0;
	  }
  }
  }
  }
  return 0;
}

void GotoXY_1( int x, int y)
 {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
 }

int CreateSquareRoom(short Xadd, short Yadd)
{
	//This checks if the space is free if not exit the case.
	for (int i =Xrand; i < Xrand+Xadd; i ++)
          {
           if(grid[i][Yrand] != char(176)) 
		    {
             return 0;
		    }
          }

		 for (int i =Xrand; i < Xrand+Xadd; i ++)
          {
		   if(grid[i][Yrand+Yadd] != char(176)) 
		    {
             return 0;
		    }
		  }

		 for (int i =Yrand+1; i < Yrand+Yadd; i ++)
          {
           if(grid[Xrand][i] != char(176)) 
		    {
             return 0;
		    }  			
		   
           if(grid[Xrand+Xadd-1][i] != char(176)) 
		    {
             return 0;
		    }
		 }

		 //This actualy creates the room.
		 for (int i =Xrand; i < Xrand+Xadd; i ++)
          {
		   grid[i][Yrand] = V_WALL;
		   grid[i][Yrand+Yadd] = V_WALL;
		   grid[Xrand][Yrand] = TL_CORNER;
		   grid[Xrand+Xadd-1][Yrand] = TR_CORNER;
          }
         
		 for (int i =Yrand+1; i < Yrand+Yadd; i ++)
          {
		   grid[Xrand][i] = H_WALL;
           grid[Xrand+Xadd-1][i] = H_WALL;
		   grid[Xrand][Yrand+Yadd] = BR_CORNER;
		   grid[Xrand+Xadd-1][Yrand+Yadd] = BL_CORNER;
		  }

		 //This creates an alternative empty space inside the square so that new squares don't get created inside them.
		 for(int i=Xrand+1; i < Xrand+Xadd-1; i++)
		 {
		 for(int j=Yrand+1; j < Yrand+Yadd; j++)
		 {
			 grid[i][j] = char(32);
		 }
		 }

	   Xrand = randomizeFunc(70);
	   Yrand = randomizeFunc(14);

	   return 0;
}

void CreateLevel()
{
	   	Xrand = randomizeFunc(70);
		Yrand = randomizeFunc(14);

   for (int i =2; i < 80; i ++)
    {
	 for (int j =2; j < 25; j++)
      {
	   
       grid[i][j] = char(176) ;

      }

    }

  for (int x =2; x < 80; x ++)
   {
	
	for (int y =2; y < 25; y++)
     {

	   switch(randomizeFunc(7))
	   {
		 
	    case 0:
		 {
          grid[x][y] = TL_CORNER;
		  break;

		 }

	    case 1:
		 {	 
		  //small square
	      CreateSquareRoom(4,3);
	      Xrand = randomizeFunc(70);
	      Yrand = randomizeFunc(14);
		  break;
		 }

	    case 2:
		 {
		  //mid square
		  CreateSquareRoom(6,4);
		  Xrand = randomizeFunc(70);
	      Yrand = randomizeFunc(14);
		  break;
		 }

		case 3:
		 {
		  //Big Square
		  CreateSquareRoom(8,5);
		  Xrand = randomizeFunc(70);
	      Yrand = randomizeFunc(14);
		  break;
		 }

		 case 4:
		 {
		  //Right coridor
          for (int i =2; i < 80; i ++)
           {
	        for (int j =2; j < 25; j++)
             {
			  if(grid[i][j] == char(H_WALL) && grid[i+1][j] == char(H_WALL))
			   {
				   grid[i][j]= char(0);
				   grid[i+1][j]= char(0);
			   }
			   if(grid[i][j] == char(V_WALL) && grid[i][j+1] == char(V_WALL))
			   {
				   grid[i][j]= char(0);
				   grid[i][j+1]= char(0);
			   }
             }

           }



		  break;
		 }

		 	    case 5:
		 {
                   for (int i =2; i < 80; i ++)
           {
	        for (int j =2; j < 25; j++)
             {
				 if(grid[i][j] == char(32) || grid[i][j] == char(0))
				 {
					 	   if(randomizeFunc(3000) == 2)
	                       {
		                    grid[i][j] = char(238);
							CreatureCount=CreatureCount+1;
						   }
				 }
			}
		 }
		 }

//		 	    case 6:
//		 {
//
////This checks if the space is free if not exit the case.
//	for (int i =Xrand; i < Xrand+8; i ++)
//          {
//           if(grid[i][Yrand] != char(176)) 
//		    {
//             goto done;
//		    }
//          }
//
//		for (int i =Xrand; i < Xrand+8; i ++)
//          {
//           if(grid[i][Yrand+1] != char(176)) 
//		    {
//             goto done;
//		    }
//          }
//
//		 for (int i =Xrand; i < Xrand+8; i ++)
//          {
//           if(grid[i][Yrand+2] != char(176)) 
//		    {
//             goto done;
//		    }
//          }
//
//		 		for (int i =Xrand; i < Xrand+8; i ++)
//          {
//           if(grid[i][Yrand+3] != char(176)) 
//		    {
//             goto done;
//		    }
//          }
//
//						for (int i =Xrand; i < Xrand+8; i ++)
//          {
//           if(grid[i][Yrand+4] != char(176)) 
//		    {
//             goto done;
//		    }
//          }
//
//								for (int i =Xrand; i < Xrand+8; i ++)
//          {
//           if(grid[i][Yrand+5] != char(176)) 
//		    {
//             goto done;
//		    }
//          }
//
//										for (int i =Xrand; i < Xrand+8; i ++)
//          {
//           if(grid[i][Yrand+6] != char(176)) 
//		    {
//             goto done;
//		    }
//          }
//		 //This actualy creates the room.
//		   if(randomizeFunc(10) == 5)
//		   {
//		 for (int i =Xrand; i < Xrand+8; i ++)
//          {
//
//		   grid[Xrand][Yrand] = char(176);
//		   grid[Xrand+1][Yrand] = char(176);
//		   grid[i][Yrand] = char(61);
//		   grid[Xrand+6][Yrand] = char(176);
//		   grid[Xrand+7][Yrand] = char(176);
//		   grid[Xrand+8][Yrand] = char(176);
//		   grid[Xrand][Yrand+1] = char(176);
//		   grid[Xrand+1][Yrand+1] = char(35);
//		   grid[i][Yrand+1] = char(32);
//		   grid[Xrand+6][Yrand+1] = char(35);
//		   grid[Xrand+7][Yrand+1] = char(176);
//
//		   grid[Xrand][Yrand+2] = char(35);
//		   grid[i][Yrand+2] = char(32);
//		   grid[Xrand+7][Yrand+2] = char(35);
//		   grid[Xrand][Yrand+3] = char(35);
//		   grid[i][Yrand+3] = char(32);
//		   grid[Xrand+7][Yrand+3] = char(35);
//		   grid[Xrand][Yrand+4] = char(35);
//		   grid[i][Yrand+4] = char(32);
//		   grid[Xrand+7][Yrand+4] = char(35);
//
//		   grid[Xrand][Yrand+6] = char(176);
//		   grid[Xrand+1][Yrand+6] = char(176);
//		   grid[i][Yrand+6] = char(61);
//		   grid[Xrand+6][Yrand+6] = char(176);
//		   grid[Xrand+7][Yrand+6] = char(176);
//		   grid[Xrand+8][Yrand+6] = char(176);
//		   grid[Xrand][Yrand+5] = char(176);
//		   grid[Xrand+1][Yrand+5] = char(35);
//		   grid[i][Yrand+5] = char(32);
//		   grid[Xrand+6][Yrand+5] = char(35);
//		   grid[Xrand+7][Yrand+5] = char(176);
//		   }
//
//		           for (int i =2; i < 80; i ++)
//           {
//	        for (int j =2; j < 25; j++)
//             {
//			  if(grid[i][j] == char(35) && grid[i+1][j] == char(35))
//			   {
//				   grid[i][j]= char(0);
//				   grid[i+1][j]= char(0);
//			   }
//			   if(grid[i][j] == char(61) && grid[i][j+1] == char(61))
//			   {
//				   grid[i][j]= char(0);
//				   grid[i][j+1]= char(0);
//			   }
//             }
//
//           }
//
//
//          }
//         		   else
//		   {
//			   goto done;
//		   }
//
//
//
//	   Xrand = randomizeFunc(70);
//	   Yrand = randomizeFunc(14);
//
//		 }
//done:
//		 {
//
//		 }
/*




*/
	   }
		 
     }
    
   }



   for (int i =2; i < 80; i ++)
    {
	 for (int j =2; j < 25; j++)
      {

	  		            for (int i =2; i < 80; i ++)
           {
	        for (int j =2; j < 25; j++)
             {

               if(grid[i][j] == char(H_WALL))
			   {
				  CreateCoridor(i,j,0);
				  
			   }
             }

           }
	 }
   }

      for (int i =2; i < 80; i ++)
    {
	 for (int j =2; j < 25; j++)
      {

	  		            for (int i =2; i < 80; i ++)
           {
	        for (int j =2; j < 25; j++)
             {

               if(grid[i][j] == char(H_WALL))
			   {
				  CreateCoridor2(i,j,0);
				  
			   }
             }

           }
	 }
   }


}

void DrawLevel()
 {
  for (int i =0; i < 80; i ++)
   {
    for (int j =0; j < 20; j++)
     {
	  if(grid[i][j] != char(176)  )
	  {
	  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0f );
	  GotoXY_1(i,j);
	  cout << grid[i][j] <<endl ;
	  }
	  	  if(grid[i][j] == char(176) )
	  {
	  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x30  );
	  GotoXY_1(i,j);
	  cout << grid[i][j] <<endl ;
	  }

	 }
 		
   }
 
 }

char Getgrid(short x,short y,short dir)
 { 
	
  return grid[x][y];
 }

void delThing(short x,short y)
{

	grid[x][y] = char(0);
	CreatureCount=CreatureCount-1;
}

