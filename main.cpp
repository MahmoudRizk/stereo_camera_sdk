#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <thread.h>
#include <iostream>
#include <list>
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    thread camera1("camera1",-1);
    camera1.start(QThread::HighestPriority);

    return a.exec();
}
