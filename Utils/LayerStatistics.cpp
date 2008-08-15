#include <Utils/LayerStatistics.h>
#include <Logging/Logger.h>
#include <sstream>

namespace OpenEngine {
    namespace Utils {

LayerStatistics::LayerStatistics(float interval, TextSurface* ts)
  : interval(interval),
    elapsed(0),
    frames(0),
	  surface(ts) {}
      
      void LayerStatistics::Handle(OpenEngine::Core::InitializeEventArg arg) 
      {
      }
      
      void LayerStatistics::Handle(OpenEngine::Core::ProcessEventArg arg) {
        using namespace OpenEngine::Logging;
        
        float deltaTime = 1;
        logger.error << "Timing Broken in LayerStatistics" << logger.end;

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

      void LayerStatistics::Handle(OpenEngine::Core::DeinitializeEventArg arg) 
      {
      }

    }
}

