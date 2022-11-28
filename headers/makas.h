#ifndef MAKAS_H
#define MAKAS_H

#include "nesne.h"

class Makas : public Nesne
{
public:
	Makas();
	Makas(int dayaniklilikP, int seviyePuani);

	double etkiHesapla(Nesne *rakip) override;
};

#endif // MAKAS_H
