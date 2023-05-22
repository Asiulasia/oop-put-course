#include <iostream>
#include <vector>
#include <string>
using namespace std;


class IntegerSequence {
protected:
	vector<int> sequence;

public:
	IntegerSequence(vector<int> seq) {
		sequence = seq;
	}

	virtual vector<int> Numbers();

	void VectorSequence(vector<int> seq) {
		vector<int> Numbers() const override {
			return seq;
		}
	}
};

class PositiveSequence : public IntegerSequence {
private:
	IntegerSequence seq;

public:
	std::vector<int> Numbers() const override {
		for (int i = 0; i < seq.size(); i++) {
			if (seq[i] < 0) {
				seq.erase(seq.begin() + i);
			}
		}
		return seq;
	}
};


class EvenSequence : public IntegerSequence {
private:
	IntegerSequence seq;

public:
	std::vector<int> Numbers() const override {
		for (int i = 0; i < seq.size(); i++) {
			if (seq[i] != 0) {
				seq.erase(seq.begin() + i);
			}
		}
		return seq;
	}
};

class SortedSequence : public IntegerSequence {
private:
	IntegerSequence seq;

public:

	std::vector<int> Numbers() const override {
		std::vector<int> seq = this->Numbers();
		std::sort(seq.begin(), seq.end());
		return seq;
	}
};

int main() {
	vector<int> 
}
