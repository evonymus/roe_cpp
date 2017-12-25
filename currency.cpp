/*!
 * definition of the Currency class
 * */
#include "currency.h"

roe::Currency::Currency(std::string name
      , std::string code
      , double value) {
    name_  = name;
    code_  = code;
    value_ = value;
}

roe::Currency::~Currency() {
    ;
}

std::string roe::Currency::getName() const {
    return name_;
}

 std::string roe::Currency::getCode() const {
    return code_;
}

 double roe::Currency::getValue() const {
    return value_;
}
