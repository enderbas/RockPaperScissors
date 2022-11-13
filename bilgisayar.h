#ifndef BILGISAYAR_H
#define BILGISAYAR_H

#include "oyuncu.h"

class Bilgisayar : public Oyuncu
{
public:
	Bilgisayar();
	Bilgisayar(QString oyuncuId, QString oyuncuAdi, int skor);

	QString oyuncuIdpc;
	int skorPc;
	QString oyuncuAdipc;
	void super();
};
#endif // BILGISAYAR_H
