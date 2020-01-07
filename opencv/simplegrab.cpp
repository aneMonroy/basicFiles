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
		cerr << "Error: Unable to open the camera" <<endl;
		return 0;
	}
	
	Mat frame;
	while(1)
	{
		cap >> frame;
		if(frame.empty())
		{
			cerr << "Error: Unable to grab from cam" <<endl;
			break;
		}
	namedWindow("LIVE",2);
	imshow("LIVE", frame);
	int key= waitKey(33);
	key = (key==255) ? -1:key;
	if(key>=0)
		break;
	}
	cout<<"Closing camera"<<endl;
	cap.release();
	destroyAllWindows();
	return 0;
}
