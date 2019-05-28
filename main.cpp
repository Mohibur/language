// main.cpp
#include <QtCore>
QTextStream& qStdOut()
{
	    static QTextStream ts( stdout );
	        return ts;
}

int main(int argc, char *argv[])
{
  QFile inputFile(argv[1]);
  if(inputFile.open(QIODevice::ReadOnly)) {
  QTextStream in(&inputFile);
    while (!in.atEnd()) {
    QString line = in.readLine();
  qStdOut() << line << "\n";

  inputFile.close();
  }
  return 0;
}
