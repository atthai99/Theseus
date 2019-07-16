// A routine for moving the Minotaur
// (c) 2019 Andrew Thai
#include "theseus.h"

// Birthday for advanced biometric tracking:
int BDay[] = { /* this is mine: */ 10, 30, 1999 };

// Move the minotaur 's' strides toward our hero
int chase(level *l, int s)
{
  int i;
  int moved = 0;
  // move the Minotaur 's' strides; keep track of number of successful moves
  for (i = 0; i < s; i++) {
    moved += moveM(l);
  }
  return moved;
}

// Move the minotaur one stride:
//  * always move toward Theseus
//  * if a horizontal move is possible, take it
//  * otherwise move vertically (if possible)
// Returns 1 if moved, 0 if not.
int moveM(level *l)
{
  // Theseus's position
  int pos = getT(l);
  int tRow = (pos>>4) & 0xF;
  int tCol = pos & 0xF;

  // Minotaur's position
  pos = getM(l);
  int mRow = (pos>>4) & 0xF;
  int mCol = pos & 0xF;

  // Minotaur's cell
  int mCell = get(l, mRow, mCol);

  // Minotaur's new position
  int newRow = mRow;
  int newCol = mCol;

  // check if Minotaur should/can move in a direction
  if ((mCol > tCol) && !(mCell & LEFT)) {
    newCol--; 
  } else if ((mCol < tCol) && !(mCell & RIGHT)) {
    newCol++;
  } else if ((mRow > tRow) && !(mCell & UP)) {
    newRow--;
  } else if ((mRow < tRow) && !(mCell & DOWN)) {
    newRow++;
  } else {
    return 0; // no possible moves
  }

  // makes a move
  movePiece(l,MINOTAUR,mRow,mCol,newRow,newCol);
  return 1;
}
