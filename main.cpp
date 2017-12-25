#include <iostream>
#include <string>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "HTTPDownloader.h"
#include "roe.h"

using namespace rapidjson;
using namespace std;
using namespace roe;

const std::string HOST="http://api.nbp.pl/api/exchangerates";

static const char* kTypeNames[] =
    { "Null", "False", "True", "Object", "Array", "String", "Number" };

/***************************************************************************
 *  Function takes the number of arguments and the return appropriate url  *
 ***************************************************************************/

std::string getUrl(const int argc
      ,  char* const argv[], const char* format="json") {
    switch(argc) {
        case 1: return HOST + "/tables/a/?format=" + format ;
                break;
        case 2: if(char_traits<char>::length(argv[1])== 3) {
                    return HOST + "/rates/a/" + argv[1] + "/?format=" + format;
                } else {
                    return HOST + "/tables/a/" + argv[1] + "?format=" + format ;
                }
                break;
        case 3: return HOST + "/rates/a/" + argv[1] + "/" + argv[2] + "/?format=" + format;
                break;
        case 4: return HOST + "/rates/a/" + argv[1] + "/" + argv[2] + "/?format=" + argv[3];
                break;
    }
    return "";
}

/***************************************************************************************
 *  Function takes displays on the console ROE for a given currency displayed as JSON  *
 *  params: - optional: currency [3-char code], date express as yyyy-mm-dd
 ***************************************************************************************/

int getRoe(int argc,  char* argv[]) {
    int exit_code = 0;
    HTTPDownloader downloader;

    std::string url = getUrl(argc, argv );
    std::string content = downloader.download(url);
    Roe roe(content);
    cout << roe;
    return exit_code;
}

int main(int argc, char *argv[])
{
    int res= getRoe(argc, argv);

    return res;
}
