// Laborat.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
#include <string>
#define _KAM_USE_INI_NAME_      0x001
#define _KAM_USE_INPUT_FILE_    0x002
#define _KAM_USE_OUTPUT_FILE_   0x004
#define _KAM_STUDENT_INFO_      0x008	
#define _KAM_STUDENE_MAIL_      0x010
#define _KAM_OPEN_MENU_         0x020
#define _KAM_OPEN_HELP_         0x040
#define _KAM_USE_INI_FILE_      0x080
#define _KAM_USE_CRYPTER_       0x100
#define COM                     30
#define FLAGS_COUNT             9

struct ControleKamStruct
{
	unsigned uKamFlags;
	char *szfIniName;
	char *szfIName;
	char *szfOutName;
	char *szfLogName;
}g_ControlKamFlags;

char*com[COM] =
{
	"-fini","/fini",//0,1
	"-fin","/fin",//2,3
	"-fout","/fout",//4,5
	"-s","/s",//6,7
	"-e","/e",//8,9
	"-m","/m",//10,11
	"-h","/h",//12,13
	"-i","/i",//14,15
	"-c","/c",//16,17
	"-!s","/!s",//18,19
	"-!e","/!e",//20,21
	"-!m","/!m",//22,23
	"-!h","/!h",//24,25
	"-!i","/!i",//26,27
	"-!c","/!c",//28,29

};

unsigned Changes = 0;

char *MemIni, *MemIn, *MemOut;

void ChangeIniName();
void ChangeInName();
void ChangeOutName();
void ShowInfo();
void ShowMail();
void ShowMenu();
void ShowHelp();
void UseIni();
void UseCrypto();
void(*pfn_aFunctions[9])(void)
{
	ChangeIniName,
	ChangeInName,
	ChangeOutName,
	ShowInfo,
	ShowMail,
	ShowMenu,
	ShowHelp,
	UseIni,
	UseCrypto



};







int main(int argc, char* argv[])
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	g_ControlKamFlags.uKamFlags = 280;
	g_ControlKamFlags.szfIniName = "Ini.txt";
	g_ControlKamFlags.szfIName = "InPut.txt";
	g_ControlKamFlags.szfLogName = "log.txt";
	g_ControlKamFlags.szfOutName = "Out.txt";


	

	int Con = 1, Comn, i;
	
	if (argc > 1)
	{
		while (Con < argc)
		{
			for (Comn = 0; Comn < COM; Comn) 
			{
				if (!strcmp(argv[Con], com[Comn]))break;
				Comn++;
			}
			switch (Comn)
			{
			case 0:
			case 1:g_ControlKamFlags.uKamFlags |= _KAM_USE_INI_NAME_;
				MemIni = argv[++Con];
				break;
			case 2:
			case 3:g_ControlKamFlags.uKamFlags |= _KAM_USE_INPUT_FILE_;
				MemIn = argv[++Con];
				break;
			case 4:
			case 5:g_ControlKamFlags.uKamFlags |= _KAM_USE_OUTPUT_FILE_;
				MemOut = argv[++Con];
				break;
			case 6:
			case 7:g_ControlKamFlags.uKamFlags |= _KAM_STUDENT_INFO_;
				Changes &= ~1;
				break;
			case 8:
			case 9:g_ControlKamFlags.uKamFlags |= _KAM_STUDENE_MAIL_;
				Changes &= ~2;
				break;
			case 10:
			case 11:g_ControlKamFlags.uKamFlags |= _KAM_OPEN_MENU_;
				Changes |= 4;
				break;
			case 12:
			case 13:g_ControlKamFlags.uKamFlags |= _KAM_OPEN_HELP_;
				Changes |= 8;
				break;
			case 14:
			case 15:g_ControlKamFlags.uKamFlags |= _KAM_USE_INI_FILE_;
				Changes |= 16;
				break;
			case 16:
			case 17:g_ControlKamFlags.uKamFlags |= _KAM_USE_CRYPTER_;
				Changes |= 32;
				break;
			case 18:
			case 19:g_ControlKamFlags.uKamFlags &= ~_KAM_STUDENT_INFO_;
				Changes |= 1;
				break;
			case 20:
			case 21:g_ControlKamFlags.uKamFlags &= ~_KAM_STUDENE_MAIL_;
				Changes |= 2;
				break;
			case 22:
			case 23:g_ControlKamFlags.uKamFlags &= ~_KAM_OPEN_MENU_;
				Changes |= 4;
				break;
			case 24:
			case 25:g_ControlKamFlags.uKamFlags &= ~_KAM_OPEN_HELP_;
				Changes |= 8;
				break;
			case 26:
			case 27:g_ControlKamFlags.uKamFlags &= ~_KAM_USE_INI_FILE_;
				Changes |= 16;
				break;
			case 28:
			case 29:g_ControlKamFlags.uKamFlags &= ~_KAM_USE_CRYPTER_;
				Changes |= 32;
				break;
			case 30: std::cout << "ops";
				break;
			
			}
			Con++;
		}
		


	}
	
	for (i = 1; i < FLAGS_COUNT; i++) {
			if ((g_ControlKamFlags.uKamFlags >> i) & 1)
				pfn_aFunctions[i]();
		}
	
	
	
	getchar();
	

	return 0;
}


void ChangeIniName()
{
	g_ControlKamFlags.szfIniName = MemIni;
}

void ChangeInName()
{
	g_ControlKamFlags.szfIName = MemIn;
}

void ChangeOutName()
{
	g_ControlKamFlags.szfOutName = MemOut;
}

void ShowInfo()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Разработал программу студент\nКаменев Артем Романович\nГруппа:\nТ3О-103Б-16\n8-999-812-91-98\nРожден 18 лет назад\nВодолей\nА НАСО идут лесом, не хочу я быть козерогом\n";
	getchar();
	system("cls");
	
}

void ShowMail()
{
	std::cout << "kamenev29@gmail.com\n";
	getchar();
	system("cls");
}

void ShowMenu()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Тут должно быть меню\n";
	getchar();
	system("cls");
}


void ShowHelp()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "А тут вся инфа что как\n";
	getchar();
	system("cls");
}

void UseIni()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Тут реализация инициализации\n";
	getchar();
	system("cls");
}

void UseCrypto()
{
	char S[256];
	int x = 0, y = 0;
	
	setlocale(LC_ALL, "Russian");
	std::cout << "И собственно сама шифровка\n";
	std::string key;
	std::getline(std::cin, key);
	int KeyLen = key.length;
	for (int i = 0; i < 256; i++)
	{
		S[i] = i;
	}
	getchar();
	system("cls");
}