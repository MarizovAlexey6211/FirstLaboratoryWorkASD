#include "pch.h"
#include "CppUnitTest.h"
#include<C:\Users\Professional\source\repos\FirstLaboratoryWork\Source.cpp>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ConstructorTest) {
			Set<int> set;
			Assert::IsTrue(set.getSize() == 0);
			Assert::IsTrue(!set.begin());
		}
	};
}
