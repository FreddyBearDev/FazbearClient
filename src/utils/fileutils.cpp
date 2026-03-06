#include "fileutils.h"
#include <QFile>

bool FileUtils::fileExists(const QString& path)
{
    return QFile::exists(path);
}