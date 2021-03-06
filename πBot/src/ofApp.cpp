#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// Config
	ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, 0);
	ofSetVerticalSync(false);
	ofSetFrameRate(60);
	ofSetBackgroundColorHex(ofHexToInt("0D1B1E"));
	ofEnableDataPath();
	
	// Load
	chat = Chat(std::move("chat.txt"));
	piBot.fillBrain(std::move("brain.json"), chat);
	
	// Init
	w = ofGetWidth();
	h = ofGetHeight();
	
	// GUI
		// Fonts
	ofxSmartFont::add("../fonts/SFDisplayRegular.otf", 27, "SFDisplayRegular");
	input.setFont(ofxSmartFont::get("SFDisplayRegular"));
	chat.setFont(ofxSmartFont::get("SFDisplayRegular"));
	
		// Rect
	input.setRect(25, h - 100, w - 50, 70, 20);
	
	// TEST
	Node n;
	n.value = "spanish";
	n.entity = "language";
	n.addAttribute("territory", "spain");
	n.addAttribute("color", "red and yellow");
	n.addSynonym("castellano");
	n.addActionToValue(Action("improve"));
	piBot.addValue(n);
	piBot.addEntity("language");
	piBot.addEntity("food");
	piBot.addEntity("animal");
	piBot.addRelation("speak");
	piBot.addRelation("write");
	piBot.addRelation("talk");
}

//--------------------------------------------------------------
void ofApp::update()
{
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	input.draw();
	chat.update();
}

//--------------------------------------------------------------
void ofApp::exit()
{
	chat.saveChat();
	piBot.saveBrain();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	input.update(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	this->w = w;
	this->h = h;
	input.setRect(25, h - 100, w - 50, 70, 20);
	chat.setRect(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	chat.writeMessage(true, msg.message);
	Message response = piBot.whatAreYouTalkingAbout(msg.message);
	responseMessage(response);
}

//--------------------------------------------------------------

void ofApp::responseMessage(Message &msg)
{
	if (not msg.error)
	{
		chat.writeMessage(false, msg.text);
	}
	
	else
	{
		cerr << msg.text << endl;
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
