#ifndef _GUI_LAYER_NODE_H_
#define _GUI_LAYER_NODE_H_

#include <Scene/RenderNode.h>
#include <Resources/ITextureResource.h>
#include <Renderers/IRenderingView.h>
#include <Display/Layer.h>

#include <list>

using OpenEngine::Resources::ITextureResourcePtr;
using OpenEngine::Renderers::IRenderingView;
using OpenEngine::Display::Layer;

namespace OpenEngine {
namespace Scene {

    class LayerNode : public RenderNode {
    private:
	int w,h;
	std::list<Layer> layers;
    public:
	
	LayerNode(int w, int h);

	void AddLayer(Layer l);

	virtual void Apply(IRenderingView *rv);

    };

}
}

#endif 
