#ifndef ROE_H
#define ROE_H
#include <string>
#include <ostream>
#include <vector>
#include <iomanip>
#include "currency.h"
#include "table.h"

using namespace std;
namespace roe {

class Roe {
public:
    Roe( string json);
    virtual ~Roe();
    vector<Currency> getCurrencies() const;
    Table getTable() const;
    friend ostream& operator <<(ostream& os, const Roe& roe);

private:
    vector<Currency> _currencies;
    Table _table;
};

} //namespace
#endif /* ROE_H */
