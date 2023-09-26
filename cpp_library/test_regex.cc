#include "test_regex.h"

#include <iomanip>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <sstream>


std::string test_html = R"(<table align=center border=1>
<caption><b><u>Symbol Pin Report</u></b></caption>
<tr>
<td><b>REFDES</b></td>
<td><b>PIN_NUMBER</b></td>
<td><b>SYM_NAME</b></td>
<td><b>COMP_DEVICE_TYPE</b></td>
<td><b>PAD_STACK_NAME</b></td>
<td><b>PIN_X</b></td>
<td><b>PIN_Y</b></td>
<td><b>NET_NAME</b></td>
</tr>
<tr>
<td nowrap=true>IP</b></td>
<td nowrap=true>A1</b></td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>-2.410</td>
<td nowrap=true>3.900</td>
<td><b>DNU</td>
</tr>

</table>)";

std::string test_data = R"(<person>\n
<first>Nico</first>\n
<last>Josuttis</last>\n
</person>\n)";

using namespace std;
void test1()
{
	std::regex reg(R"(<(\w*)>.*</\1>)");
	std::string line("<tag>value</tag>");
	bool found = std::regex_match(line, reg);
}

void test2() {
	string data = "XML tag: <tag-name>the value</tag-name>.";
	cout << "data				" << data << "\n\n";

	smatch m;
	bool found = regex_search(data, m, regex("<(.*)>(.*)</(\\1)>"));

	cout << "m.empty(): " << boolalpha << m.empty() << endl;
	cout << "m.size(): " << m.size() << endl;

	if (found) {
		cout << "m.str(): " << m.str() << endl;
		cout << "m.length(): " << m.length() << endl;
		cout << "m.position(): " << m.position() << endl;
		cout << "m.prefix().str(): " << m.prefix().str() << endl;
		cout << "m.suffix().str(): " << m.suffix().str() << endl;
		cout << endl;

		for (int i = 0; i < m.size(); ++i)
		{
			cout << "m[" << i << "].str(): " << m[i].str() << endl;
			cout << "m.str(" << i << "): " << m.str(i) << endl;
			cout << "m.position(" << i << "): " << m.position(i) << endl;
		}
		cout << endl;

	} // 使用regex_search查找的是子串的匹配
}

void test3()
{
	string data = "<person>\n"
		" <first>Nico</first> sdfasdf"
		" asdfas <last>Josuttis</last>"
		" </person>\n";

	regex reg("<(.*)>(.*)</(\\1)>");
	auto pos = data.cbegin();
	auto end = data.cend();
	smatch m;
	for (; regex_search(pos, end, m, reg); pos = m.suffix().first) {
		cout << "match: " << m.str() << endl;
		cout << " tag: " << m.str(1) << endl;
		cout << " value: " << m.str(2) << endl;
	}

}

void test4()
{
	std::string line = R"(   ((6 0) (26 0) (21 0))   )";

	auto pos = line.cbegin();
	auto end = line.cend();

	regex reg(R"(\((\d+)\s\d\)\s*)");

	smatch m;
	for (; regex_search(pos, end, m, reg); pos = m.suffix().first) {
		cout << "match: " << m.str() << endl;
		cout << "layer id: " << m.str(1) << endl;

	}
}

void test5()
{
	string data = "<person><first>Nico</first><last>Josuttis</last></person>\n";

	regex reg("<(.*)>(.*)</(\\1)>");
	auto pos = data.cbegin();
	auto end = data.cend();
	smatch m;
	for (; regex_search(pos, end, m, reg); pos = m.suffix().first) {
		cout << "match: " << m.str() << endl;
		cout << " tag: " << m.str(1) << endl;
		cout << " value: " << m.str(2) << endl;
	}
}

void test6()
{
	string data = "<person><first>Nico</first><last>Josuttis</last></person>\n";

	regex reg("<(.*)>([^<]*)</(\\1)>");
	auto pos = data.cbegin();
	auto end = data.cend();
	smatch m;
	for (; regex_search(pos, end, m, reg); pos = m.suffix().first) {
		cout << "match: " << m.str() << endl;
		cout << " tag: " << m.str(1) << endl;
		cout << " value: " << m.str(2) << endl;
	}
}


void test7()
{
	string data = "<person>\n"
		"<first>Nico</first>\n"
		"<last>Josuttis</last>\n"
		"< / person>\n";

	regex reg("<(.*)>(.*)</(\\1)>");
	auto pos = data.cbegin();
	auto end = data.cend();
	smatch m;
	for (; regex_search(pos, end, m, reg); pos = m.suffix().first) {
		cout << "match: " << m.str() << endl;
		cout << " tag: " << m.str(1) << endl;
		cout << " value: " << m.str(2) << endl;
	}
}

