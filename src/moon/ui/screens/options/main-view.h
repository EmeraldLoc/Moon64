#ifndef MoonScreenTest
#define MoonScreenTest
#include "moon/ui/interfaces/moon-screen.h"

class MoonOptMain : public MoonScreen {
public:
    void Update();
    void Draw();
    void Mount();
private:
    void setCategory(int index);
};


#endif