#include <iostream>
#include <cassert>
#include <string>

std::string bmi(double w, double h) {
    const auto result = w / (h * h);
    return result <= 18.5 ? "Underweight" :
            result <= 25. ? "Normal" : 
            result <= 30. ? "Overweight" :
            "Obese";
}

int main() {
    assert(bmi(50, 1.80) == ("Underweight"));
    assert(bmi(80, 1.80) == ("Normal"));
    assert(bmi(90, 1.80) == ("Overweight"));
    assert(bmi(100, 1.80) == ("Obese"));
    std::cout << "All tests passed.\n";

    return 0;
}

// if bmi <= 18.5 return "Underweight"
// if bmi <= 25.0 return "Normal"
// if bmi <= 30.0 return "Overweight"
// if bmi > 30 return "Obese"