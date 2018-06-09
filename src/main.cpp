//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Selba Ward - Spline *EXAMPLE*
//
//  by Hapaxia (https://github.com/Hapaxia)
//
//
//  Draw a spline in the window by moving the mouse.
//
//
//    Controls:
//
//  Escape key          Quit
//  Mouse movement      Draw
//  Mouse wheel         Adjust thickness
//  F1 key              Toggle pause
//  Space key           Toggle bezier/linear curve mode
//  Tab key             Toggle primitive type
//
//  Low frame rate is intentional so that fewer points are added to show how bezier interpolation can create curves from very few points
//
//  Please note that this example makes use of C++11 features
//    and also requires the SFML library (http://www.sfml-dev.org)
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include "Simulation.h"

int main() {
    Simulation simulation;
    simulation.run();
    return EXIT_SUCCESS;
}