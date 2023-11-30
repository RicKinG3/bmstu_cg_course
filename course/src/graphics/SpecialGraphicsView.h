#ifndef SRC_SPECIALGRAPHICSVIEW_H
#define SRC_SPECIALGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>

class SpecialGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SpecialGraphicsView(QWidget *parent = nullptr);
};

#endif // SRC_SPECIALGRAPHICSVIEW_H
