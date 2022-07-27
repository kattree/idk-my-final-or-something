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
  int p1Pos;
  int p2Pos;
  int p3Pos;
  int p4Pos;
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
  printf("|");
  for (int i = 0; i<board.size; i++) {board.realBoard[i] = block;
  cout<< board.realBoard[i];}
  printf("|");
}
//Determines how the player will move after the roll.
void playerPos(int total,int player,Board board){
  if (player==1){
    switch(total){
      case 2 :{
        board.p1Pos += 2;
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
  }
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
  }
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
  }
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
  }
}


int main() {
   Board board;

  printf("hi");
  int players;
  cin>>players;
  switch (players){
    case 2 : {
      board.p1Pos = 0; 
      board.p2Pos = 0;
      printf("$&");
      break;
    }
    case 3:{
      board.p1Pos = 0; 
      board.p2Pos = 0;
      board.p3Pos = 0;
      printf("$&@");
      break;}
    case 4 :{
      board.p1Pos = 0; 
      board.p2Pos = 0;
      board.p3Pos = 0;
      board.p4Pos = 0;
      printf("$&@#");
      break;
    }
        default:{ board.p1Pos = 0; 
      board.p2Pos = 0;
      printf("Whatever you entered was wrong so I'll go ahead and assume you meant two\n$&");
          break;
      }
  }
 printBoard(board);

  //std::cout << diceRoll();
 printf("%d,%d",dieRoll(),otherDieRollBCITS3AMANDTHISDUMBTHINGWONTWORK());
  return 0;
}
