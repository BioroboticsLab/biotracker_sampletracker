#include "TrackerParameter.h"
#include "ParamNames.h"


TrackerParameter::TrackerParameter(QObject *parent) :
    IModel(parent)
{
    m_Threshold = 12345;

    _lowH = 0;
    _highH = 125;
    _lowS = 0;
    _highS = 125;
    _lowV = 0;
    _highV = 125;
    Q_EMIT notifyView();
}

void TrackerParameter::setThreshold(int x)
{
    m_Threshold = x;

    Q_EMIT notifyView();
}

int TrackerParameter::getThreshold()
{
    return m_Threshold;
}
