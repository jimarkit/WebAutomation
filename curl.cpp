#include <fstream>
#include <iostream>
#include <string>
#include "WebCrawlDataStruct.h"
#include "WebCrawlConstant.h"
using std::ofstream;
using std::string;

static size_t body_callback(char *pBuffer, size_t ulSize, size_t ulItem, void *pData)
{
  string *pStrData = (string *)pData;
  pStrData->append(pBuffer, ulSize * ulItem);
  return ulItem * ulSize;
}

int main(void)
{
  CCurlHandler objCurlHandler;
  objCurlHandler.SetCallback_ResponseBody(body_callback);
  objCurlHandler.AddHeader("Connection: keep-alive");

  {
    // Landing page to get cookie
    objCurlHandler.SendRequest(URL_LIHKG_HOME_PAGE);
  }

  {
    // Pretend to be a browser to request dummy js files.
    objCurlHandler.SendRequest(URL_LIHKG_MISC_JS);
    objCurlHandler.SendRequest(URL_LIHKG_STYLE_JS);
    objCurlHandler.SendRequest(URL_LIHKG_MAIN_JS);
  }

  {
    // This is the category dictionary of LIHKG
    objCurlHandler.AddHeader("Referer: https://lihkg.com/category/1");
    objCurlHandler.SendRequest(URL_LIHKG_PROPERTY);
    objCurlHandler.ClearLastResponseBody();
  }

  {
    // This is the main interest of this example to get all latest threads
    objCurlHandler.SendRequest(URL_LIHKG_LATEST);
  }

  // Finally, save the response body of the last response
  ofstream fOutput("output.log");
  fOutput << objCurlHandler.GetLastResponseBody();

  return 0;
}
