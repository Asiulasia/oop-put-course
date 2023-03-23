#include <iostream>
#include <string>
using namespace std;

// class Ball {
//  private:
//   std::string color;
//  public:
//   Ball Paint(std::string newColor) {
//     this->color = std::move(newColor);
//     return *this;
//   }
//   std::string CurrentColor() {
//     return this->color;
//   };
// };

class Car {
	private:
		std::string color;
	public:
		int speed(int maxSpeed);
		Car Paint(std::string newColor) {
		this->color = std::move(newColor);
		return *this;
	   }
		std::string CurrentColor() {
			return this->color;
		};
};

int Car::speed(int maxSpeed) {
	return maxSpeed;
}

class User
{
private:
	std::string name;
public:
	void NameCar(std::string carsNewName) {
		this->name = std::move(carsNewName);
	}
};

int main() {
	Car car; 
	User newuser;
	Car NewCar = car.Paint("Red");
	newuser.NameCar("Audi");

	std::cout << car.CurrentColor();
	std::cout << newuser.NameCar();
	return 0;
}


// class Dog {
//  private:
//   std::string name;
//   std::optional<std::vector<Ball>> dogsBalls;
//  public:
//   void NameDog(std::string dogsNewName) {
//     this->name = std::move(dogsNewName);
//   }
//   void GiveBall(const Ball &ball) {
	// this->dogsBalls->push_back(ball);
//   }
//   Ball TakeBall() {
//     Ball takenFromDog = this->dogsBalls->back();
//     this->dogsBalls->pop_back();
//     return takenFromDog;
//   }
// };

// int main() {
//   Dog goodBoy;
//   goodBoy.NameDog("Piernik");
//   Ball ball;
//   Ball newBall = ball.Paint("Pink");
//   goodBoy.GiveBall(newBall);
//   Ball wetBall = goodBoy.TakeBall();
//   std::cout << wetBall.CurrentColor();
	// std::cout << newBall;
//   return 0;
// }

