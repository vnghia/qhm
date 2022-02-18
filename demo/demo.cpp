#include "simulation.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QWidget>

int main(int argc, char **argv) {
  qputenv("QSG_RHI_BACKEND", "opengl");

  QApplication app(argc, argv);

  Q3DScatter *graph = new Q3DScatter();
  QWidget *container = QWidget::createWindowContainer(graph);

  if (!graph->hasContext()) {
    QMessageBox msg_box;
    msg_box.setText("Couldn't initialize the OpenGL context.");
    msg_box.exec();
    return -1;
  }

  QSize screen_size = graph->screen()->size();
  container->setMinimumSize(
      QSize(screen_size.width() / 2, screen_size.height() / 1.5));
  container->setMaximumSize(screen_size);

  container->setWindowTitle(QStringLiteral("QHM"));
  container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  container->setFocusPolicy(Qt::StrongFocus);

  auto simulation = new Simulation(graph);

  container->show();
  return app.exec();
}
