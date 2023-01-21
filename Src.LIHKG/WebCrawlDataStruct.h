#pragma once
#include <curl/curl.h>
#include <string>
#include "WebCrawlConstant.h"

class CCurlHandler
{
public:
  CCurlHandler(const char *szCookieFile = COOKIES_DEFAULT_PATH);
  ~CCurlHandler();

private:
  CURL *m_CURL;
  const char *m_szCookieFile;
  struct curl_slist *m_listHeader; // Linked-list
  std::string m_strResponseBody;

public:
  void CrossPlatformSleep(int s);

  void SetCallback_ResponseBody(Callback_ResponseBody cbResponseBody);

  void AddHeader(const char *szHeader);

  CURLcode SendRequest(const char *szURL, long lVerbose = 1L);

  const std::string GetLastResponseBody();
  void ClearLastResponseBody();
};
