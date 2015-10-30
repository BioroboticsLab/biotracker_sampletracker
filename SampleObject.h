#pragma once

#include <opencv2/opencv.hpp>

#include <biotracker/serialization/ObjectModel.h>

class SampleObject :
    public ObjectModel {
  public:
    SampleObject(void);
    virtual ~SampleObject(void);
    void setPosition(cv::Point pos);
    cv::Point getPosition();

  private:
    cv::Point _position;
};
