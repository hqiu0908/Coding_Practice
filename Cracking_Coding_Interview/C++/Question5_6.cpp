/*
 * Career Cup 5.6
 * Swap odd and even bits in an integer with as few instructions
 * as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3
 * are swapped, and so on)
 */

#include <iostream>
#include <string>

using namespace std;

string toFullBinaryString(unsigned int number)
{ 
  if (number == 0) return "0";
  if (number == 1) return "1";

  if(number % 2 == 0)
    return toFullBinaryString(number / 2) + "0";
  else 
    return toFullBinaryString(number / 2) + "1";
}

int swapOddEvenBits(int number)
{
  /*
   * Mask all odd bits with 10101010 in binary (0xaaaa)
   * Mask all even bits with 01010101 in binary (0x5555)
   * Shift right the odd bits by 1, 
   * Shift left the even bits by 1, 
   * merge with even bits.
   */
  return ( ((number & 0xaaaaaaaa) >> 1) + ((number & 0x55555555) << 1) );
}

int main()
{
  unsigned int N;

  cout << "Please input N(decimal): " << endl;
  cin >> N;
	
  // Calculate
  unsigned int result =  swapOddEvenBits(N);
	
  // print out the result
  cout << "N is(binary): " << toFullBinaryString(N) << endl;
  cout << "The result is(binary): " << toFullBinaryString(result) << endl;
}
