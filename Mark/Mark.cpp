#include "Mark.h"

Mark::Mark()
{
    pinMode(eyes, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
};

void Mark::eyesOn()
{
    digitalWrite(eyes, HIGH);
};

void Mark::eyesOff()
{
    digitalWrite(eyes, LOW);
};

void Mark::eyesBlink()
{
    do
    {
        digitalWrite(eyes, HIGH);
        delay(200);
        digitalWrite(eyes, LOW);
        delay(200);
    }while(Serial1.read() != 's');

};

long Mark::prossimity()
{
    long duration=0, distance=0;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    /* Calcola la distanza in centimetri dall'oggetto*/
    distance = duration/58.2;

    return distance;
};

void Mark::attac(int p, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11)
{
    s1.attach(p);
    s2.attach(p1);
    s3.attach(p2);
    s4.attach(p3);
    s5.attach(p4);
    s6.attach(p5);
    s7.attach(p6);
    s8.attach(p7);
    s9.attach(p8);
    s10.attach(p9);
    s11.attach(p10);
    s12.attach(p11);
};

void Mark::attacUp(int p, int p1, int p2, int p3, int p4, int p5)
{
    s1.attach(p);
    s2.attach(p1);
    s3.attach(p2);
    s4.attach(p3);
    s5.attach(p4);
    s6.attach(p5);

};

void Mark::attacDown(int p, int p1, int p2, int p3, int p4, int p5)
{
    s1.attach(p);
    s3.attach(p1);
    s4.attach(p2);
    s10.attach(p3);
    s11.attach(p4);
    s12.attach(p5);
};

void Mark::detac()
{
    s1.detach();
    s2.detach();
    s3.detach();
    s4.detach();
    s5.detach();
    s6.detach();
    s7.detach();
    s8.detach();
    s9.detach();
    s10.detach();
    s11.detach();
    s12.detach();
};


void Mark::motion(int frames[][18], int waiting_time[], int n_frames, char attac_zone)
{
    for(int k=0; k<n_frames; k++)
    {
        attac(l_shoulder_pitch, l_thigh_yaw, l_shoulder_roll, l_elbow_roll, l_thigh_roll, l_thigh_pitch, l_knee_pitch, l_foot_pitch, l_foot_roll, r_shoulder_pitch, r_thigh_yaw, r_shoulder_roll);

        s1.write(frames[k][0]);
        s2.write(frames[k][1]);
        s3.write(frames[k][2]);
        s4.write(frames[k][3]);
        s5.write(frames[k][4]);
        s6.write(frames[k][5]);
        s7.write(frames[k][6]);
        s8.write(frames[k][7]);
        s9.write(frames[k][8]);
        s10.write(frames[k][9]);
        s11.write(frames[k][10]);
        s12.write(frames[k][11]);

        delay(220);
        if(attac_zone == 'u')
        {
            attacUp(r_elbow_roll,r_thigh_roll,r_thigh_pitch,r_knee_pitch,r_foot_pitch,r_foot_roll );

            s1.write(frames[k][12]);
            s2.write(frames[k][13]);
            s3.write(frames[k][14]);
            s4.write(frames[k][15]);
            s5.write(frames[k][16]);
            s6.write(frames[k][17]);
        }

        if(attac_zone == 'd')
        {
            attacDown(r_elbow_roll,r_thigh_roll,r_thigh_pitch,r_knee_pitch,r_foot_pitch,r_foot_roll );

            s1.write(frames[k][12]);
            s3.write(frames[k][13]);
            s4.write(frames[k][14]);
            s10.write(frames[k][15]);
            s11.write(frames[k][16]);
            s12.write(frames[k][17]);
        }


        delay(420);

        /*while (Serial.read() != 'a')
        {
        }*/
        delayMicroseconds(waiting_time[k]);
    }
};

void Mark::waiting()
{
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={170,90,10,90,97,92,90,99,89,30,90,170,85,83,89,180,78,87};
    int waiting_time[]={300};
    motion(frames,waiting_time,1,'d');
};

void Mark::handsUp()
{
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={10,90,20,90,97,89,90,99,89,180,90,160,85,83,89,180,78,87};
    int waiting_time[]={300};
    motion(frames,waiting_time,1,'d');
};

void Mark::walkForward()
{
    waiting();
    handsUp();
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={
               //10,90,10,90,97,91,90,99,89,180,90,170,85,83,87,180,78,87,


                //10,90,20,100,98,94,83,97,86,180,90,160,75,80,89,180,78,75,
                //10,90,20,100,99,94,83,97,83,180,90,160,75,80,89,180,78,75,
                    10,90,20,100,100,94,83,97,80,180,90,160,75,80,89,180,78,75,
                //10,90,20,100,100,96,83,97,80,180,90,160,75,80,110,98,35,75,
                //10,90,20,100,100,99,83,97,80,180,90,160,75,80,110,98,35,75,
                    10,90,20,100,100,101,83,97,80,180,90,160,75,80,110,98,35,75,
                    10,90,20,100,97,100,83,102,87,180,90,160,75,83,125,130,70,89,
                    10,90,20,100,105,90,107,120,96,180,90,160,75,90,117,130,65,96,
                    10,90,20,100,97,83,90,87,96,180,90,160,75,83,89,180,78,96,
                    10,90,20,100,107,60,165,132,100,180,90,160,75,85,89,180,78,96,
                    10,90,20,100,108,45,130,98,105,180,90,160,75,93,89,180,78,96,
                    10,90,20,100,94,65,120,110,86,180,90,160,75,81,89,158,57,80};
    int waiting_time[]={160,220,220,220,380,180,220,360};
    do
    {
        if(prossimity() > 10)
        {
            motion(frames,waiting_time,8,'d');
            delay(20);
        }
    }while(Serial1.read() != 's');
    handsUp();
    handsUp();
    eyesBlink();
    waiting();
    waiting();
    eyesOn();
};

void Mark::feaderMode(int n)
{
    do
    {
      char c[1];
      if(Serial1.available())
      {
        c[0]= Serial1.read();
        int value=atoi(c);
        Serial.print(value);
        moveServo(n,map(value,0,9,0,180));
      }
    }while(Serial1.read() != 's');
};

void Mark::clap()
{
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={170,90,10,90,97,89,90,99,89,30,90,170,85,83,86,180,78,87,
                    85,90,20,90,97,93,90,99,89,100,90,160,85,83,86,180,78,87,
                    85,90,20,120,97,89,90,99,89,100,90,160,50,83,86,180,78,87,
                    85,90,0,120,97,89,90,99,89,100,90,180,50,83,86,180,78,87,
                    85,90,20,120,97,89,90,99,89,100,90,160,50,83,86,180,78,87,
                    85,90,0,120,97,89,90,99,89,100,90,180,50,83,86,180,78,87,
                    85,90,20,120,97,89,90,99,89,100,90,160,50,83,86,180,78,87,
                    85,90,0,120,97,89,90,99,89,100,90,180,50,83,86,180,78,87,
                    85,90,20,120,97,89,90,99,89,100,90,160,50,83,86,180,78,87,
                    85,90,20,90,97,89,90,99,89,100,90,160,85,83,86,180,78,87,
                    127,90,20,90,97,89,90,99,89,65,90,160,85,83,86,180,78,87,
                    170,90,10,90,97,89,90,99,89,30,90,170,85,83,86,180,78,87};
    int waiting_time[]={100,500,220,220,220,220,220,220,220,400,400,800};
    motion(frames,waiting_time,12,'d');
};

void Mark::handshake1()
{
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={170,90,10,90,97,89,90,99,89,30,90,170,85,83,86,180,78,87,
                    170,90,10,90,97,89,90,99,89,90,90,175,70,83,86,180,78,87};

    int waiting_time[]={100,500};
    motion(frames,waiting_time,2,'d');
};

void Mark::handshake2()
{
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={170,90,10,90,97,89,90,99,89,135,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,180,90,175,70,83,89,180,78,87};

    int waiting_time[]={100,500};
    motion(frames,waiting_time,2,'d');
};

void Mark::handshake3()
{
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={170,90,10,90,97,89,90,99,89,90,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,90,90,175,70,83,89,180,78,87};

    int waiting_time[]={100,500};
    motion(frames,waiting_time,2,'d');
};

void Mark::handshake4()
{
    /////////////////  1   2  3 4  5  6  7  8  9  10 11 12  13 14 15 16  17 18
    int frames[][18]={170,90,10,90,97,89,90,99,89,90,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,100,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,80,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,100,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,80,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,90,90,175,70,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,90,90,170,85,83,89,180,78,87,
                    170,90,10,90,97,89,90,99,89,30,90,170,85,83,89,180,78,87};

    int waiting_time[]={100,500,220,220,220,220,220,220};
    motion(frames,waiting_time,8,'d');
    waiting();
};

void Mark::handshakeJoke()
{
    handshake1();
    int r = 0;
    do
    {
      if(prossimity() <= 10 and r < 2)
      {
        handshake2();
        delay(200);
        handshake3();
        r++;
      }
      if (r == 2 and prossimity() <= 10)
      {
        handshake4();
        r++;
      }
      delay(30);
    }
    while( r < 3 );
    waiting();
};

void Mark::handShake()
{
    bool r = 0;
    do
    {
      if(prossimity() < 10)
      {
        handshake1();
        handshake4();
        r=1;
      }
    }
    while( r == 0 );
};

void Mark::moveServo(int nServo, int angle)
{
    int frames[][18]={170,90,10,90,97,89,90,99,89,30,90,170,85,83,89,180,78,87};
    frames[0][nServo-1]=angle;
    int waiting_time[]={300};

    motion(frames,waiting_time,1,'u');
};

void Mark::objectDistance()
{
    int time = 0;
    do
    {
        if(prossimity() > 250 && prossimity() <= 450)
        {
            time = 1000;
        }
        if(prossimity() > 50 && prossimity() <= 250)
        {
            time = 500;
        }
        if(prossimity() > 30 && prossimity() <= 50)
        {
            time = 300;
        }
        if(prossimity() > 10 && prossimity() <= 30)
        {
            time = 100;
        }
        Serial.println("Distanza: "+prossimity());
        digitalWrite(eyes, HIGH);
        delay(time);
        if(time > 0)
        {
            digitalWrite(eyes, LOW);
            delay(time);
        }
    }while(Serial1.read() != 's');
    eyesOn();
};
