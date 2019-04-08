// https://github.com/diederickh/ofxOsc/blob/master/addons/ofxOsc/examples/oscSenderExample/src/testApp.h

#pragma once


#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOsc.h"


using namespace std;


//#define HOST "localhost"
#define HOST "192.168.7.20"
#define PORT 9001


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		ofxOscSender sender;
		
};


#endif
