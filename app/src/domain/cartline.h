#pragma once
#include <QString>

struct CartLine {
    int productId = 0;
    QString name;
    int quantity = 0;
    int unitPrice = 0;
};
