/*
 * loading and then smoothing an image before it is displayed on the screen
 */

#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
    // Load an image specified on the command line
    cv::Mat image = cv::imread(argv[1], -1);

    cv::namedWindow("Example 2-5-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example 2-5-out", cv::WINDOW_AUTOSIZE);

    cv::imshow("Example 2-5-in", image);
    cv::Mat out;

    cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
    cv::GaussianBlur(  out, out, cv::Size(5, 5), 3, 3);

    cv::imshow("Example 2-5-out", out);

    cv::waitKey(0);

    cv::destroyWindow("Example 2-5-in");
    cv::destroyWindow("Example 2-5-out");

    return 0;
}
