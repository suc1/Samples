// CarSchedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
// See README.md for details

#include <iostream>
#include <thread>

#include "Image.h"
#include "Camera.h"
#include "CountImage.h"
#include "RosBag.h"

using namespace std;
int main()
{
    Camera camCat, camDog;
    
    CountImage countCat, countDog;
    //Subscribe
    countCat.Subscribe(&camCat);
    countDog.Subscribe(&camDog);
    
    //Subscribe
    //由于先登记CountImage CALLBACK，导致.bag中CountImage计数先于图象，但是play时只播放摄像头，不播计数，所以不影响CountImage计数
    RosBag rb;
    camCat.Subscribe( [&rb](IMAGE img) {rb.ProcessImage(0, img);} );
    camDog.Subscribe( [&rb](IMAGE img) {rb.ProcessImage(1, img);} );

    countCat.Subscribe( [&rb](int count) {rb.Process(2, count);} );
    countDog.Subscribe( [&rb](int count) {rb.Process(3, count);} );

    camCat.Start();
    camDog.Start();

    cout << "Press enter to exit RosBag";
    cin.get();

    camCat.SetExitFlag();
    camDog.SetExitFlag();
}
