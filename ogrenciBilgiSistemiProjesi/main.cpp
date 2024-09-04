#include "Ogrenci.h";
#include <list>

void showMenu()
{
	cout << endl << endl;

	cout << "* * * * * * * * * *" << endl;
	cout << "* *             * *" << endl;
	cout << "* *	MENÜ    * *" << endl;
	cout << "* *             * *" << endl;
	cout << "* * * * * * * * * *" << endl;

	cout << endl << endl;
	
	cout << "1. Yeni Kayýt Ekle " << endl;
	cout << "2. Tüm Listeleri Göster " << endl;
	cout << "3. Öðrenci id'ye Göre Kayýt Sil " << endl;
	cout << "4. Öðrenci Ara " << endl;
	cout << "5. Çýkýþ " << endl;
	
	cout << endl << endl;

}

void ogrenciEkle(list<Ogrenci>*lst)
{
	int id, sinavNot;
	string ad,soyad,isim;
	
	cout << "Lütfen öðrenci id giriniz: ";
	cin >> id;

	cout << "Lütfen öðrenci ad giriniz: ";
	cin >> ad;

	cout << "Lütfen öðrenci soyad giriniz: ";
	cin >> soyad;

	isim = ad + " " + soyad;

	cout << "Lütfen öðrenci sýnav notunu giriniz: ";
	cin >> sinavNot;

	Ogrenci ogr(id, isim, sinavNot);
	lst->push_back(ogr);
}

void showList(list<Ogrenci>* lst)
{
	list<Ogrenci>::iterator it;

	cout << endl << "- - - - - Tüm Öðrenci Listesi - - - - -" << endl;

	for (it = lst->begin(); it != lst->end(); it++)
	{
		it->bilgileriGetir();
	}
	cout << endl;
}

void kayitSil(list<Ogrenci>*lst)
{
	int id;
	cout << "Lütfen silinicek olan öðrencini id giriniz: ";
	cin >> id;

	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++)
	{
		if (it->getId() == id)
		{
			cout <<endl<< id << " id'li öðrencini kaydý silindi! " << endl;
			break;
		}
	}
	if (it == lst->end())
		cout << "Hatalý id girdiniz!!!" << endl;
	else
		lst->erase(it);

	

}

void ogrenciAra(list<Ogrenci>* lst)
{
	int id;
	cout << "Lütfen aramak istediðiniz öðrencini id giriniz: ";
	cin >> id;

	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++)
	{
		if (it->getId() == id)
		{
			cout << endl << id << " id'li öðrencini bilgileri: " << endl;
			it->bilgileriGetir();
			break;
		}
	}
	if (it == lst->end())
		cout << "Hatalý id girdiniz!!!" << endl;

}

int main() 
{
	setlocale(LC_ALL, "turkish");

	list<Ogrenci>* ogrenciList = new list<Ogrenci>();


	int secim = 0;

	do {
		showMenu();
		cout << "Yapmak Ýstediðiniz Ýþlem: ";
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
			cout << "Hatalý seçim yaptýnýz, yeniden deneyiniz!";

	} while (secim != 5);






	return 0;
}