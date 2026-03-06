#pragma once

#include <QJsonObject>
#include <QString>

class JsonUtils
{
public:
    static QJsonObject loadJson(const QString& path);
    static bool saveJson(const QString& path, const QJsonObject& object);
};