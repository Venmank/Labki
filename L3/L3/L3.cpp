// L3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;

class CMonom{
	unsigned *Ccoef, *Cst;
public:
	CMonom(int a, unsigned b);
	~CMonom();
	unsigned ShowCoef();
	unsigned ShowSt();
	void ChangeCoef(int a);
	void ChangeSt(unsigned b);
	CMonom::CMonom(int a, unsigned b){
		new (Ccoef);
		*Ccoef = a;
		new (Cst);
		*Cst = b;
	}
	CMonom::~CMonom(){
		free(Ccoef);
		free(Cst);
	}
	unsigned ShowCoef(){
		return Ccoef;
	}
	unsigned ShowSt(){
		return Cst;
	}
};


class CPolynom{
	CPolynom *Next;
	CMonom *Pmon;
public:
	CPolynom();
	void CFreeNext(CPolynom *ptr);
	void CFreeMonom(CMonom *ptr);
	CPolynom::CPolynom(){
		CMonom ob(int a = 1, unsigned b = 0);
		*Pmon = ob;
	}
	void CFreeNext(CPolynom *ptr){
		free(ptr);
	}
	void CFreeMonom(CMonom *ptr){
		free(ptr);
	}
};


int main()
{
	FILE * fin;
	char reader, sym;
	int coef = 1, st = 0, count = 0, fl = 0;
	unsigned st_u = 0;
	char buf[30];
	fin = fopen("In.txt", "r");
	if (fin == NULL){
		cout << "Error Input File";
	}
	else{
		while (reader=fgetc(fin)!=EOF)
		{
			if (count == 2){

			}
			while (isspace(reader)) reader = fgetc(fin);
			if (reader == '<'){
				count++;
				while (reader != '>'){
					reader = fgetc(fin);
					if (reader == '-'){
						fl = 1;
						reader=fgetc(fin);
					}
					if (isdigit(reader)){
						while (isdigit(reader)){
							strcat(buf, &reader);
							reader = fgetc(fin);
						}
						coef = atoi(buf);
					}

					if (isalpha(reader)){
						sym = tolower(reader);
						st_u = 1;
						reader = fgetc(fin);
						if (reader == '^'){
							reader = fgetc(fin);
							while (isdigit(reader)){
								strcat(buf, &reader);
								reader = fgetc(fin);
							}
							st = atoi(buf);
							st_u = (unsigned)st;
						}

					}
				}
				//!!!доделывается ввод монома
			}
		}
	}
	return 0;
}

