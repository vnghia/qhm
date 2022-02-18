#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include <QtDataVisualization/q3dscatter.h>

class Simulation : public QObject {
  Q_OBJECT
public:
  explicit Simulation(Q3DScatter *graph);
  ~Simulation();

  void add_data();
  void update_data();

private:
  Q3DScatter *graph_;
  int direction_;
  float dt_;
  float speed_;
};

#endif
