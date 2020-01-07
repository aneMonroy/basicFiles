#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	VideoCapture cap(0);
	if(!cap.isOpened())
	{
		cerr << "[ERR] >> UNABLE TO OPEN CAMERA" <<endl;
		return 0;
	}
	
	Mat frame;
	while(1)
	{
		cap >> frame;
		if(frame.empty())
		{
			cerr << "[ERR] >> UNABLE TO GRAB FROM CAMERA" <<endl;
			break;
		}
	namedWindow("LIVE",2);
	imshow("LIVE", frame);
	int key= waitKey(33);
	key = (key==255) ? -1:key;
	if(key>=0)
		break;
	}
	cout<<"[INFO] >> RELEASING CAMERA..."<<endl;
	cap.release();
	destroyAllWindows();
	cout<<"[INFO] >> PROGRAM STOPPED"<<endl;
	return 0;
}
