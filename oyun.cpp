#include "oyun.h"
#include "agirtas.h"
#include "bilgisayar.h"
#include "kagit.h"
#include "kullanici.h"
#include "makas.h"
#include "nesne.h"
#include "ozelkagit.h"
#include "tas.h"
#include "ui_oyun.h"
#include "ustamakas.h"

#include <QMessageBox>
#include <QTime>

Oyun::Oyun(QWidget *parent) : QMainWindow(parent), ui(new Ui::Oyun)
{
	ui->setupUi(this);
	ui->toolBackToMain->hide();
	ui->stackedWidget->setCurrentIndex(0);

	oyunSolButonListesi.push_back(ui->pushOyunNesne1);
	oyunSolButonListesi.push_back(ui->pushOyunNesne2);
	oyunSolButonListesi.push_back(ui->pushOyunNesne3);
	oyunSolButonListesi.push_back(ui->pushOyunNesne4);
	oyunSolButonListesi.push_back(ui->pushOyunNesne5);

	oyunSagButonListesi.push_back(ui->pushHide1);
	oyunSagButonListesi.push_back(ui->pushHide2);
	oyunSagButonListesi.push_back(ui->pushHide3);
	oyunSagButonListesi.push_back(ui->pushHide4);
	oyunSagButonListesi.push_back(ui->pushHide5);

	ui->pushHide1->hide();
	ui->pushHide2->hide();
	ui->pushHide3->hide();
	ui->pushHide4->hide();
	ui->pushHide5->hide();
	ui->labelHide->hide();
	ui->labelTur->hide();
	ui->spinTur->hide();
	ui->labelTur_2->hide();
	ui->spinTur_2->hide();
	ui->toolBackToMain->hide();
}

Oyun::~Oyun()
{
	delete ui;
}

void Oyun::on_toolUserPcSelection_clicked()
{
	oyuncuSol = new Kullanici;
	oyuncuSag = new Bilgisayar;
	for (int i = 0; i < 5; i++) {
		createNesneButton(oyuncuSag, oyunSagButonListesi.at(i));
	}
	pcpc = false;
	ui->toolBackToMain->setVisible(true);
	ui->stackedWidget->setCurrentIndex(PAGES::NESNESECME);
	ui->pushOyunNesne1->show();
	ui->pushOyunNesne2->show();
	ui->pushOyunNesne3->show();
	ui->pushOyunNesne4->show();
	ui->pushOyunNesne5->show();
	ui->label_10->show();
}

void Oyun::on_toolPCPCSelection_clicked()
{
	oyuncuSol = new Bilgisayar;
	oyuncuSag = new Bilgisayar;
	for (int i = 0; i < 5; i++) {
		createNesneButton(oyuncuSol, oyunSolButonListesi.at(i));
		createNesneButton(oyuncuSag, oyunSagButonListesi.at(i));
	}

	pcpc = true;
	ui->toolBackToMain->setVisible(true);
	ui->stackedWidget->setCurrentIndex(PAGES::YARISMACIBILGI);
	ui->pushOyunNesne1->hide();
	ui->pushOyunNesne2->hide();
	ui->pushOyunNesne3->hide();
	ui->pushOyunNesne4->hide();
	ui->pushOyunNesne5->hide();
	ui->label_10->hide();

	ui->pushHide1->hide();
	ui->pushHide2->hide();
	ui->pushHide3->hide();
	ui->pushHide4->hide();
	ui->pushHide5->hide();
	ui->labelHide->hide();
}

void Oyun::on_toolBackToMain_clicked()
{
	ui->stackedWidget->setCurrentIndex(PAGES::ANASAYFA);
	ui->toolBackToMain->hide();
	clearGame();
}

void Oyun::on_pushBasla_clicked()
{
	if(oyuncuSol->nesneListesi.size() != 5) {
		QMessageBox msgBox;
		msgBox.setText("Bes tane nesne secmeniz gerekmekte.");
		msgBox.exec();
		return;
	}
	ui->stackedWidget->setCurrentIndex(PAGES::YARISMACIBILGI);
	for (int i = 0; i < 5; i++) {
		setName(oyunSolButonListesi.at(i), oyuncuSol->nesneSec(i)->type);
	}
	puanYenile();
}

void Oyun::on_pushTasSec_clicked()
{
	if (secimSayisi < 5) {
		ui->labelSecimler->setText(ui->labelSecimler->text() + " Tas");
		secimSayisi++;
		auto *n = new tas;
		n->type = tas::TAS;
		oyuncuSol->nesneListesi.push_back(n);
	}
}

