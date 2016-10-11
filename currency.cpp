#include "currency.h"
using namespace std;

roe::Currency::Currency() {
    _name  = "";
    _code  = "";
    _value = 0.0;
}

roe::Currency::Currency(std::string name, std::string code, double value) {
    _name  = name;
    _code  = code;
    _value = value;
}

roe::Currency::~Currency() {
    ;
}

std::string roe::Currency::getName() const {
    return _name;
}

 std::string roe::Currency::getCode() const {
    return _code;
}

 double roe::Currency::getValue() const {
    return _value;
}
