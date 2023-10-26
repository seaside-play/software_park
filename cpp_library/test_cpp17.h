#pragma once

namespace test
{
	class TestCpp17
	{
	public:
		void Test();

	private:
		// 1.构造函数模板推导
		void TestConstructTemplateDeduce();

		// 2. 结构化绑定
		void TestStructureBind();

		// 3. if - switch语句初始化
		void TestIfSwitch();

		// 4. 内联变量
		void TestInlineVariable();

		// 5. 折叠表达式
		void TestFoldExpress();

		// 6. constexpr lambda表达式
		void TestConstexprLambda();

		// 7. namespace嵌套
		void TestNamespaceNesting();
		//
		// 8. __has_include预处理表达式
		void TestHasInclude();

		// 9. 在lambda表达式用 * this捕获对象副本
		void TestLambadThisCopy();
		
		// 10. 新增Attribute
		void TestAttibute();

		// 11. 字符串转换
		void TestCharTransform();

		// 12. std::variant
		void TestVariant();

		// 13. std::optional
		void TestOptional();

		// 14. std::any
		void TestAny();
		// 
		// 15. std::apply
		void TestApply();

		// 16. std::make_from_tuple
		void TestMakeFromTuple();

		// 17. as_const
		void TestAsConst();

		// 18. std::string_view
		void TestStringView();

		// 19. file_system
		void TestFileSystem();

		//
		// 20. std::shared_mutex
		void TestSharedMutex();
	};

}

