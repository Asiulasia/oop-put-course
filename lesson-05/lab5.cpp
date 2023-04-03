#include <iostream>
using namespace std;

class Bird {
	virtual void fly() = 0;
	virtual void sing() = 0;
	virtual void swim() = 0;
};


class Goose : public Bird{
private:
	string name;
public:
	Goose(string name) {
		this->name = name;
	}
	void fly() override { cout << this->name << " is flying"; };
	void sing() override { cout << this->name << " is singing"; };
	void swim() override { cout << this->name << " is swimming"; };
};

class Penguin : public Bird {
private:
	string name;
public:
	Penguin(string name) {
		this->name = name;
	}
	void fly() override { cout << this->name << " is flying"; };
	void swim() override { cout << this->name << " is swimming"; };
	void sing() override { cout << this->name << " is not singing sorry"; };
};

int main()
{
	Goose goose("goose");
	goose.fly();
	cout << " \n";
	goose.swim();
	cout << " \n";
	Penguin penguin("pinguu");
	penguin.sing();
	cout << " \n";
	penguin.swim();
}
