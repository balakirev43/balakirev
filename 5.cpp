#include <iostream>

using namespace std;

// Базовый класс

template <class DB1, class DB2>
class RGD
{
protected:
	DB1 spead, god, width;
	char* poezd;
public:
	void vvod();
	void vivod();
	RGD();
	RGD(DB2 n_spead, DB1 n_god, DB1 n_width, char* n_poezd);
	RGD(const RGD<DB1, DB2>& temp);
	~RGD<DB1, DB2>();
	RGD<DB1, DB2> operator = (const RGD<DB1, DB2>& rgd);
	bool operator == (const RGD<DB1, DB2>& rgd);
};

template <class DB1, class DB2>
void RGD<DB1, DB2>::vvod()
{
	cout << "Введите название: ";
	cin >> poezd;
	cout << "Введите скорость: ";
	cin >> spead;
	cout << "Введите год выпуска: ";
	cin >> god;
	cout << "Введите ширину: ";
	cin >> width;
}

template <class DB1, class DB2>

void RGD<DB1, DB2>::vivod()
{
	cout << poezd << endl;
	cout << "Скорость:" << spead << endl;
	cout << "Год:" << god << endl;
	cout << "Ширина:" << width << endl;
	cout << endl;
}

template <class DB1, class DB2>
RGD<DB1, DB2>::RGD()
{
	spead = (DB1)140;
	god = (DB1)2011;
	width = (DB1)3480;
	poezd = new char[10]{ "Swallow" };
}

template <class DB1, class DB2>
RGD<DB1, DB2>::RGD(DB2 n_spead, DB1 n_god, DB1 n_width, char* n_poezd)
{
	spead = n_spead;
	god = n_god;
	width = n_width;
	poezd = new char[strlen(n_poezd) + 1];
	strcpy(poezd, n_poezd);
}

template <class DB1, class DB2>
RGD<DB1, DB2>::RGD(const RGD<DB1, DB2>& temp)
{
	spead = temp.spead;
	god = temp.god;
	width = temp.width;
	poezd = new char[strlen(temp.poezd) + 1];
	strcpy(poezd, temp.poezd);
}

template <class DB1, class DB2>
RGD<DB1, DB2>::~RGD()
{
	delete[]poezd;
}

template <class DB1, class DB2>
RGD<DB1, DB2> RGD<DB1, DB2> :: operator = (const RGD& rgd)
{
	if (this == &rgd)
		return *this;
	spead = rgd.spead;
	god = rgd.god;
	width = rgd.width;
	poezd = new char[strlen(rgd.poezd) + 1];
	strcpy(poezd, rgd.poezd);
	return *this;
}

template<class DB1, class DB2>
bool RGD<DB1, DB2> :: operator == (const RGD<DB1, DB2>& rgd)
{
	return (spead + god + width == rgd.spead + rgd.god + rgd.width);
}

// Класс-наследник

template<class DB1, class DB2>
class Service : public RGD<DB1, DB2>
{
public:
	void vvod();
	void vivod();
	Service();
	Service(DB1 n_spead, DB1 n_god, DB1 n_width, char* n_poezd, char* n_service);
	~Service();
	Service<DB1, DB2>(const Service& temp);
	Service& operator = (const Service<DB1, DB2>& rgd);
protected:
	char* service;
};

template<class DB1, class DB2>
void Service<DB1, DB2>::vvod()
{
	RGD<DB1, DB2>::vvod();
	cout << "Введите род службы: ";
	cin >> service;
}

template<class DB1, class DB2>
void Service<DB1, DB2>::vivod()
{
	RGD<DB1, DB2>::vivod();
	cout << endl;
	cout << "Род службы:" << service << endl;
}

template<class DB1, class DB2>
Service<DB1, DB2>::Service() : RGD<DB1, DB2>()
{
	service = new char[11]{ "passenger" };
}

template<class DB1, class DB2>
Service<DB1, DB2>::Service(DB1 n_spead, DB1 n_god, DB1 n_width, char* n_poezd, char* n_service)
{
	this->service = service;
}

template<class DB1, class DB2>
Service<DB1, DB2>::~Service()
{
	RGD<DB1, DB2>::~RGD();
}

template<class DB1, class DB2>
Service<DB1, DB2>::Service<DB1, DB2>(const Service& temp)
{
	service = temp.service;
	this->spead = temp.spead;
	this->god = temp.god;
	this->width = temp.width;
	this->poezd = new char[strlen(temp.poezd) + 1];
	strcpy(this->poezd, temp.poezd);
}

template<class DB1, class DB2>
Service<DB1, DB2>& Service<DB1, DB2> :: operator = (const Service& rgd)
{
	service = rgd.service;
	this->spead = rgd.spead;
	this->god = rgd.god;
	this->width = rgd.width;
	this->poezd = new char[strlen(rgd.poezd) + 1];
	strcpy(this->poezd, rgd.poezd);
	return (*this);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	RGD<int, char> RGD_1;
	Service<int, char> service_1;

	// Базовый класс

	cout << "Введите информацию о объекте:" << endl;
	RGD_1.vvod();
	cout << endl << "Базовый класс:" << endl;
	RGD_1.vivod();
	cout << endl;

	// Конструктор с параметрами

	cout << "Введите информацию о роде службы объекта:" << endl;
	service_1.vvod();
	cout << endl << "Класс-наследник:" << endl;
	service_1.vivod();
	cout << endl;

	// Конструктор по умолчанию

	cout << endl << "Конструктор по умолчанию:" << endl;
	Service<int, char> service_2;
	service_2.vivod();
	cout << endl;

	// Копирующий конструктор

	cout << endl << "Копирующий конструктор:" << endl;
	Service<int, char> service_3(service_1);
	service_3.vivod();
	cout << endl;

	// Оператор =

	cout << endl << "Оператор =" << endl;
	service_2 = service_1;
	service_2.vivod();

	// Оператор ==

	cout << endl << "Оператор ==" << endl;
	if (service_1 == service_2) cout << "Объекты равны" << endl;
	else cout << "Объекты не равны" << endl;

	system("pause");
	return 0;
}

