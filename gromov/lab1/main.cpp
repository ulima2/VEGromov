/*
Создать класс Triangle для представления треугольника.
Поля данных должны включать стороны.
Требуется реализовать операции: получения и изменения полей данных,
вычисления площади, вычисление периметра, вычисление высот,
а также определения вида треугольника (равносторонний, равнобедренный или прямоугольный).
*/


#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
    auto  t = Triangle();
    //заполнение полей объекта
    cin >> t;
    cout << t << endl;
    //изменения сторон треугольника
    int a, b, c;
    cin >> a >> b >> c;
    t.setA(a);
    t.setB(b);
    t.setC(c);
    cout << t << endl;
    return 0;
}
