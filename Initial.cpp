#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <stdexcept>

class Calculator {
private:
    std::unordered_map<std::string, std::function<double(double, double)>> operations;

public:
    Calculator() {
        // Initialize supported operations
        operations["+"] = [](double a, double b) { return a + b; };
        operations["-"] = [](double a, double b) { return a - b; };
        operations["*"] = [](double a, double b) { return a * b; };
        operations["/"] = [](double a, double b) -> double {
            if (b == 0) {
                throw std::runtime_error("Error: Division by zero is not allowed!");
            }
            return a / b;
        };
    }

    double calculate(double num1, const std::string& operator, double num2) {
        auto it = operations.find(operator);
        if (it == operations.end()) {
            throw std::invalid_argument("Invalid operator! Please use: +, -, *, /");
        }
        return it->second(num1, num2);
    }
};

void getUserInput() {
    Calculator calculator;
    double num1, num2;
    std::string operator;

    std::cout << "Simple Calculator in C++" << std::endl;

    try {
        std::cout << "Enter the first number: ";
        std::cin >> num1;
        if (std::cin.fail()) {
            throw std::invalid_argument("Please enter a valid number!");
        }

        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> operator;

        std::cout << "Enter the second number: ";
        std::cin >> num2;
        if (std::cin.fail()) {
            throw std::invalid_argument("Please enter a valid number!");
        }

        double result = calculator.calculate(num1, operator, num2);
        std::cout << "Result: " << num1 << " " << operator << " " << num2 << " = " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    getUserInput();
    return 0;
}
