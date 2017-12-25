/*********************************************************************
 *                        HTTPDownloader.hpp                         *
 *********************************************************************/
#ifndef _HTTPDOWNLOADER_H
#define _HTTPDOWNLOADER_H
#include <string>
namespace roe { 
class HTTPDownloader {
public:
    HTTPDownloader ();
    virtual ~HTTPDownloader ();

    std::string download(const std::string& url);
private:
    void* curl_;
};
}
#endif
