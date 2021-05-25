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
	int code;
	char* Reservoir_Name = nullptr;
	double width;
	double length;
	double depth;
	char* Dop_Info = nullptr;
	char* Tip = nullptr;
	double area;
	double volume;

public:

	Reservoir();
	//Reservoir(Reservoir*& vodoem, int* countreservoir, int* _number);
	Reservoir(int _id, int _code, const char* _name, double _width, double _length, double _depth, const char* _tip, const char* _info);


	//конструктор копировани€
	Reservoir(const Reservoir& obj);


	void DeleteReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	void AddReservoir(Reservoir*& vodoem, int* countreservoir, int* _number);

	//void AddReservoir();

	//расчет площади воды S = a * b, где S Ч площадь; a - длина и b - ширина.
	double SearchArea(Reservoir* vodoem, const int countreservoir, int _code, int* _idarray, int* check);

	//расчет объема воды (Q = width * length * depth, где Q Ч объем; width * length * depth Ч ширина, длина и глубина)
	void SearchVolume(Reservoir* vodoem);

	//вывод водоемов на экран
	void Show_Reservoir();

	//вывод одного водоема на экран

	void Show_One_Reservoir();

	~ Reservoir();

	//геттеры

	int Getid();
	int Getcode();
	char GetReservoir_Name();
	double Getwidth();
	double Getlength();
	double Getdepth();
	char GetDop_Info();
	char GetTip();
	double Getarea();
	double Getvolume();

	//сеттеры
	void Setid(int _id);
	void Setcode(int _code);
	void SetReservoir_Name(char* _Reservoir_Name);
	void Setwidth(double _width);
	void Setlength(double _length);
	void Setdepth(double _depth);
	void SetDop_Info(char* _Dop_Info);
	void SetTip(char* _Tip);
	void Setarea(double _area);
	void Setvolume(double _volume);

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