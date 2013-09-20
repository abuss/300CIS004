#pragma once

#include <QtWidgets>
#include "figura.hpp"

class tablero
  : public QGraphicsView
{
  Q_OBJECT

  QGraphicsScene scene;
  QTimer timer;
  Figura currentFig;

public:
  tablero();
  virtual ~tablero() {}

protected:
  void keyPressEvent(QKeyEvent* event);

};
