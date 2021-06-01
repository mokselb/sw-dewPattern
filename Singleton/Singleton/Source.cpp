#include <iostream>

using namespace std;

class Singleton
{
private:
	static Singleton* _object;
	float length;
	string name;
	int age;
protected:
	Singleton()
	{
		length = 0;
		name = string();
		age = 0;
	}
public:
	static Singleton* Object()
	{
		if (_object == NULL)
		{
			_object = new Singleton;
		}
		return _object;
	}
	float GetLength() { return length; }
	string GetName() { return name; }
	int GetAge() { return age; }
	void SetLength(float _length) { length = _length; }
	void SetName(string _name) { name = _name; }
	void SetAge(int _age) { age = _age; }
	~Singleton() { delete _object; }
};
Singleton* Singleton::_object = NULL;
int main()
{
	Singleton* Morphling = Singleton::Object();
	Morphling->SetName("Morphling");
	Morphling->SetAge(300);
	Morphling->SetLength(1.6);
	cout << "Name1 : " << Morphling->GetName() << endl;
	Singleton* Pudge = Singleton::Object();
	cout << "Name2.1 : " << Pudge->GetName() << endl;
	Pudge->SetName("Pudge");
	cout << "Neme2.2 : " << Pudge->GetName() << endl;
	return 0;
}