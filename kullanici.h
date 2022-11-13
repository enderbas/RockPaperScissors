#ifndef KULLANICI_H
#define KULLANICI_H

#include "oyuncu.h"

class Kullanici : public Oyuncu
{
public:
	Kullanici();
	Kullanici(int oyuncuId, QString oyuncuAdi, int skor);

	QString oyuncuIdk;
	int skorK;
	QString oyuncuAdiK;
	void super();
};

#endif // KULLANICI_H
