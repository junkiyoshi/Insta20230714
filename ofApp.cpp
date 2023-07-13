#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(2);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofColor color;
	for (int k = 0; k < 10; k++) {

		ofRotate(10);

		color.setHsb(ofMap(k, 0, 10, 0, 255), 180, 255);
		ofSetColor(color);
		
		vector<glm::vec2> vertices;
		for (int i = 0; i < 60; i++) {

			auto radius = ofMap(sin((ofGetFrameNum() + i) * 0.314 * 0.75), -1, 1, 200, 300);
			auto deg = (ofGetFrameNum() + i) * 4;
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			vertices.push_back(location);
		}

		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();

		ofFill();
		ofDrawCircle(vertices[0], 3);
		ofDrawCircle(vertices[vertices.size() - 1], 3);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}