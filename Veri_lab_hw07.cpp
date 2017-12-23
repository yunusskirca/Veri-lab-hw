#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std;

void paraEkle(int para[]) {

	char menu;
	while (1) {
		system("cls");
		cout << "\t1- |TL(200)TL|  x" << para[0] << endl;
		cout << "\t2- |TL(100)TL|  x" << para[1] << endl;
		cout << "\t3- |TL(50)TL|   x" << para[2] << endl;
		cout << "\t4- |TL(20)TL|   x" << para[3] << endl;
		cout << "\t5- |TL(10)TL|   x" << para[4] << endl;
		cout << "\t6- |TL(5)TL|    x" << para[5] << endl << endl;
		cout << "\t0- ANA MENÜ" << endl << endl;
		cout << "Eklemek istediğiniz paranın başındaki sayıya basınız." << endl;

		menu = _getch();

		if (menu == '1') {
			system("cls");
				para[0]++;
		}
		else if (menu == '2') {
			system("cls");
				para[1]++;
		}
		else if (menu == '3') {
			system("cls");
				para[2]++;
		}
		else if (menu == '4') {
			system("cls");
				para[3]++;
		}
		else if (menu == '5') {
			system("cls");
				para[4]++;
		}
		else if (menu == '6') {
			system("cls");
				para[5]++;
		}
		else if (menu == '0')
			break;
	}
}

void paraCikar(int para[]) {

	char menu;
	while (1) {
		system("cls");
		cout << "\t1- |TL(200)TL|  x" << para[0] << endl;
		cout << "\t2- |TL(100)TL|  x" << para[1] << endl;
		cout << "\t3- |TL(50)TL|   x" << para[2] << endl;
		cout << "\t4- |TL(20)TL|   x" << para[3] << endl;
		cout << "\t5- |TL(10)TL|   x" << para[4] << endl;
		cout << "\t6- |TL(5)TL|    x" << para[5] << endl << endl;
		cout << "\t0- ANA MENÜ" << endl << endl;
		cout << "Çıkarmak istediğiniz paranın başındaki sayıya basınız." << endl;

		menu = _getch();

		if (menu == '1') {
			system("cls");
			if (para[0] > 0)
				para[0]--;
		}
		else if (menu == '2') {
			system("cls");
			if (para[1] > 0)
				para[1]--;
		}
		else if (menu == '3') {
			system("cls");
			if (para[2] > 0)
				para[2]--;
		}
		else if (menu == '4') {
			system("cls");
			if (para[3] > 0)
				para[3]--;
		}
		else if (menu == '5') {
			system("cls");
			if (para[4] > 0)
				para[4]--;
		}
		else if (menu == '6') {
			system("cls");
			if (para[5] > 0)
				para[5]--;
		}
		else if (menu == '0')
			break;
	}
}

int toplam(int para[], int banknot[]) {
	int toplamPara = 0;
	
	for (int i = 0; i < 6; i++) {
		toplamPara += para[i] * banknot[i];
	}
	return toplamPara;
}

void enAzBanknot(int para[], int banknot[]) {
	int miktar;
	int adet[6] = { 0,0,0,0,0,0 };
	bool flag = false;
	if (toplam(para, banknot) < 1) {
		cout << "Elde hiç para yok" << endl;
		cout << "Ana menüye dönmek için bir tuşa basınız." << endl;
		_getch();
		return;
	}
	do {
		system("cls");
		if (flag) {
			cout << "Miktar negatif veya eldeki paradan büyük olamaz." << endl;
		}
		cout << "Eldeki para : " << toplam(para, banknot) << endl;
		cout << "Miktar giriniz : ";
		cin >> miktar;
		flag = true;
	} while (toplam(para, banknot) < miktar || miktar < 0);

	system("cls");

	cout << miktar << " TL en az banknotla aşağıdaki şekilde hesaplanabilir." << endl << endl;

	// -5 beyin yaktı mı ? :D ama doru
	if (miktar % 5 != 0)
		miktar -= (miktar % 5) - 5;
	for (int i = 5; i >= 0; i--) {
		if (para[i] == 0)
			miktar += banknot[i];
		else
			break;
	}

	for (int i = 0; i < 6;) {
		if (miktar >= banknot[i] && para[i] > adet[i]) {
			adet[i]++;
			miktar -= banknot[i];
		}
		else
			i++;
	}

	cout << "ELDEKİ : " << endl;
	cout << "\t|TL(200)TL|  x" << para[0] << endl;
	cout << "\t|TL(100)TL|  x" << para[1] << endl;
	cout << "\t|TL(50)TL|   x" << para[2] << endl;
	cout << "\t|TL(20)TL|   x" << para[3] << endl;
	cout << "\t|TL(10)TL|   x" << para[4] << endl;
	cout << "\t|TL(5)TL|    x" << para[5] << endl << endl << endl;

	cout << "HESAPLANAN :" << endl;
	cout << "\t|TL(200)TL|  x" << adet[0] << endl;
	cout << "\t|TL(100)TL|  x" << adet[1] << endl;
	cout << "\t|TL(50)TL|   x" << adet[2] << endl;
	cout << "\t|TL(20)TL|   x" << adet[3] << endl;
	cout << "\t|TL(10)TL|   x" << adet[4] << endl;
	cout << "\t|TL(5)TL|    x" << adet[5] << endl << endl << endl;

	cout << "Ana menüye dönmek için bir tuşa basınız." << endl;
	_getch();
}

