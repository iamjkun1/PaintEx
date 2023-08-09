#ifndef PAINTAREA_H
#define PAINTAREA_H
/*PaintArea 类继承自 QWidget 类，在类声明中，首先声明一个枚举型数据 Shape, 列举了所
有本实例可能用到的图形形状；其次声明 set Shape() 函数用于设置形状， setPen() 函数用千设置画
笔， setBrush() 函数用千设置画刷， setFillRule() 函数用千设置填充模式，以及重绘事件 paintEvent()
函数；最后声明表示各种属性的私有变量。*/
#include <QWidget>
#include <QPen>
#include <QBrush>
class PaintArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape{Line, Rectangle, RoundRect, Ellipse, Polygon, Polyline, Points, Arc, Path, Text, Pixmap};

    explicit PaintArea(QWidget *parent = nullptr);

    void setShape(Shape);
    void setPen(QPen);
    void setBrush(QBrush);
    void setFillRule(Qt::FillRule);
    void paintEvent(QPaintEvent *);


signals:

public slots:

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    Qt::FillRule fillRule;


};

#endif // PAINTAREA_H
