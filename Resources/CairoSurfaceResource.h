

#ifndef _OEGUI_CAIRO_SURFACE_RESOURCE_H_
#define _OEGUI_CAIRO_SURFACE_RESOURCE_H_

#include <Resources/ITextureResource.h>
#include <Meta/OpenGL.h>
#include <cairo.h>

namespace OpenEngine {
namespace Resources {


    class CairoSurfaceResource : public ITextureResource {
    private:
	GLuint id;
	int width,height;
	cairo_surface_t* surface;
	cairo_t* context;
	unsigned char* data;
    public:
	

	/**
	 * Create a new resoruce for a cairo surface
	 * @param surface Must be a cairo image surface
	 */
	CairoSurfaceResource(cairo_surface_t* surface);
	cairo_t* GetContext();
	void Rebind();
	static cairo_surface_t* CreateCairoSurface(int width, int height);

	// From ITextureResource
	void Load();
	void Unload();

	int GetID();
	void SetID(int);
	int GetWidth();
	int GetHeight();
	int GetDepth();
	unsigned char* GetData();
    };


typedef boost::shared_ptr<CairoSurfaceResource> CairoSurfaceResourcePtr;

}
}

#endif
