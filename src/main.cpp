#include <drogon/drogon.h>

int main() {
    // تنظیم یک مسیر برای پاسخ به درخواست‌ها
    drogon::app()
        .registerHandler("/hello", [](const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("Hello, Drogon!");
            callback(resp);
        })
        .addListener("0.0.0.0", 8080)
        .run();

    return 0;
}
