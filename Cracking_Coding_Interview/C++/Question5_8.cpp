/*
 * Career Cup 5.8
 * A monochrome screen is stored as a single array of bytes, allowing eight consec-
 * utive pixels to be stored in one byte. The screen has width w, where w is divisible
 * by 8. The height of the screen can be derived from the length of the array and the
 * width. Implement a function drawHorizontalLine(byte[] screen, int width, int x1, 
 * int x2, int y) which draws a horizonal line from (x1, y) to (x2,y).
 */

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

// If use byte
// typedef char byte;

#define BYTEPERLINE 4

// The full bytes can be set one at a time by doing screen[pos] = 0xFF
// The residual start and end of the line can be set using masks
void drawHorizontalLine(char* screen, int width, int x1, int x2, int y)
{
  // Calculate the starting byte number which needs to be set full 1s (after x1)
  // Calculate the ending byte number which needs to be set full 1s (before x2)
  int startByte = x1 / 8 + 1;
  int endByte = x2 / 8 - 1;
	
  // Calculate the position(offset) of x1 and x2 in the byte
  int startOffset = x1 % 8;
  int endOffset = x2 % 8;
	
  // Adjust the boundary
  // If x1 = 0 (first bit in the byte), startByte = 0 (first byte in the line)
  // If x1 = 1..7 (other bits in the byte), startByte = 1 (second byte in the line)
  if ( startOffset == 0 )
  {
    startByte--;
  }
	
  // If x2 = 0..6 (other bits in the byte), endByte = -1 (don't need to set)
  // If x2 = 7 (last bit in the byte), endByte = 0 (first byte in the line)
  if ( endOffset == 7 )
  {
    endByte++;
  }
	
  // Set full bytes (between starting byte and ending byte)
  for ( int i = startByte; i <= endByte; i++ )
  {
    // y indicates which line do x1 and x2 exist
    screen[ y * BYTEPERLINE + i ] = (char)0xff;
  }
	
  // Set residual bytes (contains x1 and x2)
  // Create left_mask(for x2) and right_mask(for x1)
  char right_mask = (char) (0xff >> startOffset);
  char left_mask = (char) (0xff << (8 - endOffset - 1));
	
  // If x1 and x2 are in the same byte
  if( (x1 / 8) == (x2 / 8) )
  {
    // get intersection
    char mask = left_mask & right_mask;
    screen[ y * BYTEPERLINE + x1 / 8 ] |= mask;
  }
  else 
  {
    if (startOffset != 0)
    {
      int byteNumber = y * BYTEPERLINE + x1 / 8;
      screen [byteNumber] |= right_mask;
    }
    if (endOffset != 7)
    {
      int byteNumber = y * BYTEPERLINE + x2 / 8;
      screen [byteNumber] |= left_mask;
    }
  }
}

void printByte(char byte)
{
  // print from the most significant bit to the least one, i--
  for(int i = 7; i >= 0; i--)
  {
    cout << ( (byte >> i) & 1 );
  }
}

void printScreen (char* screen, int width, int height)
{
  for ( int i = 0; i < height; i++)
  {
    for ( int j = 0; j < width / 8; j++)
    {
      printByte( screen[ i * BYTEPERLINE + j] );
    }
    cout << endl;
  }
}

int main()
{
  int width = 8 * BYTEPERLINE;
  int height = 15;
  char* screen = new char[ width * height / 8];
	
  int x1, x2, h;
  cout << "Please input x1: " << endl;
  cin >> x1;
  cout << "Please input x2: " << endl;	
  cin >> x2;
  cout << "Please input line number (0~14): " << endl;	
  cin >> h;
	
  drawHorizontalLine(screen, width, x1, x2, h);
	
  printScreen(screen, width, height);	
	
  // free memory
  delete[] screen;
}
