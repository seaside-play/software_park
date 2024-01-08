#pragma once

#include <initializer_list>

namespace test
{
	template <class T>
	struct TreeNode
	{
		T value;
		TreeNode* left;
		TreeNode* right;
	};

	template <class T>
	class BinaryTree
	{
	public:
		void CreateBinary(std::initializer_list<T> list);

	private:
		TreeNode<T>* root_;
	};

	template <class T>
	void BinaryTree<T>::CreateBinary(std::initializer_list<T> list)
	{
		root_ = new TreeNode;
		auto temp = root_;
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			temp->value = *it;
			temp->left = nullptr;
			temp->right = nullptr;
		}
	}
}

