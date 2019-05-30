#include "log.h"
#include <QDateTime>

void TestLog::log(const QString &s, const QString &info)
{
  
  if ( file.open(QIODevice::WriteOnly | QIODevice::Append) ) {
    stream << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")  << info << " "<< s << "\n";
  }
  file.close();
}

QString TestLog::filename("my_log.log");
QFile TestLog::file(TestLog::filename);
QTextStream TestLog::stream(&TestLog::file );
