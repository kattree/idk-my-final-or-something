#include <iostream>
#include <cstdio>
#include <ctime>
#include  <cstdlib>
#include <string.h>
#include <time.h>
#define block "\u25a9"
using namespace std;

int dieRoll(){
   srand(time(NULL));
  
  

  int die1 = (rand() % 5)+1;
  //int die2 = (rand() % 5);

  return die1;
}
int otherDieRollBCITS3AMANDTHISDUMBTHINGWONTWORK(){
   srand(time(0));
  int die = (rand()%11)/2+1;
  return die;
}

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


void printBoard(Board board){
  board.realBoard[board.p1Pos] = "$";
  board.realBoard[board.p2Pos] = "&";
  if ((board.p3Pos >= 0 )&&(board.p3Pos <= 60)) board.realBoard[board.p3Pos] = "@";
  if ((board.p4Pos >= 0 )&&(board.p4Pos <= 60)) board.realBoard[board.p4Pos] = "#";
  
  printf("|");
  for (int i = 0; i<board.size; i++)cout<< board.realBoard[i];
  printf("|");
}
//Determines how the player will move after the roll.
void playerPos(int total,int player,Board board){
 

      
      
}


int main() {
  
   Board board;
    for (int i = 0; i<board.size; i++) board.realBoard[i] = block;
  
  printf("hi");
  int players;
  cin>>players;
  switch (players){
    case 2 : {
      board.p1Pos = 0; 
      board.p2Pos = 0;

      break;
    }
    case 3:{
      board.p1Pos = 0; 
      board.p2Pos = 0;
      board.p3Pos = 0;

      break;}
    case 4 :{
      board.p1Pos = 0; 
      board.p2Pos = 0;
      board.p3Pos = 0;
      board.p4Pos = 0;
      
      break;
    }
        default:{ board.p1Pos = 0; 
      board.p2Pos = 0;
      printf("Whatever you entered was wrong so I'll go ahead and assume you meant two");
          break;
      }
  }

 printBoard(board);

  
  
  printBoard( board);
printf("%d",board.p1Pos);


  srand(time(NULL));




  
  int player=1;
 bool running=true;
  //game loop
  while(running){
    if (player >players ) player =1;
      printf("Player %d's turn\n",player);
   // printBoard(board);
  int die1 = (rand() % 6)+1;
  int die = (rand()%11)/2+1;
  int total = die1+die;
   //player one dice movements
  if (player==1){
    switch(total){
      case 2 :{
        //printf("i ran");
        board.p1Pos += 2;
        //return board.p1Pos;
        break;
      }
      case 3: {
        board.p1Pos += 3;
        break;
      }
      case 4:{
        if (board.p1Pos >= 1){
           board.p1Pos -= 1;
        }
       break;
      }
      case 5:{
        if (board.p1Pos >=3) board.p1Pos-=3;
          else board.p1Pos = 0;
        break;
      }
      case 6:{
        board.p1Pos+=6;
        break;
      }
      case 7:{
        int temp;
        int temp2;
        if (inLast(board) == 1) break;
        else if (inLast(board) == 2){
          board.p1Pos = temp;
          board.p2Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p2Pos;
        }
        else if (inLast(board) == 3){
          board.p1Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p3Pos;
        }
        else if (inLast(board) == 4){
          board.p1Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 8:{
        break;
      }
      case 9:{
        board.p1Pos+=9;
        break;
      }
      case 10:{
        board.p1Pos+=10;
        break;
      }
      case 11:{
        int temp;
        int temp2;
        if (inLead(board) == 1) break;
        else if (inLead(board) == 2){
          board.p1Pos = temp;
          board.p2Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p2Pos;
        }
        else if (inLead(board) == 3){
          board.p1Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p3Pos;
        }
        else if (inLead(board) == 4){
          board.p1Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 12: {
        board.p1Pos=0;
        break;
      }
    }
    if ((board.p1Pos == board.p2Pos || board.p1Pos == board.p3Pos||board.p1Pos == board.p4Pos) && board.p1Pos != 0) board.p1Pos = 0;
  }
  //player 2
  if (player==2){
   switch(total){
      case 2 :{
        board.p2Pos += 2;
        break;
      }
      case 3: {
        board.p2Pos += 3;
        break;
      }
      case 4:{
        if (board.p2Pos >= 1){
           board.p2Pos -= 1;
        }
       break;
      }
      case 5:{
        if (board.p2Pos >=3) board.p2Pos-=3;
          else board.p2Pos = 0;
        break;
      }
      case 6:{
        board.p2Pos+=6;
        break;
      }
      case 7:{
        int temp;
        int temp2;
        if (inLast(board) == 2) break;
        else if (inLast(board) == 1){
          board.p1Pos = temp;
          board.p2Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p2Pos;
        }
        else if (inLast(board) == 3){
          board.p2Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p2Pos;
          temp = board.p3Pos;
        }
        else if (inLast(board) == 4){
          board.p2Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p2Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 8:{
        break;
      }
      case 9:{
        board.p2Pos+=9;
        break;
      }
      case 10:{
        board.p2Pos+=10;
        break;
      }
      case 11:{
        int temp;
        int temp2;
        if (inLead(board) == 2) break;
        else if (inLead(board) == 1){
          board.p1Pos = temp;
          board.p2Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p2Pos;
        }
        else if (inLead(board) == 3){
          board.p2Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p2Pos;
          temp = board.p3Pos;
        }
        else if (inLead(board) == 4){
          board.p2Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p2Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 12: {
        board.p2Pos=0;
        break;
      }
    } 
    if ((board.p2Pos == board.p1Pos || board.p2Pos == board.p3Pos||board.p2Pos == board.p4Pos) && board.p2Pos != 0) board.p2Pos = 0;
  }
  //player 3
  if (player==3){
    switch(total){
      case 2 :{
        board.p3Pos += 2;
        break;
      }
      case 3: {
        board.p3Pos += 3;
        break;
      }
      case 4:{
        if (board.p3Pos >= 1){
           board.p3Pos -= 1;
        }
       break;
      }
      case 5:{
        if (board.p3Pos >=3) board.p3Pos-=3;
          else board.p3Pos = 0;
        break;
      }
      case 6:{
        board.p3Pos+=6;
        break;
      }
      case 7:{
        int temp;
        int temp2;
        if (inLast(board) == 3) break;
        else if (inLast(board) == 1){
          board.p1Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p3Pos;
        }
        else if (inLast(board) == 2){
          board.p2Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p2Pos;
          temp = board.p3Pos;
        }
        else if (inLast(board) == 4){
          board.p3Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p3Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 8:{
        break;
      }
      case 9:{
        board.p3Pos+=9;
        break;
      }
      case 10:{
        board.p3Pos+=10;
        break;
      }
      case 11:{
        int temp;
        int temp2;
        if (inLead(board) == 3) break;
        else if (inLead(board) == 1){
          board.p1Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p3Pos;
        }
        else if (inLead(board) == 2){
          board.p2Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p2Pos;
          temp = board.p3Pos;
        }
        else if (inLead(board) == 4){
          board.p3Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p3Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 12: {
        board.p3Pos=0;
        break;
      }
    }
    if ((board.p3Pos == board.p2Pos || board.p3Pos == board.p1Pos||board.p3Pos == board.p4Pos) && board.p3Pos != 0) board.p3Pos = 0;
  }
  //player 4
  if (player==4){
    switch(total){
      case 2 :{
        board.p4Pos += 2;
        break;
      }
      case 3: {
        board.p4Pos += 3;
        break;
      }
      case 4:{
        if (board.p4Pos >= 1){
           board.p4Pos -= 1;
        }
       break;
      }
      case 5:{
        if (board.p4Pos >=3) board.p4Pos-=3;
          else board.p4Pos = 0;
        break;
      }
      case 6:{
        board.p4Pos+=6;
        break;
      }
      case 7:{
        int temp;
        int temp2;
        if (inLast(board) == 4) break;
        else if (inLast(board) == 2){
          board.p4Pos = temp;
          board.p2Pos = temp2;
          temp2 = board.p4Pos;
          temp = board.p2Pos;
        }
        else if (inLast(board) == 3){
          board.p4Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p4Pos;
          temp = board.p3Pos;
        }
        else if (inLast(board) == 1){
          board.p1Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 8:{
        break;
      }
      case 9:{
        board.p4Pos+=9;
        break;
      }
      case 10:{
        board.p4Pos+=10;
        break;
      }
      case 11:{
        int temp;
        int temp2;
        if (inLead(board) == 4) break;
        else if (inLead(board) == 2){
          board.p4Pos = temp;
          board.p2Pos = temp2;
          temp2 = board.p4Pos;
          temp = board.p2Pos;
        }
        else if (inLead(board) == 3){
          board.p4Pos = temp;
          board.p3Pos = temp2;
          temp2 = board.p4Pos;
          temp = board.p3Pos;
        }
        else if (inLead(board) == 1){
          board.p1Pos = temp;
          board.p4Pos = temp2;
          temp2 = board.p1Pos;
          temp = board.p4Pos;
        }
        break;
      }
      case 12: {
        board.p4Pos=0;
        break;
      }
    }
    if ((board.p4Pos == board.p2Pos || board.p4Pos == board.p3Pos||board.p4Pos == board.p1Pos) && board.p4Pos != 0) board.p4Pos = 0;
  }
  printf("You rolled a %d and a %d for a total of %d\n",die1,die,total);
    //if (total ==7) printf("%d",temp);
    printBoard(board);
   printf("Press any key to continue to the next player's turn"); 
    cin.ignore(1);
   cin.get();

  player++;

  
    
  }

  return 0;
}
