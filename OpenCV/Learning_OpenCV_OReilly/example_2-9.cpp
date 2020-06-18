/*
 * Getting and setting pixels in Example 2-8
 */

#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
	int x = 16, y = 32;
	cv::Mat img_rgb, img_gry, img_pyr, img_pyr2, img_cny;

	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread(argv[1]);
	cv::Vec3b intensity = img_rgb.at<cv::Vec3b>(y, x); // Note: img_rgb.at<cv::Vec3b>(y,x)[0]

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	std::cout << "At (x,y) = (" << x << ", " << y <<
			  "): (blue, green, red) = (" <<
			  (unsigned int) blue << ", " <<
			  (unsigned int) green << ", " <<
			  (unsigned int) red << ")" << std::endl;

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gry);

	std::cout << "Gray pixel there is: " <<
			  (unsigned int) img_gry.at<uchar>(y, x) << std::endl;

	cv::pyrDown(img_gry, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);

	x /= 4;
	y /= 4;
	std::cout << "Pyramid2 pixel there is: " <<
			  (unsigned int) img_pyr2.at<uchar>(y, x) << std::endl;

	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);

	img_cny.at<uchar>(x, y) = 128; // Set the Canny pixel there to 128

	cv::imshow("Example Canny", img_cny);

	cv::waitKey(0);
	cv::destroyWindow("Example Canny");
	cv::destroyWindow("Example Gray");

	return 0;
}

