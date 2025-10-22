#include <iostream>
#include "BrowserHistory.h"
using namespace std;

int main() {
    BrowserHistory browser;

    cout << "Current Page: " << browser.getCurrentPage() << endl;

    browser.visitPage("https://google.com");
    browser.visitPage("https://openai.com");
    browser.visitPage("https://github.com");

    cout << "\nCurrent Page: " << browser.getCurrentPage() << endl;
    cout << "Back history size: " << browser.getBackHistorySize() << endl;

    if (browser.canGoBack()) {
        browser.goBack();
        cout << "\nWent back! Current Page: " << browser.getCurrentPage() << endl;
    }

    if (browser.canGoBack()) {
        browser.goBack();
        cout << "Went back again! Current Page: " << browser.getCurrentPage() << endl;
    }

    browser.goBack();
    cout << "\nFinal Current Page: " << browser.getCurrentPage() << endl;
    cout << "Remaining Back History Size: " << browser.getBackHistorySize() << endl;

    return 0;
}