#pragma once


#include <string>
#include <memory>
#include <vector>

#include "NuiDevice.h"

class SKPrefs;

class SKApp {
public:
    SKApp();

    void init(SKPrefs &);
    void run();
    void stop();

    void onButton(unsigned id, unsigned value);
    void onEncoder(unsigned id, int value);

private:
    int execShell(const std::string &cmd);
    void runScript(const std::string &name, const std::string &cmd);
    int checkFileExists(const std::string &filename);
    void displayMenu();
    void activateItem();
    void saveState();

    unsigned POLL_MS_ = 1;
    unsigned ACTIVE_TIME_ = 5000; //5000 mSec
    std::string patchDir_;
    int activeCount_ = -1;

    NuiLite::NuiDevice device_;

    struct MenuItem {
        explicit MenuItem(const std::string &n) : name_(n) { ; }

        std::string name_;
    };

    std::vector<std::shared_ptr<MenuItem>> mainMenu_;

    bool sidekickActive_ = false;
    unsigned selIdx_ = 0;
    bool buttonState_[4] = {false, false, false, false};
    unsigned maxItems_ = 5;
    bool keepRunning_;

    std::string lastPatch_;

    bool loadOnStartup_;
    std::string stateFile_;
    int startupTime_;
    int startupCount_;
};