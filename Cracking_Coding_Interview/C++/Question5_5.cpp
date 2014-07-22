/*
 * Career Cup 5.5
 * Write a function to determine the number of bits required
 * to convert integer A to integer B. 
 */

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream> // std::ostringstream

using namespace std;

// convert to string
template<typename T>
string to_string(const T& value)
{
  ostringstream s;
  s << value;
  return s.str();
}

// output the decimal in binary format
string toFullBinaryString(int number)
{
  string s = "";
  for (int i = 0; i < 32; i++)
  {
    // get the least significant number
    int lsb = number & 1;
    s = to_string(lsb) + s;
    number = number >> 1;
  }

  return s;
}

// Figure out which bits in two numbers are different
// Use XOR, each 1 in XOR represents a bit that is different
// Check the least significant bit
int bitSwapRequired(int a, int b)
{
  int count = 0;
  int numOfDiff = 0;
  // shift numOfDiff repeatedly and always checking the 
  // least significant bit in numOfDiff
  for ( numOfDiff = a^b; numOfDiff != 0; numOfDiff = numOfDiff >> 1)
  {
    count += numOfDiff & 1;	  
  }
	
  return count;
}

// Clear the least significant bit
int bitSwapRequired2(int a, int b)
{
  int count = 0;
  int numOfDiff = a^b;
  // numOfDiff = numOfDiff & (numOfDiff - 1) will clear
	// the 1 bit from least significant bit
  for ( ; numOfDiff != 0; numOfDiff = numOfDiff & (numOfDiff - 1))
  {
    count++;	  
  }
	
  return count;
}

// Check the most significant bit
int countOnes(int number)
{
  if (number == 0) return 0;
  if (number == 1) return 1;
  if (number % 2 == 0)
    return countOnes(number / 2);
  else
    return countOnes(number / 2) + 1;
}

int bitSwapRequired3(int a, int b)
{
  int count = 0;
  int numOfDiff = a^b;

  return countOnes(numOfDiff);
}

int main()
{
  int N, M;
	
  cout << "Please input N(decimal): " << endl;
  cin >> N;
	
  cout << "Please input N(decimal): " << endl;
  cin >> M;
	
  // Calculate
  int result = bitSwapRequired(N, M);
  int result2 = bitSwapRequired2(N, M);
  int result3 = bitSwapRequired3(N, M);
	
  // print out the result
  cout << "N is(binary): " << toFullBinaryString(N) << endl;
  cout << "M is(binary): " << toFullBinaryString(M) << endl;
  cout << "result1 is: " << result << endl;
  cout << "result2 is: " << result2 << endl;
  cout << "result3 is: " << result3 << endl;
}














