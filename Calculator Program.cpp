// File: calculator.cpp (28 lines)
#include <iostream>
#include <cmath>

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) { 
        if (b != 0) return a / b;
        std::cout << "Error: Division by zero!\n";
        return 0;
    }
    double power(double base, double exp) { return pow(base, exp); }
    double squareRoot(double num) { 
        if (num >= 0) return sqrt(num);
        std::cout << "Error: Cannot calculate square root of negative number!\n";
        return 0;
    }
};

int main() {
    Calculator calc;
    double num1 = 10.5, num2 = 2.5;
    
    std::cout << "Addition: " << calc.add(num1, num2) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(num1, num2) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(num1, num2) << std::endl;
    std::cout << "Division: " << calc.divide(num1, num2) << std::endl;
    std::cout << "Power: " << calc.power(num1, 2) << std::endl;
    std::cout << "Square Root: " << calc.squareRoot(num1) << std::endl;
    
    return 0;
}
