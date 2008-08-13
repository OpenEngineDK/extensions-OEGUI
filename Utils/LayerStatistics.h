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

	    // IModule methods
    bool IsTypeOf(const std::type_info& inf);
    void Initialize();
    void Process(const float deltaTime, const float percent);
    void Deinitialize();

    };

}
}


#endif
