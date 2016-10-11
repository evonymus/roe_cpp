#include "table.h"

roe::Table::Table() {
    _tableType   = "";
    _tableNumber = "";
    _date        = "";
}

roe::Table::Table(std::string tableType, std::string tableNumber, std::string date) {
    _tableType   = tableType;
    _tableNumber = tableNumber;
    _date        = date;
}

roe::Table::~Table() {
    ;
}

 std::string roe::Table::getTableType() const {
    return _tableType;
}

 std::string roe::Table::getTableNumber() const {
    return _tableNumber;
}

 std::string roe::Table::getDate() const {
    return _date;
}
