#pragma once

#ifndef TEST_BINARY_TREE_H_
#define TEST_BINARY_TREE_H_

#include <utility>

namespace test
{

struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
 public:
  BinaryTree() = default;

  template <typename Container>
  BinaryTree(Container&& data);

  template <typename Container>
  bool CreateBinaryTree(Container&& data);

 private:
  TreeNode* root;
};

template <typename Container>
BinaryTree::BinaryTree(Container&& data) {
  CreateBinaryTree(std::forward<Container>(data));
}

template <typename Container>
bool CreateBinaryTree(Container&& data) {
  return false;
}

}  // namespace test



#endif  // TEST_BINARY_TREE_H_
