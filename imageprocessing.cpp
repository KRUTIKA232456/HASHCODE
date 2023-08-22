#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
    // Read the input image
    cv::Mat image = cv::imread("download.jpeg"); // Change this to your image file path

    if (image.empty()) {
        std::cerr << "Error: Unable to read the image." << std::endl;
        return 1;
    }

    // Grayscale conversion
    cv::Mat grayscaleImage;
    cv::cvtColor(image, grayscaleImage, cv::COLOR_BGR2GRAY);

    // Image resizing
    int newWidth = 400; // Change this to the desired width
    int newHeight = static_cast<int>(image.rows * (static_cast<double>(newWidth) / image.cols));
    cv::resize(image, image, cv::Size(newWidth, newHeight));

    // Applying Gaussian blur
    cv::Mat blurredImage;
    cv::GaussianBlur(image, blurredImage, cv::Size(5, 5), 0);

    // Display results
    cv::imshow("Original Image", image);
    cv::imshow("Grayscale Image", grayscaleImage);
    cv::imshow("Blurred Image", blurredImage);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}