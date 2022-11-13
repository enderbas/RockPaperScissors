#include "tas.h"

tas::tas()
{
	setKatilik(2);
}

tas::tas(int dayaniklilikP, int seviyePuani)
{
	setKatilik(2);
	super(dayaniklilikP, seviyePuani);
}

double tas::etkiHesapla(Nesne *rakip)
{
	if((rakip->type == Nesne::TAS) || (rakip->type == Nesne::AGIRTAS))
		return 0;
	double result;
	result = (getKatilik() * getSicaklik()) /
				 ((aDegeri * rakip->getKeskinlik() * rakip->getDirenc()) +
			 ((1 - aDegeri) * rakip->getNufuz() * rakip->getKalinlik()));
	return result;
}
