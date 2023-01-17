#define HEADER_USER_AGENT "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:106.0) Gecko/20100101 Firefox/106.0"

#define URL_LIHKG_HOME_PAGE "https://lihkg.com/category/1"

#define URL_LIHKG_MISC_JS "https://cdn.lihkg.com/static/2212210915-12qn8/js/misc.js"
#define URL_LIHKG_STYLE_JS "https://cdn.lihkg.com/static/2212210915-12qn8/js/styles.chunk.js"
#define URL_LIHKG_MAIN_JS "https://cdn.lihkg.com/static/2212210915-12qn8/js/main.js"

#define URL_LIHKG_PROPERTY "https://lihkg.com/api_v2/system/property"
#define URL_LIHKG_LATEST "https://lihkg.com/api_v2/thread/latest?cat_id=1&page=1&count=60&type=now"

// Function pointer
typedef size_t (*Callback_ResponseBody)(char *pBuffer, size_t ulSize, size_t ulItem, void *pData);
