#include "test_object.h"
#include <iostream>
#include <string>

#include "base.h"

namespace test
{
	struct Person
	{
		Person() = default;
		Person(int age, int sex) {}
		Person(char* name) {}
	};

	struct Student
		: public Person
	{
		using Person::Person;

		Student(const std::string& class_name, int number) 
		{
			std::cout << "Studtent(const std::string& class_name, int number) " << std::endl;
		}
	};

	void TestObject::Test()
	{
		mars::Tool tool(10);

		Student s("class 10 grade 1", 28);
		Student s2(10, 1);
	}

}