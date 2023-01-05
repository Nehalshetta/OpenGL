#include <windows.h>
#include <iostream>
using namespace std;
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <mmsystem.h>

float angle=0,xx=-20, yy=-20, cloudz1=-40, cloudz2=-110;
double rotate_by_key=0;
double rotate_x=0.5;
float sun_step=-50;

float ver[8][3] ={ //to handle all vertices of house's cubed shape

    {-15,0,-15},
    {-15,0,15},
    {15,0,-15},
    {15,0,15},
    {-15,20,-15},
    {-15,20,15},
    {15,20,15},
    {15,20,-15},
};
GLfloat color[8][3] ={ //create gradient color map consistent of two colors baby blue and off white

    {0.6,0.93,0.84}, //blue
    {0.6,0.93,0.84},
    {0.6,0.93,0.84},
    {0.6,0.93,0.84},
    {0.98,0.9,0.9}, //offwhite
    {0.98,0.9,0.9},
    {0.98,0.9,0.9},
    {0.98,0.9,0.9},
};
void specialKeys( int key, int x, int y ){ //to handle keyboard inputs

      if(key == GLUT_KEY_UP) //zooms in and out on scene using UP and DOWN keys
            rotate_x += .05; //by moving along x
        else if(key == GLUT_KEY_DOWN)
             rotate_x -= .05;


    glutPostRedisplay();
}
void sky(){
    glPushMatrix();

//glClearColor(0.482, 0.408, 0.933,0);
    glColor3f(0.460, 0.390, 0.910);

    glutSolidSphere(150,150,150); //the scene takes places inside a sphere to give depth

    glPopMatrix();
}
void clouds(){
    glPushMatrix();
    glTranslatef(cloudz1,35,-30);//cloudz moves on the z-axis relative to the animation
    glRotatef(90,0,0,1);

    glPushMatrix();
    glColor3f( 	0.902, 0.902, 0.980);
    glTranslatef(0,10,-40);

    glutSolidSphere(4,100,100);

    glPopMatrix();

    glPushMatrix();
    glColor3f( 	0.902, 0.902, 0.980);
    glTranslatef(2,14,-40);

    glutSolidSphere(5,100,100);

    glPopMatrix();

    glPushMatrix();
    glColor3f(0.902, 0.902, 0.980);
    glTranslatef(0,18,-40);

    glutSolidSphere(4,100,100);

    glPopMatrix();
    glPopMatrix();

////////////////////////////////////////////

    glPushMatrix();
    glTranslatef(cloudz1+9,50,-40);
    glRotatef(90,0,0,1);

    glPushMatrix();
    glColor3f( 	0.902, 0.902, 0.980);
    glTranslatef(0,10,-40);

    glutSolidSphere(3,100,100);

    glPopMatrix();

    glPushMatrix();
    glColor3f( 	0.902, 0.902, 0.980);
    glTranslatef(2,14,-40);

    glutSolidSphere(5,100,100);

    glPopMatrix();

    glPushMatrix();
    glColor3f( 	0.902, 0.902, 0.980);
    glTranslatef(0,18,-40);

    glutSolidSphere(3,100,100);

    glPopMatrix();
    glPopMatrix();



}
void sunAnim(int){ //syncing clouds and sun

    glutTimerFunc(1000/60,sunAnim,0);
    glutPostRedisplay();

    //animation for clouds
    cloudz1+=0.5;cloudz2+=0.5;
    if(cloudz1==100){cloudz1=-120;}
    if(cloudz2==100){cloudz2=-120;}
    //animation for sun
    sun_step+=0.5;
    if(sun_step==100){sun_step=-120;}



}
void ground(){
    glPushMatrix();

    glColor3f(0.180, 0.545, 0.341);
    glTranslatef(0,-5,0);
    glBegin(GL_POLYGON); //rectangular ground shape

    glVertex3f(-200,-10,-200);
    glVertex3f(200,-10,-200);
    glVertex3f(200,-10,200);
    glVertex3f(-200,-10,200);

    glEnd();

    glPopMatrix();

}
void house(int a,int b,int c,int d){
    //cube is done be taking inputs of shape from color and ver attribute
    glPushMatrix();
    glTranslatef(15,-11,-67);
    glRotatef(20,0,1,0);

    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver[a]);

    glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();


    ///////////////roof///////////////
    //done manually by drawing 4 faces back to back
    glColor3f(0.000, 0.000, 1.000);
    //back roof
    glBegin(GL_POLYGON);

    glVertex3f(-15,20,-15);
    glVertex3f(0,35,0);
    glVertex3f(15,20,-15);

    glEnd();

    //left roof
    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.000, 1.000);

    glVertex3f(-15,20,-15);
    glVertex3f(0,35,0);
    glVertex3f(-15,20,15);

    glEnd();

    //right roof
    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.000, 1.000);

    glVertex3f(15,20,-15);
    glVertex3f(0,35,0);
    glVertex3f(15,20,15);

    glEnd();

    //front roof
    glBegin(GL_POLYGON);
    glColor3f(0.000, 0.000, 1.000);

    glVertex3f(-15,20,15);
    glVertex3f(0,35,0);
    glVertex3f(15,20,15);

    glEnd();

