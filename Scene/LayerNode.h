// Hej verden

#ifndef _GUI_LAYER_NODE_H_
#define _GUI_LAYER_NODE_H_

#include <Renderers/IRenderNode.h>
#include <Resources/ITextureResource.h>
#include <Renderers/IRenderingView.h>

using OpenEngine::Resources::ITextureResourcePtr;
using OpenEngine::Renderers::IRenderingView;

namespace OpenEngine {
namespace Scene {

    class LayerNode : public IRenderNode {
    private:
	int x,y;
    public:
	ITextureResourcePtr texr;
	
	LayerNode(int x, int y);
	virtual void Apply(IRenderingView *rv);

    };

}
}

#endif 
