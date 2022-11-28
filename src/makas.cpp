#include "makas.h"

Makas::Makas()
{
	setKeskinlik(2);
}

Makas::Makas(int dayaniklilikP, int seviyePuani)
{
	setKeskinlik(2);
	super(dayaniklilikP, seviyePuani);
}

double Makas::etkiHesapla(Nesne *rakip)
{
	if((rakip->type == Nesne::MAKAS) || (rakip->type == Nesne::USTAMAKAS))
		return 0;
	double result;
	result = (getKeskinlik() * getDirenc()) /
			((aDegeri * rakip->getNufuz() * rakip->getKalinlik()) +
			 (1 - aDegeri) * rakip->getKatilik() * rakip->getSicaklik());
	return result;
}
