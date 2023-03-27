#include <iostream>
#include <string>
using namespace std;

class Human {
private:
	double height;
	string hair;
public:
	Human(double h, string hair) {
		this->height = h;
		this->hair = hair;
	}
	Human(int h, string hair):Human(static_cast<double>(h), hair) {};
	Human(float h, string hair) : Human(static_cast<double>(h), hair) {};
	void info() {
		cout << height << " cm\n";
		cout << hair << " color\n";
	}
};


int main()
{
	Human doubleHeight(155.0, "blonde");
	doubleHeight.info();
	return 0;
}


