#include"Reservoir.h"



//счетчки количества водоемов в массиве
int countreservoir = 3;

//счетчки количества стран
int countrountry = 1;

//ID водоема в массиве. Служебное свойство
int number = 1;

//Первоначальное заполнение абонентской книги
Reservoir* vodoem = new Reservoir[countreservoir]
{
	{number++, 2201, "Голубое озеро", 0.72, 0.45, 50, "озеро", "Бугский Гард. Село Мигия. Николаевская область"},
	{number++, 3301, "Днепровское водохранилище", 3.5, 170, 8, "водохранилище","Запорожская и Днепропетровская области"},
	{number++, 4421, "Азовское море", 200, 380, 7.4, "море", "Херсонская, Запорожская и Донецкая области"}
};


Country* cname = new Country[countrountry]
{
	{countrountry++, "Украина"},
	
};

 //-----------------------------------------------------------------------------------------------
string* MenuItems() 
{
	string* item = new string[7];
	item[0] = "1. Список Водоемов";
	item[1] = "2. Добавление Водоема. Удаление Водоема";
	item[2] = "3. Расчет объема водоема";
	item[3] = "4. Определения площади водной поверхности";
	item[4] = "5. Проверка типа водоема";
	item[5] = "6. Сравнения площади водной поверхности";
	item[6] = "7. Выход из программы";

	return item;
}
//-----------------------------------------------------------------------------------------------
void gotoxy(int xpos, int ypos) 
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
//-----------------------------------------------------------------------------------------------
void MenuFun1()
{
	system("cls"); 

	gotoxy(1, 6);
	cout << "Список Водоемов\n\n";
	gotoxy(17, 6);
	cname->Show_Country();


	gotoxy(1, 7);
	cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";
	gotoxy(1, 8);
	cout << "|Код    | Наименование               | Ширина, км | Длина, км | Глубина, м | Тип             | Дополнительная информация                       |\n";
	gotoxy(1, 9);
	cout << "+-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";	

	for (size_t i = 0; i < countreservoir; i++)
	{
		gotoxy(1, 10 + i);
		vodoem[i].Show_Reservoir();
		
	}
	cout << " +-------+----------------------------+------------+-----------+------------+-----------------+-------------------------------------------------+\n";
	
	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun2()
{
	system("cls"); 
	gotoxy(0, 5);
	cout << "Страна: \n";
	gotoxy(9, 5);
	cname->Show_Country();
	cout << endl;
	gotoxy(0, 6);

	int choose;
	cout << "1. Добавление Водоема"<< endl;	
	cout << "2. Удаление Водоема" << endl;	
	cout << "3. Выход" << endl;	
	cout << "Введите номер меню: ";
	cin >> choose;
	cout << endl << endl;
	if (choose == 1)
		vodoem->AddReservoir(vodoem, &countreservoir, &number);
	
	if (choose == 2)
		vodoem->DeleteReservoir(vodoem, &countreservoir, &number);	

	if (choose > 2)
    cout << "Выход..." << endl;
	

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun3()
{
	system("cls");
	gotoxy(25, 9);
	cout << "Расчет объема водоема\n";
	
	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun4()
{
	system("cls");
	int _code;
	int idarray = NULL;
	int check = 0;

	gotoxy(0, 9);
	cout << "Определения площади водной поверхности\n";
	cout << "Введите кадастровый номер водоема: ";
	cin >> _code;
	vodoem->SearchArea(vodoem, countreservoir, _code, &idarray, &check);

	if (check)
	{
		cout << "Площадь водоема ";
		vodoem[idarray].Show_One_Reservoir();
		cout << " = " << vodoem[idarray].Getarea() << " км.";
	}

	else
		cout << "По запросу ничего не найдено...";

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun5()
{
	system("cls");
	gotoxy(25, 9);
	cout << "Проверка типа водоема\n";


	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun6()
{
	system("cls");
	gotoxy(25, 9);
	cout << "Сравнения площади водной поверхности\n";


	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void ExitOption()
{
	gotoxy(35, 15);
	delete[]vodoem;
	delete[]cname;
	cout << "Exitting..." << endl;
	_getch();
	exit(0);
}
//-----------------------------------------------------------------------------------------------
void ChangeCursorStatus(bool Visible)
{
	CONSOLE_CURSOR_INFO* c = new CONSOLE_CURSOR_INFO;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Visible)
	{
		c->bVisible = TRUE;
		c->dwSize = 0;
	}
	else
	{
		c->bVisible = FALSE;
		c->dwSize = 1;
	}

	SetConsoleCursorInfo(h, c);
}
//-----------------------------------------------------------------------------------------------
