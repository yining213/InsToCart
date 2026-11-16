#pragma once
#include <QString>

namespace SQLiteBackend {
bool open(const QString &dataDirectory, QString *error);
}
