# ofxPerPixelSegment

* What code this is using
* What code this depends on: openFrameworks, ofxCv, ofxOpenCv
* Note about moving the `model` folder into `data`
* If you train on RGB images, you don't need to convert your input to BGR (could be a small optimization)
* Might want to clean up all the printouts from the library so it's not so much in the console each time you load something.
* Is it possible to print some progress in the console during training?
* Besides checking that they exist, we should check that directories aren't empty just before loading.
* Might want to make more examples of how to use the foreground mask. It looks like the library is internally running a contour finder so it would be good to expose those contours as a `vector<ofPolyline>` or something similar. ofxCv can convert from CV lines to ofPolylines.
* A little work is needed to make this fully cross-platform, right now it should work on OSX and Linux but not on Windows due to the use of the `find` and other system commands. These could be replaced by OF calls.