#ifndef THREAD_H
#define THREAD_H
#include <QtCore>
#include <opencv2/opencv.hpp>
#include <string>
#include <QThread>
#include <QMutex>
#include <list>

using namespace std;
using namespace cv;


class thread : public QThread
{

public:
    struct Coordinates{
        float x;
        float y;
    };

    std::string name;   //camera name
    int camera_number;  //camera number
    list<Coordinates> points; //list of selected points from the image


    thread(string, int);  //constructor
    void run();           //overrode function from the QThread class. Considered the main() function of the program
    static void CallBackFunc(int , int , int , int , void*) ;  //Used to handle the mouse pointer with the image
    void print(); //prints list of selected points

signals: 
public slots:
};

#endif // THREAD_H
