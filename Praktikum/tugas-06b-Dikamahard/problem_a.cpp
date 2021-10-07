#include "problem_a.hpp"

using namespace strukdat::stack;

template <typename T>
int getMax(Stack<T> Top) {
    int max = 0;
    max = peek(Top);
    pointer<int> pHelp;
    while (!isEmpty(Top)) {
    pHelp = pop(Top, pHelp);
        if (max < pHelp->data) {
            max = pHelp->data;
        }
    }
  return max;
}

template <typename T>
int getEqualStack(Stack<T> Top1, Stack<T> Top2, Stack<T> Top3)
{
    int count1, count2, count3;
    pointer<int> pHelp;

    Stack<T> temp = Top1;
  if (isEmpty(Top1)) {
    // do nothing
  } else {
    do {
      count1 += temp->data;
      temp = temp->next;
    } while (temp != nullptr);
  }

     temp = Top2;
  if (isEmpty(Top2)) {
    // do nothing
  } else {
    do {
      count2 += temp->data;
      temp = temp->next;
    } while (temp != nullptr);
  }

     temp = Top3;
  if (isEmpty(Top3)) {
    // do nothing
  } else {
    do {
      count3 += temp->data;
      temp = temp->next;
    } while (temp != nullptr);
  }

    while (1) {
    if (count1 == count2 && count2 == count3) {
      return count1;
    }

    if (count1 >= count2 && count1 >= count3) {
      pHelp = pop(Top1, pHelp);
      count1 -= pHelp->data;
    } else if (count2 >= count1 && count2 >= count3) {
      pHelp = pop(Top2, pHelp);
      count2 -= pHelp->data;
    } else if (count3 >= count1 && count3 >= count1) {
      pHelp = pop(Top3, pHelp);
      count3 -= pHelp->data;
    }
  }

}

bool isBracketBalanced(std::string expression)
{ 
    pointer<char> newElement = nullptr;
  Stack<char> Top = createStack(Top);
  pointer<char> pHelp;
  char s;

  for (char c : expression) {
    if (c == '{' || c == '(' || c == '[') {
      createElement(newElement, c);
      Top = push(Top, newElement);
      continue;
    }

    if (isEmpty(Top))
      return false;
    switch (c) {
    case ')':
      s = peek(Top);
      pHelp = pop(Top, pHelp);
      if (s == '{' || s == '[')
        return false;
      break;

    case '}':
      s = peek(Top);
      pHelp = pop(Top, pHelp);
      if (s == '(' || s == '[')
        return false;
      break;

    case ']':
      s = peek(Top);
      pHelp = pop(Top, pHelp);
      if (s == '(' || s == '{')
        return false;
      break;
    }
  }

  return isEmpty(Top);
}