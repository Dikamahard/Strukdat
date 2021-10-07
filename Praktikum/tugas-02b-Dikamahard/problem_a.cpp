#include "problem_a.hpp"

int *multiply_by_two(int &n)
{
  int *p;

  p = &n;
  *p *= 2;
  
  return p;
}

std::string the_third_and_fifth(char *ptr)
{
  std::string hasil;
  ptr+=2;
  hasil.push_back(*ptr);
  ptr+=2;
  hasil.push_back(*ptr);

  return hasil;

}

int my_own_strlen(char *ptr)
{
  int n = 0;
  int i = 0;
  while (*(&ptr[i]) != '\0'){
    n++;
    i++;
  }
  return n;
}

void element_swapper(int *ptr1, int *ptr2, int n)
{
  int swap = ptr1[n];
  ptr1[n] = ptr2[n];
  ptr2[n] = swap;
}