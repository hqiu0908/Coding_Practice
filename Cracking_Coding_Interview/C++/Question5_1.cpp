/*
 * Career Cup 5.1
 * Given two 32 bit numbers N and M.
 * Insert M into N from position i to j.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

unsigned int updateBits(unsigned int n, unsigned int m, int i, int j){
  
  // Validation
  if (i >= 32 || j < i)
  {
    return 0;
  }
                            
  /*
   * Create a right mask to clear bits from i in N.
   * Example: N = 11111111, i = 2, j = 6. 
   * Result should be 00000011.
   */
  unsigned int right_mask = (1<<i)-1; // 1s after position i. right = 00000011.
                                                                    
  // Shift left the left part of N. (from i+1 bits, shift j+1 bits)
  // Put M from i to j.
  // Use OR or Add to combine two integers.(Do bit by bit)
  return ( (m << i) | (n & right_mask) | ((n >> 2) << (j+1)) );
  
  /*
   *  If we want to replace N with M from i to j, create a left_mask
   *  unsigned int allOnes = ~0; // allOnes = 111111...111.
   *  unsigned int left_mask = allOnes << (j+1); // 1s from position (j+1). then 0s. left_mask = 11111100.
   *  return ( (m <<i) | (n & right_mask) | (n & left_mask));
   */ 
}

string DecToBin(unsigned int number)
{ 
  if (number == 0) return "0";
  if (number == 1) return "1";

  if(number % 2 == 0)
    return DecToBin(number / 2) + "0";
  else 
    return DecToBin(number / 2) + "1";
}

int main(){
  
  int N, M;

  cout << "Please input N(decimal): " << endl;
  cin >> N;

  cout << "Please input M(decimal): " << endl;
  cin >> M;

  // Calculate
  unsigned int result =  updateBits(N, M, 2, 8);

  // print out the result
  cout << "N is(binary): " << DecToBin(N) << endl;
  cout << "M is(binary): " << DecToBin(M) << endl;
  cout << "The result is(binary): " << DecToBin(result) << endl;
}
