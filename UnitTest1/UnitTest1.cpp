#include "pch.h"
#include "CppUnitTest.h"
#include "../Project8.2/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			string signs = "!\"\'#%()[]{}.,-:;?";
			bool b = IsSpaceBeforeSybols("Hello ! , I 'm here !", signs);
			Assert::AreEqual(b, true);
		}
	};
}