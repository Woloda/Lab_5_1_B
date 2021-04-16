#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_5.1(B)/FuzzyNumber.h"
#include "../Lab_5.1(B)/FuzzyNumber.cpp"
#include "../Lab_5.1(B)/Multi_and_Addit.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51B
{
	TEST_CLASS(UnitTestLab51B)
	{
	public:
		
		TEST_METHOD(Test_Addit)
		{
			FuzzyNumber A(2.0, 3.0, 4.0),
				B(2.0, 3.0, 4.0),
				C(0.0, 0.0, 0.0);

			C = A + B;
			Assert::AreEqual(C.get_x(), -2.0);
		}
	};
}