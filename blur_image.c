#include <opencv2/opencv.hpp>

int main()
{
    // Read the image
    cv::Mat image = cv::imread("input_image.jpg");

    // Apply blur effect
    cv::Mat blurredImage;
    cv::blur(image, blurredImage, cv::Size(15, 15));

    // Save the blurred image
    cv::imwrite("blurred_image.jpg", blurredImage);

    return 0;
}
