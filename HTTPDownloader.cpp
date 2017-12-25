#include "HTTPDownloader.h"
#include <curl/curl.h>
#include <sstream>
#include <iostream>


static size_t write_data(void* ptr
        , size_t size
        , size_t nmemb
        , void* stream) {
   std::string data((const char*) ptr
          , (size_t) size * nmemb);
    
    *((std::stringstream*) stream) << data << std::endl;
    return size * nmemb;
}

roe::HTTPDownloader::HTTPDownloader() {
    curl_ = curl_easy_init();
}

roe::HTTPDownloader::~HTTPDownloader() {
    curl_easy_cleanup(curl_);
}

std::string roe::HTTPDownloader::download(const std::string& url) {
    std::stringstream out;

    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &out);

    CURLcode res = curl_easy_perform(curl_);
    /* check for errors*/
    if (res != CURLE_OK) {
        std::cout << "An error occured: \n"; 
    }
    return out.str();
}

