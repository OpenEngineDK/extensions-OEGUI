// Hej verden

#ifndef _GUI_LAYER_NODE_H_
#define _GUI_LAYER_NODE_H_

#include <Renderers/IRenderNode.h>
#include <Resources/ITextureResource.h>
#include <Renderers/IRenderingView.h>
#include <Display/Layer.h>

using OpenEngine::Resources::ITextureResourcePtr;
using OpenEngine::Renderers::IRenderingView;
using OpenEngine::Display::Layer;

namespace OpenEngine {
namespace Scene {

    class LayerNode : public IRenderNode {
    private:
	int w,h;
	list<Layer> layers;
    public:
	
	LayerNode(int w, int h);

	void AddLayer(Layer l);

	virtual void Apply(IRenderingView *rv);

    };

}
}

#endif 
