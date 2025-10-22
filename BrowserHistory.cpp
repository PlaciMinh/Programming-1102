#include "BrowserHistory.h"
#include <iostream>

BrowserHistory::BrowserHistory() {
    currentPage = "home page";
}

void BrowserHistory::visitPage(std::string url) {
    backHistory.push(currentPage);
    currentPage = url;
}

void BrowserHistory::goBack() {
    if (!backHistory.empty()) {
        currentPage = backHistory.top();
        backHistory.pop();
    }
}

bool BrowserHistory::canGoBack() {
    return !backHistory.empty();
}

std::string BrowserHistory::getCurrentPage() {
    return currentPage;
}

int BrowserHistory::getBackHistorySize() {
    return backHistory.size();
}