void Oyun::on_pushKagiSec_clicked()
{
	if (secimSayisi < 5) {
		ui->labelSecimler->setText(ui->labelSecimler->text() + " Kagit");
		secimSayisi++;
		auto *n = new kagit;
		n->type = kagit::KAGIT;
		oyuncuSol->nesneListesi.push_back(n);
	}
}

void Oyun::on_pushMakasSec_clicked()
{
	if (secimSayisi < 5) {
		ui->labelSecimler->setText(ui->labelSecimler->text() + " Makas");
		secimSayisi++;
		auto *n = new Makas;
		n->type = Makas::MAKAS;
		oyuncuSol->nesneListesi.push_back(n);
	}
}

void Oyun::on_pushYenidenSec_clicked()
{
	ui->labelSecimler->setText("");
	secimSayisi = 0;
	oyuncuSol->nesneListesi.clear();
}

void Oyun::clearGame()
{
	ui->labelSecimler->setText("");
	secimSayisi = 0;
	turSayisi = 0;

	oyuncuSag->nesneListesi.clear();
	oyuncuSag->blokluNesneler.clear();
	oyuncuSag->elenenNesneler.clear();

	oyuncuSol->nesneListesi.clear();
	oyuncuSol->blokluNesneler.clear();
	oyuncuSol->elenenNesneler.clear();

	ui->labelStatusLeft->clear();
	ui->labelStatusRight->clear();
	ui->pushLeftMoveNoClick->setText("");
	ui->pushRightMoveNoClick->setText("");
	ui->labelSagSkor->setText("");
	ui->labelSolSkor->setText("");
	for (int i = 0; i < 5; i++) {
		setName(oyunSolButonListesi.at(i), Nesne::NONE);
		setName(oyunSagButonListesi.at(i), Nesne::NONE);
	}
	toplamTurSayisi = ui->spinTur->value();
}

void Oyun::setName(QPushButton *pb, Nesne::TURLER tur)
{
	switch (tur) {
	case Nesne::AGIRTAS:
		pb->setText("AGIR TAS");
		break;
	case Nesne::USTAMAKAS:
		pb->setText("USTA MAKAS");
		break;
	case Nesne::OZELKAGIT:
		pb->setText("OZEL KAGIT");
		break;
	case Nesne::NONE:
		pb->setText("");
		break;
	case Nesne::KAGIT:
		pb->setText("KAGIT");
		break;
	case Nesne::MAKAS:
		pb->setText("MAKAS");
		break;
	case Nesne::TAS:
		pb->setText("TAS");
		break;
	default:
		break;
	}
}

void Oyun::createNesneButton(Oyuncu *p, QPushButton *buton)
{
	auto n = randNesneUret();
	p->nesneListesi.push_back(n);
	setName(buton, n->type);
}

int Oyun::randInt(int low, int high)
{
	return qrand() % ((high + 1) - low) + low;
}

Nesne *Oyun::randNesneUret()
{
	Nesne::TURLER tur;
	Nesne *p;
	for (int i = 0; i < 5; i++) {
		int val = randInt(0, 2);
		tur = (Nesne::TURLER)val;
		switch (tur) {
		case Nesne::TAS:
			p = new tas;
			p->type = Nesne::TAS;
			break;
		case Nesne::KAGIT:
			p = new kagit;
			p->type = Nesne::KAGIT;
			break;
		case Nesne::MAKAS:
			p = new Makas;
			p->type = Nesne::MAKAS;
			break;
		default:
			break;
		}
	}
	return p;
}

void Oyun::terfi(Nesne *n, QPushButton *pb)
{
	Nesne::TURLER type = n->type;
	switch (type) {
	case Nesne::TAS:
		n = new AgirTas;
		n->type = Nesne::AGIRTAS;
		pb->setText("Agir Tas");
		break;
	case Nesne::KAGIT:
		n = new OzelKagit;
		n->type = Nesne::OZELKAGIT;
		pb->setText("Ozel Kagit");
		break;
	case Nesne::MAKAS:
		n = new UstaMakas;
		n->type = Nesne::USTAMAKAS;
		pb->setText("Usta Makas");
		break;
	case Nesne::NONE:
		break;
	default:
		break;
	}
}

