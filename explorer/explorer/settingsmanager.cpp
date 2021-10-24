#include "settingsmanager.h"

SettingsManager::SettingsManager(const QString& filepath) : settings(filepath) {}

void SettingsManager::set(const QString& key, const QVariant& value)
{
    settings.setValue(key, value);
}

QVariant SettingsManager::get(const QString& key, const QVariant& defaultValue)
{
    return settings.value(key, defaultValue);
}
