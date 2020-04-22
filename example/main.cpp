#include "FrameSource/FrameSourceFactory.h"
#include "SuperResolution/SuperResolutionBase.h"
#include "SuperResolution/SuperResolutionFactory.h"

#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    /*******************************************************************************
     *
     * Create a Super Resolution object and set default props
     *
     *******************************************************************************/
    auto superResolution = SuperResolutionFactory::CreateSuperResolutionBase();

    auto alpha = 0.7;
    auto beta = 1.0;
    auto lambda = 0.04;
    auto p = 2;
    auto maxIterationCount = 20;

    int bufferSize = 20;
    int srFactor = 4;

    superResolution->SetProps(alpha, beta, lambda, p, maxIterationCount);

    /*******************************************************************************
     *
     * set Data Source
     *
     *******************************************************************************/

    /***********************         From Video             ***********************/
    //	const string videoFileName = "Data/fog_low_gray.avi";

    //	auto videoFrameSource = FrameSourceFactory::createFrameSourceFromVideo(videoFileName);

    //	superResolution->SetFrameSource(videoFrameSource);


    /***********************         From Image List         ***********************/

    /*******************************
    *
    *  This is test case for Adyoron,
    *  uncomment it if run want get
    *  Text test case result
    *
    ******************************/
//    auto startIndex = 0;
//    auto totalImageCount = 61;
//    auto fileNameFormat = "../data/Adyoron/%06d.png";
//    auto resultNameFormat = "../result/Adyoron_4x4_result_%02d.png";
//    bufferSize = 20;
    /*******************************
    *
    *  This is test case for EIA,
    *  uncomment it if run want get
    *  Text test case result
    *
    ******************************/
//    auto startIndex = 0;
//    auto totalImageCount = 16;
//    auto fileNameFormat = "../data/eia/%06d.png";
//    auto resultNameFormat = "../result/eia_4x4_result_%02d.png";
//    bufferSize = totalImageCount;

    /*******************************
    *
    *  This is test case for Text,
    *  uncomment it if run want get
    *  Text test case result
    *
    ******************************/
//    auto startIndex = 1;
//    auto totalImageCount = 29;
//    auto fileNameFormat = "../data/text/%06d.png";
//    auto resultNameFormat = "../result/text_4x4_result_%02d.png";
//    bufferSize = 29;

    /*******************************
     *
     *  This is test case for Emily,
     *  uncomment it if run want get
     *  Emliy test case result
     *
     ******************************/
    	auto startIndex = 0;
    	auto totalImageCount = 82;
    	auto fileNameFormat = "../data/Emily/%06d.png";
    	auto resultNameFormat = "../result/Emily_4x4_result_%02d.png";
        bufferSize = 53;

    // Override default parameters if supplied on command line
    if (argc == 7)
    {
        startIndex = atoi(argv[1]);
        totalImageCount = atoi(argv[2]);
        fileNameFormat = argv[3];
        resultNameFormat = argv[4];
        bufferSize = atoi(argv[5]);
        srFactor = atoi(argv[6]);
    }
    // Echo super resolution parameters
    cout << "startIndex=" << startIndex << " totalImageCount=" << totalImageCount << " fileNameFormat=" << fileNameFormat << endl;
    cout << "resultNameformat=" << resultNameFormat << " bufferSize=" << bufferSize << " srFactor=" << srFactor << endl;

    superResolution->SetBufferSize(bufferSize);
    superResolution->SetSRFactor(4);



    auto imageListFrameSource = FrameSourceFactory::createFrameSourceFromImageList(totalImageCount, fileNameFormat,
                                                                                   startIndex);

    superResolution->SetFrameSource(imageListFrameSource);

    /*******************************************************************************
     *
     * Processing Super Resolution
     *
     *******************************************************************************/
    auto index = 0;
    Mat currentFrame;
    while (true)
    {
        cout << index << endl;
        auto currentStatus = superResolution->NextFrame(currentFrame);

        imshow("High Resolution Frame", currentFrame);

        waitKey(1000);

        char name[50];
        sprintf(name, resultNameFormat, index);
        imwrite(name, currentFrame);

        if (currentStatus == -1)
            break;

        ++index;
    }
//    cv::waitKey(0);
    destroyAllWindows();

    cout << endl;
    cout << "All Done!" << endl;

    return 0;
}
