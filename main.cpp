/*
Author: kattree
Last Update: July 29, 2022
Project: Final- The board game Sorry
Purpose: 2-4 player moves through 60 spaces to try to be the first one to the finish. Each dice roll has different tricks that may be hiding up its sleeve
*/
//I have an obsession with if statements
#include <iostream>
#include <cstdio>
#include <ctime>
#include  <cstdlib>
#include <string.h>
#include <time.h>
#define block "\u25a9"
using namespace std;

//classes are private structs but I made mine public
//Holds the players and their postitions and also the size of the board
class Board{
public: 
  int size = 60;
//had to intialise these because the random memory that was stored there was causing me problems
  int p1Pos=0;
  int p2Pos=0;
  int p3Pos=70;
  int p4Pos=70;
  char* realBoard[60];
  
};


//its near impossible to spot an error in this little function. Anyways it calculates who's in the lead in the LEAST efficient way possible
int inLead(Board board){
  //4players
     if ((board.p3Pos >= 0 && board.p4Pos >= 0)&&(board.p3Pos <= 60 && board.p4Pos <= 60)){
      if (board.p1Pos < board.p2Pos && board.p1Pos < board.p3Pos && board.p1Pos < board.p4Pos ) return 1;
      else if (board.p2Pos < board.p1Pos && board.p2Pos < board.p3Pos && board.p2Pos < board.p4Pos ) return 2;
       else if (board.p3Pos < board.p1Pos && board.p3Pos < board.p2Pos && board.p3Pos < board.p4Pos ) return 3;
       else return 4;}
  //3 players
       else if ((board.p3Pos >= 0 )&&(board.p3Pos <= 60 )){
      if (board.p1Pos < board.p2Pos && board.p1Pos < board.p3Pos ) return 1;
      else if (board.p2Pos < board.p1Pos && board.p2Pos < board.p3Pos ) return 2;
       else  return 3;}
  //2 players
  else{
    if (board.p1Pos < board.p2Pos) return 1;
    else return 2;
  }
}
//Is the exact same function above except it calculates who's in last. Again- inefficient
int inLast(Board board){
   //4 players
     if ((board.p3Pos >= 0 && board.p4Pos >= 0)&&(board.p3Pos <= 60 && board.p4Pos <= 60)){
      if (board.p1Pos > board.p2Pos && board.p1Pos > board.p3Pos && board.p1Pos > board.p4Pos ) return 1;
      else if (board.p2Pos > board.p1Pos && board.p2Pos > board.p3Pos && board.p2Pos > board.p4Pos ) return 2;
       else if (board.p3Pos > board.p1Pos && board.p3Pos > board.p2Pos && board.p3Pos > board.p4Pos ) return 3;
       else return 4;}
  //3 players
       else if ((board.p3Pos >= 0 )&&(board.p3Pos <= 60 )){
      if (board.p1Pos > board.p2Pos && board.p1Pos > board.p3Pos ) return 1;
      else if (board.p2Pos > board.p1Pos && board.p2Pos > board.p3Pos ) return 2;
       else  return 3;}
  //2 players
  else{
    if (board.p1Pos > board.p2Pos ) return 1;
    else return 2;
  } 
}

//prints the board while marking where each player is
void printBoard(Board board){
  board.realBoard[board.p1Pos] = "$";
  board.realBoard[board.p2Pos] = "&";
  if ((board.p3Pos >= 0 )&&(board.p3Pos <= 60)) board.realBoard[board.p3Pos] = "@";
  if ((board.p4Pos >= 0 )&&(board.p4Pos <= 60)) board.realBoard[board.p4Pos] = "#";
  
  printf("\n|");
  for (int i = 0; i<board.size; i++)cout<< board.realBoard[i];
  printf("|");
}



