#include "kagit.h"

kagit::kagit()
{
	setNufuz(2);
}

kagit::kagit(int dayaniklilikP, int seviyePuani)
{
	setNufuz(2);
	super(dayaniklilikP, seviyePuani);
}

double kagit::etkiHesapla(Nesne *rakip)
{
	if((rakip->type == Nesne::KAGIT) || (rakip->type == Nesne::OZELKAGIT))
		return 0;
	double result;
	result = (getNufuz() * getKalinlik()) /
			((aDegeri * rakip->getKatilik() * rakip->getSicaklik()) +
			 ((1 - aDegeri) * rakip->getKeskinlik() * rakip->getDirenc()));
	return result;
}
