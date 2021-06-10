/* 
*4.  Функция переводит часы и минуты в секунды. 
* Во всех заданиях реализуемые функции должны генерировать подходящие исключения.
* Обработку исключений нужно выполнять главной функцией, которая должна демонстрировать обработку всех перехватываемых исключений.
* Функции, реализуемые в заданиях, обязаны выполнять проверку передаваемых параметров и
* генерировать исключения в случае ошибочных.
* Все функции реализуются в четырех вариантах:
*	- без спецификации исключений;
*	- со спецификацией throw();
*	- с конкретной спецификацией с подходящим стандартным исключением;
*	- спецификация с собственным реализованным исключением.
*	(как пустой класс, как независимый класс с полями-параметрами функции, как наследник от стандартного исключения с полями)
*/

#include <iostream>
using namespace std;

/*
* \brief структура для хранения минут и секунд
*/
struct Time {
	unsigned int minutes;
	unsigned int seconds;
};
enum TimeConst {
	SECONDS_IN_HOUR = 3600,
	SECONDS_IN_MINUTE = 60
};
Time convertTime(const double hours) {
	Time tmp;
	int seconds = hours * SECONDS_IN_HOUR;
	tmp.minutes = seconds / SECONDS_IN_MINUTE;
	tmp.seconds = seconds % SECONDS_IN_MINUTE;
	return tmp;
}
/*
* \brief без спецификации исключений
*/
Time TimeConvertor_1(const double hours) {
	if (hours <= 0) {
		throw 'e';
	}
	return convertTime(hours);
}

/*
* \brief со спецификацией throw()
*/
Time TimeConvertor_2(const double hours) throw() {
	if (hours <= 0) throw 'e';
	return convertTime(hours);
}

/*
* \brief с конкретной спецификацией с подходящим стандартным исключением
*/
Time TimeConvertor_3(const double hours) throw(invalid_argument) {
	if (hours <= 0) throw invalid_argument("time value <= 0");
	return convertTime(hours);
}

/*
* \brief независимый класс с полями-параметрами функции
*/
class my_exception
{
public:
	string _e;
	my_exception(string e) :_e(e) {}
	string what(){
		return _e;
	}
};
/*
* \brief Спецификация с собственным реализованным исключением
*/
Time TimeConvertor_4_1(const  double hours) throw(my_exception) {
	if (hours <= 0) throw my_exception("time value <= 0");
	return convertTime(hours);
}

/*
* \brief пустой класс
*/
class new_exception {};
/*
* \brief Спецификация с собственным реализованным исключением
*/
Time TimeConvertor_4_2(const double hours) throw(new_exception) {
	if (hours <= 0) throw new_exception();
	return convertTime(hours);
}

/*
* \brief Класс наследник от стандартного исключения с полем
*/
class InvalidHoursValue : public exception
{
public:
	const char* what() const throw() {
		return "time value <= 0";
	}
};
/*
* \brief Спецификация с собственным реализованным исключением
*/
Time TimeConvertor_4_3(const double hours) {
	if (hours <= 0) throw InvalidHoursValue();
	return convertTime(hours);
}

int main()
{
	double hours;
	cout << "hours to convert: ";
	cin >> hours;

	cout << "Test err 1: ";
	try {
		Time convertedTime;
		convertedTime = TimeConvertor_1(hours);
		cout << convertedTime.minutes << ":" << convertedTime.seconds << endl;
	}
	catch (char) {
		cout << "err 1!\n";
	}


	cout << "Test err 2: ";
	try {
		Time convertedTime;
		convertedTime = TimeConvertor_2(hours);
		cout << convertedTime.minutes << ":" << convertedTime.seconds << endl;
	}
	catch (char) {
		cout << "err 2!\n";
	}


	cout << "Test err 3: ";
	try {
		Time convertedTime;
		convertedTime = TimeConvertor_3(hours);
		cout << convertedTime.minutes << ":" << convertedTime.seconds << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what()<<endl;
	}


	cout << "Test err 4.1: ";
	try {
		Time convertedTime;
		convertedTime = TimeConvertor_4_1(hours);
		cout << convertedTime.minutes << ":" << convertedTime.seconds << endl;
	}
	catch (my_exception& e) {
		cout << e.what()<<endl;
	}


	cout << "Test err 4.2: ";
	try {
		Time convertedTime;
		convertedTime = TimeConvertor_4_2(hours);
		cout << convertedTime.minutes << ":" << convertedTime.seconds << endl;
	}
	catch (new_exception& e) {
		cout << "Error 4.2\n";
	}


	cout << "Test err 4.3: ";
	try {
		Time convertedTime;
		convertedTime = TimeConvertor_4_3(hours);
		cout << convertedTime.minutes << ":" << convertedTime.seconds << endl;
	}
	catch (InvalidHoursValue& e) {
		cout << e.what();
	}
}