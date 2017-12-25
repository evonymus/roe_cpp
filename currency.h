#ifndef _CURRENCY_
#define _CURRENCY_ 
#include <string>
namespace roe {
/*!
 * class currency: stores information on a single currency
 */
class Currency
{
public:
    Currency (std::string name, std::string code, double value);
    virtual ~Currency ();

    std::string getName() const;
    std::string getCode() const;
    double getValue() const;

protected:
    /* data */
    std::string name_;
    std::string code_;
    double value_;
    
};
}
#endif /* ifndef _CURRENCY_ */
