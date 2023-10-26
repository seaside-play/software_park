#pragma once

namespace test
{
	class TestCpp17
	{
	public:
		void Test();

	private:
		// 1.���캯��ģ���Ƶ�
		void TestConstructTemplateDeduce();

		// 2. �ṹ����
		void TestStructureBind();

		// 3. if - switch����ʼ��
		void TestIfSwitch();

		// 4. ��������
		void TestInlineVariable();

		// 5. �۵����ʽ
		void TestFoldExpress();

		// 6. constexpr lambda���ʽ
		void TestConstexprLambda();

		// 7. namespaceǶ��
		void TestNamespaceNesting();
		//
		// 8. __has_includeԤ������ʽ
		void TestHasInclude();

		// 9. ��lambda���ʽ�� * this������󸱱�
		void TestLambadThisCopy();
		
		// 10. ����Attribute
		void TestAttibute();

		// 11. �ַ���ת��
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

