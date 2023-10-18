#pragma once

namespace test
{
	class TestContainer
	{
	public:
		void Test();

	private:
		void TestUnorderMap();
		void TestVector();

		void TestCompressibleMatrixWithVectorInVector();
		void TestCompressibleMatrixWithLinearVector();

		void TestUnordermapHash();

		void TestUnorderedMapSort();
	};

}

