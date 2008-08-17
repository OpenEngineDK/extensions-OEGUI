#include <Utils/LayerStatistics.h>
#include <Utils/Convert.h>

namespace OpenEngine {
namespace Utils {

LayerStatistics::LayerStatistics(float interval, TextSurface* ts)
    : interval(interval),
      frames(0),
      surface(ts) {
    timer.Start();
}
      
void LayerStatistics::Handle(OpenEngine::Core::ProcessEventArg arg) {
    frames += 1;
    unsigned int elapsed = timer.GetElapsedTime().AsInt();
    if (elapsed > interval) {
        surface->SetString(Convert::ToString<double>( (double)frames * 1000000 / elapsed));
        frames = 0;
        timer.Reset();
    }
}

}
}
