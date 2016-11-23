#include "ofApp.h"
#include "Pila.h"
#include "Arbol.h"
//--------------------------------------------------------------
void ofApp::setup()
{
	Arbol<std::string>  *arbol = new Arbol<std::string>(new std::string("Presidente"), NULL, 1 );

	Arbol<std::string> *hacienda =   arbol->insertar(new std::string("Secretario de Hacienda"));
	Arbol<std::string> *marina = arbol->insertar(new std::string("Secretario de Marina"));
	Arbol<std::string> *defensa = arbol->insertar(new std::string("Secretario de Defensa"));

	hacienda->insertar(new std::string("Subsecretario del SAT"));
	hacienda->insertar(new std::string("Subsecretario del SAE"));

	marina->insertar(new std::string("Almirante del Pacifico"));
	marina->insertar(new std::string("Almirante del Atlantico"));

	defensa->insertar(new std::string("General de Zona I"));
	defensa->insertar(new std::string("General de Zona II"));
	defensa->insertar(new std::string("General de Zona III"));

	arbol->DFS();
	/*
	Pila<int> *p = new Pila<int>();
	p->Insert(new int(666));
	printf("vacia? %i \n", p->IsEmpty() ? 1 : 0);
	int t = *(p->pop());
	printf("vacia? %i \n", p->IsEmpty() ? 1 : 0);
	*/
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
