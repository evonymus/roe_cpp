#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "roe.h"

using namespace std;
using namespace rapidjson;

namespace roe {
/**********************************************************************
*        Constructor:
* creates Roe object using json string 
**********************************************************************/

Roe::Roe( string json) {
    Document doc;
    char isTable = 0;
    // if json contains the whole table then parse remove square brackets
    if(json[0] == '[' ){
        //remove square brackets
        json = json.substr(1, json.rfind(']') - 1) ;
        // removing internal '\n' if there exists any
        json.erase(std::remove(json.begin(), json.end(),'\n'),json.end());

        isTable = 1;
    } 
    doc.Parse(json.c_str());

    // parsing single currency
    if(!isTable && doc.IsObject()) {
        Currency cur = Currency(doc["currency"].GetString()
                , doc["code"].GetString()
                , doc["rates"][0]["mid"].GetDouble());
        _currencies.push_back(cur); 
        _table = Table(doc["table"].GetString()
                , doc["rates"][0]["no"].GetString() 
                , doc["rates"][0]["effectiveDate"].GetString());
    // parsing the whole table
    } else if (isTable && doc.IsObject()) {        
        int size = doc["rates"].Size();
        int i = 0;
        _table = Table(doc["table"].GetString(), doc["no"].GetString(), doc["effectiveDate"].GetString());
        while( i < size) {
            Currency cur = Currency(doc["rates"][i]["currency"].GetString()
                    , doc["rates"][i]["code"].GetString()
                    , doc["rates"][i]["mid"].GetDouble());
            _currencies.push_back(cur);
            i++;
        }
    }
}

Roe::~Roe() {}

vector<Currency> Roe::getCurrencies() const {
    return _currencies;
}

Table Roe::getTable() const {
    return _table;
}


ostream& operator<<(ostream& os ,  const Roe& roe ){
    os << "========================================================================\n";
    os << "Table: " << roe.getTable().getTableType() << ", No: "<< roe.getTable().getTableNumber() 
        <<", date: " << roe.getTable().getDate() << "\n";
    os << "========================================================================\n";
    os << "   Code\t | ROE\t\t | Name \n";
    os << "========================================================================\n";
    for(auto curr : roe.getCurrencies()) {
        os << setw(6) << curr.getCode()<< "\t | "
            <<  setw(6) << curr.getValue()<< "\t | "
            <<  setw(12) << curr.getName() << "\n";
        os<< "------------------------------------------------------------------------\n";
    }
    return os;
}

}
