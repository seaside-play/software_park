#include "test_cpp17.h"
#include "base.h"
#include "lib_head.h"

namespace test
{
	void TestCpp17::Test()
	{
		// 1.���캯��ģ���Ƶ�
		TestConstructTemplateDeduce();

		// 2. �ṹ����
		TestStructureBind();

		// 3. if - switch����ʼ��
		TestIfSwitch();

		// 4. ��������
		TestInlineVariable();

		// 5. �۵����ʽ
		TestFoldExpress();

		// 6. constexpr lambda���ʽ
		TestConstexprLambda();

		// 7. namespaceǶ��
		TestNamespaceNesting();
		//
		// 8. __has_includeԤ������ʽ
		TestHasInclude();

		// 9. ��lambda���ʽ�� * this������󸱱�
		TestLambadThisCopy();

		// 10. ����Attribute
		TestAttibute();

		// 11. �ַ���ת��
		TestCharTransform();

		// 12. std::variant
		TestVariant();

		// 13. std::optional
		TestOptional();

		// 14. std::any
		TestAny();
		// 
		// 15. std::apply
		TestApply();

		// 16. std::make_from_tuple
		TestMakeFromTuple();

		// 17. as_const
		TestAsConst();

		// 18. std::string_view
		TestStringView();

		// 19. file_system
		TestFileSystem();

		// 20. std::shared_mutex
		TestSharedMutex();
	}

	// 1.���캯��ģ���Ƶ�
	void TestCpp17::TestConstructTemplateDeduce()
	{
		std::vector vi{ 1,2,3,4,5 };
		std::pair pair{ 3,2 };
	}

	// 2. �ṹ���󶨣����ǰ��ն����б����Ĵ��˳��ͨ������������Ӧ�����
	// ʹ�ó�������1��������������2����������ֵ������������һ���ṹ��������ʱ��ʹ�ýṹ���󶨿���ֱ�ӻ�÷���ֵ�ĸ�����Ա
	// ���첻�㣺���ܷ���˽�г�Ա
	void TestCpp17::TestStructureBind()
	{
		test::Tip(__func__);

		auto func = []() -> std::tuple<int, double> { return std::tuple(1, 2.2); };

		auto [i, d] = func();
		std::cout << i << std::endl;
		std::cout << d << std::endl;

		std::map<int, std::string> students{
			{1, "wu"}, 
			{2, "chaojiang"}, 
			{3, "Chris"}
		};

		for (const auto& [index, name] : students)
		{
			std::cout << "index: " << index << ", name: " << name << std::endl;
		}

		class Student
		{
		public:
			Student(int no, bool sex, std::string&& name, std::string&& province)
				: no_(no), sex_(sex), name_(std::move(name)), province_(std::move(province))
			{}


		private:
			int no_;
			bool sex_;
			std::string name_;
			std::string province_;
		};
		
		std::vector<Student> vstudents;
		vstudents.emplace_back(1, true, "Wu Chaojiang", "Beijing");
		vstudents.emplace_back(2, false, "Xiaoxiao", "Beijing");
		vstudents.emplace_back(3, true, "Shaowei", "Zhejiang");

		auto GetStudent = [](const decltype(vstudents)& students) -> decltype(vstudents) { return students; };

		auto cur_students = GetStudent(vstudents);

		//auto [no, sex, name, province] = GetStudent(vstudents);
		//for (const auto& [no, sex, name, province] : vstudents)
		//{
		//	std::cout << no << " " << std::boolalpha << sex << " " << name << " " << province << std::endl;
		//}

		class MyClass {
		public:
			int myPrivateVar;
			int private2;

		public:
			// Getter method for myPrivateVar  
			int getMyPrivateVar() const {
				return myPrivateVar;
			}

			// Setter method for myPrivateVar  
			void setMyPrivateVar(int value) {
				myPrivateVar = value;
			}
		};

		MyClass obj;
		obj.setMyPrivateVar(42);

		// Use structured binding to access the private member indirectly  
		auto [private_var, var2] = obj;
		std::cout << "Private member value: " << private_var << std::endl;

	}

	// 3. if - switch����ʼ��
	void TestCpp17::TestIfSwitch()
	{

	}

	// 4. ��������
	void TestCpp17::TestInlineVariable()
	{

	}

	// 5. �۵����ʽ
	void TestCpp17::TestFoldExpress()
	{

	}

	// 6. constexpr lambda���ʽ
	void TestCpp17::TestConstexprLambda()
	{

	}

	// 7. namespaceǶ��
	void TestCpp17::TestNamespaceNesting()
	{

	}

	// 8. __has_includeԤ������ʽ
	void TestCpp17::TestHasInclude()
	{

	}

	// 9. ��lambda���ʽ�� * this������󸱱�
	void TestCpp17::TestLambadThisCopy()
	{

	}

	// 10. ����Attribute
	void TestCpp17::TestAttibute()
	{

	}

	// 11. �ַ���ת��
	void TestCpp17::TestCharTransform()
	{

	}

	// 12. std::variant
	void TestCpp17::TestVariant()
	{

	}

	// 13. std::optional
	void TestCpp17::TestOptional()
	{

	}

	// 14. std::any
	void TestCpp17::TestAny()
	{

	}

	// 15. std::apply
	void TestCpp17::TestApply()
	{

	}

	// 16. std::make_from_tuple
	void TestCpp17::TestMakeFromTuple()
	{

	}

	// 17. as_const
	void TestCpp17::TestAsConst()
	{

	}

	// 18. std::string_view
	void TestCpp17::TestStringView()
	{

	}

	// 19. file_system
	void TestCpp17::TestFileSystem()
	{

	}

	// 20. std::shared_mutex
	void TestCpp17::TestSharedMutex()
	{

	}
}