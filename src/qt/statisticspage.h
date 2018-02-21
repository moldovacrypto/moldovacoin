#ifndef STATISTICSPAGE_H
#define STATISTICSPAGE_H

#include <QWidget>

//#include "walletmodel.h"

namespace Ui {
	class StatisticsPage;
}
class ClientModel;

class StatisticsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsPage(QWidget *parent = 0);
    ~StatisticsPage();
    
    void setModel(ClientModel *model);
    void updatePlot();
	void updatePlot2();

private slots:

private:
    Ui::StatisticsPage *ui;
    ClientModel *model;
	
	QVector<double> vX;
	QVector<double> vY;
	
	QVector<double> vX3;
	QVector<double> vY3;

	QVector<double> vX2;
	QVector<double> vY2;
	
	QVector<double> vX4;
	QVector<double> vY4;
	
	double currentStrength;
};

#endif 