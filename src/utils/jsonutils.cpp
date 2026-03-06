#include "jsonutils.h"
#include <QFile>
#include <QJsonDocument>

QJsonObject JsonUtils::loadJson(const QString& path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
        return QJsonObject();

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (!doc.isObject())
        return QJsonObject();

    return doc.object();
}

bool JsonUtils::saveJson(const QString& path, const QJsonObject& object)
{
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly))
        return false;

    QJsonDocument doc(object);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    return true;
}