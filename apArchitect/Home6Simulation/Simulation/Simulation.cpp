// Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

#include "Image.h"
#include "Camera.h"
#include "CountImage.h"
#include "RosBag.h"

using namespace std;

static const char *RosBagName = "../CarSchedule/CatDog.bag";

class SimSchedule {
public:
    SimSchedule();
    ~SimSchedule() = default;

    void PlayRosBag();
    void Debug();

private:
    void PlayCallBack(const char* rec);

private:
    Camera camCat, camDog;
    CountImage countCat, countDog;
    RosBag rb;
};

SimSchedule::SimSchedule() : rb(RosBagName, false) {
    countCat.Subscribe(&camCat);
    countDog.Subscribe(&camDog);
}

void SimSchedule::PlayRosBag() {
    rb.Play( std::bind(&SimSchedule::PlayCallBack, this, std::placeholders::_1) );
}

void SimSchedule::Debug() {
    cout << endl << "CountCat= ";
    countCat.Debug();

    cout << "CountDog= ";
    countDog.Debug();
}

/// .bag文件格式: TXT, 每个消息一行(类型，数据). For example:
/// 0, 11	//CAT相机,  图象内容是11
/// 1, 20	//DOG相机,  图象内容是20
/// 2, 8    //CAT计数, 8个
/// 3, 6    //DOG计数, 6个
void SimSchedule::PlayCallBack(const char* rec) {
    int type, count;
    if (sscanf_s(rec, "%d,%d", &type, &count) != 2) return;     //64=sizeof(buf)

    switch (type) {
    case 0:
        camCat.SetCurrentImage(count);
        break;
    case 1:
        camDog.SetCurrentImage(count);
        break;
    default:
        break;
    }
}

int main()
{
    std::cout << "Playing " << RosBagName << endl;

    SimSchedule sim;
    sim.PlayRosBag();
    sim.Debug();
}
