/*
Написать программу, в которой описана иерархия классов:
геометрические фигуры (эллипс, квадрат, трапеция). 
Реализовать методы вычисления площади и периметра фигуры. 
Продемонстрировать работу всех методов классов, 
предоставив пользователю выбор типа фигуры для демонстрации
*/

#include <iostream>
#include "lab4.h"
using namespace std;

/*
* \brief функция вывода меню
*/
void menu()
{
    string list[3] = { "Ellipse", "Trapezoid", "Square" };
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter " << i << " for test " << list[i] << endl;
    }
    cout << "Enter -1 for exit" << endl;
}

int main() {
    while (true)
    {
        Ellipse e;
        Trapezoid t;
        Square s;
        int i;
        menu();
        cin >> i;
        switch (i)
        {
        case 0:
        {
            cin >> e;
            e.area();
            e.perimeter();
            cout << e << endl;
            break;
        }
        case 1:
        {
            cin >> t;
            t.area();
            t.perimeter();
            cout << t << endl;
            break;
        }
        case 2:
        {
            cin >> s;
            s.area();
            s.perimeter();
            cout << s << endl;
            break;
        }
        case -1:
        {
            return 0;
        }
        }
    }
}