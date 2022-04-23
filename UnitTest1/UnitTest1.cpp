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

		TEST_METHOD(FindKeyMethodTest) {
			Set<int> set;
			for (int i = 0; i < 10; i++) {
				set.add(i);
			}
			Assert::IsTrue(set.contains(5));
			Assert::IsTrue(set.contains(1));
			Assert::IsTrue(set.contains(9));
			Assert::IsTrue(!set.contains(15));
			Assert::IsTrue(!set.contains(112));
			Assert::IsTrue(!set.contains(150));
		}
	};
}