void enFazlaBanknot(int para[], int banknot[]) {
	int miktar;
	int adet[6];
	bool flag = false;
	if (toplam(para, banknot) < 1) {
		cout << "Elde hiç para yok" << endl;
		cout << "Ana menüye dönmek için bir tuşa basınız." << endl;
		_getch();
		return;
	}
	do {
		system("cls");
		if (flag) {
			cout << "Miktar negatif veya eldeki paradan büyük olamaz." << endl;
		}
		cout << "Eldeki para : " << toplam(para, banknot) << endl;
		cout << "Miktar giriniz : ";
		cin >> miktar;
		flag = true;
	} while (toplam(para, banknot) < miktar || miktar < 0);

	system("cls");

	cout << miktar << " TL en fazla banknotla aşağıdaki şekilde hesaplanabilir." << endl << endl;

	if (miktar % 5 != 0)
		miktar -= (miktar % 5) - 5;

	for (int i = 0; i < 6; i++) 
		adet[i] = para[i];
	
	
	for (int i = 0; i < 6;) {
		if (toplam(adet, banknot) > miktar && adet[i] > 0) {
			adet[i]--;
		}
		else
			i++;
	}


	cout << "ELDEKİ : " << endl;
	cout << "\t|TL(200)TL|  x" << para[0] << endl;
	cout << "\t|TL(100)TL|  x" << para[1] << endl;
	cout << "\t|TL(50)TL|   x" << para[2] << endl;
	cout << "\t|TL(20)TL|   x" << para[3] << endl;
	cout << "\t|TL(10)TL|   x" << para[4] << endl;
	cout << "\t|TL(5)TL|    x" << para[5] << endl << endl << endl;

	cout << "HESAPLANAN :" << endl;
	cout << "\t|TL(200)TL|  x" << adet[0] << endl;
	cout << "\t|TL(100)TL|  x" << adet[1] << endl;
	cout << "\t|TL(50)TL|   x" << adet[2] << endl;
	cout << "\t|TL(20)TL|   x" << adet[3] << endl;
	cout << "\t|TL(10)TL|   x" << adet[4] << endl;
	cout << "\t|TL(5)TL|    x" << adet[5] << endl << endl << endl;

	cout << "Ana menüye dönmek için bir tuşa basınız." << endl;
	_getch();
}

void main() {
	setlocale(LC_ALL, "turkish");
	system("color 0f");

	int banknot[] = { 200,100,50,20,10,5 };
	int para[6] = { 0,0,0,0,0,0 };


	char menu;
	while (1) {
		system("cls");
		cout << "\t|TL(200)TL|  x" << para[0] << endl;
		cout << "\t|TL(100)TL|  x" << para[1] << endl;
		cout << "\t|TL(50)TL|   x" << para[2] << endl;
		cout << "\t|TL(20)TL|   x" << para[3] << endl;
		cout << "\t|TL(10)TL|   x" << para[4] << endl;
		cout << "\t|TL(5)TL|    x" << para[5] << endl << endl << endl;


		cout << "\t-ANA MENÜ-" << endl << endl
			<< "\t 1- PARA EKLE" << endl
			<< "\t 2- PARA ÇIKAR" << endl
			<< "\t 3- EN AZ BANKNOT" << endl
			<< "\t 4- EN FAZLA BANKNOT" << endl
			<< "\t X- ÇIKIŞ!";

		menu = _getch();

		if (menu == '1') {
			system("cls");
			paraEkle(para);
		}
		else if (menu == '2') {
			system("cls");
			paraCikar(para);
		}
		else if (menu == '3') {
			system("cls");
			enAzBanknot(para, banknot);

		}
		else if (menu == '4') {
			system("cls");
			enFazlaBanknot(para, banknot);
		}

		else if (menu == 'X' || menu == 'x')
			break;
	}

}