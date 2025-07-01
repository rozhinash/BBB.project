#include "mainwindow.h"
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    auto *central = new QWidget(this);
    auto *mainLayout = new QHBoxLayout(central);

    drawingArea = new DrawingArea;

    auto *buttonLayout = new QVBoxLayout;
    auto *btnLine = new QPushButton("Line");
    auto *btnRect = new QPushButton("Rectangle");
    auto *btnEllipse = new QPushButton("Ellipse");
    auto *btnFreehand = new QPushButton("Freehand");

    buttonLayout->addWidget(btnLine);
    buttonLayout->addWidget(btnRect);
    buttonLayout->addWidget(btnEllipse);
    buttonLayout->addWidget(btnFreehand);
    buttonLayout->addStretch();

    connect(btnLine, &QPushButton::clicked, [=]() {
        drawingArea->setTool(Line);
    });
    connect(btnRect, &QPushButton::clicked, [=]() {
        drawingArea->setTool(Rectangle);
    });
    connect(btnEllipse, &QPushButton::clicked, [=]() {
        drawingArea->setTool(Ellipse);
    });
    connect(btnFreehand, &QPushButton::clicked, [=]() {
        drawingArea->setTool(Freehand);
    });

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(drawingArea, 1);

    setCentralWidget(central);
    setWindowTitle("Drawing App");
}
