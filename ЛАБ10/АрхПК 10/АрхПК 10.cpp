#include <iostream>

int main()
{
    float X = 5.0f;  // Значення x
    float Y;         // Змінна для збереження результату
    float CONST1 = 1024.0f; // Константа 1024
    float CONST2 = 3.2f;    // Константа 3.2
    float CONST3 = 25.0f;   // Константа 25

    __asm {
        finit                   // Очищення регістрів співпроцесора
        fld X                   // Завантажуємо значення X
        fmul X                  // Обчислюємо x^2
        fmul CONST2             // Множимо на 3.2 (CONST2), отримаємо 3.2 * x^2
        fsub CONST3             // Віднімаємо 25 (CONST3), отримаємо 3.2 * x^2 - 25
        fstp Y                  // Зберігаємо (3.2x^2 - 25) у Y

        fld CONST1              // Завантажуємо 1024 (CONST1)
        fld Y                   // Завантажуємо значення Y (3.2x^2 - 25)
        fdiv                    // Ділимо 1024 на Y
        fstp Y                  // Зберігаємо результат у Y
    }

    // Виведення результату
    std::cout << "y = " << Y << std::endl;

    return 0;
}
