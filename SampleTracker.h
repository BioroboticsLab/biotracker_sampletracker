#ifndef SampleTracker_H
#define SampleTracker_H

#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

#include <biotracker/TrackingAlgorithm.h>

class SampleTracker : public TrackingAlgorithm {
    Q_OBJECT
  public:
    SampleTracker(Settings &settings);

    void track(size_t frameNumber, const cv::Mat &frame) override;
    void paint(size_t frameNumber, ProxyMat &m, View const &view = OriginalView) override;
    void paintOverlay(size_t frameNumber, QPainter *, View const &) override;

    void postConnect() override;

  public Q_SLOTS:
    void changeFilterColor();

  private:
    QPointF _selectorRecStart;
    QPointF _selectorRecEnd;

    bool _showSelectorRec;
    bool _showOriginal;

    // values for filtering a color (HSV format)
    int _lowH;
    int _highH;
    int _lowS;
    int _highS;
    int _lowV;
    int _highV;

    cv::Mat _imgTracked;

    // gui elements to set those values
    QLineEdit *_lowHEdit;
    QLineEdit *_highHEdit;
    QLineEdit *_lowSEdit;
    QLineEdit *_highSEdit;
    QLineEdit *_lowVEdit;
    QLineEdit *_highVEdit;

    QPushButton *_colorBut;
    std::string _currentView;
    bool _imageChanged;

    std::vector<TrackedObject> _trackedObjects;

    void drawRectangle(QPainter *painter);
    void initToolsFrame();

  private:
    //mouse click and move events
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseWheelEvent(QWheelEvent *e) override;
};

#endif
