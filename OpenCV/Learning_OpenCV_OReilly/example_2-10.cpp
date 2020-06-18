/*
 * The same object can load videos from a camera or a file
 */

#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv) {
	cv::namedWindow("Example 2-10", cv::WINDOW_NORMAL);
	cv::resizeWindow("Example 2-10", 800, 600);

	cv::VideoCapture cap;
	if (argc == 1) {
		cap.open(0);
	} else {
		cap.open(argv[1]);
	}
	if (!cap.isOpened()) {
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	cv::Mat frame;
	for (;;) {
		cap >> frame;
		cv::imshow("Example 2-10", frame);
		char c = cv::waitKey(1);
		if (c == 27)
			break;
	}

	cv::destroyWindow("Example 2-10");
	cv::destroyAllWindows();

	return 0;
}
