#include "HTTPDownloader.h"
#include <curl/curl.h>
#include <sstream>
#include <iostream>

using namespace std;

static size_t write_data(void* ptr
        , size_t size
        , size_t nmemb
        , void* stream) {
    string data((const char*) ptr, (size_t) size * nmemb);
    *((std::stringstream*) stream) << data << endl;
    return size * nmemb;
}

HTTPDownloader::HTTPDownloader() {
    curl = curl_easy_init();
}

HTTPDownloader::~HTTPDownloader() {
    curl_easy_cleanup(curl);
}

std::string HTTPDownloader::download(const std::string& url) {
    std::stringstream out;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);

    CURLcode res = curl_easy_perform(curl);
    /* check for errors*/
    if (res != CURLE_OK) {
        std::cout << "An error occured: \n"; 
    }
    return out.str();
}

