#include "ofMain.h"
#include "ofApp.h"

//3 niveles de verbosidad: 2 extrema, 1 normal, 0 nada


//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
