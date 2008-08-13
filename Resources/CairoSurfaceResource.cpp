#include <Resources/CairoSurfaceResource.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Resources {

    CairoSurfaceResource::CairoSurfaceResource(cairo_surface_t *surface)
	: id(0),surface(surface) {
	context = cairo_create(surface);
	data = cairo_image_surface_get_data(surface);
	width = cairo_image_surface_get_width(surface);
	height = cairo_image_surface_get_height(surface);
    }

    void CairoSurfaceResource::Rebind() {
	// Try to use textureloader instead?
	if (id) {
	    glDeleteTextures (1, &id);
	    glGenTextures (1, &id);

	    glBindTexture(GL_TEXTURE_2D, id);

	    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);



	    glTexImage2D(GL_TEXTURE_2D,
			 0,
			 GL_RGBA,
			 width,
			 height,
			 0,
			 GL_RGBA,
			 GL_UNSIGNED_BYTE,
			 data);
	}
    }

    cairo_surface_t* CairoSurfaceResource::CreateCairoSurface(int width, int height) {
	int channels = 4;
	unsigned char *buffer = (unsigned char*)calloc(channels * width * height,
						       sizeof(unsigned char));
	// TODO : check for memory fail
	cairo_surface_t* ret = 
	    cairo_image_surface_create_for_data(buffer,
						CAIRO_FORMAT_ARGB32,
						width,
						height,
						channels * width);
	// TODO : check for errors
	
	
	// TODO : check for more errors!
	
	return ret;
    }

    cairo_t* CairoSurfaceResource::GetContext() {
	return context;
    }
    
    void CairoSurfaceResource::Load() {}
    void CairoSurfaceResource::Unload() {}
    int CairoSurfaceResource::GetID() {return id;}
    void CairoSurfaceResource::SetID(int i) {id = i;}
    int CairoSurfaceResource::GetWidth() {return width;}
    int CairoSurfaceResource::GetHeight() {return height;}
    int CairoSurfaceResource::GetDepth() {return 32;}
    unsigned char* CairoSurfaceResource::GetData() {
	// for (int i=0;i<height;i++) {
	//     for (int j=0;j<width;j++) {
	// 	logger.info << "|" << data[height*i+j] << "|" << logger.end;
	//     }
	// }
	return data;
    }
}
}
