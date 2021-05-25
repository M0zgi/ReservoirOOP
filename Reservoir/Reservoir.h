#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iomanip>

using namespace std;


class Reservoir
{
private:

	int id;
	int kod;
	char* Reservoir_Name = nullptr;
	double width;
	double length;
	double depth;
	char* Dop_Info = nullptr;
	char* Tip = nullptr;

public:

	Reservoir();
	//Reservoir(Reservoir*& vodoem, int* countreservoir, int* _number);
	Reservoir(int _id, int _kod, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info);


	//����������� �����������
	Reservoir(const Reservoir& obj);


	void DeleteReservoir();

	void AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	//void AddReservoir();

	//����� �������� �� �����
	void Show_Reservoir();

	~ Reservoir();

	//�������

	int Getid();
	int Getkod();
	char GetReservoir_Name();
	double Getwidth();
	double Getlength();
	double Getdepth();
	char GetDop_Info();
	char GetTip();

};

//����� ������ ������ ��� �������������� ������� �� ������ �������� ������ �����
//�������������� ����������� �������� �������� � ���������� ������ Reservoir *Name
//� ����������� �������������� ������-�������
class Country
{
private:

	int cid;
	char* Country_Name = nullptr;
	Reservoir *Name = nullptr;


public:

	Country();
	Country(int _cid, const char* _name);

	Country(const Country& obj);

	void Show_Country();

	~Country();



};

//-----------------------------------------------------------------------------------------------

void gotoxy(int, int);

void ChangeCursorStatus(bool);
void MenuFun1();
void MenuFun2();
void MenuFun3();
void MenuFun4();
void MenuFun5();
void MenuFun6();

void ExitOption();
//-----------------------------------------------------------------------------------------------