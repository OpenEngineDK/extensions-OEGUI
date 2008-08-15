#ifndef _GUI_LAYER_STATISTICS_H_
#define _GUI_LAYER_STATISTICS_H_

#include <Core/IModule.h>
#include <Display/TextSurface.h>

using namespace OpenEngine::Display;

namespace OpenEngine {
namespace Utils {

    using namespace OpenEngine::Core;

    class LayerStatistics : public IModule {
    private:
	float interval, elapsed;
	int frames;
	TextSurface* surface;

    public:
	LayerStatistics(const float interval, TextSurface* ts);

  void Handle(OpenEngine::Core::InitializeEventArg arg);
  void Handle(OpenEngine::Core::ProcessEventArg arg);
  void Handle(OpenEngine::Core::DeinitializeEventArg arg);

    };

}
}


#endif
