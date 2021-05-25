#include "Reservoir.h"

Reservoir::Reservoir()
{
	id = 0;
	kod = 0;
	Reservoir_Name = new char[10]{ "��� �����" };	
	width = 0;
	length = 0;
	depth = 0;
	Tip = new char[2]{ "-" };
	Dop_Info = new char[2]{ "-" };
}

//Reservoir::Reservoir(Reservoir*& vodoem, int* countreservoir, int* _number)
//{
//
//}

Reservoir::Reservoir(int _id, int _kod, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info)
{
	id = _id;
	kod = _kod;
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
	kod = obj.kod;
	Reservoir_Name = obj.Reservoir_Name;
	width = obj.width;
	length = obj.length;
	depth = obj.depth;
	Dop_Info = obj.Dop_Info;
	Tip = obj.Tip;
}

void Reservoir::DeleteReservoir()
{
}

void Reservoir::AddReservoir(Reservoir*& vodoem, int* countreservoir, int *_number)
{
	Reservoir* temp = new Reservoir[*countreservoir + 1];
	char _name, _tip, _info;
	int numbertmp = *_number;

	for (size_t i = 0; i < *countreservoir; i++)
	{
		temp[i].id = vodoem[i].id;
		temp[i].kod = vodoem[i].kod;
		temp[i].width = vodoem[i].width;
		temp[i].length = vodoem[i].length;
		temp[i].depth = vodoem[i].depth;

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
	cin >> temp[*countreservoir].kod;
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

void Reservoir::Show_Reservoir()
{
	cout << left << "| " << setw(5) << kod << " | " << setw(26) << Reservoir_Name << " | " << setw(10) << width << " | " << setw(9) <<  length << " | " << setw(10) << depth << " | " << setw(15) << Tip << " | " << setw(47) << Dop_Info << " | " << endl;

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

int Reservoir::Getkod()
{
	return kod;
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