int main() {
  srand(time(NULL));
  
  bool play = true;
  bool canroll1=false;
  bool canroll2=false;
  bool canroll3=false;
  bool canroll4=false;
  int player=1;
  int players;
  bool running=true;
  //variables for dice roll number
  int t =0;
  int th =0;
  int f=0;
  int fv=0;
  int sx = 0;
  int sv = 0;
  int e=0;
  int n= 0;
  int tn = 0;
  int lvn = 0 ;
  int tw = 0;
  Board board;
  //allows the board to have sqaures so it can be visualised
    for (int i = 0; i<board.size; i++) board.realBoard[i] = block;

  //greeting
  printf("Hi hi!! Welcome to Sorry! I'm sure you know how the game works and if you don't go google it! Each player will have a different symbol for his/her little piece. P1 = $ P2 = & P3 = @ P4 = # . So now I must ask you, how many people are playing?");
  //game loop
  while(running){
    //checks if the amount of players needs to be evaluated and does so when it needs to be
    if(play){
      cin>>players;
      switch (players){
    case 2 : {
      board.p1Pos = 0; 
      board.p2Pos = 0;
      play = false;
      break;
    }
    case 3:{
      board.p1Pos = 0; 
      board.p2Pos = 0;
      board.p3Pos = 0;
      play = false;
      break;}
    case 4 :{
      board.p1Pos = 0; 
      board.p2Pos = 0;
      board.p3Pos = 0;
      board.p4Pos = 0;
      play = false;
      break;
    }
        default:{ board.p1Pos = 0; 
      board.p2Pos = 0;
      printf("Whatever you entered was wrong so I'll go ahead and assume you meant two");
          play = false;
          break;
      }
  }
    }
    
    if (player >players ) player =1;
      printf("Player %d's turn\n",player);
   //Dice function
  int die1 = (rand() % 6)+1;
  int die = (rand()%11)/2+1;
  int total = die1+die;
  printf("You rolled a %d and a %d for a total of %d\n",die1,die,total);
    //player movement--determines how the player will move after each roll
   //player one dice movements
  if (player==1){
    //checks if the player has rolled doubles
    if(die == die1) canroll1 = true;
    if (canroll1){ 
    //checks if the player is not too close to the end   
    if(board.p1Pos <= 50){  
    switch(total){
      case 2 :{
        printf("Moved forward two\n");
        board.p1Pos += 2;
        t++;
        break;
      }
      case 3: {
        printf("Moved forward three\n");
        board.p1Pos += 3;
        th++;
        break;
      }
      case 4:{
        printf("Moved back a space\n");
        if (board.p1Pos >= 1){
           board.p1Pos -= 1;
        }
        f++;
       break;
      }
      case 5:{
        printf("Moved back three spaces\n");
        if (board.p1Pos >=3) board.p1Pos-=3;
          else board.p1Pos = 0;
        fv++;
        break;
      }
      case 6:{
        printf("Moved forward six spaces\n");
        board.p1Pos+=6;
        sx++;
        break;
      }
      case 7:{
        sv++;
        printf("Did a good ol' switchero with another player");
        //temporarily stores the positions of two players to swap them
        int temp;
        int temp2;
        if (inLast(board) == 1) break;
        else if (inLast(board) == 2){
               temp2 = board.p1Pos;
          temp = board.p2Pos;
          board.p1Pos = temp;
          board.p2Pos = temp2;
     
        }
        else if (inLast(board) == 3){
           temp2 = board.p1Pos;
          temp = board.p3Pos;
          board.p1Pos = temp;
          board.p3Pos = temp2;
                   

         
        }
        else if (inLast(board) == 4){
          temp2 = board.p1Pos;
          temp = board.p4Pos;
          board.p1Pos = temp;
          board.p4Pos = temp2;
        }
        break;
      }
      case 8:{
        e++;
        printf("Lost a turn!");
        break;
      }
      case 9:{
        n++;
        printf("Moved forward nine");
        board.p1Pos+=9;
        break;
      }
      case 10:{
        tn++;
        printf("Moved forward ten");
        board.p1Pos+=10;
        break;
      }
      case 11:{
        lvn++;
        printf("Did a good ol' switchero with another player");
        int temp;
        int temp2;
        if (inLead(board) == 1) break;
        else if (inLead(board) == 2){
          temp2 = board.p1Pos;
          temp = board.p2Pos;
          board.p1Pos = temp;
          board.p2Pos = temp2;
         
        }
        else if (inLead(board) == 3){
            temp2 = board.p1Pos;
          temp = board.p3Pos;
          board.p1Pos = temp;
          board.p3Pos = temp2;
        }
        else if (inLead(board) == 4){
          temp2 = board.p1Pos;
          temp = board.p4Pos;          
          board.p1Pos = temp;
          board.p4Pos = temp2;

        }
        break;
      }
      case 12: {
        tw++;
        printf("Sent back to the beginning!");
        board.p1Pos=0;
        break;
      }
    }
    if ((board.p1Pos == board.p2Pos || board.p1Pos == board.p3Pos||board.p1Pos == board.p4Pos) && board.p1Pos != 0) {board.p1Pos = 0; printf("It seems as though you landed on the same square as another player. Back to the beginning!\n");}
        printf("Player %d you are at square %d\n", player,board.p1Pos);
      }
      //here a player's dice roll must equal the end of the board
      else {printf("You must roll the perfect number to reach victory from this point forward! Unless someone switches with you, then you're unlucky");if(board.size-board.p1Pos == total)board.p1Pos = 59;}
  }
    else printf("No double. No move.\n");
  }  
  //player 2
  //includes the same routines as player one  
  if (player==2){
    if(die == die1) canroll2 = true;
    if(canroll2){
    if(board.p2Pos <= 50){  
   switch(total){
      case 2 :{
      printf("Moved forward two\n");
        board.p2Pos += 2;
        t++;
        break;
      }
      case 3: {
        printf("Moved forward three\n");
        board.p2Pos += 3;
        th++;
        break;
      }
      case 4:{
        f++;
        printf("Moved back a space\n");
        if (board.p2Pos >= 1){
           board.p2Pos -= 1;
        }
       break;
      }
      case 5:{
        fv++;
        printf("Moved back three spaces\n");
        if (board.p2Pos >=3) board.p2Pos-=3;
          else board.p2Pos = 0;
        break;
      }
      case 6:{
        sx++;
        printf("Moved forward six spaces\n");
        board.p2Pos+=6;
        break;
      }
      case 7:{
        sv++;
          printf("Did a good ol' switchero with another player\n");
        int temp;
        int temp2;
        if (inLast(board) == 2) break;
        else if (inLast(board) == 1){
                    temp2 = board.p1Pos;
          temp = board.p2Pos;
          board.p1Pos = temp;
          board.p2Pos = temp2;
        }
        else if (inLast(board) == 3){
                    temp2 = board.p2Pos;
          temp = board.p3Pos;
          board.p2Pos = temp;
          board.p3Pos = temp2;

        }
        else if (inLast(board) == 4){
            temp2 = board.p2Pos;
          temp = board.p4Pos;
          board.p2Pos = temp;
          board.p4Pos = temp2;
        
        }
        break;
      }
      case 8:{
        e++;
        printf("Lost a turn!\n");
        break;
      }
      case 9:{
        n++;
        printf("Moved forward nine\n");
        board.p2Pos+=9;
        break;
      }
      case 10:{
        tn++;
        printf("Moved forward ten\n");
        board.p2Pos+=10;
        break;
      }
      case 11:{
        lvn++;
        printf("Did a good ol' switchero with another player\n");
        int temp;
        int temp2;
        if (inLead(board) == 2) break;
        else if (inLead(board) == 1){
          temp2 = board.p1Pos;
          temp = board.p2Pos;          
          board.p1Pos = temp;
          board.p2Pos = temp2;
        }
        else if (inLead(board) == 3){
           temp2 = board.p2Pos;
          temp = board.p3Pos;         
          board.p2Pos = temp;
          board.p3Pos = temp2;
        }
        else if (inLead(board) == 4){
           temp2 = board.p2Pos;
          temp = board.p4Pos;         
          board.p2Pos = temp;
          board.p4Pos = temp2;
        }
        break;
      }
      case 12: {
        tw++;
        printf("Sent back to the beginning!\n");
        board.p2Pos=0;
        break;
      }
    } 
    if ((board.p2Pos == board.p1Pos || board.p2Pos == board.p3Pos||board.p2Pos == board.p4Pos) && board.p2Pos != 0) {board.p2Pos = 0; printf("It seems as though you landed on the same square as another player. Back to the beginning!\n");}
        printf("Player %d you are at square %d\n", player,board.p2Pos);
            }
  else {printf("You must roll the perfect number to reach victory from this point forward! Unless someone switches with you, then you're unlucky");if(board.size-board.p2Pos == total)board.p2Pos = 59;}

  }
      else printf("No double. No move.\n");
      } 
  //player 3
  if (player==3){
    if(die == die1) canroll3 = true;
    if(canroll3){
      if(board.p3Pos <= 50){
    switch(total){
      case 2 :{
                  printf("Moved forward two\n");
t++;
        board.p3Pos += 2;
        break;
      }
      case 3: {
                printf("Moved forward three\n");
      th++;
        board.p3Pos += 3;
        break;
      }
      case 4:{
        printf("Moved back a space\n");
        f++;
        if (board.p3Pos >= 1){
           board.p3Pos -= 1;
        }
       break;
      }
      case 5:{
        fv++;
                printf("Moved back three spaces\n");

        if (board.p3Pos >=3) board.p3Pos-=3;
          else board.p3Pos = 0;
        break;
      }
      case 6:{
        sx++;
                printf("Moved forward six spaces\n");

        board.p3Pos+=6;
        break;
      }
      case 7:{
        sv++;
        printf("Did a good ol' switchero with another player\n");
        int temp;
        int temp2;
        if (inLast(board) == 3) break;
        else if (inLast(board) == 1){
          temp2 = board.p1Pos;
          temp = board.p3Pos;
          board.p1Pos = temp;
          board.p3Pos = temp2;
          
        }
        else if (inLast(board) == 2){
           temp2 = board.p2Pos;
          temp = board.p3Pos;
          board.p2Pos = temp;
          board.p3Pos = temp2;
         
        }
        else if (inLast(board) == 4){
           temp2 = board.p3Pos;
          temp = board.p4Pos;
          board.p3Pos = temp;
          board.p4Pos = temp2;
         
        }
        break;
      }
      case 8:{
        e++;
        printf("Lost a turn!\n");
        break;
      }
      case 9:{
        n++;
        printf("Moved forward nine\n");
        board.p3Pos+=9;
        break;
      }
      case 10:{
        tn++;
        printf("Moved forward ten\n");
        board.p3Pos+=10;
        break;
      }
      case 11:{
        lvn++;
        printf("Did a good ol' switchero with another player\n");
        int temp;
        int temp2;
        if (inLead(board) == 3) break;
        else if (inLead(board) == 1){
          temp2 = board.p1Pos;
          temp = board.p3Pos;
          board.p1Pos = temp;
          board.p3Pos = temp2;
        }
        else if (inLead(board) == 2){
          temp2 = board.p2Pos;
          temp = board.p3Pos;
          board.p2Pos = temp;
          board.p3Pos = temp2;
        }
        else if (inLead(board) == 4){
          temp2 = board.p3Pos;
          temp = board.p4Pos;
          board.p3Pos = temp;
          board.p4Pos = temp2;
        }
        break;
      }
      case 12: {
        tw++;
        printf("Sent back to the beginning!\n");
        board.p3Pos=0;
        break;
      }
    }
    if ((board.p3Pos == board.p2Pos || board.p3Pos == board.p1Pos||board.p3Pos == board.p4Pos) && board.p3Pos != 0) {board.p3Pos = 0; printf("It seems as though you landed on the same square as another player. Back to the beginning!\n");}
        printf("Player %d you are at square %d\n", player,board.p3Pos);
      }
       else {printf("You must roll the perfect number to reach victory from this point forward! Unless someone switches with you, then you're unlucky");if(board.size-board.p3Pos == total)board.p3Pos = 59;}
  }
      else printf("No double. No move.\n");
      } 
  //player 4
  if (player==4){
    if(die == die1) canroll4 = true;
    if(canroll4){
    if(board.p4Pos <= 50){
    switch(total){
      case 2 :{
        t++;
        printf("Moved forward two\n");
        board.p4Pos += 2;
        break;
      }
      case 3: {
        th++;
                printf("Moved forward three\n");
        board.p4Pos += 3;
        break;
      }
      case 4:{
        f++;
                printf("Moved back a space\n");
        if (board.p4Pos >= 1){
           board.p4Pos -= 1;
        }
       break;
      }
      case 5:{
        fv++;
                printf("Moved back three spaces\n");
        if (board.p4Pos >=3) board.p4Pos-=3;
          else board.p4Pos = 0;
        break;
      }
      case 6:{
        sx++;
         printf("Moved forward six spaces\n");       
        board.p4Pos+=6;
        break;
      }
      case 7:{
        sv++;
        printf("Did a good ol' switchero with another player\n");
        int temp;
        int temp2;
        if (inLast(board) == 4) break;
        else if (inLast(board) == 2){
           temp2 = board.p4Pos;
          temp = board.p2Pos;
          board.p4Pos = temp;
          board.p2Pos = temp2;
         
        }
        else if (inLast(board) == 3){
          temp2 = board.p4Pos;
          temp = board.p3Pos;
          board.p4Pos = temp;
          board.p3Pos = temp2;
          
        }
        else if (inLast(board) == 1){
          temp2 = board.p1Pos;
          temp = board.p4Pos;
          board.p1Pos = temp;
          board.p4Pos = temp2;
          
        }
        break;
      }
      case 8:{
        e++;
        printf("Lost a turn!\n");
        break;
      }
      case 9:{
        n++;
        printf("Moved forward nine\n");
        board.p4Pos+=9;
        break;
      }
      case 10:{
        tn++;
        printf("Moved forward ten\n");
        board.p4Pos+=10;
        break;
      }
      case 11:{
        lvn++;
        printf("Did a good ol' switchero with another player\n");
        int temp;
        int temp2;
        if (inLead(board) == 4) break;
        else if (inLead(board) == 2){
          temp2 = board.p4Pos;
          temp = board.p2Pos;
          board.p4Pos = temp;
          board.p2Pos = temp2;
        }
        else if (inLead(board) == 3){
          temp2 = board.p4Pos;
          temp = board.p3Pos;
          board.p4Pos = temp;
          board.p3Pos = temp2;
        }
        else if (inLead(board) == 1){
          temp2 = board.p1Pos;
          temp = board.p4Pos;
          board.p1Pos = temp;
          board.p4Pos = temp2;
        }
        break;
      }
      case 12: {
        tw++;
        printf("Sent back to the beginning!\n");
        board.p4Pos=0;
        break;
      }
    }
    if ((board.p4Pos == board.p2Pos || board.p4Pos == board.p3Pos||board.p4Pos == board.p1Pos) && board.p4Pos != 0) {board.p4Pos = 0; printf("It seems as though you landed on top over another player. Back to the start!\n");};
        printf("Player %d you are at square %d\n", player,board.p4Pos);
            }
       else {printf("You must roll the perfect number to reach victory from this point forward! Unless someone switches with you, then you're unlucky");if(board.size-board.p4Pos == total)board.p4Pos = 59;}

  }
      else printf("No double. No move.\n");
      } 
//end of the player movement
 
    printBoard(board);
//checks to see if anyone has won
     if (board.p1Pos == 59||board.p2Pos == 59 ||board.p3Pos == 59||board.p4Pos == 59){
    printf("\n Player %d wins. Would you like to play again?(y/n)",player);
       //prints the amount of time each number was rolled
       printf("Number of time each number was rolled:\n 2: %d\n 3: %d\n 4: %d\n 5: %d\n 6: %d\n 7: %d\n 8: %d\n 9: %d\n 10: %d\n 11: %d\n 12: %d \n",t,th,f,fv,sx,sv,e,n,tn,lvn,tw);
      char throwaway;
      cin>>throwaway;
       //checks to see if the player wants to play again and resets everything to the default values
      if(throwaway == 'y'){
        cout<< "How players would you like this time?\n";
        play = true;
        player = 1;
        board.p1Pos = 70; board.p2Pos = 70; board.p3Pos = 70; board.p4Pos = 70;
           canroll1=false;
           canroll2=false;
            canroll3=false;
           canroll4=false;
        continue;
      }
      else
        printf("Thanks for playing! have a nice day!");
       break; running = false;
  }
   printf("Press enter twice to continue to the next player's turn"); 
    cin.ignore(1);
   cin.get();

  player++;

  }

  return 0;
}
