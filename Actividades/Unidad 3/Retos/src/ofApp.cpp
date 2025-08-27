#include "ofApp.h"

void ofApp::setup() {
	ofBackground(100);
	ofSetFrameRate(75);

	xStep = 20;
	yStep = 20;
	distDiv = 50.0f;
	amplitud = 150.0f;
	sphereRadius = 5.0f;

	sphereSelected = false;

	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += xStep) {
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += yStep) {
			float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
			spherePositions.push_back(ofVec3f(x, y, z));
		}
	}
}

void ofApp::update() {
	spherePositions.clear();
	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += xStep) {
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += yStep) {
			float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
			spherePositions.push_back(ofVec3f(x, y, z));
		}
	}
}

void ofApp::draw() {
	cam.begin();

	ofSetColor(225, 120, 0);
	for (auto & pos : spherePositions) {
		if (sphereSelected && pos == selectedSpherePos) {
			ofSetColor(0, 225, 0);
			ofDrawSphere(pos, sphereRadius * 1.5);
			ofSetColor(225, 120, 0);
		} else {
			ofDrawSphere(pos, sphereRadius);
		}
	}

	cam.end();

	ofSetColor(0);
	ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 20, 20);
	ofDrawBitmapString("Step: " + ofToString(xStep), 20, 40);
	ofDrawBitmapString("DistDiv: " + ofToString(distDiv), 20, 60);
	ofDrawBitmapString("Amplitud: " + ofToString(amplitud), 20, 80);

	if (sphereSelected) {
		ofDrawBitmapString("Seleccionada: " + ofToString(selectedSpherePos.x) + ", " + ofToString(selectedSpherePos.y) + ", " + ofToString(selectedSpherePos.z),
			20, 100);
	}
}

void ofApp::keyPressed(int key) {
	if (key == OF_KEY_UP) amplitud += 10;
	if (key == OF_KEY_DOWN) amplitud -= 10;
	if (key == OF_KEY_RIGHT) distDiv += 2;
	if (key == OF_KEY_LEFT) distDiv -= 2;
	if (key == '+') {
		xStep += 2;
		yStep += 2;
	}
	if (key == '-') {
		xStep -= 2;
		yStep -= 2;
	}
}

void ofApp::mousePressed(int x, int y, int button) {
	ofVec3f rayStart, rayEnd;
	convertMouseToRay(x, y, rayStart, rayEnd);

	sphereSelected = false;
	for (auto & pos : spherePositions) {
		ofVec3f intersectionPoint;
		if (rayIntersectsSphere(rayStart, rayEnd - rayStart, pos, sphereRadius, intersectionPoint)) {
			sphereSelected = true;
			selectedSpherePos = pos;
			break;
		}
	}
}

void ofApp::convertMouseToRay(int mouseX, int mouseY, ofVec3f & rayStart, ofVec3f & rayEnd) {
	glm::mat4 modelview = cam.getModelViewMatrix();
	glm::mat4 projection = cam.getProjectionMatrix();
	ofRectangle viewport = ofGetCurrentViewport();

	float x = 2.0f * (mouseX - viewport.x) / viewport.width - 1.0f;
	float y = 1.0f - 2.0f * (mouseY - viewport.y) / viewport.height;

	glm::vec4 rayStartNDC(x, y, -1.0f, 1.0f);
	glm::vec4 rayEndNDC(x, y, 1.0f, 1.0f);

	glm::vec4 rayStartWorld = glm::inverse(projection * modelview) * rayStartNDC;
	glm::vec4 rayEndWorld = glm::inverse(projection * modelview) * rayEndNDC;

	rayStartWorld /= rayStartWorld.w;
	rayEndWorld /= rayEndWorld.w;

	rayStart = ofVec3f(rayStartWorld.x, rayStartWorld.y, rayStartWorld.z);
	rayEnd = ofVec3f(rayEndWorld.x, rayEndWorld.y, rayEndWorld.z);
}

bool ofApp::rayIntersectsSphere(const ofVec3f & rayStart, const ofVec3f & rayDir,
	const ofVec3f & sphereCenter, float sphereRadius,
	ofVec3f & intersectionPoint) {
	ofVec3f oc = rayStart - sphereCenter;

	float a = rayDir.dot(rayDir);
	float b = 2.0f * oc.dot(rayDir);
	float c = oc.dot(oc) - sphereRadius * sphereRadius;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0) return false;

	float t = (-b - sqrt(discriminant)) / (2.0f * a);
	intersectionPoint = rayStart + t * rayDir;
	return true;
}
