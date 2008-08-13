#include <Scene/LayerNode.h>
#include <Meta/OpenGL.h>

#include <Renderers/OpenGL/TextureLoader.h>
#include <Logging/Logger.h>

using namespace OpenEngine::Renderers::OpenGL;

namespace OpenEngine {
namespace Scene {

    LayerNode::LayerNode(int x, int y) 
	: x(x),y(y) {}

void LayerNode::Apply(IRenderingView *rv) {
    
    glMatrixMode(GL_PROJECTION);	// Select Projection
    glPushMatrix();			// Push The Matrix
    glLoadIdentity();			// Reset The Matrix
    glOrtho( 0, x , y , 0, -1, 1 );	// Select Ortho Mode
    glMatrixMode(GL_MODELVIEW);		// Select Modelview Matrix
    glPushMatrix();			// Push The Matrix
    glLoadIdentity();			// Reset The Matrix
    // Render HUD


    //    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glDisable(GL_LIGHTING);

    if (texr != NULL) {
	if (texr->GetID() == 0) {
	    TextureLoader* tl = new TextureLoader();
	    tl->LoadTextureResource(texr);
	}
	glBindTexture(GL_TEXTURE_2D, texr->GetID());

                    
    } else {
	glBindTexture(GL_TEXTURE_2D, 0);

    }

    glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f(100,100,0);
    glTexCoord2f(1,0);
    glVertex3f(x-100,100,0);
    glTexCoord2f(1,1);
    glVertex3f(x-100,y-100,0);
    glTexCoord2f(0,1);
    glVertex3f(100,y-100,0);

    glEnd();


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
