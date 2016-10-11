#ifndef _CURRENCY_
#define _CURRENCY_ 
#include <string>
namespace roe {
class Currency
{
public:
    Currency();
    Currency (std::string name, std::string code, double value);
    virtual ~Currency ();

    std::string getName() const;
    std::string getCode() const;
    double getValue() const;

protected:
    /* data */
    std::string _name;
    std::string _code;
    double _value;
    
};
}
#endif /* ifndef _CURRENCY_ */
