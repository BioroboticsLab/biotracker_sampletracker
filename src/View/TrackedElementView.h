#ifndef TRACKEDELEMENTVIEW_H
#define TRACKEDELEMENTVIEW_H

#include "Interfaces/IView/IViewTrackedComponent.h"

/**
	* This class is an example of how a TrackedElementView could be visualized.
	* This class inherits from the IViewTrackedComponent class and is therefor part of the Composite Pattern.
	*/
class TrackedElementView : public IViewTrackedComponent
{
	Q_OBJECT
public:
	TrackedElementView(QGraphicsItem *parent = 0, IController *controller = 0, IModel *model = 0);

	// QGraphicsItem interface
public:
	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	// IViewTrackedComponent interface
	public Q_SLOTS:
	void getNotified() override;
	void rcvDimensionUpdate(int x, int y);

	public Q_SIGNAL:
	void emitUpdateCornersChanged(int id, int relX, int relY);

private:
	QRectF m_boundingRect;
	QGraphicsItem *_selectorBase;



	QPointF _selectorRecStart;
	QPointF _selectorRecEnd;
	bool _showSelectorRec;
	std::shared_ptr<QGraphicsRectItem> ri;

	// QGraphicsItem interface
protected:
	bool sceneEventFilter(QGraphicsItem * watched, QEvent * event) override;
	bool eventFilter(QObject * target, QEvent * event) override;

};

#endif // TRACKEDELEMENTVIEW_H
