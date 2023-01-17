#include <stdexcept>
#include <unistd.h>
#include "WebCrawlConstant.h"
#include "WebCrawlDataStruct.h"

CCurlHandler::CCurlHandler(const char *szCookieFile)
{
  curl_global_init(CURL_GLOBAL_ALL);

  m_CURL = curl_easy_init();
  if (m_CURL == NULL)
  {
    throw std::runtime_error("CCurlHandler == NULL");
  }

  // Set TLS 1.x
  curl_easy_setopt(m_CURL, CURLOPT_SSLVERSION, CURL_SSLVERSION_MAX_TLSv1_2);

  // Set User-Agent = Browser
  curl_easy_setopt(m_CURL, CURLOPT_USERAGENT, HEADER_USER_AGENT);

  // Set Cookie File (Save)
  m_szCookieFile = szCookieFile;
  curl_easy_setopt(m_CURL, CURLOPT_COOKIEJAR, m_szCookieFile);

  m_listHeader = NULL;
}

CCurlHandler::~CCurlHandler()
{
  if (!m_listHeader)
  {
    curl_slist_free_all(m_listHeader);
  }
  if (m_CURL)
  {
    curl_easy_cleanup(m_CURL);
  }
  curl_global_cleanup();
}

void CCurlHandler::SetCallback_ResponseBody(Callback_ResponseBody cbResponseBody)
{
  curl_easy_setopt(m_CURL, CURLOPT_WRITEFUNCTION, cbResponseBody);
  curl_easy_setopt(m_CURL, CURLOPT_WRITEDATA, &m_strResponseBody);
}

void CCurlHandler::AddHeader(const char *szHeader)
{
  m_listHeader = curl_slist_append(m_listHeader, szHeader);
  curl_easy_setopt(m_CURL, CURLOPT_HTTPHEADER, m_listHeader);
}

CURLcode CCurlHandler::SendRequest(const char *szURL, long lVerbose)
{
  curl_easy_setopt(m_CURL, CURLOPT_URL, szURL);
  curl_easy_setopt(m_CURL, CURLOPT_VERBOSE, lVerbose);
  CURLcode res = curl_easy_perform(m_CURL);
  sleep(5);
  return res;
}

const std::string CCurlHandler::GetLastResponseBody()
{
  return m_strResponseBody;
}

void CCurlHandler::ClearLastResponseBody()
{
  m_strResponseBody.clear();
}
