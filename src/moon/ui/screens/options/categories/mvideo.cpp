#include "mvideo.h"

#include "moon/texts/moon-loader.h"
#include "moon/ui/widgets/mw-value.h"

using namespace std;

extern "C" {
#include "pc/configfile.h"
}

vector<wstring> filters = {
    L"TEXT_OPT_NEAREST",
    L"TEXT_OPT_LINEAR",
    L"TEXT_OPT_THREEPT"
};

MVideoCategory::MVideoCategory() : MoonCategory("TEXT_OPT_VIDEO"){
    int texY = 91;
    int hudY = 108;
#ifndef TARGET_SWITCH
    this->catOptions.push_back(new MWValue(22, 57,  "TEXT_OPT_FSCREEN",   {.bvar = &configWindow.fullscreen}, true));
    this->catOptions.push_back(new MWValue(22, 74,  "TEXT_OPT_VSYNC",     {.bvar = &configWindow.vsync}, true));
#else
    texY = 57;
    hudY = 74;
#endif
    this->catOptions.push_back(new MWValue(22, texY, "TEXT_OPT_TEXFILTER", {.index = (int*)&configFiltering, .values = &filters, .valueKeys = true}, true));
#ifndef TARGET_SWITCH
    this->catOptions.push_back(new MWValue(22, texY, "Enable antialias",   {.bvar  = &configWindow.enable_antialias}, false));
    this->catOptions.push_back(new MWValue(22, texY, "Antialias level",    {.ivar = (int*)&configWindow.antialias_level, .max = 16, .min = 2, .step = 2, .rawValue = true}, false));
#endif
    this->catOptions.push_back(new MWValue(22, texY, "TEXT_OPT_TEXFILTER", {.index = (int*)&configFiltering, .values = &filters, .valueKeys = true}, true));
    this->catOptions.push_back(new MWValue(22, hudY, "TEXT_OPT_HUD",       {.bvar = &configHUD}, true));
#ifndef TARGET_SWITCH
    this->catOptions.push_back(new MWValue(22, 125, "TEXT_OPT_RESETWND",  {.btn = [](){
        configWindow.reset = true;
        configWindow.settings_changed = true;
    }}, true));
    this->catOptions.push_back(new MWValue(22, 142, "TEXT_OPT_APPLY",     {.btn = [](){
        configWindow.settings_changed = true;
    }}, true));
#endif
}