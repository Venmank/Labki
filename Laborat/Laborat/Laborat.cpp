// Laborat.cpp : Defines the entry point for the console application.
//

#include <iostream>
#define _KAM_USE_INI_NAME_      0x001
#define _KAM_USE_INPUT_FILE_    0x002
#define _KAM_USE_OUTPUT_FILE_   0x004
#define _KAM_STUDENT_INFO_      0x008	
#define _KAM_STUDENE_MAIL_      0x010
#define _KAM_OPEN_MENU_         0x020
#define _KAM_OPEN_HELP_         0x040
#define _KAM_USE_INI_FILE_      0x080
#define _KAM_USE_CRYPTER_       0x100
#define COM                     36
#define FLAGS_COUNT             9

struct ControleKamStruct
{
	unsigned uKamFlags;
	char szfIniName;
	char szfIName;
	char szfOutName;
	char szfLogName;
}g_ControlKamFlags;

char*com[COM] =
{
	"-fini","/fini",
	"-fin","/fin",
	"-fout","/fout",
	"-s","/s",
	"-e","/e",
	"-m","/m",
	"-h","/h",
	"-i","/i",
	"-c","/c",
	"-!fini","/!fini",
	"-!fin","/!fin",
	"-!fout","/!fout",
	"-!s","/!s",
	"-!e","/!e",
	"-!m","/!m",
	"-!h","/!h",
	"-!i","/!i",
	"-!c","/!c",

};


int main(int argc, char* argv[])
{
	int Con = 1, Comn, i;
	char *MemIni, *MemIn, *MemOut;
	if (argc < 1)
	{
		while (Con < argc)
		{
			for (Comn = 0; Comn < COM; Comn) if (!strcmp(argv[Con], com[Comn]))break;
			switch (Comn)
			{
			case 0:
			case 1:g_ControlKamFlags.uKamFlags &= ~_KAM_STUDENT_INFO_;
				MemIni = argv[++Con];
				break;
			case 2:
			case 3:g_ControlKamFlags.uKamFlags &= ~_KAM_STUDENT_INFO_;
				MemIn = argv[++Con];
				break;
			case 4:
			case 5:g_ControlKamFlags.uKamFlags &= ~_KAM_STUDENT_INFO_;
				MemOut = argv[++Con];
				break;
			case 6:
			case 7:g_ControlKamFlags.uKamFlags &= ~_KAM_STUDENT_INFO_;
				break;
			case 8:
			case 9:g_ControlKamFlags.uKamFlags &= ~_KAM_STUDENE_MAIL_;
				break;
			case 10:
			case 11:g_ControlKamFlags.uKamFlags &= ~_KAM_OPEN_MENU_;
				break;
			case 12:
			case 13:g_ControlKamFlags.uKamFlags &= ~_KAM_OPEN_HELP_;
				break;
			case 14:
			case 15:g_ControlKamFlags.uKamFlags &= ~_KAM_USE_INI_FILE_;
				break;
			case 16:
			case 17:g_ControlKamFlags.uKamFlags &= ~_KAM_USE_CRYPTER_;
				break;
			case 18:
			case 19:g_ControlKamFlags.uKamFlags |= _KAM_USE_INI_NAME_;
				break;
			case 20:
			case 21:g_ControlKamFlags.uKamFlags |= _KAM_USE_INPUT_FILE_;
				break;
			case 22:
			case 23:g_ControlKamFlags.uKamFlags |= _KAM_STUDENT_INFO_;
				break;
			case 24:
			case 25:g_ControlKamFlags.uKamFlags |= _KAM_USE_OUTPUT_FILE_;
				break;
			case 26:
			case 27:g_ControlKamFlags.uKamFlags |= _KAM_STUDENE_MAIL_;
				break;
			case 28:
			case 29:g_ControlKamFlags.uKamFlags |= _KAM_OPEN_MENU_;
				break;
			case 30:
			case 31:g_ControlKamFlags.uKamFlags |= _KAM_OPEN_HELP_;
				break;
			case 32:
			case 33:g_ControlKamFlags.uKamFlags |= _KAM_USE_INI_FILE_;
				break;
			case 34:
			case 35:g_ControlKamFlags.uKamFlags |= _KAM_USE_CRYPTER_;
				break;
			case 36:
			



			}
			Con++;
		}
		for (i = 1; i < FLAGS_COUNT; i++) {
			if ((g_ControlKamFlags.uKamFlags >> i) & 1)
				pfn_aFunctions[i]();
		}

	}
    
	
	
	
	
	
	
	
	
	return 0;
}

