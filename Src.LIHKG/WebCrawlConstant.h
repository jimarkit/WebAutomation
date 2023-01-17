#define COOKIES_DEFAULT_PATH "./cookies.txt"

#define HEADER_USER_AGENT "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:106.0) Gecko/20100101 Firefox/106.0"

#define URL_LIHKG_HOME_PAGE "https://lihkg.com/category/1"
#define URL_LIHKG_LATEST "https://lihkg.com/api_v2/thread/latest?cat_id=1&page=1&count=60&type=now"

// Function pointer
typedef size_t (*Callback_ResponseBody)(char *pBuffer, size_t ulSize, size_t ulItem, void *pData);
