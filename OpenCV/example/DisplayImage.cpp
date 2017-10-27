#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    String imageName;

    if (argc != 2) {
        std::cout << "Usage: ./DisplayImage <Image_Path>\n";
        std::cout << "Will be used standart default example image\n";
        imageName = "example.jpg"; // By default
    } else {
        imageName = argv[1];
    }

    Mat image;
    image = imread(imageName, IMREAD_COLOR); // Read the file

//    if (!image.data) {
    if (image.empty()) {    // Check for invalid input
//        std::cout << "No image data\n";
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE); // Create a window for display

    imshow("Display Image", image); // Show our image inside it

    waitKey(0); // Wait for a keystroke in the window

    return 0;
}


