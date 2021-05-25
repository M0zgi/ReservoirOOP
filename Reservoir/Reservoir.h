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


	//конструктор копировани€
	Reservoir(const Reservoir& obj);


	void DeleteReservoir();

	void AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	//void AddReservoir();

	//вывод водоемов на экран
	void Show_Reservoir();

	~ Reservoir();

	//геттеры

	int Getid();
	int Getkod();
	char GetReservoir_Name();
	double Getwidth();
	double Getlength();
	double Getdepth();
	char GetDop_Info();
	char GetTip();

};

//класс —трана создан дл€ маштабировани€ проекта до уровн€ водоемов разных стран
//предполагаетс€ копирвоание названий водоемов в переменную класса Reservoir *Name
//с последующим сопоставлением страна-водоемы
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