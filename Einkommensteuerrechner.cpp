// Einkommensteuerrechner.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Einkommensteuerrechner.h"

using namespace std;

typedef struct est23 {
	int stufe1 = 11693;
	int stufe2 = 19134;
	int stufe3 = 32075;
	int stufe4 = 62080;
	int stufe5 = 93120;
	int stufe6 = 1000000;
} EStTabelle2023_t;

typedef struct est24 {
	int stufe1 = 12816;
	int stufe2 = 20818;
	int stufe3 = 34513;
	int stufe4 = 66612;
	int stufe5 = 99266;
	int stufe6 = 1000000;
} EStTabelle2024_t;

typedef enum {
	e2023ProzentStufe1 = 20,
	e2023ProzentStufe2 = 30,
	e2023ProzentStufe3 = 48,
	e2023ProzentStufe4 = 41,
	e2023ProzentStufe5 = 50,
	e2023ProzentStufe6 = 55,
} eProzent2023;

float getESt2023(float income)
{
	float est = 0;
	EStTabelle2023_t est2023;
	if (income > est2023.stufe6) {
		est += (income - est2023.stufe6) * e2023ProzentStufe6 / 100;
		income = est2023.stufe6;
	}
	if (income > est2023.stufe5) {
		est += (income - est2023.stufe5) * e2023ProzentStufe5 / 100;
		income = est2023.stufe5;
	}
	if (income > est2023.stufe4) {
		est += (income - est2023.stufe4) * e2023ProzentStufe4 / 100;
		income = est2023.stufe4;
	}
	if (income > est2023.stufe3) {
		est += (income - est2023.stufe3) * e2023ProzentStufe3 / 100;
		income = est2023.stufe3;
	}
	if (income > est2023.stufe2) {
		est += (income - est2023.stufe2) * e2023ProzentStufe2 / 100;
		income = est2023.stufe2;
	}
	if (income > est2023.stufe1) {
		est += (income - est2023.stufe1) * e2023ProzentStufe1 / 100;
		income = est2023.stufe1;
	}

	return est;
}

int main()
{
	cout << "Bitte Bruttoverdienst eingeben" << endl;
	float income;
	cin >> income;
	float est = getESt2023(income);
	cout << "est is " << est << endl;

	
	



	return 0;
}
