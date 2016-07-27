#include "thread.h"
#include <QtCore>
#include <string>
#include <QDebug>
#include <QMutex>
#include <iostream>
#include <QThread>

using namespace std;
using namespace cv;

thread::thread(std::string n, int i)
{
   name=n;
   camera_number=i;


}
void thread::CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          Coordinates c;
          c.x=x;
          c.y=y;
          list<Coordinates>*ptr = (list<Coordinates>*) userdata;
          ptr->push_back(c);

     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if ( event == EVENT_MOUSEMOVE )
     {
          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

     }

}
void thread::print()
{
   list<Coordinates>::iterator i;
   cout<<this->name<<":";
   for(i=points.begin();i!=points.end();i++)
       cout<<"( "<<i->x<<","<<i->y<<" )"<<"  ";
   cout<<endl;
}
void thread::run()
{
      cv::VideoCapture cam;
      cv::Mat frame;
      cam.open(camera_number);

      while(1)
      {
          //run() is the main function for each thread.
          //Show video stream and handle points selection by user.
          cam>>frame;
          namedWindow(name);
          imshow(name,frame);
          if(!(this->points.empty()))
             this->print();
          setMouseCallback(name, CallBackFunc, (void*)&points);

      }
}