void test8()
{
	std::cout << std::endl << __func__ << "::" << std::endl;
	std::regex reg("<(.*)>(.*)</(\\1)>");
	std::sregex_iterator pos(test_data.cbegin(), test_data.cend(), reg);
	std::sregex_iterator end;
	for (; pos != end; ++pos)
	{
		std::cout << "match: " << pos->str() << std::endl;
		std::cout << "tag: " << pos->str(1) << std::endl;
		std::cout << "value: " << pos->str(2) << std::endl;
		std::cout << "value: " << pos->str(3) << std::endl;
	}

}

void test9()
{
	std::cout << std::endl << __func__ << "::" << std::endl;
	std::regex reg("<(.*)>(.*)</(\\1)>");
	std::sregex_token_iterator pos(test_data.cbegin(), test_data.cend(), reg, { 2 }); // 0: full match, 2: second substring
	std::sregex_token_iterator end;
	for (; pos != end; ++pos) {
		std::cout << "match: " << pos->str() << endl;
	};

	std::cout << std::endl;

	std::string names = "nico, jin, helmut,	\n paul,	\ntim, john paul, rita";
	std::regex sep("[ \t\n]*[,;.][ \t\n]*");
	std::sregex_token_iterator p(names.cbegin(), names.cend(), sep, -1);
	std::sregex_token_iterator e;
	for (; p != e; ++p)
	{
		std::cout << "name: " << *p << std::endl;
	}

}

void test10()
{
	std::regex reg("<(.*)>(.*)</(\\1)>");
	std::cout << std::regex_replace(test_data, reg, "<$1 value=\"$2\"/>") << std::endl;


	std::string res2;
	std::regex_replace(std::back_inserter(res2), test_data.begin(), test_data.end(), reg, R"(<$1 value=$2>)",
		regex_constants::format_no_copy | regex_constants::format_first_only );

	std::cout << res2 << std::endl;
}

void test11()
{
	std::cout << "test11::" << std::endl;
	std::string html = R"(<table align=center border=1>
<caption><b><u>Symbol Pin Report</u></b></caption>
<tr>
<td><b>REFDES</b></td>
<td><b>PIN_NUMBER</b></td>
<td><b>SYM_NAME</b></td>
<td><b>COMP_DEVICE_TYPE</b></td>
<td><b>PAD_STACK_NAME</b></td>
<td><b>PIN_X</b></td>
<td><b>PIN_Y</b></td>
<td><b>NET_NAME</b></td>
</tr>
<tr>
<td nowrap=true>IP</td>
<td nowrap=true>A1</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>-2.410</td>
<td nowrap=true>3.900</td>
<td nowrap=true>DNU</td>
</tr>
<tr>
<td nowrap=true>IP</td>
<td nowrap=true>A3</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>INTERPOSER-PKG-S</td>
<td nowrap=true>-1.410</td>
<td nowrap=true>3.900</td>
<td nowrap=true>DNU</td>
</tr>

</table>)";
	//std::regex pattern("<td[^>]*>([^<]+)+");
	std::regex pattern(R"(<td[^>]*>([^<]+)</td>)");
	std::sregex_iterator begin(html.begin(), html.end(), pattern);
	std::sregex_iterator end;
	for (std::sregex_iterator i = begin; i != end; ++i) {
		std::smatch match = *i;
		std::cout << match.str(0) << '\n';
		std::cout << match.str(1) << '\n';
		std::cout << match.str(2) << '\n';
	}
}

void test12()
{
	std::string line("Hello World, I love you");
	std::istringstream iss(line);
	std::string word;
	while (iss >> word)
		std::cout << word << std::flush << " ";

	std::cout << std::endl;
}

void test13()
{
	std::string line("asdfasdf<br>Dimensions in millimeters with 3 decimal places<br>asdfasf");
	std::regex pattern(R"(Dimensions in (\w+) with (\d+) decimal places<br>)");

	std::smatch m;
	auto found = std::regex_search(line, m, pattern);
	if (found && m.size() == 3)
	{
		std::string unit = m.str(1);
		std::string decimal_count = m.str();

	}
	else
	{
		std::cout << "Not found" << std::endl;
	}
}

namespace test
{
	void TestRegex::Test()
	{
		test1();
		test2();
		test3();
		test4();
		test5();
		test6();
		test7();
		test8();
		test9();
		test10();
		test11();
		test12();
		test13();
		std::string line = R"(   ((6 0) (26 0) (21 0))   )";
		std::regex reg(R"(\((\d+)\s\d\)\s*\((\d+)\s\d\)\s*\((\d+)\s\d\)\s*)");

		smatch m;
		auto found = std::regex_search(line, m, reg);

		if (found)
		{
			std::cout << "found" << std::endl; 
		}
		else
		{
			std::cout << "not found" << std::endl;
		}
	}
}
