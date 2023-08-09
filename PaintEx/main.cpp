#include "mainwidget.h"
#include <QFont>
#include <QApplication>
/*设计界面，区分各种形状及画笔颜色、画笔线宽、画笔风格、
画笔顶帽、画笔连接点、填充模式、铺展效果、画刷颜色、画刷风格设置等。*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("ZYSong18030",12);
    a.setFont(f);
    MainWidget w;
    w.show();
    return a.exec();
}
