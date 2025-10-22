#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

#include <string>
#include <stack>

class BrowserHistory {
private:
    std::stack<std::string> backHistory;  
    std::string currentPage;          

public:
    BrowserHistory();

    void visitPage(std::string url);

    void goBack();

    bool canGoBack();

    std::string getCurrentPage();

    int getBackHistorySize();
};

#endif