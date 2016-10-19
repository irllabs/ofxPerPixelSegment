#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // if you want to change any of the options
    // you need to do it here, before trainModels()
    // and before loadModels()
    
    // to train a new model, uncomment the following lines
    // and make sure there are images in:
    // data/new-handtracker/img/*.jpg
    // data/new-handtracker/mask/*.jpg
//    segmenter.setPath("new-handtracker");
//    segmenter.trainModels();
    
    segmenter.loadModels();
    
    cam.setup(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        segmenter.detect(cam);
        segmenter.getForegroundMask(foregroundMask);
        foregroundMask.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw the camera as a background
    cam.draw(0, 0);
    
    if(foregroundMask.isAllocated()) {
        ofPushStyle();
        // draw the mask as a semi-transparent colored overlay
        ofSetColor(ofColor::magenta, 64);
        foregroundMask.draw(0, 0, 640, 480);
        ofPopStyle();
    }
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
