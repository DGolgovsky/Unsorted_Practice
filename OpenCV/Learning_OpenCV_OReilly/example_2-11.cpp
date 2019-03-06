/*
 * A complete program to read in a color video and write out the log-polar-transformed video
 */

#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    cv::namedWindow("Example 2-11", cv::WINDOW_NORMAL);
    cv::resizeWindow("Example 2-11", 640, 480);

    cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

    int dev = -1;
    std::string out_file = "output.avi";
    if (argc == 3) {
        dev = std::atoi(argv[1]);
        out_file = std::string(argv[2]);
    }

    cv::VideoCapture capture;
    capture.open(dev);
    if (!capture.isOpened()) {
        std::cerr << "Couldn't open capture device: " << dev << std::endl;
        return -1;
    }

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
            (int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
            (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
    );

    cv::VideoWriter writer;
    writer.open(out_file, cv::VideoWriter::fourcc('M','J','P','G'), fps, size);

    cv::Mat logpolar_frame, bgr_frame;
    for(;;) {
        capture >> bgr_frame;
        if (bgr_frame.empty()) break;

        cv::imshow("Example 2-11", bgr_frame);

        cv::logPolar(
                bgr_frame,              // Input color frame
                logpolar_frame,         // Output log-polar frame
                cv::Point2f(            // Centerpoint for log-polar transformation
                    bgr_frame.cols/2,   // x
                    bgr_frame.rows/2    // y
                ),
                40,                     // Magnitude (scale parameter)
                cv::WARP_FILL_OUTLIERS  // Fill outliers with 'zero'
        );

        cv::imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;
        
        char c = (char)cv::waitKey(33);
        if (c == 27) break;
    }

    capture.release();

    cv::destroyAllWindows();

    return 0;
}
