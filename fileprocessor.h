#ifndef __FILEPROCESSOR_H_
#define __FILEPROCESSOR_H_
#include <QtCore>
#include <QDir>

class FileProcessor {
private:
  static const QString configFileName;
  
private:
  QString error;
  QStringList dirList;
public:
  FileProcessor();
  FileProcessor(const QString &dirName);

public:
  QString getError();
  void createDirList(QDir dir);
  void createDirList(QString dirPath);
  void buildFromConfiguration(const QString &configFileName);
  QString loadEntireFile(const QString &fname);
  
private:
  QJsonDocument validateConfigFile(const QString &fname);
};

#endif
