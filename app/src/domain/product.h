#pragma once
#include <QString>

struct Product {
    int id = 0;
    QString name;
    QString category;
    int price = 0;
    int stock = 0;
    QString imageKey;
};
