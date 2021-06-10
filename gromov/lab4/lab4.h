#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
/**
* \brief Класс фигура
*/
class Figure {

protected:    
    double _perimeter = 0;
    double  _area = 0;

    /**
    * \brief геттер поля площадь
    */
    double getArea() const;
    /**
    * \brief геттер поля периметр
    */
    double getPerimetr() const;
    /**
    * \brief сеттер поля площадь
    */
    void setArea(const double a);
    /**
    * \brief сеттер поля периметр
    */
    void setPerimetr(const double p);
public:
    /**
    * \brief Деструктор
    */
    virtual ~Figure() = default;
    /**
    * \brief виртуальный метод получения периметра
    */
    virtual double perimeter() = 0;
    /**
    * \brief виртуальный метод получения площади
    */
    virtual double area() = 0;

    friend std::ostream& operator<<(std::ostream& out, const Figure& f);
};

/**
* \brief Класс эллипс
*/
class Ellipse : public Figure {

private:
    /**
    * \brief поля - радиусы эллипса
    */
    double _r1, _r2;
    /**
    * \brief геттер поля r1
    */
    double getR1() const;
    /**
    * \brief геттер поля r2
    */
    double getR2() const;
    /**
    * \brief сеттер поля r1
    */
    void setR1(const double r1);
    /**
    * \brief сеттер поля r2
    */
    void setR2(const double r2);

public:
    /**
    * \brief Конструктор по умолчанию
    */
    Ellipse() = default;
    /**
    * \brief Конструктор параметризованный
    */
    Ellipse(const double r1, const double r2);   
    /**
    * \brief Деструктор
    */
    ~Ellipse() = default;    
    /**
    * \brief метод нахождения периметра
    */
    double perimeter() override;
    /**
    * \brief метод нахождения площади
    */
    double area() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Ellipse& e);
};

/**
* \brief Класс трапеция
*/
class Trapezoid : public Figure {

private:
    /**
    * \brief поля - 2 основания и высота
    */
    double _base1, _base2, _height;
    /**
    * \brief геттер поля base1
    */
    double getBase1() const;
    /**
    * \brief геттер поля base2
    */
    double getBase2() const;
    /**
    * \brief геттер поля height
    */
    double getHeight() const;
    /**
    * \brief сеттер поля base1
    */
    void setBase1(const double b);
    /**
    * \brief сеттер поля base2
    */
    void setBase2(const double b);
    /**
    * \brief сеттер поля height
    */
    void setHeight(const double h);

public:
    /**
    * \brief Конструктор по умолчанию
    */
    Trapezoid() = default;
    /**
    * \brief Конструктор параметризованный
    */
    Trapezoid(const double b1, const double b2, const double h);
    /**
    * \brief Деструктор
    */
    ~Trapezoid() = default;
    /**
    * \brief метод нахождения периметра равнобедренной трапеции
    */
    double perimeter() override;
    /**
    * \brief метод нахождения площади
    */
    double area() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Trapezoid& t);
};

/**
* \brief Класс квадрат
*/
class Square : public Figure {

private:
    /**
    * \brief поле - сторона квадрата
    */
    double _a;
    /**
    * \brief геттер поля A
    */
    double getA() const;
    
    /**
    * \brief сеттер поля A
    */
    void setA(const double a);

public:
    /**
    * \brief Конструктор по умолчанию
    */
    Square() = default;
    /**
    * \brief Конструктор параметризованный
    */
    Square(const double a);
    /**
    * \brief Деструктор
    */
    ~Square() = default;
    /**
    * \brief метод нахождения периметра
    */
    double perimeter() override;
    /**
    * \brief метод нахождения площади
    */
    double area() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Square& s);
};