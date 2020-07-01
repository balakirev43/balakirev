#include <iostream>
using namespace std;

// Первый базовый класс

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
	RGD(DB1 n_spead, DB1 n_god, DB1 n_width, char* n_poezd);
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
	poezd = new char[11]{ "Swallow" };
}

template <class DB1, class DB2>
RGD<DB1, DB2>::RGD(DB1 n_spead, DB1 n_god, DB1 n_width, char* n_poezd)
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

// Второй базовый класс

template <class DB1, class DB2>
class Material
{
protected:
	char* material;
public:
	Material<DB1, DB2>();
	Material<DB1, DB2>(const char* temp);
	void vvod_M();
	void vivod_M();
};

template<class DB1, class DB2>
Material<DB1, DB2>::Material()
{
	material = new char[11]{ "aluminum" };
}

template<class DB1, class DB2>
Material<DB1, DB2>::Material(const char* temp)
{
	material = temp;
}

template<class DB1, class DB2>
void Material<DB1, DB2>::vvod_M()
{
	cout << "Введите материал вагона:";
	cin >> material;
}

template<class DB1, class DB2>
void Material<DB1, DB2>::vivod_M()
{
	cout << "Материал: " << material << endl;
}

// Класс-наследник

template<class DB1, class DB2>
class Service : public RGD<DB1, DB2>, public Material<DB1, DB2>
{
public:
	void vvod();
	void vivod();
	Service();
	Service(DB1 n_spead, DB1 n_god, DB1 n_width, char* n_poezd, char* service);
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
	Material<DB1, DB2>::vvod_M();
	cout << "Введите род службы: ";
	cin >> service;
}

template<class DB1, class DB2>
void Service<DB1, DB2>::vivod()
{
	RGD<DB1, DB2>::vivod();
	cout << endl;
	Material<DB1, DB2>::vivod_M();
	cout << "Род службы:" << service << endl;
}

template<class DB1, class DB2>
Service<DB1, DB2>::Service() : RGD<DB1, DB2>()
{
	service = new char[11]{ "passenger" };
}

template<class DB1, class DB2>
Service<DB1, DB2>::Service(DB1 n_spead, DB1 n_god, DB1 n_width, char* n_poezd, char* service)
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
	Service<int, char> Service_1;

	// Базовый класс 1

	cout << "Введите информацию о объекте:" << endl;
	RGD_1.vvod();

	// Базовый класс 2

	cout << "Введите материал вагона:" << endl;
	Material<int, char> Material_1;
	Material_1.vvod_M();

	cout << endl << "Базовые классы" << endl;
	cout << "Базовый класс 1:" << endl;
	RGD_1.vivod();
	cout << endl;

	cout << "Базовый класс 2:" << endl;
	Material_1.vivod_M();
	cout << endl;

	// Производный класс с множественным наследованием

	cout << endl << "Класс-наследник" << endl;
	cout << "Введите информацию о объете, материале и роде службы:" << endl;
	Service_1.vvod();
	cout << endl;

	cout << "Класс-наследник:" << endl;
	Service_1.vivod();
	cout << endl;

	// Объект без параметров

	cout << "Объект по умолчанию:" << endl;
	Service<int, char> Service_2;
	Service_2.vivod();

	system("pause");
	return 0;
}
