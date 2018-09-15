#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	Mat img1=imread("testF1.png"),
		img2=imread("testF2.png");

	//Point 1
	bool bChannelEqual=true,
		 gChannelEqual=true,
		 rChannelEqual=true;
	Mat planes1[3], planes2[3];
	split(img1, planes1);
	split(img2, planes2);
	for(int i=0; i<img1.cols; i++){
		for(int j=0; j<img1.rows; j++){
			if((int)planes1[0].at<uchar>(i, j)!=(int)planes2[0].at<uchar>(i, j)){
				bChannelEqual=false;
				break;
			}
			if((int)planes1[1].at<uchar>(i, j)!=(int)planes2[1].at<uchar>(i, j)){
				gChannelEqual=false;
				break;
			}
			if((int)planes1[2].at<uchar>(i, j)!=(int)planes2[2].at<uchar>(i, j)){
				rChannelEqual=false;
				break;
			}
		}
		if(!bChannelEqual || !gChannelEqual || !rChannelEqual)
			break;
	}

	if(!bChannelEqual || !gChannelEqual || !rChannelEqual)
		cout<<"Images are not equal!"<<endl;
	else
		cout<<"Images are equal!"<<endl;


	namedWindow("taller_oper_esp img1", WINDOW_AUTOSIZE);
	namedWindow("taller_oper_esp img2", WINDOW_AUTOSIZE);
	imshow("taller_oper_esp img1", img1);
	imshow("taller_oper_esp img", img2);

	waitKey(0);
	return 0;
}