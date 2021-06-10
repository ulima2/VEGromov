#pragma once
#include <sstream>

/**
* \brief Класс Pair для работы с тройками чисел
*/
class Pair
{
protected:
	double a;
	double b;	

public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Pair() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	explicit Pair(const double a, const double b);

	/**
	 * \brief Деструктор
	 */
	virtual ~Pair() = default;

	/**
	 * \brief геттер значения поля А
	 */
	double getA() const;
	/**
	 * \brief геттер значения поля B
	 */
	double getB() const;

	/**
	 * \brief Сеттер поля А
	 */
	void setA(double a);
	/**
	 * \brief Сеттер поля В
	 */
	void setB(double b);

	/**
	 * \brief Метод получения произведения
	 */
	double mul() const;

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Pair& p);
	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Pair& p);
	

};

/**
* \brief Класс Rectangle для работы с прямоугольниками
*/
class Rectangle: public Pair
{
public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Rectangle() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Rectangle(const double a, const double b);

	/**
	 * \brief Деструктор
	 */
	~Rectangle() = default;

	/**
	 * \brief геттер значения стороны А
	 */
	double getSideA() const;
	/**
	 * \brief геттер значения стороны В
	 */
	double getSideB() const;

	/**
	 * \brief Сеттер стороны А
	 */
	void setSideA(double a);
	/**
	 * \brief Сеттер стороны В
	 */
	void setSideB(double b);

	/**
	 * \brief метод получения площади
	 */
	double area() const;
	/**
	 * \brief метод получения периметра
	 */
	double perimetr() const;

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Rectangle& r);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Rectangle& r);
};