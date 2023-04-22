#include <iostream>
using namespace std;

class F_Class //первый класс, родитель
{
public:
	F_Class()//конструктор по умолчанию
	{
		cout << "F_class()\n";
	}

	virtual void virtual_print()//виртуальный метод для функции print
	{
		cout << "void virtual_print() первого класса\n";
	}

	void print()//обычный метод для функции print
	{
		cout << "void print() первого класса\n";
	}

	virtual string ClassName()//базовый виртуальный метод string 
	{
		return "F_Class";
	}

	virtual bool IsA(const string& who)//базовый виртуальный метод bool IsA
	{
		return (who == "F_Class");
	}


	virtual ~F_Class()//деструктор
	{
		cout << "~F_Class()\n";
	}
};

class S_Class : public F_Class //второй класс, потомок первого класса
{
public:
	S_Class()//конструктор по умолчанию
	{
		cout << "S_class()\n";
	}

	void virtual_print() override //виртуальный метод для функции print
	{
		cout << "void virtual_print() второго класса\n";
	}

	void print()//обычный метод для функции print
	{
		cout << "void print() второго класса\n";
	}

	string ClassName()//базовый виртуальный метод string 
	{
		return "S_Class";
	}

	bool IsA(const string& who)//базовый виртуальный метод bool IsA
	{
		return (who == "S_Class") || (F_Class::IsA(who));
	}

	~S_Class()//деструктор
	{
		cout << "~S_class()\n";
	}
};

class Base //базовый класс
{
protected:
	int id;
public:
	Base()//конструктор по умолчанию
	{
		cout << "Base()\n";
		id = 0;
	}

	Base(int id)//конструктор с параметрами
	{
		cout << "Base(int id)\n";
		this->id = id;
	}

	Base(const Base& b)//конструктор копирования
	{
		cout << "Base(const Base& b)\n";
		id = b.id;
	}

	virtual bool IsA(const string& who)//базовый виртуальный метод bool IsA
	{
		return (who == "Base");
	}

	virtual void unique()
	{
		cout << "nothing";
	}

	virtual ~Base()//деструктор
	{
		cout << "~Base()\n";
	}
};

class Desc : public Base //класс потомок базового класса 
{
private:
	int model;
public:
	Desc()//конструктор по умолчанию
	{
		cout << "Desc()\n";
	}

	Desc(int id, int model)//конструктор с параметрами
	{
		cout << "Desc(int id)\n";
		this->id = id;
		this->model = model;
	}

	Desc(const Desc& d)//конструктор копирования
	{
		cout << "Desc(const Desc& d)\n";
		id = d.id;
		model = d.model;
	}

	bool IsA(const string& who)//базовый виртуальный метод bool IsA
	{
		return (who == "Desc") || (Base::IsA(who));
	}
	void unique_desc()
	{
		cout << "I'm Desc\n";
	}

	~Desc()//деструктор
	{
		cout << "~Desc()\n";
	}
};

class OtherDesc : public Base // класс потомок базового класса
{
private:
	int model;
public:
	OtherDesc()//конструктор по умолчанию
	{
		cout << "OtherDesc()\n";
	}

	OtherDesc(int id, int model)//конструктор с параметрами
	{
		cout << "OtherDesc(int id)\n";
		this->id = id;
		this->model = model;
	}

	OtherDesc(const OtherDesc& d)//конструктор копирования
	{
		cout << "OtherDesc(const OtherDesc& d)\n";
		id = d.id;
		model = d.model;
	}

	bool IsA(const string& who)//базовый виртуальный метод bool IsA
	{
		return (who == "OtherDesc") || (Base::IsA(who));
	}

	void unique_odesc()
	{
		; cout << "I'm oDesc\n";
	}

	~OtherDesc()//деструктор
	{
		cout << "~OtherDesc()\n";
	}
};


Base Base_func1()
{
	Base b;
	cout << "func1\n\n";
	return b;
}

Base* Base_func2()
{
	Base b;
	cout << "func2\n\n";
	return &b;
}

Base& Base_func3()
{
	Base b;
	cout << "func3\n\n";
	return b;
}

Base Base_func4()
{
	Base* b1 = new Base();
	cout << "func4\n\n";
	return *b1;
}

Base* Base_func5()
{
	Base* b1 = new Base();
	cout << "func5\n\n";
	return b1;
}

Base& Base_func6()
{
	Base* b1 = new Base();
	cout << "func5\n\n";
	return *b1;
}


