#include <QApplication>
#include "MobileScan.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
  QApplication a(argc, argv);
  CMobileScan w;
  w.show();
  w.move(300,200);

  return a.exec();
}
