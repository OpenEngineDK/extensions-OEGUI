#include <Utils/LayerStatistics.h>

#include <sstream>

namespace OpenEngine {
    namespace Utils {

LayerStatistics::LayerStatistics(float interval, TextSurface* ts)
        : interval(interval),
          elapsed(0),
          frames(0),
	  surface(ts) {}

    bool LayerStatistics::IsTypeOf(const std::type_info& inf) { 
        return typeid(LayerStatistics) == inf;
    }

    void LayerStatistics::Initialize() {
        
    }

    void LayerStatistics::Process(const float deltaTime, const float percent) {
        elapsed += deltaTime;
        frames += 1;
        if (elapsed > interval) {
            
	    ostringstream ost;
	    ost << "FPS: " << frames * 1000 / elapsed;
	    	   
	    surface->SetString(ost.str());

            elapsed = 0;
            frames = 0;
        }
    }

    void LayerStatistics::Deinitialize() {

    }


    }
}
