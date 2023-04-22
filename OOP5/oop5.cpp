#include <iostream>
using namespace std;

class F_Class //������ �����, ��������
{
public:
	F_Class()//����������� �� ���������
	{
		cout << "F_class()\n";
	}

	virtual void virtual_print()//����������� ����� ��� ������� print
	{
		cout << "void virtual_print() ������� ������\n";
	}

	void print()//������� ����� ��� ������� print
	{
		cout << "void print() ������� ������\n";
	}

	virtual string ClassName()//������� ����������� ����� string 
	{
		return "F_Class";
	}

	virtual bool IsA(const string& who)//������� ����������� ����� bool IsA
	{
		return (who == "F_Class");
	}


	virtual ~F_Class()//����������
	{
		cout << "~F_Class()\n";
	}
};

class S_Class : public F_Class //������ �����, ������� ������� ������
{
public:
	S_Class()//����������� �� ���������
	{
		cout << "S_class()\n";
	}

	void virtual_print() override //����������� ����� ��� ������� print
	{
		cout << "void virtual_print() ������� ������\n";
	}

	void print()//������� ����� ��� ������� print
	{
		cout << "void print() ������� ������\n";
	}

	string ClassName()//������� ����������� ����� string 
	{
		return "S_Class";
	}

	bool IsA(const string& who)//������� ����������� ����� bool IsA
	{
		return (who == "S_Class") || (F_Class::IsA(who));
	}

	~S_Class()//����������
	{
		cout << "~S_class()\n";
	}
};

class Base //������� �����
{
protected:
	int id;
public:
	Base()//����������� �� ���������
	{
		cout << "Base()\n";
		id = 0;
	}

	Base(int id)//����������� � �����������
	{
		cout << "Base(int id)\n";
		this->id = id;
	}

	Base(const Base& b)//����������� �����������
	{
		cout << "Base(const Base& b)\n";
		id = b.id;
	}

	virtual bool IsA(const string& who)//������� ����������� ����� bool IsA
	{
		return (who == "Base");
	}

	virtual void unique()
	{
		cout << "nothing";
	}

	virtual ~Base()//����������
	{
		cout << "~Base()\n";
	}
};

class Desc : public Base //����� ������� �������� ������ 
{
private:
	int model;
public:
	Desc()//����������� �� ���������
	{
		cout << "Desc()\n";
	}

	Desc(int id, int model)//����������� � �����������
	{
		cout << "Desc(int id)\n";
		this->id = id;
		this->model = model;
	}

	Desc(const Desc& d)//����������� �����������
	{
		cout << "Desc(const Desc& d)\n";
		id = d.id;
		model = d.model;
	}

	bool IsA(const string& who)//������� ����������� ����� bool IsA
	{
		return (who == "Desc") || (Base::IsA(who));
	}
	void unique_desc()
	{
		cout << "I'm Desc\n";
	}

	~Desc()//����������
	{
		cout << "~Desc()\n";
	}
};

class OtherDesc : public Base // ����� ������� �������� ������
{
private:
	int model;
public:
	OtherDesc()//����������� �� ���������
	{
		cout << "OtherDesc()\n";
	}

	OtherDesc(int id, int model)//����������� � �����������
	{
		cout << "OtherDesc(int id)\n";
		this->id = id;
		this->model = model;
	}

	OtherDesc(const OtherDesc& d)//����������� �����������
	{
		cout << "OtherDesc(const OtherDesc& d)\n";
		id = d.id;
		model = d.model;
	}

	bool IsA(const string& who)//������� ����������� ����� bool IsA
	{
		return (who == "OtherDesc") || (Base::IsA(who));
	}

	void unique_odesc()
	{
		; cout << "I'm oDesc\n";
	}

	~OtherDesc()//����������
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
		// obj �������� ���������� �� ����� Desc, �� ����� �������� ������ Desc
		d1->unique_desc();
	}
	else
	{
		// obj �� �������� ���������� �� ����� Desc, �� �� ����� �������� ������ Desc
		cout << "obj �� �������� ���������� �� ����� Desc\n";
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
	cout << "\n1.������������ ������������� ����������� �������\n2.������������ ������������� ������������� �������\n3.������������ ������� � ������������ �������� (����������� ��������)";
	cout << "\n4.������������ ������� � ������������ ��������(������������ ��������)\n5.������������ �������� �������� ��� ���������� � �������";
	cout << "\n6.�������� �� �������������� � ������\n7.Dynamic_cast\n8.Static_cast and IsA\n9. unique_ptr\n10.shared_ptr\n0.����� �� ���������\n";
	cin >> choice;
	while (choice) {
		switch (choice)
		{
		case 1:
		{
			//������������� ����������� �������
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
			//������������� ������������� �������
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
		{	//������� � ������������ ��������(�����������)
			//Base b1 = Base_func1();
			//Base* b2 = Base_func2();
			Base& b3 = Base_func3();
			goto menu;
			break;
		}
		case 4:
		{	//������� � ������������ ��������(������������)
			Base b1 = Base_func4();
			Base* b2 = Base_func5();
			Base& b3 = Base_func6();
			goto menu;
			break;
		}
		case 5:
		{	//�������� �������� ��� ���������� � �������
			cout << "��� ����������� �������� ��������\n";
			Base b1;
			func1(b1);//�������� �������
			func2(&b1);//�������� ���������
			func3(b1);//�������� �� ������

			cout << "\n\n��� ������������ �������� ��������\n";
			Base* b2 = new Base();
			func1(*b2);
			func2(b2);
			func3(*b2);
			delete b2;
			goto menu;
			break;
		}
		case 6:
		{//�������� �� �������������� � ������
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
			cout << "�������� ������ Desc\n";
			for_dynamic(b1);
			cout << "�������� ������ OtherDesc\n";
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
				int tmp = rand();//���������� ����� ��� ����, ����� ��������� ������� ������� �������� �������
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
				if (array[i]->IsA("Desc"))//�������� �� �������������� ������ Desc
					static_cast<Desc*>(array[i])->unique_desc();
				else cout << "It is not Desc\n";
			}
			for (int i = 0; i < 10; i++)
			{
				delete array[i];//������� ������
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