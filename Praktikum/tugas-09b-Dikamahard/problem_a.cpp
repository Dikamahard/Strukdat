#include "problem_a.hpp"

template <typename T>
void BFSTraversal(Tree<T> &Root, vector<T> &traversedData)
{
  queue<pointer<T>> q;
  q.push(Root);
  while (!q.empty()) {
    pointer<T> n = q.front();
    q.pop();
    traversedData.push_back(n->data);
    if (n->left != nullptr) {
      q.push(n->left);
    }if (n->right != nullptr){
      q.push(n->right);
    }  
  }
}

template <typename T>
Tree<T> lowestCommonAncestor(Tree<T>& Root, pointer<T> a, pointer<T> b)
{
  if (Root == nullptr)  {
    return nullptr;
  }if (Root->data > a->data && Root->data > b->data) {
    return lowestCommonAncestor(Root->left, a, b);
  }else if (Root->data < a->data && Root->data < b->data) {
    return lowestCommonAncestor(Root->right, a, b);
  }
  return Root;
}

template <typename T>
Tree<T> invertBST(Tree<T>& Root)
{
   if (Root == nullptr) {
     return Root;
   }
    
  invertBST(Root->left);
  invertBST(Root->right);

  pointer<T> temp = Root->left;
  Root->left = Root->right;
  Root->right = temp;

  return Root;
}