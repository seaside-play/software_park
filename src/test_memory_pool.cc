#include "test_memory_pool.h"
#include "memory_pool.h"

#include <vector>
#include <chrono>
#include <iostream>

// 参考：https://zhuanlan.zhihu.com/p/650844983

namespace test {

struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

void TestMemoryPool::Test() {
  //TestObjectPool();
  TestObjectPool2();
};

void TestMemoryPool::TestObjectPool() {
 auto size = sizeof(TreeNode);
	// 申请释放的轮次
	const size_t Rounds = 100;

	// 每轮申请释放多少次
	const size_t N = 1000000;

	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}

	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	SimpleMemoryPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	std::cout << "new cost time:" << end1 - begin1 << std::endl;
	std::cout << "object pool cost time:" << end2 - begin2 << std::endl;
}

void TestMemoryPool::TestObjectPool2() {
  auto size = sizeof(TreeNode);
	// 申请释放的轮次
	const size_t Rounds = 100;

	// 每轮申请释放多少次
	const size_t N = 1000000;

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	SimpleMemoryPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	std::cout << "object pool cost time:" << end2 - begin2 << std::endl;
}

}