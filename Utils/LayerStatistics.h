#ifndef _GUI_LAYER_STATISTICS_H_
#define _GUI_LAYER_STATISTICS_H_

#include <Core/IListener.h>
#include <Core/EngineEvents.h>
#include <Utils/Timer.h>
#include <Display/TextSurface.h>

using namespace OpenEngine::Display;

namespace OpenEngine {
namespace Utils {

using namespace OpenEngine::Core;

class LayerStatistics : public IListener<ProcessEventArg> {
private:
    Timer timer;
	float interval;
	int frames;
	TextSurface* surface;

public:
	LayerStatistics(const float interval, TextSurface* ts);
    void Handle(OpenEngine::Core::ProcessEventArg arg);
};

}
}

#endif
