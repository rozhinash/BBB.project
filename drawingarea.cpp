#include "drawingarea.h"
#include <QPainter>
#include <QMouseEvent>

DrawingArea::DrawingArea(QWidget *parent)
    : QWidget(parent), currentTool(Line), drawing(false) {
    setStyleSheet("background-color: white;");
    setMinimumSize(600, 400);
}

void DrawingArea::setTool(ToolType tool) {
    currentTool = tool;
}

void DrawingArea::mousePressEvent(QMouseEvent *event) {
    drawing = true;
    startPoint = event->pos();
    endPoint = startPoint;
    if (currentTool == Freehand) {
        currentPoints = {startPoint};
    }
}

void DrawingArea::mouseMoveEvent(QMouseEvent *event) {
    if (!drawing) return;

    endPoint = event->pos();
    if (currentTool == Freehand) {
        currentPoints.append(endPoint);
    }
    update();
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *event) {
    if (!drawing) return;

    Shape shape;
    shape.type = currentTool;
    shape.start = startPoint;
    shape.end = event->pos();
    if (currentTool == Freehand)
        shape.points = currentPoints;

    shapes.append(shape);
    currentPoints.clear();
    drawing = false;
    update();
}

void DrawingArea::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::black, 2);
    painter.setPen(pen);

    for (const Shape &s : shapes) {
        switch (s.type) {
        case Line:
            painter.drawLine(s.start, s.end);
            break;
        case Rectangle:
            painter.drawRect(QRect(s.start, s.end));
            break;
        case Ellipse:
            painter.drawEllipse(QRect(s.start, s.end));
            break;
        case Freehand:
            for (int i = 1; i < s.points.size(); ++i)
                painter.drawLine(s.points[i - 1], s.points[i]);
            break;
        }
    }

    // در حال رسم
    if (drawing) {
        switch (currentTool) {
        case Line:
            painter.drawLine(startPoint, endPoint);
            break;
        case Rectangle:
            painter.drawRect(QRect(startPoint, endPoint));
            break;
        case Ellipse:
            painter.drawEllipse(QRect(startPoint, endPoint));
            break;
        case Freehand:
            for (int i = 1; i < currentPoints.size(); ++i)
                painter.drawLine(currentPoints[i - 1], currentPoints[i]);
            break;
        }
    }
}
