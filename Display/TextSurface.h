#ifndef _OE_TEXT_SURFACE_H_
#define _OE_TEXT_SURFACE_H_

#include <Resources/CairoSurfaceResource.h>
#include <string>

using namespace std;
using namespace OpenEngine::Resources;

namespace OpenEngine {
    namespace Display {

class TextSurface {
private:
    string text;
    CairoSurfaceResource &resource;
public: 
    TextSurface(CairoSurfaceResource &res,string t);
    void SetString(string t);
    void Draw();
};

    }
}

#endif
