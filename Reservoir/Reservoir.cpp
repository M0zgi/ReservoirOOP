#include "Reservoir.h"

Reservoir::Reservoir()
{
	id = 0;
	code = 0;
	Reservoir_Name = new char[10]{ "��� �����" };	
	width = 0;
	length = 0;
	depth = 0;
	Tip = new char[2]{ "-" };
	Dop_Info = new char[2]{ "-" };
	area = 0;
	volume = 0;
}

//Reservoir::Reservoir(Reservoir*& vodoem, int* countreservoir, int* _number)
//{
//
//}

Reservoir::Reservoir(int _id, int _code, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info)
{
	id = _id;
	code = _code;
	width = _width;
	length = _length;
	depth = _depth;
	
	int count_name, count_info, count_tip;
	count_name = strlen(_name);
	count_tip = strlen(_tip);
	count_info = strlen(_info);

	Reservoir_Name = new char[count_name + 1];
	Dop_Info = new char[count_info + 1];
	Tip = new char[count_tip + 1];
	
	strcpy(Reservoir_Name, _name);
	strcpy(Dop_Info, _info);
	strcpy(Tip, _tip);

}

Reservoir::Reservoir(const Reservoir& obj)
{
	id = obj.id;
	code = obj.code;
	Reservoir_Name = obj.Reservoir_Name;
	width = obj.width;
	length = obj.length;
	depth = obj.depth;
	Dop_Info = obj.Dop_Info;
	Tip = obj.Tip;
	area = obj.area;
	volume = obj.volume;
}

void Reservoir::DeleteReservoir(Reservoir*& vodoem, int* countreservoir, int* _number)
{
	system("cls");
	gotoxy(0, 6);
	cout << "�������� �������" << endl;
	
	char _name, _tip, _info;
	int numbertmp = *_number;

	int p_count = 0;

	//����������� ����� ��� ��������
	int delnumber;

	//������� ��� �� ������ �������
	int countdel = 0;

	cout << "������� ����������� ����� ������� ��� ��������: ";
	cin >> delnumber;
	cin.ignore();

	for (size_t i = 0; i < *countreservoir; i++)
	{
		if (vodoem[i].code == delnumber)
		{
			(*countreservoir)--;
			countdel++;
		}
	}

	Reservoir* temp = new Reservoir[*countreservoir];

	for (size_t i = 0; i < *countreservoir; i++)
	{
		if (vodoem[p_count].code == delnumber)
		{
			p_count++;
			i--;
		}

		else if (vodoem[p_count].code != delnumber)
		{
			temp[i].id = vodoem[p_count].id;
			temp[i].code = vodoem[p_count].code;
			temp[i].width = vodoem[p_count].width;
			temp[i].length = vodoem[p_count].length;
			temp[i].depth = vodoem[p_count].depth;
			temp[i].area = vodoem[p_count].area;
			temp[i].volume = vodoem[p_count].volume;

			_name = strlen(vodoem[p_count].Reservoir_Name);
			_tip = strlen(vodoem[p_count].Tip);
			_info = strlen(vodoem[p_count].Dop_Info);

			temp[i].Reservoir_Name = new char[_name + 1];
			temp[i].Tip = new char[_tip + 1];
			temp[i].Dop_Info = new char[_info + 1];

			strcpy(temp[i].Reservoir_Name, vodoem[p_count].Reservoir_Name);
			strcpy(temp[i].Tip, vodoem[p_count].Tip);
			strcpy(temp[i].Dop_Info, vodoem[p_count].Dop_Info);

			p_count++;
		}
	}

	if (countdel)
	{
		cout << "��������� �������...\n";
	}

	delete[]vodoem;
	vodoem = temp;

	if (!countdel)
	{
		cout << "����������� ����� �� ������.\n";
		cout << "����� ����� ������ ��� �������� � ����.";
	}
}

void Reservoir::AddReservoir(Reservoir*& vodoem, int* countreservoir, int *_number)
{	
	system("cls");
	gotoxy(0, 6);
	cout << "���������� �������" << endl;

	Reservoir* temp = new Reservoir[*countreservoir + 1];
	char _name, _tip, _info;
	int numbertmp = *_number;

	for (size_t i = 0; i < *countreservoir; i++)
	{
		temp[i].id = vodoem[i].id;
		temp[i].code = vodoem[i].code;
		temp[i].width = vodoem[i].width;
		temp[i].length = vodoem[i].length;
		temp[i].depth = vodoem[i].depth;
		temp[i].area = vodoem[i].area;
		temp[i].volume = vodoem[i].volume;

		_name = strlen(vodoem[i].Reservoir_Name);
		_tip = strlen(vodoem[i].Tip);
		_info = strlen(vodoem[i].Dop_Info);

		temp[i].Reservoir_Name = new char[_name + 1];
		temp[i].Tip = new char[_tip + 1];
		temp[i].Dop_Info = new char[_info + 1];

		strcpy(temp[i].Reservoir_Name, vodoem[i].Reservoir_Name);
		strcpy(temp[i].Tip, vodoem[i].Tip);
		strcpy(temp[i].Dop_Info, vodoem[i].Dop_Info);
	}

	temp[*countreservoir].id = numbertmp;

	cout << "������� ����������� ��� �������: ";
	cin >> temp[*countreservoir].code;
	cin.ignore();

	cout << "������� ������������ �������: ";
	char buff[250];
	cin.getline(buff, 250);
	_name = strlen(buff);
	temp[*countreservoir].Reservoir_Name = new char[_name + 1];
	strcpy(temp[*countreservoir].Reservoir_Name, buff);	
	
	cout << "������� ������(��) �������: ";
	cin >> temp[*countreservoir].width;	
	cin.ignore();

	cout << "������� �����(��) �������: ";
	cin >> temp[*countreservoir].length;	
	cin.ignore();

	cout << "������� �������(�) �������: ";
	cin >> temp[*countreservoir].depth;	
	cin.ignore();

	cout << "������� ��� �������: ";	
	cin.getline(buff, 250);
	_tip = strlen(buff);
	temp[*countreservoir].Tip = new char[_tip + 1];
	strcpy(temp[*countreservoir].Tip, buff);	

	cout << "������� �������������� ����������: ";	
	cin.getline(buff, 250);
	_info = strlen(buff);
	temp[*countreservoir].Dop_Info = new char[_info + 1];
	strcpy(temp[*countreservoir].Dop_Info, buff);
	cout << endl;	

	(*countreservoir)++;
	(*_number)++;

	delete[]vodoem;

	vodoem = temp;

	cout << "��������� �������...\n";
	cout << "����� ����� ������ ��� �������� � ����.";
}

