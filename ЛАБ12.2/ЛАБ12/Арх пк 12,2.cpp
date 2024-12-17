#include <iostream>
#include <iomanip>  // Для форматованого виведення

// Функція обчислення y = 4 * (x^2 + 1) з використанням асемблера
double calculate_y(double x) {
    double result;
    double four = 4.0; // Значення 4 для множення

    __asm {
        fld qword ptr[x];       // Завантажити x у стек (ST(0) = x)
        fmul st(0), st(0);      // ST(0) = x^2
        fld1;                   // Завантажити 1 у стек (ST(0) = 1)
        fadd;                   // ST(0) = x^2 + 1
        fld qword ptr[four];    // Завантажити 4 у стек (ST(0) = 4)
        fmul;                   // ST(0) = 4 * (x^2 + 1)
        fstp qword ptr[result]; // Зберегти результат у result і звільнити стек
    }

    return result;
}

int main() {
    double x = 0.2;     // Початкове значення x
    double step = 0.4;  // Крок зміни x

    std::cout << std::fixed << std::setprecision(4);  // Формат виведення
    std::cout << "x\t\ty\n";
    std::cout << "-----------------\n";

    // Цикл для обчислення 5 значень
    for (int i = 0; i < 5; ++i) {
        double y = calculate_y(x);
        std::cout << x << "\t\t" << y << "\n";
        x += step;  // Збільшення x на крок
    }

    return 0;
}
