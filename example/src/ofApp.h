#pragma once

#include "ofMain.h"

#include <opencv2/opencv.hpp>

#include "FeatureComputer.hpp"
#include "Classifier.h"
#include "LcBasic.h"
#include "HandDetector.hpp"


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
    
    ofVideoGrabber cap;
    bool trackerReady;
    
    bool TRAIN_MODEL;           //1 if you are training the models, 0 if you are running the program to predict
    bool TEST_MODEL;           //0 if you are training the models, 1 if you are running the program to predict
    
    int target_width;			// for resizing the input (small is faster)
    
    // maximum number of image masks that you will use
    // must have the masks prepared in advance
    // only used at training time
    int num_models_to_train;
    
    
    // number of models used to compute a single pixel response
    // must be less than the number of training models
    // only used at test time
    int num_models_to_average;
    
    // runs detector on every 'step_size' pixels
    // only used at test time
    // bigger means faster but you lose resolution
    // you need post-processing to get contours
    int step_size;
    
    // Assumes a certain file structure e.g., /root/img/basename/00000000.jpg
    string root;                        //replace with path to your Xcode project
    string basename;
    string img_prefix;                  // color images
    string msk_prefix;                  // binary masks
    string model_prefix;                // output path for learned models
    string globfeat_prefix;  			// output path for color histograms
    
    // types of features to use (you will over-fit if you do not have enough data)
    // r: RGB (5x5 patch)
    // v: HSV
    // l: LAB
    // b: BRIEF descriptor
    // o: ORB descriptor
    // s: SIFT descriptor
    // u: SURF descriptor
    // h: HOG descriptor
    string feature_set;
    
    
    string vid_filename;
    
    HandDetector hd;
    
    
    
    Mat im;
    Mat ppr;
    
    VideoWriter avi;
    
};
