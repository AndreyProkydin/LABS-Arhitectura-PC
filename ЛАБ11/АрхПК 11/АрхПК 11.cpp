#include <iostream>
#include <cmath>

#define MAX_SIZE 100
#define M_PI 3.14159265358979323846 // Визначення M_PI

int main() {
    double b[MAX_SIZE]; // Масив для зберігання елементів
    double sum = 0.0;   // Сума елементів
    int N = 0;          // Номер елемента

    // Обчислення масиву
    for (int i = 0; i < MAX_SIZE; i++) {
        b[i] = sin(2 * pow(i + 1, 2) * M_PI / 180.0); // Обчислення значень
        std::cout << "b[" << (i + 1) << "] = " << b[i] << std::endl; // Вивід значень масиву
    }

    // Обчислення суми елементів до перевищення 3
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += b[i];
        if (sum > 3) {
            N = i + 1; // Номер елемента, при якому сума перевищує 3
            break;
        }
    }

    // Виводимо результат
    std::cout << "Значення N, при якому сума елементів перевищує 3: " << N << std::endl;

    return 0;
}
