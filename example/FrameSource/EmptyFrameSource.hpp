#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/superres/superres.hpp"

using namespace std;

class EmptyFrameSource : public cv::superres::FrameSource
{
public:
	void nextFrame(cv::OutputArray frame) override;
	void reset() override;
};

inline void EmptyFrameSource::nextFrame(cv::OutputArray frame)
{
	frame.release();
}

inline void EmptyFrameSource::reset()
{

}
