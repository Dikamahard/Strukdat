#include "problem_a.hpp"

bool is_prime(int n)
{
  if (n <= 1){
    return false;
  }

  for (int i=2; i<n; i++){
    if (n % i == 0){
      return false;
      break;
    } 
  } return true; 
}

unsigned int factorial(unsigned int n)
{
   int mul = 1;   

   for(int i=1; i<=n; i++){
     mul *= i;
   }

   return mul;

}

void inplace_sort(size_t n, int arr[])
{
  int temp;
  for(int i=0; i<n; i++){
    for(int j=0; j<n-i-1; j++){
       if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void inplace_reverse_str(std::string &str)
{
  int n = str.size();
  int temp;
  for (int i = 0; i < n / 2; i++) {
    //swap(str[i], str[n - i - 1]);
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
  }
}

std::string reverse_str(const std::string &str)
{
  std :: string kata = str;
  int n = kata.size();
  int temp;
  for (int i = 0; i < n / 2; i++) {
    //swap(str[i], str[n - i - 1]);
        temp = kata[i];
        kata[i] = kata[n-i-1];
        kata[n-i-1] = temp;
  }
  return kata;
}