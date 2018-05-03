#include "CrispASN1.hpp"

using namespace std;
using namespace PositionManager;

CrispASN1::CrispASN1()
{}

int CrispASN1::updateJointPose(const Pose_InFuse& asnPose)
{
    PositionManager::Pose pose;
   
    fromASN1SCC(asnPose, pose);

    //cout << "Got pose :" << endl << pose.toStringVerbose() << endl << endl;

    return this->updateJointPose(pose);
}

int CrispASN1::updateJointPose(BitStream bstream)
{
    Pose_InFuse asnPose;
    flag res;
    int errorCode;

    BitStream_Init(&bstream, bstream.buf, Pose_InFuse_REQUIRED_BYTES_FOR_ENCODING);
    res = Pose_InFuse_Decode(&asnPose, &bstream, &errorCode);
    if(!res)
    {
        cout << "error CrispASN1 : decoding error : " << errorCode << endl;
    }

    return this->updateJointPose(asnPose);
}

