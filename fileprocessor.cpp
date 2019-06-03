#include "fileprocessor.h"
FileProcessor::FileProcessor() {
  
}
FileProcessor::FileProcessor(const QString &configFileName, const QString &srcDir, bool shouldSub, bool isSeparateJsonFile) {
  
}

QString FileProcessor::getError() {
  
}

void FileProcessor::createDirList(QDir dir) {
  QStringList list = dir.entryList(QDir::Dirs);
  dirList = QStringList();
  foreach (const QString &s, list) {
    if(s.indexOf("-") == 0 || s.indexOf(".") == 0) {
      continue;
    }

    if(QFile(s + "/" + configFileName).exists()) {
      dirList.push_back(s);
    }
  }
}

void FileProcessor::createDirList(QString dirPath) {
  createDirList(QDir(dirPath));
}

void FileProcessor::buildFromConfiguration(const QString &configFileName) {
}


QString FileProcessor::loadEntireFile(const QString &fname);
    QFile f(fname);
    if (!f.open(QFile::ReadOnly | QFile::Text)) break;
    QTextStream in(&f);
    return in.readAll();
}

QJsonDocument FileProcessor::validateConfigFile(const QString &fname) {
  const QString commonError = "An Object is expected. Please run: parsejson --help config-json"
/*
{
  "default": "en",
  langs: {
    "en":"en.josn",
    "fr":"fr.josn"
  }
}
OR
// in the following case en.json, fr.json file will be expected
{
  "default": "en",
  langs: ["en","fr"]
}

// program will look for setting.json en.json, fr.json in each directory
*/

  QString jsonText = loadEntireFile(fname);
  QJsonDocument doc = QJsonDocument::fromJson(jsonText.toUtf8());
  if(!doc.isObject()) {
    error = commonError;
    return false;
  }
  QJsonObject jsonObj = doc.object();

  if(!jsonObj.contains("default")) {
    error = commonError;
    return QJsonDocument();
  }

  #TODO working here
  
}

QString FileProcessor::configFileName("config.json");