void Oyun::puanYenile()
{
	for (int i = 0; i < 5; i++) {
		int seviye = oyuncuSol->nesneListesi.at(i)->nesnePuaniGoster().first;
		int dayaniklilik =
			oyuncuSol->nesneListesi.at(i)->nesnePuaniGoster().second;
		QString mes = QString("Seviye: %1 Dayaniklilik: %2")
						  .arg(seviye)
						  .arg(dayaniklilik);
		oyunSolButonListesi.at(i)->setToolTip(mes);

		seviye = oyuncuSag->nesneListesi.at(i)->nesnePuaniGoster().first;
		dayaniklilik = oyuncuSag->nesneListesi.at(i)->nesnePuaniGoster().second;
		mes = QString("Seviye: %1 Dayaniklilik: %2")
				  .arg(seviye)
				  .arg(dayaniklilik);
		oyunSagButonListesi.at(i)->setToolTip(mes);
	}

	int seviye =
		oyuncuSol->nesneListesi.at(solCurrentIndex)->nesnePuaniGoster().first;
	int dayaniklilik =
		oyuncuSol->nesneListesi.at(solCurrentIndex)->nesnePuaniGoster().second;
	QString mes =
		QString("Seviye: %1 Dayaniklilik: %2").arg(seviye).arg(dayaniklilik);
	ui->pushLeftMoveNoClick->setToolTip(mes);

	seviye =
		oyuncuSag->nesneListesi.at(sagCurrentIndex)->nesnePuaniGoster().first;
	dayaniklilik =
		oyuncuSag->nesneListesi.at(sagCurrentIndex)->nesnePuaniGoster().second;
	mes = QString("Seviye: %1 Dayaniklilik: %2").arg(seviye).arg(dayaniklilik);
	ui->pushRightMoveNoClick->setToolTip(mes);
}

void Oyun::oyunSonu()
{
	int puanSag = 0;
	for(int i = 0 ; i < oyuncuSag->nesneListesi.size() ; i++) {
		if(oyuncuSag->elenenNesneler.contains(i))
			continue;
		puanSag = puanSag + oyuncuSag->nesneSec(i)->getDayaniklilik();
	}

	int puanSol = 0;
	for(int i = 0 ; i < oyuncuSol->nesneListesi.size() ; i++) {
		if(oyuncuSol->elenenNesneler.contains(i))
			continue;
		puanSol = puanSol + oyuncuSol->nesneSec(i)->getDayaniklilik();
	}
	QMessageBox msgBox;
	if(puanSag > puanSol) {
		msgBox.setText("Sag taraf kazandi");
		oyuncuSag->setSkor(puanSag);
	} else {
		msgBox.setText("Sol taraf kazandi");
		oyuncuSol->setSkor(puanSol);
	}
	ui->labelSagSkor->setText(QString::number(puanSag));
	ui->labelSolSkor->setText(QString::number(puanSol));
	ui->pushDevam->hide();
	msgBox.exec();
	return;
}

Nesne *Oyun::randNesneSec(Oyuncu *p, QPushButton *pb, bool isLeft = false)
{
	int index;
	do {
		index = randInt(0, 4);
	} while (p->blokluNesneler.contains(index) ||
			 p->elenenNesneler.contains(index));

	setName(pb, p->nesneSec(index)->type);
	if (!isLeft)
		sagCurrentIndex = index;
	else
		solCurrentIndex = index;
	return p->nesneSec(index);
}

void Oyun::solIcinNesneSec(int index)
{
	if(pcpc)
		return;
	if ((oyuncuSol->blokluNesneler.size() != 4) &&
		oyuncuSol->blokluNesneler.contains(index)) {
		QMessageBox msgBox;
		msgBox.setText("Tum nesneler secilmeden ayni nesne secilemez");
		msgBox.exec();
		return;
	}
	setName(ui->pushLeftMoveNoClick, oyuncuSol->nesneListesi.at(index)->type);
	solCurrentIndex = index;
	isPlayed = true;
}

void Oyun::on_pushOyunNesne1_clicked()
{
	solIcinNesneSec(0);
}

void Oyun::on_pushOyunNesne2_clicked()
{
	solIcinNesneSec(1);
}

void Oyun::on_pushOyunNesne3_clicked()
{
	solIcinNesneSec(2);
}

void Oyun::on_pushOyunNesne4_clicked()
{
	solIcinNesneSec(3);
}

void Oyun::on_pushOyunNesne5_clicked()
{
	solIcinNesneSec(4);
}

