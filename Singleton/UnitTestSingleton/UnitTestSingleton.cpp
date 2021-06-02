#include "pch.h"
#include "CppUnitTest.h"
#include "../Singleton/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSingleton
{
	TEST_CLASS(UnitTestSingleton)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Singleton* Morphling = Singleton::Morph();
			Morphling->SetAgility(24);
			Assert::AreEqual(Morphling->GetStrength(), 22);
			Assert::AreEqual(Morphling->GetAgility(), 24);
			Assert::AreEqual(Morphling->GetIntelligence(), 15);
		}
		TEST_METHOD(TestMethod2)
		{
			Singleton* Morphling = Singleton::Morph();
			Morphling->SetAgility(24);
			Singleton* Pudge = Singleton::Morph();
			Assert::AreEqual(Pudge->GetAgility(), 24);//checking if the "new" object stores the properties of the old one
			Pudge->SetAgility(14);
			Pudge->SetStrength(25);
			Pudge->SetIntelligence(16);
			Assert::AreEqual(Pudge->GetStrength(), 25);
			Assert::AreEqual(Pudge->GetAgility(), 14);
		    Assert::AreEqual(Pudge->GetIntelligence(), 16);
			Assert::IsTrue(Pudge == Morphling);//checking for coincidence of pointers
		}
	};
}
