#ifndef HELPERS_H
#define HELPERS_H

#include <QObject>
#include <filesystem>

class Helpers
{
public:
    static void tryOpenFile(const QString&);
private:
    Helpers() = delete;
};

#endif // HELPERS_H
