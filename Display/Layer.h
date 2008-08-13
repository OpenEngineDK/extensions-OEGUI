#ifndef _GUI_LAYER_H_
#define _GUI_LAYER_H_

#include <Resources/ITextureResource.h>
#include <Math/Vector.h>

using namespace OpenEngine::Resources;
using namespace OpenEngine::Math;

namespace OpenEngine {
namespace Display {


    class Layer {
    public:
	ITextureResourcePtr texr;
	Vector<2,float> origin;
	
	Layer(int x, int y);
    };

}
}


#endif
