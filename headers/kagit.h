#ifndef KAGIT_H
#define KAGIT_H

#include "nesne.h"

class kagit : public Nesne
{
public:
	kagit();
	kagit(int dayaniklilikP, int seviyePuani);

	double etkiHesapla(Nesne *rakip) override;
};

#endif // KAGIT_H
