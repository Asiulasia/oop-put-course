#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Product {
	string name;
	static int IDProd;
protected:
	float price;
public:
	Product(string n, float p) {
		name = n;
		price = p;
		IDProd++;
	}

	float Price() {
		return price;
	}
};

int Product::IDProd = 0;

class Customer {
	string name;
	string email;
	static int IDCust;
public:
	Customer(string n, string e) {
		name = n;
		email = e;
		IDCust++;
	}
};
int Customer::IDCust = 0;

class Order {
	Customer* c1;
	vector <Product*> prod;
	static int IDOrder;
	static float TotalPrice;
public:
	Order(Customer* c) {
		c1 = c;
		IDOrder++;
	}

	void AddProduct(Product* p) {
		prod.push_back(p);
	}

	void TotalCost() {
		int ProductCount = prod.size();
		for (int i = 0; i < ProductCount; i++) {
			TotalPrice += prod[i]->Price();
		}

		cout << TotalPrice;
	}
};

int Order::IDOrder = 0;
float Order::TotalPrice = 0;

int main() {
	Product p1("egg", 3);
	Product p2("carrot", 5.5);
	Customer c1("Michal", "michal@gmail");
	Order o1(&c1);
	o1.AddProduct(&p1);
	o1.AddProduct(&p2);
	o1.TotalCost();
	return 0;
}
