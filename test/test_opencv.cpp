// C++ program for the above approach
#include <iostream>
#include <opencv2/core/core.hpp>

// Library to include for
// drawing shapes
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

// Driver Code
int main(int argc, char** argv) {
  // Create a blank image of size
  // (500 x 500) with black
  // background (B, G, R) : (0, 0, 0)
  Mat image(500, 500, CV_8UC3, Scalar(0, 0, 0));

  // Check if the image is created
  // successfully
  if (!image.data) {
    cout << "Could not open or find"
         << " the image";

    return 0;
  }

  Point p1(0, 0), p2(100, 0);
  Point p3(200, 0), p4(500, 500);
  int thickness = 2;

  // Line drawn using 8 connected
  // Bresenham algorithm
  line(image, p1, p4, Scalar(255, 0, 0), thickness, LINE_8);

  // Line drawn using 4 connected
  // Bresenham algorithm
  line(image, p2, p4, Scalar(0, 255, 0), thickness, LINE_4);

  // Antialiased line
  line(image, p3, p4, Scalar(0, 0, 255), thickness, LINE_AA);

  // Show our image inside window
  imshow("Output", image);
  waitKey(0);

  return 0;
}
