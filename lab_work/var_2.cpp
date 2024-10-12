#include <random> 
#include <iostream> 
class Base {
public:
    Base() : max(6), dstr(1, max) {} 
    template<typename... Args>
    Base(unsigned int max, Args... args) : max(max), dstr(1, max) {
        for (auto arg : { args... }) {
            rengs.push_back(std::default_random_engine(arg));
        }
    }

    virtual unsigned roll() {
        unsigned int summ_of_rolls = 0;
        for (auto& reng : rengs) {
            summ_of_rolls += dstr(reng);
        }
        return summ_of_rolls;
    }
    unsigned int max;
    std::vector<std::default_random_engine> rengs;
    virtual ~Base() {}
private:
    std::uniform_int_distribution<unsigned> dstr;

};
 
class Dice : public Base {
public:
    template<typename... Args>
    Dice(Args... args) : Base(args...) {}
    
};

class ThreeDicePool : public Base
{
public:
    template<typename... Args>
    ThreeDicePool(Args... args) : Base(args...) {}
};

class PenaltyDice :public virtual Base {
public:
    template<typename... Args>
    PenaltyDice(Args... args) : Base(args...) {}
    unsigned int roll() override{
        return std::min(Base::roll(), Base::roll());
    }
};

class BonusDice :public virtual Base {
public:
    template<typename... Args>
    BonusDice(Args... args) : Base(args...) {}
    unsigned int roll() override  {
        return std::max(Base::roll(), Base::roll());
    }
};


double expected_value(Base& d, unsigned number_of_rolls = 1000000)
{
    auto accum = 0llu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt)
        accum += d.roll();
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

double value_probability(unsigned value, Base& d, unsigned
    number_of_rolls = 100000) {
    auto accum = 0llu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt) {
        if (value == d.roll())
            accum += 1;
    }
    return
        static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

void value_for_histogram(Base& d, unsigned number_of_rolls = 100000) {
    unsigned int max = d.max, i = 1;
    while (i <= d.max*d.rengs.size()) {
        std::cout << value_probability(i, d) << ", ";
        i += 1;
    }
    std::cout << "\n" << "\n";
}


int main() {
    Dice dice(100, 1);
    ThreeDicePool three_dice(6, 17, 13, 19);
    PenaltyDice penalty_dice_1(100, 1);
    BonusDice bonus_dice_1(100, 1);
    PenaltyDice penalty_dice_3(6, 17, 13, 19);
    BonusDice bonus_dice_3(6, 17, 13, 19);
    std::cout << "Expected value for one roll: " << expected_value(dice) << "\n";
    std::cout << "Expected value for three rolls: " << expected_value(three_dice) << "\n";
    std::cout << "The rools of Dice: ";
    value_for_histogram(dice);
    std::cout << "The rools of PenaltyDice: ";
    value_for_histogram(penalty_dice_1);
    std::cout << "The rools of BonusDice: ";
    value_for_histogram(bonus_dice_1);
    std::cout << "The rools of ThreeDicePool: ";
    value_for_histogram(three_dice);
    std::cout << "The rools of PenaltyDice_3: ";
    value_for_histogram(penalty_dice_3);
    std::cout << "The rools of BonusDice_3: ";
    value_for_histogram(bonus_dice_3);

    std::cout << dice.roll()<<" "<< dice.roll();

    return 0;
}