#ifndef BIOTRACKERTRACKINGALGORITHM_H
#define BIOTRACKERTRACKINGALGORITHM_H


#include "Interfaces/IModel/IModel.h"

#include "TrackerParameter.h"

#include <opencv2/opencv.hpp>
#include "Interfaces/IModel/IModelTrackingAlgorithm.h"
#include "Interfaces/IModel/IModelDataExporter.h"
#include "TrackedComponents/TrackedElement.h"
#include "TrackedComponents/TrackedTrajectory.h"
#include "Interfaces/IModel/IModelAreaDescriptor.h"
#include <iostream>

class BioTrackerTrackingAlgorithm : public IModelTrackingAlgorithm
{
    Q_OBJECT
public:
    BioTrackerTrackingAlgorithm(IModel* parameter, IModel* trajectory);

    int _imageX;
    int _imageY;

Q_SIGNALS:
    void emitCvMatA(std::shared_ptr<cv::Mat> image, QString name);
    void emitDimensionUpdate(int x, int y);
    void emitTrackingDone(uint framenumber);

    // ITrackingAlgorithm interface
    public Q_SLOTS:
    void doTracking(std::shared_ptr<cv::Mat> image, uint framenumber) override;
    void receiveAreaDescriptorUpdate(IModelAreaDescriptor *areaDescr) {};
    void receiveParametersChanged() {};

private:

    TrackedTrajectory* _TrackedTrajectoryMajor;

    TrackerParameter* _TrackingParameter;

};

#endif // BIOTRACKERTRACKINGALGORITHM_H
