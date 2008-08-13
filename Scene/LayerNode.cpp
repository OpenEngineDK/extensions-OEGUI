#include <Scene/LayerNode.h>
#include <Meta/OpenGL.h>

#include <Renderers/OpenGL/TextureLoader.h>
#include <Logging/Logger.h>

using namespace OpenEngine::Renderers::OpenGL;

namespace OpenEngine {
namespace Scene {

    LayerNode::LayerNode(int w, int h) 
	: w(w),h(h) {}

    void LayerNode::AddLayer(Layer l) {
	layers.push_back(l);
    }

void LayerNode::Apply(IRenderingView *rv) {
    
    glMatrixMode(GL_PROJECTION);	// Select Projection
    glPushMatrix();			// Push The Matrix
    glLoadIdentity();			// Reset The Matrix
    glOrtho( 0, w , h , 0, -1, 1 );	// Select Ortho Mode
    glMatrixMode(GL_MODELVIEW);		// Select Modelview Matrix
    glPushMatrix();			// Push The Matrix
    glLoadIdentity();			// Reset The Matrix
    // Render HUD


    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glDisable(GL_LIGHTING);
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    for(list<Layer>::iterator itr = layers.begin();
	itr != layers.end();
	itr++) {
	
	ITextureResourcePtr texr = itr->texr;

	float width = texr->GetWidth();
	float height = texr->GetHeight();

	float x = itr->origin[0];
	float y = itr->origin[1];

	if (texr != NULL) {
	    if (texr->GetID() == 0) {
		TextureLoader* tl = new TextureLoader();
		tl->LoadTextureResource(texr);
	    }
	    glBindTexture(GL_TEXTURE_2D, texr->GetID());
                    
	} else {
	    glBindTexture(GL_TEXTURE_2D, 0);

	}

	glColor3f(1,1,1);

	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(x,y,0);

	glTexCoord2f(0,1);
	glVertex3f(x,y+height,0);

	glTexCoord2f(1,1);
	glVertex3f(x+width,y+height,0);

	glTexCoord2f(1,0);
	glVertex3f(x+width,y,0);

	glEnd();

    }

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    // Reset state
    glMatrixMode( GL_PROJECTION );	// Select Projection
    glPopMatrix();			// Pop The Matrix
    glMatrixMode( GL_MODELVIEW );	// Select Modelview
    glPopMatrix();			// Pop The Matrix
}


}
}
