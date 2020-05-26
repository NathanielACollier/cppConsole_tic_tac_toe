/*
Nathaniel Collier
4/14/2006 12:34:30 PM
Programming Contest Problem 2
*/
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

// Macros

// Random Number Generation
#define RNUM( min, max ) rand() % (max - min + 1) + min 
#define BOARD(x) board[x-1]


 // Function Declerations
 int get_position( char board[], int & piece_count );
 int computer_position(  char board[], int & piece_count );
 void print_board( char board[] );
 int check_winner( char board[] );
 void clear_game( char board[], int & last_pc, int & last_com, int & piece_count);
 void new_game( char board[], int & last_pc, int & last_com, int & piece_count );

int main()
{

 // Variable Declerations
 int last_pc = 0;
 int last_com = 0;
 int win_status = 0;
 char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' '}; // 1 2 3 4 5 6 7 8 9
 bool game_end = false;
               // use D2_INDEX( R, C ) to compute as 2d matrix
 int piece_count = 0; // index for how many pieces are on the board if this number
                      // becomes 9 the board is full and the game is over 
                      // its basicly array length
 cout << "\nNathaniel Collier\nTic-Tac-Toe\n";
 srand( clock() );
 // these functions will be  in some kind of loop
for(;;) // game loop
{
  last_pc = get_position( board, piece_count ); // player plays
  win_status = check_winner( board );
  if( win_status == 1) 
  {
   cout << "\nYou Win! Thank you for playing.\n";
   new_game( board, last_pc, last_com, piece_count );
   continue; // should get us to the next iteration of the loop with a new game
  }
  if( piece_count == 9 )
  {
   cout << "\nIt is a Tie.\n";
   new_game( board, last_pc, last_com, piece_count );
   continue; // should get us to the next iteration of the loop with a new game
  }
  if( win_status == 2)
  {
   cout << "\nI Win! Thank you for playing.\n";
   new_game( board, last_pc, last_com, piece_count );
   continue; // should get us to the next iteration of the loop with a new game
  }
  last_com = computer_position( board, piece_count ); // computer plays
  win_status = check_winner( board );
  if( win_status == 1) 
  {
   cout << "\nYou Win! Thank you for playing.\n";
   new_game( board, last_pc, last_com, piece_count );
   continue; // should get us to the next iteration of the loop with a new game
  }
  if( piece_count == 9 )
  {
   cout << "\nIt is a Tie.\n";
   new_game( board, last_pc, last_com, piece_count );
   continue; // should get us to the next iteration of the loop with a new game
  }
  if( win_status == 2)
  {
   cout << "\nI Win! Thank you for playing.\n";
   new_game( board, last_pc, last_com, piece_count );
   continue; // should get us to the next iteration of the loop with a new game
  }
  
  
  
}

return 0;
}


// Function Definitions

/*
Get Position of Board that player wishes to place there game piece
Position can be any integer 1 to 9
Program according to given instructions assumes players piece is allways X
*/
int get_position( char board[], int & piece_count )
{
 int choice = 0;
 
 // display of the board
 cout << "\n 1 | 2 | 3 "
      << "\n 4 | 5 | 6 "
      << "\n 7 | 8 | 9 ";
 while( choice < 1 || choice > 9 )
 {
  cout << "\nWhere do you want to place an X?  Enter a value from 1 to 9: ";
      cin>> choice;
  if( (choice < 1 && choice > 8 ) || board[choice-1] == 'O' || board[choice-1] == 'X' )
  {
   cout << "\nSorry, \'" << choice << "\' is not a valid choice.  Please try again...\n";
   choice = 0;
  }
 }
 board[choice-1] = 'X';
 ++piece_count;
 if( piece_count == 9 ) choice = -1;
 print_board(board);
 return choice;
}


#define CHECK_CHOICE( z, x, y ) if( board[ z - 1 ] == 'O' ){ \
                               if( board[x-1] == 'O' && board[y-1] != 'X' ) choice = y; \
                               else \
                               if( board[y-1] == 'O' && board[x-1] != 'X' ) choice = x; } \


/*
This function gets the computers next move
it will have to be changed however to meet the requirement of allways winning if possible
See vector Graphic for win strategies
*/
int computer_position(  char board[], int & piece_count  )
{
 // this can't really stay as the choice since the computer
 // will need to play somewhat strategic
 int choice = RNUM(1,9);

  // This does a linear search to see if the computer can win or not

        CHECK_CHOICE(1,2,3)
        else
        CHECK_CHOICE(1,5,9)
        else
        CHECK_CHOICE(1,4,7)

      CHECK_CHOICE(2,5,8)
    

      CHECK_CHOICE(3,6,9)
      else
      CHECK_CHOICE(3,5,7)

     CHECK_CHOICE(4,5,6)

     CHECK_CHOICE(7,8,9)

     CHECK_CHOICE(9,7,8)
    
   // computer cannot win at this time
   while( board[choice-1] == 'X' || board[choice-1] == 'O' ){ choice = RNUM(1,9);}

 
 /*
 If any board space connected to a board space that has a piece in it
 
 */

 
 board[choice-1] = 'O';
 ++piece_count;
 if( piece_count == 9 ) choice = -1;
 cout << "The Computer chooses to place an O in space " << choice << "\n";
 print_board(board);
 return choice;
}

/*
Prints the tic tac toe board to the screen
*/
void print_board( char board[] )
{
 cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n"
      << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n"
      << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

/*
Checks for a winning sequence returns
1 - player won
2 - computer won
0 - no one won
*/

#define CHECK_WINNER(x,y,z,c)  if( board[x-1] == c && board[y-1] == c && board[z-1] == c ) winner_found = true;

int check_winner( char board[] )
{
 // Basic Linear Strategy is probably the best to get started
 bool winner_found = false;
 char cc = 'X';
 while( cc != 0 )
 {
  CHECK_WINNER(1,2,3,cc)
  CHECK_WINNER(1,4,7,cc)
  CHECK_WINNER(1,5,9,cc)
  CHECK_WINNER(2,5,8,cc)
  CHECK_WINNER(3,6,9,cc)
  CHECK_WINNER(3,5,7,cc)
  CHECK_WINNER(4,5,6,cc)
  CHECK_WINNER(7,8,9,cc)
 
  
  if( winner_found == true )
  {
   return ( cc == 'X') ? 1 : 2; // winner_found would not be true if cc equaled 0
  }
   cc = ( cc == 'X') ? 'O' : 0;
 } 
                           
return 0;
}

/*
Clear Game
reinitializes all of the game variables so that a new game can begin
*/
void clear_game( char board[], int & last_pc, int & last_com, int & piece_count)
{
 // clear game variables
 last_pc = 0;
 last_com = 0;
 piece_count = 0;
 
 // clear board
 for( int i=0; i < 9; ++ i )
 board[i] = ' ';
}


/*
New Game
Checks to see if the player wants to play a new game
if the player does want to play a new game then the clear game function is called
*/
void new_game( char board[], int & last_pc, int & last_com, int & piece_count )
{
 char rerun = 48;
 while( rerun != 'Y' && rerun != 'y' && rerun != 'N' && rerun != 'n' )
   {
    cout << "\nWould you like to play again?  (Y/N) ";
    cin >> rerun;
   }
    if( rerun == 'N' || rerun == 'n' )
    {
      cout << "\nGoodbye ... \n";
      exit(0);
    }
   clear_game( board, last_pc, last_com, piece_count );

}















