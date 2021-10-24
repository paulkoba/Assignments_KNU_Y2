#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>

class SettingsManager
{
public:
    SettingsManager(const QString& filepath);

    void set(const QString& key, const QVariant& value);
    QVariant get (const QString& key, const QVariant& defaultValue);

private:
    QSettings settings;
};

#endif // SETTINGSMANAGER_H
