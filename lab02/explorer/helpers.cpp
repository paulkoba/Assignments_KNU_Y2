#include "helpers.h"

void Helpers::tryOpenFile(const QString& path)
{
    std::string unpacked = path.toStdString();
    if(std::filesystem::is_directory(unpacked)) return;

    system(("xdg-open \"" + unpacked + "\"&").c_str());
}
