#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    serial.listDevices();
    deviceList = serial.getDeviceList();
    
    int baud = 57600;
    serial.setup(1, 57600);
    
    if(serial.isInitialized()){
        cout << "initialized successfully " << endl;
    }
    else{
        cout << "initialized fail " << endl;
    }
    
    sound.load("kick.wav");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // we want to read 8 bytes
    int bytesRequired = 8;
    unsigned char bytes[bytesRequired];
    
    int bytesRemaining = bytesRequired;
    string value;
    
    // loop until we've read everything
    while ( bytesRemaining > 0 )
    {
        
        // check for data
        if ( serial.available() > 0)
        {
            // try to read - note offset into the bytes[] array, this is so
            // that we don't overwrite the bytes we already have
            int bytesArrayOffset = bytesRequired - bytesRemaining;
            int result = serial.readBytes( &bytes[bytesArrayOffset],bytesRemaining );;
            
            
            // check for error code
            if ( result == OF_SERIAL_ERROR )
            {
                // something bad happened
                ofLog( OF_LOG_ERROR, "unrecoverable error reading from serial" );
                // bail out
                break;
            }
            else if ( result == OF_SERIAL_NO_DATA )
            {
                // nothing was read, try again
            }
            else
            {
                // we read some data!
                bytesRemaining -= result;
            }
            
            value = ofToString(&bytes[bytesArrayOffset]);
            
            cout << "the value is: " + value << endl;
            
            
        }
    }
    
    
    //play sound
    //    if(value > 300){
    //            sound.play();
    //            sound.setMultiPlay(true);
    //    }
    
    
}
//--------------------------------------------------------------
void ofApp::calculate(int value){
    
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