///////////windows/////////////////

    //front left window
    glBegin(GL_POLYGON);
    glColor3f(0.416, 0.353, 0.804);

    glVertex3f(-13,10,15.1);
    glVertex3f(-8,10,15.1);
    glVertex3f(-8,15,15.1);
    glVertex3f(-13,15,15.1);

    glEnd();


    //front right window
    glBegin(GL_POLYGON);
    glColor3f(0.416, 0.353, 0.804);

    glVertex3f(13,10,15.1);
    glVertex3f(8,10,15.1);
    glVertex3f(8,15,15.1);
    glVertex3f(13,15,15.1);

    glEnd();

    //left side, left window
    glBegin(GL_POLYGON);
    glColor3f(0.416, 0.353, 0.804);

    glVertex3f(-15.1,10,-13);
    glVertex3f(-15.1,10,-8);
    glVertex3f(-15.1,15,-8);
    glVertex3f(-15.1,15,-13);


    glEnd();


    //left side, right window
    glBegin(GL_POLYGON);
    glColor3f(0.416, 0.353, 0.804);

    glVertex3f(-15.1,10,13);
    glVertex3f(-15.1,10,8);
    glVertex3f(-15.1,15,8);
    glVertex3f(-15.1,15,13);


    glEnd();


///////////door////////////////


    //door frame
    glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);

    glVertex3f(-4,0,15.1);
    glVertex3f(4,0,15.1);
    glVertex3f(4,11,15.1);
    glVertex3f(-4,11,15.1);

    glEnd();

    //door line vertical
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.271, 0.075);

    glVertex3f(-0.3,0,15.2);
    glVertex3f(0.3,0,15.2);
    glVertex3f(0.3,11,15.2);
    glVertex3f(-0.3,11,15.2);

    glEnd();


    //door line horizental
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.271, 0.075);

    glVertex3f(-3,5.5,15.3);
    glVertex3f(3,5.5,15.3);
    glVertex3f(3.3,5.2,15.3);
    glVertex3f(-3,5.2,15.3);

    glEnd();

    //door line knob
    glPushMatrix();
    glColor3f(0.502, 0.000, 0.000);
    glTranslatef(-2.9,4.7,15.5);
    glutSolidSphere(0.3,100,100);

    glEnd();

    glPopMatrix();

    glPopMatrix();



}
void colorcube(){ //every vertix from the cube has a color assigned to it

    house(0,3,2,1);
    house(2,3,7,6);
    house(0,4,7,3);
    house(0,2,6,5);
    house(4,5,6,7);
    house(0,1,5,4);
}
void street(){


    //car1();
    glPushMatrix();

    glTranslatef(15,-10,-30);

/////////road//////////////
    glBegin(GL_QUADS);
    glColor3f(0.22,0.22,0.22);
    glTranslatef(0,5,25);

    glVertex3f(-180,5.5,15.3);
    glVertex3f(180,5.5,15.3);
    glVertex3f(180,5.2,30);
    glVertex3f(-180,5.2,30);

    glEnd();

/////////sidewalk/////////

    glBegin(GL_POLYGON);
    glColor3f(0.33,0.33,0.33);
    glTranslatef(0,5,25);

    glVertex3f(-180,5.5,15.3);
    glVertex3f(180,5.5,15.3);
    glVertex3f(180,5.2,10);
    glVertex3f(-180,5.2,10);

    glEnd();


        glBegin(GL_POLYGON);
        glTranslatef(0,5,25);

        glVertex3f(-180,5.6,25);
        glVertex3f(180,5.6,25);
        glVertex3f(180,5.3,23);
        glVertex3f(-180,5.3,23);

        glEnd();



//////////yellow lanes/////////
//for loop to print multiple streen lines
    for(int i=0;i<=360;i+=9)
    {
        glColor3f(0.855, 0.647, 0.125);

        glBegin(GL_POLYGON);

        glVertex3f(-180+i,5.7,20.5);
        glVertex3f(-175+i,5.7,20.5);
        glVertex3f(-175+i,5.4,20.75);
        glVertex3f(-180+i,5.4,20.75);

        glEnd();

    }

    glPopMatrix();



}
void pond(){

            glPushMatrix();
            glColor3f(0.255, 0.412, 0.882);
            glTranslatef(-8,-5,-26);


            //draws an oval as pond
            glBegin(GL_POLYGON);
            for(int i =0; i <= 360; i++){


            double radius = 4;
            double angle;
            angle = i*3.14/180;
            glVertex2f(radius * cos(angle) , radius * sin(angle)*0.2);}
            glEnd();
            glPopMatrix();

        ///////////////rock at pond////////////////

            //rocks around pond
            glPushMatrix();
            glColor3f(0.545, 0.271, 0.075);
            glTranslatef(-10,-6,-35);

            glutSolidIcosahedron();

            glEnd();
            glPopMatrix();

            //rocks around pond
            glPushMatrix();
            glColor3f( 	0.647, 0.165, 0.165);
            glTranslatef(-7,-6,-35);

            glutSolidIcosahedron();

            glEnd();
            glPopMatrix();

            //rocks around pond
            glPushMatrix();
            glColor3f( 	0.647, 0.165, 0.165);
            glTranslatef(-9,-5,-35);

            glutSolidIcosahedron();



            glEnd();
            glPopMatrix();

            glPushMatrix();
            glColor3f(0.545, 0.271, 0.075);
            glTranslatef(-8,-5,-35);

            glutSolidIcosahedron();



            glEnd();
            glPopMatrix();




}
void sun(){

    glPushMatrix();
    glTranslatef(sun_step,45,-77);
    glColor3f(1, 0.65, 0.0);

    glutSolidSphere(5,100,100);

    glPopMatrix();

}
void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glScalef( rotate_x,rotate_x,1.0f );
    //glScalef(1.0f,1.0f,rotate_x);
    glRotatef(  rotate_by_key,-1.0f, 1.5f, -5.0f );

    ground();
    clouds();
    sky();
    colorcube();
    street();
    pond();
    sun();

    /*glPushMatrix();
    glTranslatef(1,0,0);
    glRotatef(90,0,1,0);
    //glScalef(2,2,2);
    car1();
    glPopMatrix();*/

    glutSwapBuffers();
    glFlush();

}
void reshape(int w, int h ){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(75,(GLdouble)w / (GLdouble)h,5,200);


    glMatrixMode(GL_MODELVIEW);
}
void init(){
    glClearColor(0.482, 0.408, 0.933,0); //houses back ground
    glEnable(GL_DEPTH_TEST);
}
int main (int argc, char** argv) {
glutInit(&argc,argv);
glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );

glutInitWindowPosition(200,0);
glutInitWindowSize(1200,800);
glutCreateWindow("19103469");


glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutSpecialFunc(specialKeys);
glutTimerFunc(0,sunAnim,0);
//glutTimerFunc(0,cloudAnim,0);

sndPlaySound("cardinal-37075.wav",SND_ASYNC |SND_LOOP);

init();
glEnable( GL_DEPTH_TEST );
glutMainLoop();

return 0;


}

