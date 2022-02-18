#include "simulation.h"

#include <QtDataVisualization/q3dtheme.h>
#include <QtDataVisualization/qscatter3dseries.h>
#include <QtDataVisualization/qscatterdataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>

#include <QTimer>

Simulation::Simulation(Q3DScatter *graph)
    : graph_(graph), direction_(-1), dt_(1000 / 60), speed_(0.05) {
  graph_->activeTheme()->setType(Q3DTheme::ThemeEbony);
  graph_->setAspectRatio(1);
  graph_->setHorizontalAspectRatio(1);

  QScatterDataProxy *proxy = new QScatterDataProxy;
  QScatter3DSeries *series = new QScatter3DSeries(proxy);
  series->setItemLabelFormat(
      QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel"));
  graph_->addSeries(series);

  this->add_data();
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &Simulation::update_data);
  timer->start(dt_);
}

Simulation::~Simulation() { delete graph_; }

void Simulation::add_data() {
  graph_->axisX()->setTitle("X");
  graph_->axisY()->setTitle("Y");
  graph_->axisZ()->setTitle("Z");
  graph_->axisX()->setRange(0, 2);
  graph_->axisY()->setRange(0, 2);
  graph_->axisZ()->setRange(0, 2);

  QScatterDataArray *data_array = new QScatterDataArray;
  data_array->resize(1);
  data_array->first().setPosition(QVector3D(1, 1, 1));
  graph_->seriesList().at(0)->dataProxy()->resetArray(data_array);
}

void Simulation::update_data() {
  float y = graph_->seriesList().at(0)->dataProxy()->itemAt(0)->y();
  y += direction_ * speed_;

  if (y <= 0) {
    direction_ = 1;
  } else if (y >= 2) {
    direction_ = -1;
  }
  graph_->seriesList().at(0)->dataProxy()->setItem(0,
                                                   QScatterDataItem({1, y, 1}));
}
