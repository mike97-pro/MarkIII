#ifndef Mark_h
#define Mark_h
#include "Arduino.h"
#include "Servo.h"

class Mark
{
    public:
    #define eyes 16
    #define echoPin 15
    #define trigPin 14
    #define l_shoulder_pitch 4
    #define l_thigh_yaw 5
    #define l_shoulder_roll 11
    #define l_elbow_roll 12
    #define l_thigh_roll 6
    #define l_thigh_pitch 8
    #define l_knee_pitch 7
    #define l_foot_pitch 9
    #define l_foot_roll 10
    #define r_shoulder_pitch 2
    #define r_thigh_yaw 3
    #define r_shoulder_roll A0
    #define r_elbow_roll 13
    #define r_thigh_roll A5
    #define r_thigh_pitch A4
    #define r_knee_pitch A3
    #define r_foot_pitch A2
    #define r_foot_roll A1

    Mark();
    void moveServo(int nServo, int angle);
    void eyesOn();
    void eyesOff();
    void eyesBlink();
    long prossimity();
    void feaderMode(int n);
    void waiting();
    void walkForward();
    void clap();
    void handshakeJoke();
    void handShake();
    void handsUp();
    void objectDistance();

    private:
        Servo   s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;

        void attac(int p, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11);
        void attacUp(int p, int p1, int p2, int p3, int p4, int p5);
        void attacDown(int p, int p1, int p2, int p3, int p4, int p5);
        void detac();
        void motion(int frames[][18], int waiting_time[], int n_frames, char attac_zone);
        void handshake1();
        void handshake2();
        void handshake3();
        void handshake4();
};
#endif // MARK_H
