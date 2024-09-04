#include "Ogrenci.h";

Ogrenci::Ogrenci(int _id, string _ad, int _sinavNot)
{
	id = _id;
	ad = _ad;
	sinavNot = _sinavNot;

}

void Ogrenci::setId(int _ýd)
{
	id = _ýd;
}

void Ogrenci::setAd(string _ad)
{
	ad = _ad;
}

void Ogrenci::setSinavNot(int _sinavNot)
{
	sinavNot = _sinavNot;
}

int Ogrenci::getId()
{
	return id;
}

string Ogrenci::getAd()
{
	return ad;
}

int Ogrenci::getSinavNot()
{
	return sinavNot;
}

void Ogrenci::bilgileriGetir()
{
	cout << endl;
	cout << "Id: " << id << endl;
	cout << "Ad: " << ad << endl;
	cout<<"Sýnav Notu: " << sinavNot << endl;
}