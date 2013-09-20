#pragma once

#include <QGraphicsItem>
#include <QKeyEvent>

class Figura
  : public QGraphicsItem
{
public:
    Figura();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void moveDerecha();
    void moveIzquierda();

protected:
    void advance(int step);

private:
  int posx = 100;
  int posy = 100;
};

