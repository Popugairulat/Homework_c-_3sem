#include <random>
#include <iostream>

class Dice {
public:
	Dice(unsigned max, unsigned seed) :
		max(max), dstr(1, max), reng(seed) { }
		unsigned roll() {
		return dstr(reng);	
	    }
	
private:
	unsigned max;
	std::uniform_int_distribution<unsigned> dstr;
	std::default_random_engine reng;
};

template <typename Creature>
class PenaltyDice {
public:
	
	PenaltyDice(Creature& d)  :dice(d){}
	unsigned roll() {
		return std::min(dice.roll, dice.roll);
	}
private:
	Creature& dice;
};

template <typename Creature>
class BonusDice {
public:

	BonusDice(Creature& d) :dice(d) {}
	unsigned roll() {
		return std::max(dice.roll, dice.roll);
	}
private:
	Creature& dice;
};

class ThreeDicePool {
public:
	ThreeDicePool(unsigned max, unsigned seed_1, unsigned seed_2, unsigned seed_3)
		: dice_1(max, seed_1), dice_2(max, seed_2), dice_3(max, seed_3) {}

	unsigned roll() {
		return dice_1.roll() + dice_2.roll() + dice_3.roll();
	}

private:
	Dice dice_1, dice_2, dice_3;
	unsigned max;
	std::uniform_int_distribution<unsigned> dstr;
	std::default_random_engine reng;
};

template <typename Creature> // параметрический полиморфизм
double expected_value(Creature& d, unsigned number_of_rolls = 1) {
	auto accum = 0llu;
	for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt)
		accum += d.roll();
	return
		static_cast<double>(accum) / static_cast<double>(number_of_rolls);
	
}

template <typename Creature>
double value_probability(unsigned value, Creature& d, unsigned
	number_of_rolls = 1) {
	auto accum = 0llu;
	for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt) {
		if (value== d.roll())
			accum += 1;
	}
	return
		static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

int main() {
	return 0;
}