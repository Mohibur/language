#ifndef __FILEPROCESSOR_H_
#define __FILEPROCESSOR_H_
#include <QtCore>

class FileProcessor {
private:
  QString error;
public:
  FileProcessor();
  FileProcessor(
    // read the configuration file
    const QString &configFileName,
    const QString &srcDir,
    bool shouldSub, 
    bool isSeparateJsonFile);

public:
  QString getError();
  void buildFromConfiguration(const QString &configFileName);
  QString loadEntireFile(const QString &fname);
};

#endif
