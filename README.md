# WebAutomation
This repo aims to automate web scraping with c++ (libcurl) on the level of HTTP request/response.

###### Notice
This repo only compiled and tested on Linux. However, porting to Windows is an ongoing task.

###### v0.0.2 (developing)
Testing site: HERMES, ...

Special policy:
1. Suspect the website is static, which depends on HTML structure.

###### v0.0.1
Testing site: LIHKG

Special policy (developed in order):
1. Fake User-Agent on Request AddHeader
2. Reuse cookies by saving into a file
3. Keep the connection alive for the same domain
4. Add delay (sleep) between request to simulate a slow human

###### Why c++ (libcurl)
1. Using c++ in low level HTTP request/response provides the largest control of handling.

###### Why not Python
1. Using Python relies on 3rd-party library.
2. Using Python would not be as efficient as c++.
3. Using Python is harder to manage the low level communication.
