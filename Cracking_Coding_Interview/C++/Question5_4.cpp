/*
 * Career Cup 5.4
 * Explain what the following code does:
 * ((n & (n-1)) == 0)
 */

/*
 * If A & B == 0
 * Means A and B never have a 1 bit in the same place.
 * If n & (n-1) == 0
 * Means n and n-1 never share a 1.
 *
 * What does n-1 look like?
 * 1101011000 - 1 = 1101010111
 * Look at the least significant bit:
 * If 1, change it to 0
 * If 0, "borrow" from a larger bit
 *
 * Thus n-1 will look like n.
 * n's initial 0s will be 1s in n-1
 * n's least significant 1 will be 0 in n-1
 * if      n = abcde1000
 * then  n-1 = abcde0111
 *
 * If n & (n-1) == 0
 * n and n-1 must have no 1s in common
 * So abcde must be 0s
 * n = 000001000
 * n is a power of 2.
 *
 * So ((n & (n-1)) == 0) checks if n is a power of 2
 * of in n = 0.
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

int main()
{  
  unsigned int N;

  cout << "Please input N(decimal): " << endl;
  cin >> N;

  // Calculate
  unsigned int result =  N & (N-1);

  // print out the result
  cout << "N is(binary): " << toFullBinaryString(N) << endl;
  cout << "The result is(binary): " << toFullBinaryString(result) << endl;
}