void for_dynamic(Base* obj)
{
	Desc* d1 = dynamic_cast<Desc*>(obj);
	if (d1)
	{
		// obj является указателем на класс Desc, мы можем вызывать методы Desc
		d1->unique_desc();
	}
	else
	{
		// obj не является указателем на класс Desc, мы не можем вызывать методы Desc
		cout << "obj не является указателем на класс Desc\n";
	}
}



void func1(Base obj)
{
	cout << "func1\n\n";
}

void func2(Base* obj)
{
	cout << "func2\n\n";
}
void func3(Base& obj)
{
	cout << "func3\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
menu:
	cout << "\n1.Демонстрация использования виртуальных методов\n2.Демонстрация использования невиртуальных методов\n3.Демонстрация функций с возвращением объектов (статическое создание)";
	cout << "\n4.Демонстрация функций с возвращением объектов(динамическое создание)\n5.Демонстрация передачи объектов как параметров в функции";
	cout << "\n6.Проверка на принадлежность к классу\n7.Dynamic_cast\n8.Static_cast and IsA\n9. unique_ptr\n10.shared_ptr\n0.Выход из программы\n";
	cin >> choice;
	while (choice) {
		switch (choice)
		{
		case 1:
		{
			//использование виртуальных методов
			F_Class* f = new F_Class();
			F_Class* s = new S_Class();
			f->virtual_print();
			s->virtual_print();
			delete s;
			delete f;
			goto menu;
			break;
		}
		case 2:
		{
			//использование невиртуальных методов
			F_Class* f = new F_Class();
			F_Class* s = new S_Class();
			f->print();
			s->print();
			delete s;
			delete f;
			goto menu;
			break;
		}
		case 3:
		{	//функции с возвращением объектов(статические)
			//Base b1 = Base_func1();
			//Base* b2 = Base_func2();
			Base& b3 = Base_func3();
			goto menu;
			break;
		}
		case 4:
		{	//функции с возвращением объектов(динамические)
			Base b1 = Base_func4();
			Base* b2 = Base_func5();
			Base& b3 = Base_func6();
			goto menu;
			break;
		}
		case 5:
		{	//передача объектов как параметров в функции
			cout << "При статическом создании объектов\n";
			Base b1;
			func1(b1);//передача объекта
			func2(&b1);//передача указателя
			func3(b1);//передача по ссылке

			cout << "\n\nПри динамическом создании объектов\n";
			Base* b2 = new Base();
			func1(*b2);
			func2(b2);
			func3(*b2);
			delete b2;
			goto menu;
			break;
		}
		case 6:
		{//Проверка на принадлежность к классу
			Desc* d1 = new Desc();
			if (dynamic_cast<Desc*>(d1))
			{
				cout << "d1 is Desc\n";
			}
			else
			{
				cout << "d1 isn't Desc\n";
			}
			goto menu;
			break;
		}
		case 7:
		{	// Dynamic_cast
			Base* b1 = new Desc();
			Base* b2 = new OtherDesc();
			cout << "Передаем объект Desc\n";
			for_dynamic(b1);
			cout << "Передаем объект OtherDesc\n";
			for_dynamic(b2);
			delete b1;
			delete b2;
			goto menu;
			break;
		}
		case 8:
		{//Static_cast and IsA
			srand(time(NULL));
			Base* array[10];
			for (int i = 0; i < 10; i++)
			{
				int tmp = rand();//генерируем число для того, чтобы случайным образом вызвать создание классов
				if (tmp % 2 == 0)
				{
					array[i] = new Desc();
				}
				else
				{
					array[i] = new OtherDesc();
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (array[i]->IsA("Desc"))//проверка на принадлежность классу Desc
					static_cast<Desc*>(array[i])->unique_desc();
				else cout << "It is not Desc\n";
			}
			for (int i = 0; i < 10; i++)
			{
				delete array[i];//очищаем массив
			}
			goto menu;
			break;
		}
		case 9:
		{//unique_ptr
			unique_ptr<Base> based(new Base());
			goto menu;
			break;
		}
		case 10:
		{//shared_ptr
			cout << ("{\n");
			{
				shared_ptr<Base> based(new Base());
				{
					cout << ("{\n");
					shared_ptr<Base> based1 = based;
				}
				cout << ("}\n");
			}
			cout << ("}\n");
			goto menu;
			break;
		}
		case 0:
		{
			goto menu;
			break;
		}
		}
	}
}