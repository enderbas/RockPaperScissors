#ifndef TAS_H
#define TAS_H

#include "nesne.h"

class tas : public Nesne
{
public:
	tas();
	tas(int dayaniklilikP, int seviyePuani);

	double etkiHesapla(Nesne *rakip) override;
};

#endif // TAS_H
