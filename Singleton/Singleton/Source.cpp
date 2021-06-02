#include <iostream>

using namespace std;

class Singleton
{
private:
	static Singleton* _morph;
	int strength;
	int agility;
	int intelligence;
protected:
	Singleton()
	{
		strength = 22;
		agility = 0;
		intelligence = 15;
	}
public:
	static Singleton* Morph()
	{
		if (_morph == NULL)
		{
			_morph = new Singleton;
		}
		return _morph;
	}
	int GetStrength() { return strength; }
	int GetAgility() { return agility; }
	int GetIntelligence() { return intelligence; }
	void SetStrength(int _strength) { strength = _strength; }
	void SetAgility(int _agility) { agility = _agility; }
	void SetIntelligence(int _intelligence) { intelligence = _intelligence; }
	~Singleton() { delete _morph; }
};
Singleton* Singleton::_morph = NULL;
int main()
{
	Singleton* Morphling = Singleton::Morph();//Some DotA mechanics are allowed for the pattern implementation
	cout << "Morphling`s Strength : " << Morphling->GetStrength() << endl;
	Morphling->SetAgility(24);
	cout << "Morphling`s Agility : " << Morphling->GetAgility() << endl;
	cout << "Morphling`s Intelligence : " << Morphling->GetIntelligence() << endl;
	cout << "Morphling`s pointer : " << Morphling << endl;
	Singleton* Pudge = Singleton::Morph();//Morphling changes its shape to the image and likeness of the selected enemy
	Pudge->SetAgility(14);
	Pudge->SetStrength(25);
	Pudge->SetIntelligence(16);
	cout << "Pudge`s pointer : " << Pudge << endl;//That`s steel Morphling by "ID", but looks and has properties seems to Pudge (or any another character)
	//I'm just trying to implement the mechanics of one ultimate
	cout << "Pudge`s Strength : " << Pudge->GetStrength() << endl;
	cout << "Pudge`s Agility : " << Pudge->GetAgility() << endl;
	cout << "Pudge`s Intelligence : " << Pudge->GetIntelligence() << endl;
	return 0;
}