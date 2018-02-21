#include "splashscreen.h"
#include "clientversion.h"
#include "util.h"

#include <QApplication>

#include <QDesktopWidget>

SplashScreen::SplashScreen(QWidget *parent) :
    QWidget(parent)
{

    QRect rec = QApplication::desktop()->screenGeometry();

    int screenWidth = rec.width();
    int screenHeight = rec.height();

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(0,screenHeight/2-150,screenWidth,300);


    QPixmap bgPixmap(screenWidth,300);

    QLinearGradient bgGradient(QPointF(0, 0), QPointF(screenWidth, 0));
    bgGradient.setColorAt(0, QColor("#FFFFFF"));
	bgGradient.setColorAt(1, QColor("#97E6E6"));

    QRect rect_linear(0,0,screenWidth,300);

    QPainter *painter = new QPainter(&bgPixmap);
    painter->fillRect(rect_linear, bgGradient);

    painter->end();

    bg = new QLabel(this);
    bg->setPixmap(bgPixmap);


    bg->setGeometry(0,0,screenWidth,300);

    splashImage = new QLabel(this);
    splashImage->setStyleSheet("QLabel { background: transparent; }");
    QPixmap newPixmap;
    if(GetBoolArg("-testnet")) {
        newPixmap.load(":/images/splash_testnet");
    }
    else {
        newPixmap.load(":/images/splash");
    }


    splashImage->setPixmap(newPixmap);
    splashImage->move(screenWidth/2-567/2,50);



    QFont smallFont; smallFont.setPixelSize(10);

    versionLabel = new QLabel(this);
    versionLabel->setStyleSheet("QLabel { background: transparent; color: #FFFFFF; }");
    versionLabel->setFont(smallFont);
    versionLabel->setText(QString::fromStdString(FormatFullVersion()).split("-")[0]);
    versionLabel->setFixedSize(1000,30);
    versionLabel->move(screenWidth/2-10,215);


    QFont largeFont; largeFont.setPixelSize(14);

    label = new QLabel(this);
    label->setStyleSheet("QLabel { background: transparent; color: #FFFFFF; }");
    label->setFont(largeFont);
    label->setText("...");
    label->setFixedSize(1000,30);
    label->move(screenWidth/2-56,260);

}

SplashScreen::~SplashScreen()
{
}