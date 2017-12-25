#ifndef _TABLE_
#define _TABLE_ 
#include <string>

namespace roe {
class Table
{
public:
    Table();
    Table (std::string tableType
          , std::string tableNumber
          , std::string date);
    virtual ~Table ();
     std::string getTableType() const ;
     std::string getTableNumber() const;
     std::string getDate() const;

private:
    /* data */
    std::string _tableType;
    std::string _tableNumber;
    std::string _date;
};
}
#endif /* ifndef _TABLE_ */
