#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QVector>
#include <QPoint>

enum ToolType {
    Line,
    Rectangle,
    Ellipse,
    Freehand
};

struct Shape {
    ToolType type;
    QPoint start;
    QPoint end;
    QVector<QPoint> points; // For Freehand
};

class DrawingArea : public QWidget {
    Q_OBJECT

public:
    explicit DrawingArea(QWidget *parent = nullptr);
    void setTool(ToolType tool);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QVector<Shape> shapes;
    QVector<QPoint> currentPoints;
    ToolType currentTool;
    bool drawing;
    QPoint startPoint, endPoint;
};

#endif // DRAWINGAREA_H
