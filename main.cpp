// Chat GPT example app

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"


using namespace ci;
using namespace ci::app;

class BasicApp : public App {
public:
    void setup() override;
    void draw() override;
};

void BasicApp::setup()
{
    // Set the window size
    setWindowSize(800, 600);
}

void BasicApp::draw()
{
    // Clear the window with a red color
    gl::clear(Color(1, 0, 0));
}

CINDER_APP(BasicApp, RendererGl)
