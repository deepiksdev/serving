#include <fstream>
#include <sstream>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size,
                            size_t nmemb, void *userp)
{
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

int main(int argc, char** argv)
{
  char* url = argv[1];
  CURL *curl;
  std::string readBuffer;
  curl = curl_easy_init();
  if(curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
      curl_easy_perform(curl);
      curl_easy_cleanup(curl);
    }
  // readBuffer contains the image as a string

  std::istringstream imageFile(readBuffer, std::ios::binary);
  // imageFile contains the image as an istringstream

  std::istream& imageFileBis(imageFile);
  // imageFileBis contains the image as an istream

  std::ofstream file("/home/remi/test_rewrite.jpg");
  file << imageFile.str();

  return 0;
}
