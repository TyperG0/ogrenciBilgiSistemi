#include "Ogrenci.h";
#include <list>

void showMenu()
{
	cout << endl << endl;

	cout << "* * * * * * * * * *" << endl;
	cout << "* *             * *" << endl;
	cout << "* *	MEN�    * *" << endl;
	cout << "* *             * *" << endl;
	cout << "* * * * * * * * * *" << endl;

	cout << endl << endl;
	
	cout << "1. Yeni Kay�t Ekle " << endl;
	cout << "2. T�m Listeleri G�ster " << endl;
	cout << "3. ��renci id'ye G�re Kay�t Sil " << endl;
	cout << "4. ��renci Ara " << endl;
	cout << "5. ��k�� " << endl;
	
	cout << endl << endl;

}

void ogrenciEkle(list<Ogrenci>*lst)
{
	int id, sinavNot;
	string ad,soyad,isim;
	
	cout << "L�tfen ��renci id giriniz: ";
	cin >> id;

	cout << "L�tfen ��renci ad giriniz: ";
	cin >> ad;

	cout << "L�tfen ��renci soyad giriniz: ";
	cin >> soyad;

	isim = ad + " " + soyad;

	cout << "L�tfen ��renci s�nav notunu giriniz: ";
	cin >> sinavNot;

	Ogrenci ogr(id, isim, sinavNot);
	lst->push_back(ogr);
}

void showList(list<Ogrenci>* lst)
{
	list<Ogrenci>::iterator it;

	cout << endl << "- - - - - T�m ��renci Listesi - - - - -" << endl;

	for (it = lst->begin(); it != lst->end(); it++)
	{
		it->bilgileriGetir();
	}
	cout << endl;
}

void kayitSil(list<Ogrenci>*lst)
{
	int id;
	cout << "L�tfen silinicek olan ��rencini id giriniz: ";
	cin >> id;

	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++)
	{
		if (it->getId() == id)
		{
			cout <<endl<< id << " id'li ��rencini kayd� silindi! " << endl;
			break;
		}
	}
	if (it == lst->end())
		cout << "Hatal� id girdiniz!!!" << endl;
	else
		lst->erase(it);

	

}

void ogrenciAra(list<Ogrenci>* lst)
{
	int id;
	cout << "L�tfen aramak istedi�iniz ��rencini id giriniz: ";
	cin >> id;

	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++)
	{
		if (it->getId() == id)
		{
			cout << endl << id << " id'li ��rencini bilgileri: " << endl;
			it->bilgileriGetir();
			break;
		}
	}
	if (it == lst->end())
		cout << "Hatal� id girdiniz!!!" << endl;

}

int main() 
{
	setlocale(LC_ALL, "turkish");

	list<Ogrenci>* ogrenciList = new list<Ogrenci>();


	int secim = 0;

	do {
		showMenu();
		cout << "Yapmak �stedi�iniz ��lem: ";
		cin >> secim;

		if (secim == 1)
			ogrenciEkle(ogrenciList);
		else if (secim == 2)
			showList(ogrenciList);
		else if (secim == 3)
			kayitSil(ogrenciList);
		else if (secim == 4)
			ogrenciAra(ogrenciList);
		else if (secim == 5)
			break;
		else
			cout << "Hatal� se�im yapt�n�z, yeniden deneyiniz!";

	} while (secim != 5);






	return 0;
}