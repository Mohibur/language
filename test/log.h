#include <QFile>
#include <QTextStream>

#define TONUMBER1(num)         #num
#define TONUMBER(num)         TONUMBER1(num)

#define INFO(msg)     TestLog::log(msg, QString("[INFO]" __FILE__ "[" TONUMBER(__LINE__) "]:"))
#define FATAL(msg)    TestLog::log(msg, QString("[FATAL]" __FILE__ "[" TONUMBER(__LINE__) "]:"))
#define ERROR(msg)    TestLog::log(msg, QString("[ERROR]" __FILE__ "[" TONUMBER(__LINE__) "]:"))

class TestLog {
public:
  static void log(const QString &msg, const QString &info);
};
