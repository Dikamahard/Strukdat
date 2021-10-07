/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 */

#include "problem_a.hpp"
#include <iostream>

/*
void sort(size_t n, int arr[])
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
*/

int main(int argc, char const *argv[]){
  
  std :: string tes = "mahardika xyz";
  inplace_reverse_str(tes);
  std :: cout << tes;
    
}
 