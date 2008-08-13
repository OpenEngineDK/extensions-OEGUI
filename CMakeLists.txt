
# Create the extension library
ADD_LIBRARY(Extensions_OEGUI
  Scene/LayerNode.cpp
  Display/Layer.cpp
  Display/TextSurface.cpp
  Utils/LayerStatistics.cpp
  Resources/CairoSurfaceResource.cpp
)

TARGET_LINK_LIBRARIES(Extensions_OEGUI
	${CAIRO_LIB}
)
