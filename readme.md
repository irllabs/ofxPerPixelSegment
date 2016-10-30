# ofxPerPixelSegment


This repository contains code for performing foreground/background segmentation of the human hand in videos from an egocentric perspective, using pixel-level classification.  This project is based on [work by Cheng Li and Kris Kitani](http://www.cs.cmu.edu/~kkitani/datasets/), and described in the publication below: 

*Li, Cheng, and Kris M. Kitani. "Pixel-level hand detection in ego-centric videos." Proceedings of the IEEE Conference on Computer Vision and Pattern Recognition. 2013. [(pdf)](http://www.cs.cmu.edu/~kkitani/pdf/LK-CVPR13.pdf)*

The code is packaged up to work as an [OpenFrameworks AddOn](http://ofxaddons.com/categories). This AddOn includes one example that implements both training, and prediction.


## Requirements
* openFrameworks (tested with version 0.9.4)
* ofxCv
* ofxOpenCv
* ofxGui

## Usage
1. Install this addon by cloning this repository in the `AddOns` folder of your OpenFrameworks environment
2. Use the `Project Genrator` to create a new project; include ofxCv, ofxOpenCv, ofxGui, and ofxPerPixelSegment
3. In the generated projects folder, replace the contents of the `src` folder (i.e., "main.cpp","ofApp.cpp" and "ofApp.h") with the same files from the `src` folder of this repository
4. open the generated project in Xcode and build.

## Training and Predicting
This AddOn can perform *training* and *prediction*. Commenting and uncommenting some lines in "ofApp.cpp" allows you to switch between training and prediction; specifically:

    // to train a new model, uncomment the following lines
    // and make sure there are images in:
    // data/new-handtracker/img/*.jpg
    // data/new-handtracker/mask/*.jpg
    //    segmenter.setPath("new-handtracker");
    //    segmenter.trainModels();

Training data consists of amples of images and their corresponding masks.  Once training is complete, the app genrates models that are used for prediction.  This add  This project comes with existing models in [this subfolder of the repository](https://github.com/cmuartfab/ofxPerPixelSegment/tree/master/libs/perpix/models/handtracking).  You can also create your own models by providing images and masks in the corresponding directories indicated above. Creating your own by training set requires labeling images using [Kitani's 'Labeling Tool'](http://www.cs.cmu.edu/~kkitani/perpix/code_grabcut/), which we have also ported to work with the latest Xcode IDE. You can find it [here](https://github.com/cmuartfab/grabcut).

## Additional Notes
* In order for the training models to be used, the "models" and "globfeat" folders must be moved into "../data/handtracking/"
* If you train on RGB images, you don't need to convert your input to BGR (could be a small optimization)
* A little work is needed to make this fully cross-platform, right now it should work on OSX and Linux but not on Windows due to the use of the `find` and other system commands. These could be replaced by OF calls.

## To Do 
* Clean up all the printouts from the library so it's not so much in the console each time you load something.
* Print some progress in the console during training
* Check that directories aren't empty just before loading
* Make more examples of how to use the foreground mask. It looks like the library is internally running a contour finder so it would be good to expose those contours as a `vector<ofPolyline>` or something similar. ofxCv can convert from CV lines to ofPolylines.
