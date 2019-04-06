// https://github.com/diederickh/ofxOsc/blob/master/addons/ofxOsc/examples/oscSenderExample/src/testApp.cpp

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(40, 100, 40);

	// open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);
	//sender.setup("10.0.1.40", 12346);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// display instructions
	char buf[256];
	sprintf(buf, "sending osc messages to %s:%d", HOST, PORT);
	ofDrawBitmapString(buf, 10, 20);
	ofDrawBitmapString("move the mouse to send osc message [/mouse/position <x> <y>]", 10, 50);
	ofDrawBitmapString("click to send osc message [/mouse/button <button> <\"up\"|\"down\">]", 10, 65);
	ofDrawBitmapString("press A to send osc message [/test 1 3.5 hello <time>]", 10, 80);
	ofDrawBitmapString("press B to send osc bundle [ [/bundle1 3] [/bundle2 5.5]\n    [ [/bundle3a nested_bundle_test] [/bundle3b test2] ] ]", 10, 95);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a' || key == 'A')
	{
		ofxOscMessage m;
		m.setAddress("/test");
		m.addIntArg(1);
		m.addFloatArg(3.5f);
		m.addStringArg("hello");
		m.addFloatArg(ofGetElapsedTimef());
		sender.sendMessage(m);
	}
	else if (key == 'b' || key == 'B')
	{
		ofxOscBundle b;

		// make message
		ofxOscMessage m;
		m.setAddress("/bundle1");
		m.addIntArg(3);
		// add to bundle
		b.addMessage(m);

		// and repeat
		m.clear();
		m.setAddress("/bundle2");
		m.addFloatArg(5.5f);
		// add to bundle
		b.addMessage(m);

		// make nested bundle
		ofxOscBundle nested_b;
		m.clear();
		m.setAddress("/bundle3a");
		m.addStringArg("nested bundle test");
		nested_b.addMessage(m);
		m.clear();
		m.setAddress("/bundle3b");
		m.addStringArg("test2");
		nested_b.addMessage(m);

		// add to outer bundle
		b.addBundle(nested_b);

		// send
		sender.sendBundle(b);
	}
	else if (key == 'c' || key == 'C')
	{
		ofxOscMessage m;
		m.setAddress("/test");
		m.addStringArg("hello");		
		sender.sendMessage(m);
		cout << "send" << endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	ofxOscMessage m;
	m.setAddress("/mouse/position");
	m.addIntArg(x);
	m.addIntArg(y);
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofxOscMessage m;
	m.setAddress("/mouse/button");
	m.addStringArg("down");
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ofxOscMessage m;
	m.setAddress("/mouse/button");
	m.addStringArg("up");
	sender.sendMessage(m);
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
