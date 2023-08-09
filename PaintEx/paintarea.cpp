#include "paintarea.h"
#include <QPainter>
/*PaintArea 类的构造函数用于完成初始化工作，设置图形显示区域的背景色及最小显示尺寸*/
PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{

    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMinimumSize(400,400);

}
/*setShape() 函数可以设置形状， setPen() 函数可以设置画笔， setBrush() 函数可以设置画刷，
setFillRule() 函数可以设置填充模式*/
void PaintArea::setShape(Shape s){

    shape = s;
    update();
}

void PaintArea::setPen(QPen p){

    pen = p;
    update();
}

void PaintArea::setBrush(QBrush b){

    brush = b;
    update();

}

void PaintArea::setFillRule(Qt::FillRule rule){

    fillRule = rule;
    update();   //重画绘制区窗体
}

void PaintArea::paintEvent(QPaintEvent *){

    QPainter p(this);  //新建QPainter 对象
    p.setPen(pen);  //设置QPainter对象的画笔
    p.setBrush(brush);  //设置QPainter对象的画刷
    QRect rect(50,100,300,200);  //设定一个方形区域，为画长方形、圆角方形、椭圆等做准备
    static const QPoint points[4] = {  //：创建一个QPoint 的数组，包含四个点，为画多边形、多边线及点做准备
        QPoint(150,100),
        QPoint(300,150),
        QPoint(350,250),
        QPoint(100,300)
    };

    int startAngle = 30*16;  //参数 startAngle 表示起始角，为弧形的起始点与圆心之间连线与水平方向的夹角；参数 spanAngle 表示的是跨度角，为弧形起点、终点分别与圆心连线之间的夹角
    int spanAngle = 120*16;
    QPainterPath path;  //新建QPainterPath对象为画路径做准备
    path.addRect(150,150,100,100);
    path.moveTo(100,100);
    path.cubicTo(300,100,200,200,300,300);
    path.cubicTo(100,300,200,200,100,100);
    switch (shape) {  //对所要画的形状做判断，调用 QPainter 的各draw() 函数完成图形的绘制
    //当需要绘制此预先存储在 QPainterPath 对象中的内容时，只需调用 QPainter 类的 drawPath() 函数即可。
    case Line:  //直线
        p.drawLine(rect.topLeft(), rect.bottomRight());
        break;
    case Rectangle:  //长方形
        p.drawRect(rect);
        break;
    case RoundRect:  //圆角方形
        p.drawRoundRect(rect);
        break;
    case Ellipse: //椭圆形
        p.drawEllipse(rect);
        break;
    case Polygon:  //多边形
        p.drawPolygon(points, 4);
        break;
    case Polyline:
        p.drawPolyline(points,4);
        break;
    case Points:
        p.drawPoints(points,4);
        break;
    case Arc:
        p.drawArc(rect, startAngle, spanAngle);
        break;
    case Path:
        p.drawPath(path);
        break;
    case Text:
        p.drawText(rect, Qt::AlignCenter, tr("Hello Qt!"));
        break;
    case Pixmap:
        p.drawPixmap(150,150, QPixmap("20190310203343399.png"));
        break;

    default:
        break;
    }


}