long double Reservoir::SearchArea(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int *check)
{
	int searchidarray = 0;	
	int count = 0;
	long double area = 0;

	for (size_t i = 0; i < countreservoir; i++)
	{
		if (vodoem[i].code == _code)
		{
			searchidarray = count;
			*_idarray = count;
			(*check)++;
		}			
		count++;
	}
	cout << endl;

	if (check++)
	{
		area = vodoem[searchidarray].Getwidth() * vodoem[searchidarray].Getlength();
		vodoem[searchidarray].Setarea(area);
	}

	return area;

}

void Reservoir::AutoSearchArea(Reservoir* vodoem, const int countreservoir)
{
	long double area = 0;
	for (size_t i = 0; i < countreservoir; i++)
	{
		area = vodoem[i].Getwidth() * vodoem[i].Getlength();
		vodoem[i].Setarea(area);
	}
}

void Reservoir::SearchVolume(Reservoir* vodoem)
{
}

void Reservoir::SearchAreaTip(Reservoir* vodoem, char const* charsearch, int const countreservoir)
{
	int countsearch = 0;

	for (size_t i = 0; i < countreservoir; i++)
	{
		char* temp = strstr(vodoem[i].Tip, charsearch);

		if (temp)
		{
			countsearch++;

			if (countsearch == 1)
			{
				gotoxy(0, 13);
				cout << "+-------+---------------------------+-----------------+-------------+\n";
				gotoxy(0, 14);
				cout << "|���    | ������������              | ���             | �������, �� |\n";
				gotoxy(0, 15);
				cout << "+-------+---------------------------+-----------------+-------------+\n";
			}

			cout << left << "| " << setw(5) << vodoem[i].code << " | " << setw(26);
			vodoem[i].Show_One_Reservoir();

			cout << left << "| " << setw(15) << vodoem[i].Tip << " | " << setw(11) << vodoem[i].area << " | " << endl;
		}
		
	}

	cout << "+-------+---------------------------+-----------------+-------------+\n";

	if (countsearch < 1)
	{
		cout << "�������� �� ������� �� �������" << endl;
		cout << "����� ����� ������ ��� �������� � ����.";
	}
}

void Reservoir::Show_Reservoir()
{
	cout << left << "| " << setw(5) << code << " | " << setw(26) << Reservoir_Name << " | " << setw(10) << width << " | " << setw(9) <<  length << " | " << setw(10) << depth << " | " << setw(15) << Tip << " | " << setw(47) << Dop_Info << " | " << endl;

}

void Reservoir::Show_One_Reservoir()
{
	cout << Reservoir_Name;
}

Reservoir::~Reservoir()
{
	delete[]Reservoir_Name;
	delete[]Dop_Info;
	delete[]Tip;
}

int Reservoir::Getid()
{
	return id;
}

int Reservoir::Getcode()
{
	return code;
}

char Reservoir::GetReservoir_Name()
{
	return *Reservoir_Name;
}

double Reservoir::Getwidth()
{
	return width;
}

double Reservoir::Getlength()
{
	return length;
}

double Reservoir::Getdepth()
{
	return depth;
}

char Reservoir::GetDop_Info()
{
	return *Dop_Info;
}

char Reservoir::GetTip()
{
	return *Tip;
}

long double Reservoir::Getarea()
{
	return area;
}

long double Reservoir::Getvolume()
{
	return volume;
}

void Reservoir::Setid(int _id)
{
	id = _id;
}

void Reservoir::Setcode(int _code)
{
	code = _code;
}

void Reservoir::SetReservoir_Name(char* _Reservoir_Name)
{
	Reservoir_Name = _Reservoir_Name;
}

void Reservoir::Setwidth(double _width)
{
	width = _width;
}

void Reservoir::Setlength(double _length)
{
	length = _length;
}

void Reservoir::Setdepth(double _depth)
{
	depth = _depth;
}

void Reservoir::SetDop_Info(char* _Dop_Info)
{
	Dop_Info = _Dop_Info;
}

void Reservoir::SetTip(char* _Tip)
{
	Tip = _Tip;
}

void Reservoir::Setarea(long double _area)
{
	area = _area;
}

void Reservoir::Setvolume(long double _volume)
{
	volume = _volume;
}

Country::Country()
{
	cid = 0;
	Country_Name = new char[10]{ "��� �����" };
}

Country::Country(int _cid, const char* _name)
{
	cid = _cid;

	int count_name;
	count_name = strlen(_name);	
	Country_Name = new char[count_name + 1];
	strcpy(Country_Name, _name);
}

Country::Country(const Country& obj)
{
	cid = obj.cid;
	Country_Name = obj.Country_Name;
	Name = obj.Name;
}

void Country::Show_Country()
{
	cout << Country_Name;
}

Country::~Country()
{
	delete[]Name;
}
