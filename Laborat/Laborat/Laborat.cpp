// Laborat.cpp : Defines the entry point for the console application.
//

#include <windows.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

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

HANDLE hConsole;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

struct ControleKamStruct
{
	unsigned uKamFlags;
	char szfIniName[255];
	char szfInName[255];
	char szfOutName[255];
	char szfLogName[255];
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

unsigned Changes = 0, x = 1, y = 3, leng = 0;
int RC4_i = 0;
int RC4_j = 0;
unsigned char RC4_S[256];

char *MemIni, *MemIn, *MemOut;
char keyRC4[256], *pkey = keyRC4;

void ChangeIniName();
void ChangeInName();
void ChangeOutName();
void ShowInfo();
void ShowMail();
void ShowMenu();
void ShowHelp();
void UseIni();
void UseCrypto();
void RC4_InitKey();
unsigned char RC4_Transform(unsigned char nextByte);
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
	g_ControlKamFlags.uKamFlags = 32;
	strcpy_s(g_ControlKamFlags.szfIniName,"I.txt");
	strcpy_s(g_ControlKamFlags.szfInName,"Out.jpg");
	strcpy_s(g_ControlKamFlags.szfLogName,"log.txt");
	strcpy_s(g_ControlKamFlags.szfOutName, "Out2.jpg");
	strcpy_s(keyRC4, "Key1");
	leng = strlen(pkey);
	 

	

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
			case 30: std::cout << "ops\n";
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
	strcpy_s(g_ControlKamFlags.szfIniName,MemIni);
}

void ChangeInName()
{
	strcpy_s(g_ControlKamFlags.szfInName,MemIn);
}

void ChangeOutName()
{
	strcpy_s(g_ControlKamFlags.szfOutName,MemOut);
}

void ShowInfo()
{
	std::cout << "STDUDENT\n";
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
	int Menuchange;
	int i;
	y = 3, x = 1;
	unsigned short readKeyCode = 0;
	while (readKeyCode != 27)
	{
		std::cout << "\xC9";
		for (i = 0; i < 38; i++) std::cout << "\xCD";
		std::cout << "\xCB";
		for (i = 0; i < 38; i++) std::cout << "\xCD";
		std::cout << "\xBB\n\xBA";
		(x == 0 && y == 0) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Show help (F1)";
		for (i = 0; i < 22; i++) std::cout << " ";
		std::cout << "\xBA";
		(x == 1 && y == 0) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Change input file name";
		for (i = 0; i < 14; i++) std::cout << " ";
		std::cout << "\xBA\n\xBA";
		(x == 0 && y == 1) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Show task info";
		for (i = 0; i < 22; i++) std::cout << " ";
		std::cout << "\xBA";
		(x == 1 && y == 1) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Change output file name";
		for (i = 0; i < 13; i++) std::cout << " ";
		std::cout << "\xBA\n\xBA";
		(x == 0 && y == 2) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Show student info";
		for (i = 0; i < 19; i++) std::cout << " ";
		std::cout << "\xBA";
		(x == 1 && y == 2) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Change key";
		for (i = 0; i < 26; i++) std::cout << " ";
		std::cout << "\xBA\n\xBA";
		(x == 0 && y == 3) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Show student e-mail";
		for (i = 0; i < 17; i++) std::cout << " ";
		std::cout << ("\xBA");
		for (i = 0; i < 38; i++) std::cout << " ";
		std::cout << "\xBA\n\xBA";
		for (i = 0; i < 38; i++) std::cout << " ";
		std::cout << "\xBA";
		(x == 1 && y == 3) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Exit from menu (ESC)";
		for (i = 0; i < 16; i++) std::cout << " ";
		std::cout << "\xBA\n\xBA";
		(x == 0 && y == 4) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Start task";
		for (i = 0; i < 26; i++) std::cout << " ";
		std::cout << "\xBA";
		(x == 1 && y == 4) ? std::cout << "->" : std::cout << "  ";
		std::cout << "Exit";
		for (i = 0; i < 32; i++) std::cout << " ";
		std::cout << "\xBA\n\xC8";
		for (i = 0; i < 38; i++) std::cout << "\xCD";
		std::cout << "\xCA";
		for (i = 0; i < 38; i++) std::cout << "\xCD";
		std::cout << "\xBC\n";

		readKeyCode = _getch();
		switch (readKeyCode)
		{
		case 72:y == 0 ? y += 4 : y -= 1;
			break;
		case 80:y = (y + 1) % 5;
			break;
		case 75:x == 0 < 0 ? x += 1 : x -= 1;
			break;
		case 77:x = (x + 1) % 2;
			break;
		case 13:Menuchange = y * 2 + x;
			switch (Menuchange)
			{
			case 0:ShowHelp();
				break;
			case 1:system("cls");
				std::cout << "New Input file: ";
				std::cin >> g_ControlKamFlags.szfInName; 
				break;
			case 2:ShowHelp();
				break;
			case 3:system("cls");
				std::cout << "New Output file: ";
				std::cin >> g_ControlKamFlags.szfOutName;
				break;
			case 4:ShowInfo();
				break;
			case 5:system("cls");
				std::cout << "New key: ";
				leng = strlen(pkey);
				break;
			case 6:ShowMail();
				break;
			case 7:readKeyCode = 27;
				break;
			case 8:UseCrypto();
				break;
			case 9:exit(0);
				break;
			}

		}
		system("cls");

	}
	system("cls");
}


void ShowHelp()
{
	std::cout << "Info\n";
	getchar();
	system("cls");
}

void UseIni()
{
	std::cout << "Ini\n";
	getchar();
	system("cls");
}

void UseCrypto()
{
	FILE *fin = fopen(g_ControlKamFlags.szfInName, "r"), *fout = fopen(g_ControlKamFlags.szfOutName, "w+");
	RC4_InitKey();
	if (fin == NULL | fout == NULL)
	{
		cout << "Cannot open InPut and/or OutPut file.\n";
	getchar();
	}
	else
	{
		int result;
		unsigned char buffer[4096];
		
		while (true)
		{
			result = fread(buffer, 1, 4096, fin);
			if (result == 0) break;
			for (int i = 0; i<result; i++)
				buffer[i] = RC4_Transform(buffer[i]);
			fwrite(buffer, 1, result, fout);
		}

		
	fclose(fin);
	fclose(fout);
	}
	system("cls");
}

void RC4_InitKey()
{

	for (int i = 0; i<256; i++)
	{
		RC4_S[i] = i;
	}

	int j = 0;
	for (int i = 0; i<256; i++)
	{
		j = (j + (unsigned char)keyRC4[i % leng] + RC4_S[i]) % 256;

		unsigned char temp = RC4_S[i];
		RC4_S[i] = RC4_S[j];
		RC4_S[j] = temp;
	}
}

unsigned char RC4_Transform(unsigned char nextByte)
{
	RC4_i = (RC4_i + 1) % 256;
	RC4_j = (RC4_j + RC4_S[RC4_i]) % 256;
	unsigned char temp = RC4_S[RC4_i];
	RC4_S[RC4_i] = RC4_S[RC4_j];
	RC4_S[RC4_j] = temp;
	temp = (RC4_S[RC4_i] + RC4_S[RC4_j]) % 256;

	return nextByte ^ RC4_S[temp];
}

