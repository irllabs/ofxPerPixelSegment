#include "ofApp.h"

#include <opencv2/opencv.hpp>

#include "FeatureComputer.hpp"
#include "Classifier.h"
#include "LcBasic.h"
#include "HandDetector.hpp"

#include "ofxCv.h"

using namespace std;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    trackerReady = false;
    
    target_width = 320;			// for resizing the input (small is faster)
    
    // number of models used to compute a single pixel response
    // must be less than the number of training models
    // only used at test time
    num_models_to_average = 10;
    
    // runs detector on every 'step_size' pixels
    // only used at test time
    // bigger means faster but you lose resolution
    // you need post-processing to get contours
    step_size = 3;
    
    // Assumes a certain file structure e.g., /root/img/basename/00000000.jpg
    model_prefix = ofToDataPath("models"); // output path for learned models
    globfeat_prefix = ofToDataPath("globfeats"); // output path for color histograms
    
    ofLog() << model_prefix;
    ofLog() << globfeat_prefix;
    
    // types of features to use (you will over-fit if you do not have enough data)
    // r: RGB (5x5 patch)
    // v: HSV
    // l: LAB
    // b: BRIEF descriptor
    // o: ORB descriptor
    // s: SIFT descriptor
    // u: SURF descriptor
    // h: HOG descriptor
    string feature_set = "rvl";
    
    hd.testInitialize(model_prefix,globfeat_prefix,feature_set,num_models_to_average,target_width);
    
    cap.setup(1280, 720);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    cap.update();
    if(cap.isFrameNew()) {
        Mat im;
        ofxCv::convertColor(cap, im, CV_RGB2BGR);
        hd.test(im,num_models_to_average,step_size);
        trackerReady = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(trackerReady) {
        Mat pp_contour = hd.postprocess(hd._response_img);		// binary contour
        hd.colormap(pp_contour,pp_contour,0);					// colormap of contour
        ofxCv::drawMat(pp_contour, target_width*2, 0);
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
