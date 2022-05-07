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
		TEST_METHOD(InsertTest) {
			Set<int> set;
			Assert::IsTrue(set.getSize() == 0);
			Assert::IsTrue(!set.begin());
			set.add(2);
			auto tmp = set.begin();
			Assert::IsTrue(set.getSize() == 1);
			Assert::IsTrue(set.begin()->data == 2);
			set.add(1);
			Assert::IsTrue(set.getSize() == 2);
			set.add(3);
			Assert::IsTrue(set.getSize() == 3);
			Assert::IsTrue(tmp->left->data == 1);
			Assert::IsTrue(tmp->right->data == 3);
			set.add(3);
			Assert::IsTrue(set.getSize() == 3);
		}

		TEST_METHOD(EraseTest) {
			Set<int> set;
			set.add(2);
			auto tmp = set.begin();
			set.add(1);
			set.add(3);
			Assert::IsTrue(set.getSize() == 3);
			set.remove(3);
			Assert::IsTrue(set.getSize() == 2);
			Assert::IsTrue(tmp->right == nullptr);
			Assert::IsTrue(tmp->left != nullptr);
		}
		TEST_METHOD(PrintTest) {
			Set<int> set;
			set.add(2);
			set.add(1);
			set.add(3);
			ostringstream os1, os2;
			set.print(os1);
			string result = os1.str();
			Assert::IsTrue(result == "{ 1 2 3 }\n");
			set.remove(2);
			set.print(os2);
			result = os2.str();
			Assert::IsTrue(result == "{ 1 3 }\n");
		}
	};
}
