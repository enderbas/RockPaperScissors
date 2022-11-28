#include "Nesne.h"

Nesne::Nesne()
{
}

Nesne::Nesne(int dayaniklilikP, int seviyePuani)
{
	super(dayaniklilikP, seviyePuani);
}

void Nesne::super(int dayaniklilikP, int seviyePuani)
{
	dayaniklilik = dayaniklilikP;
	seviye = seviyePuani;
}

QPair<int, int> Nesne::nesnePuaniGoster()
{
	return {seviye, dayaniklilik};
}

double Nesne::etkiHesapla(Nesne *rakip)
{
	return -1;
}

void Nesne::durumGuncelle(int etkiDegeri, Nesne *rakip)
{
	dayaniklilik = dayaniklilik - etkiDegeri;
	if(dayaniklilik < 0) {
		rakip->setSeviye(20);
	}
}

void Nesne::setNufuz(int newNufuz)
{
	nufuz = newNufuz;
}

int Nesne::getDayaniklilik() const
{
	return dayaniklilik;
}

void Nesne::setDayaniklilik(int newDayaniklilik)
{
	dayaniklilik = newDayaniklilik;
}

int Nesne::getSeviye() const
{
	return seviye;
}

void Nesne::setSeviye(int newSeviye)
{
	if(terfiDurdur) {
		terfiEttiMi = false;
		seviye = seviye + newSeviye;
		return;
	}
	seviye = seviye + newSeviye;
	if((seviye > 30) && !terfiEttiMi) {
		terfiEttiMi = true;
		terfiDurdur = true;
		switch (type) {
		case Nesne::TAS:
			sicaklik = sicaklik + 1;
			break;
		case Nesne::KAGIT:
			kalinlik = kalinlik + 1;
			break;
		case Nesne::MAKAS:
			direnc = direnc + 1;
			break;
		default:
			break;
		}
	}
}

int Nesne::getDirenc() const
{
	return direnc;
}

void Nesne::setDirenc(int newDirenc)
{
	direnc = newDirenc;
}

int Nesne::getKalinlik() const
{
	return kalinlik;
}

void Nesne::setKalinlik(int newKalinlik)
{
	kalinlik = newKalinlik;
}

int Nesne::getSicaklik() const
{
	return sicaklik;
}

void Nesne::setSicaklik(int newSicaklik)
{
	sicaklik = newSicaklik;
}

bool Nesne::getElendiMi() const
{
	if(dayaniklilik <= 0)
		return true;
	return false;
}

bool Nesne::getTerfiEttiMi() const
{
	return terfiEttiMi;
}

int Nesne::getNufuz() const
{
	return nufuz;
}

int Nesne::getKatilik() const
{
	return katilik;
}

void Nesne::setKatilik(int newKatilik)
{
	katilik = newKatilik;
}

int Nesne::getKeskinlik() const
{
	return keskinlik;
}

void Nesne::setKeskinlik(int newKeskinlik)
{
	keskinlik = newKeskinlik;
}
