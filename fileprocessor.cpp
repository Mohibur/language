#include "fileprocessor.h"
FileProcessor::FileProcessor() {
  
}
FileProcessor::FileProcessor(const QString &configFileName, const QString &srcDir, bool shouldSub, bool isSeparateJsonFile) {
  
}

QString FileProcessor::getError() {
  
}

void FileProcessor::buildFromConfiguration(const QString &configFileName) {
  const QString commonError = "An Object is expected. Please run: parsejson --help config-json"
  QString jsonText = loadEntireFile(configFileName);
  QJsonDocument doc = QJsonDocument::fromJson(jsonText.toUtf8());
  QJsonValue jasonValue;
  if(!doc.isObject()) {
    error = commonError;
    return;
  }
  QTextStream(stdout) << "Checking default"
  if(!jasonValue.contains("default") || jasonValue.)
  QString defaultLang = jsonData.getValue("default");

// expected json filebuf
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
}


QString FileProcessor::loadEntireFile(const QString &fname);
    QFile f(fname);
    if (!f.open(QFile::ReadOnly | QFile::Text)) break;
    QTextStream in(&f);
    return in.readAll();
}