void Oyun::on_pushDevam_clicked()
{
	if (!pcpc) {
		if (!isPlayed) {
			QMessageBox msgBox;
			msgBox.setText("Sizin Siraniz");
			msgBox.exec();
			return;
		}
	}

	Nesne *sagNesne = randNesneSec(oyuncuSag, ui->pushRightMoveNoClick, false);
	Nesne *solNesne;
	if (pcpc) {
		solNesne = randNesneSec(oyuncuSol, ui->pushLeftMoveNoClick, true);
	} else {
		solNesne = oyuncuSol->nesneSec(solCurrentIndex);
		setName(ui->pushLeftMoveNoClick, solNesne->type);
	}

	oyuncuSol->blokluNesneler.push_back(solCurrentIndex);
	oyuncuSag->blokluNesneler.push_back(sagCurrentIndex);
	turSayisi++;
	isPlayed = false;
	double solEtki = solNesne->etkiHesapla(sagNesne);
	double sagEtki = sagNesne->etkiHesapla(solNesne);
	ui->labelStatusLeft->setText("-" + QString::number(sagEtki));
	ui->labelStatusRight->setText("-" + QString::number(solEtki));
	sagNesne->durumGuncelle(solEtki, solNesne);
	solNesne->durumGuncelle(sagEtki, sagNesne);

	if (solNesne->getElendiMi()) {
		oyunSolButonListesi.at(solCurrentIndex)->setEnabled(false);
		oyuncuSol->elenenNesneler.push_back(solCurrentIndex);
	}
	if (solNesne->getTerfiEttiMi()) {
		terfi(oyuncuSol->nesneListesi[solCurrentIndex],
			  oyunSolButonListesi.at(solCurrentIndex));
	}

	if (sagNesne->getElendiMi()) {
		oyunSagButonListesi.at(sagCurrentIndex)->setEnabled(false);
		oyuncuSag->elenenNesneler.push_back(sagCurrentIndex);
	}
	if (sagNesne->getTerfiEttiMi()) {
		terfi(oyuncuSag->nesneListesi[sagCurrentIndex],
			  oyunSagButonListesi.at(sagCurrentIndex));
	}

	puanYenile();
	if (((oyuncuSol->blokluNesneler.count() +
		  oyuncuSol->elenenNesneler.count()) >= 5) ||
		(oyuncuSag->blokluNesneler.count() +
		 oyuncuSag->elenenNesneler.count()) >= 5) {
		oyuncuSol->blokluNesneler.clear();
		oyuncuSag->blokluNesneler.clear();
	}
	if ((oyuncuSol->elenenNesneler.count() == 5) ||
		oyuncuSag->elenenNesneler.count() == 5) {
		oyunSonu();
		return;
	}

	int kalanHamle = toplamTurSayisi - turSayisi;
	QString mes = QString("Tur: %1 / %2").arg(kalanHamle).arg(toplamTurSayisi);
	ui->labelHamle->setText(mes);

	if (turSayisi == toplamTurSayisi) {
		QMessageBox msgBox;
		msgBox.setText("Tur Sayisi Tukendi");
		msgBox.exec();
		oyunSonu();
		return;
	}
}

void Oyun::on_pushPrivilageMode_clicked()
{
	ui->labelTur->show();
	ui->spinTur->show();
	ui->labelHide->show();
	ui->pushHide1->show();
	ui->pushHide2->show();
	ui->pushHide3->show();
	ui->pushHide4->show();
	ui->pushHide5->show();

	ui->pushOyunNesne1->show();
	ui->pushOyunNesne2->show();
	ui->pushOyunNesne3->show();
	ui->pushOyunNesne4->show();
	ui->pushOyunNesne5->show();
	ui->label_10->show();

	ui->labelTur_2->show();
	ui->spinTur_2->show();
}

void Oyun::on_pushOyuncuKayit_clicked()
{
	oyuncuSol->setOyuncuAdi(ui->lineLeftName->text());
	oyuncuSol->setOyuncuID(ui->lineLeftID->text());
	oyuncuSag->setOyuncuAdi(ui->lineRightName->text());
	oyuncuSag->setOyuncuID(ui->lineRightID->text());

	ui->labelSolOyuncuAdi->setText(oyuncuSol->getOyuncuAdi());
	ui->labelSolOyuncuID->setText(oyuncuSol->getOyuncuID());
	ui->labelSagOyuncuAdi->setText(oyuncuSag->getOyuncuAdi());
	ui->labelSagOyuncuID->setText(oyuncuSag->getOyuncuID());

	if(ui->spinTur_2->value())
		toplamTurSayisi = ui->spinTur_2->value();
	else {
		toplamTurSayisi = ui->spinTur->value();
	}
	int kalanHamle = toplamTurSayisi - turSayisi;
	QString mes = QString("Tur: %1 / %2").arg(kalanHamle).arg(toplamTurSayisi);
	ui->labelHamle->setText(mes);

	ui->stackedWidget->setCurrentIndex(PAGES::OYUNALANI);
}
