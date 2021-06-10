#pragma once
#include <sstream>
/**
 * \brief Класс Triangle для работы с треугольниками
 */
class Triangle
{
private:
	/**
	 * \brief поля - стороны треугольника
	 */
	double _a;
	double _b;
	double _c;

	static constexpr double AREA_CONST = 2;
	/**
	 * \brief метод проверки на правильность
	 */
	bool checkEquilateral() const;
	/**
	 * \brief метод проверки на равнобедренность
	 */
	bool checkIsosceles() const;
	/**
	 * \brief метод проверки на прямоугольность
	 */
	bool checkRectangular() const;
public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Triangle() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Triangle(const double a, const double b, const double c);

	/**
	 * \brief Деструктор
	 */
	~Triangle() = default;

	/**
	 * \brief геттер стороны а
	 */
	double getA() const;
	/**
	 * \brief геттер стороны в
	 */
	double getB() const;
	/**
	 * \brief геттер стороны с
	 */
	double getC() const;

	/**
	 * \brief сеттер стороны а
	 */
	void setA(const double a);
	/**
	 * \brief сеттер стороны в
	 */
	void setB(const double b);
	/**
	 * \brief сеттер стороны с
	 */
	void setC(const double c);
	/**
	 * \brief метод вычисления площади
	 */
	double getArea() const;

	/**
	 * \brief метод вычисления периметра
	 */
	double getPerimetr() const;
	/**
	 * \brief метод вычисления высоты к стороне а
	 */
	double getHeightA() const;
	/**
	 * \brief метод вычисления высоты к стороне в
	 */
	double getHeightB() const;
	/**
	 * \brief метод вычисления высоты к стороне с
	 */
	double getHeightC() const;
	/**
	 * \brief метод получения типов треугольника
	 */
	std::string getType() const;
	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Triangle& t);
	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Triangle& t);
};
