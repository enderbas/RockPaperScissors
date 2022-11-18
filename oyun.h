#ifndef ROCKPAPERSCISSOR_H
#define ROCKPAPERSCISSOR_H

#include <QMainWindow>
#include <QPushButton>
#include "oyuncu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Oyun; }
QT_END_NAMESPACE

class Oyun : public QMainWindow
{
	Q_OBJECT

public:
	Oyun(QWidget *parent = nullptr);
	~Oyun();

private slots:
	void on_toolUserPcSelection_clicked();
	void on_toolPCPCSelection_clicked();
	void on_toolBackToMain_clicked();
	void on_pushBasla_clicked();
	void on_pushTasSec_clicked();
	void on_pushKagiSec_clicked();
	void on_pushMakasSec_clicked();
	void on_pushYenidenSec_clicked();
	void on_pushOyunNesne1_clicked();
	void on_pushOyunNesne2_clicked();
	void on_pushOyunNesne3_clicked();
	void on_pushOyunNesne4_clicked();
	void on_pushOyunNesne5_clicked();
	void on_pushDevam_clicked();
	void on_pushPrivilageMode_clicked();
	void on_pushOyuncuKayit_clicked();

private:
	Ui::Oyun *ui;
	Oyuncu *oyuncuSol = nullptr;
	Oyuncu *oyuncuSag = nullptr;

	QList<QPushButton*> oyunSolButonListesi;
	QList<QPushButton*> oyunSagButonListesi;
	QList<QPushButton*> blokluSolButonListesi;
	QList<QPushButton*> blokluSagButonListesi;
	QList<QPushButton*> elenenSolButonListesi;
	QList<QPushButton*> elenenSagButonListesi;

private:
	void clearGame();
	void setName(QPushButton *pb, Nesne::TURLER tur);
	void setPbIcon(QAbstractButton *pb, QString path, int size = 100);
	void createNesneButton(Oyuncu *p, QPushButton * buton);
	int randInt(int low, int high);
	Nesne *randNesneUret();
	Nesne* randNesneSec(Oyuncu *p, QPushButton *pb, bool isLeft);
	void solIcinNesneSec(int index);
	void terfi(Nesne *n, QPushButton *pb);
	void puanYenile();
	void oyunSonu();

private:
	bool isPlayed = false;
	bool pcpc = false;
	int solCurrentIndex = 0;
	int sagCurrentIndex = 0;
	int toplamTurSayisi = 0;
	int turSayisi = 0;
	int secimSayisi = 0;
	enum PAGES{
		ANASAYFA,
		YARISMACIBILGI,
		NESNESECME,
		OYUNALANI,
	};
};
#endif // ROCKPAPERSCISSOR_H
