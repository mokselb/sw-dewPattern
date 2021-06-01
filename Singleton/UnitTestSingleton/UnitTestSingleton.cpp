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
			Singleton* Morphling = Singleton::Object();
			Morphling->SetName("Morphling");
			Morphling->SetAge(300);
			Morphling->SetLength(1.6);
			string name = "Morphling";
			float Length = 1.6;
			Assert::AreEqual(Morphling->GetAge(), 300);
			Assert::AreEqual(Morphling->GetName(), name);
			Assert::AreEqual(Morphling->GetLength(), Length);
		}
		TEST_METHOD(TestMethod2)
		{
			Singleton* Morphling = Singleton::Object();
			Morphling->SetName("Morphling");
			string name = "Morphling";
			Assert::AreEqual(Morphling->GetName(), name);
			Singleton* Pudge = Singleton::Object();
			Assert::AreEqual(Pudge->GetName(), name);
			string name1 = "Pudge";
			Pudge->SetName("Pudge");
			Assert::AreEqual(Pudge->GetName(), name1);
		}
		TEST_METHOD(TestMethod3)
		{
			Singleton* Morphling = Singleton::Object();
			Morphling->SetName("Morphling");
			Morphling->SetAge(300);
			Morphling->SetLength(1.6);
			string name = "Morphling";
			float Length = 1.6;
			Singleton* Pudge = Singleton::Object();
			Assert::AreEqual(Pudge->GetAge(), 300);
			Assert::AreEqual(Pudge->GetName(), name);
			Assert::AreEqual(Pudge->GetLength(), Length);
			Pudge->SetName("Pudge");
			Pudge->SetAge(159);
			Pudge->SetLength(1.9);
			string name1 = "Pudge";
			float Length1 = 1.9;
			Assert::AreEqual(Pudge->GetAge(), 159);
			Assert::AreEqual(Pudge->GetName(), name1);
			Assert::AreEqual(Pudge->GetLength(), Length1);
		}
	};
}
