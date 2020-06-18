/*
 * A simple OpenCV program for playing a video file from disk
 */

#include <opencv2/highgui/highgui.cpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char **argv) {
	cv::namedWindow("Example 2-3", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open(string(argv[1]));

	cv::Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty()) break;
		cv::imshow("Example 2-3", frame);
		if ((char) cv::waitKey(33) >= 0) break;
	}

	cv::destroyWindow("Example 2-3");

	return 0;
}
