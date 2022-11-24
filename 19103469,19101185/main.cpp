#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include <stdlib.h>
#include <windows.h>

void display();
void reshape(int w,int h);
void fish_anim(int);
void bubble_anim(int);
void star_anim(int);
void eyes_anim(int);

double fish_step=0,bubble_step=0,star_step=0,eyes_step=0,sky_step=0; //to monitor steps
int fish_state=0,bubble_state=0,star_state=0,eyes_state=0;//to monitor state
int i;
double angle, radius;


void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    gluOrtho2D(-20,20,-20,20);
    glEnable(GL_BLEND); //glcolor4f
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}



int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);



    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("Hide & Seek");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,fish_anim,0);
    glutTimerFunc(0,bubble_anim,0);
    glutTimerFunc(0,star_anim,0);
    glutTimerFunc(0,eyes_anim,0);
    init();

    glutMainLoop();
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //door

    glPushMatrix(); //to work on a specific object

    glColor3f(0.1, 0.000, 0.000);
    glTranslated(-1,0,0);
    glBegin(GL_POLYGON); //rectangle for door

    glVertex2f(9,-12); //coordinates studied in documentation //top left
    glVertex2f(18,-12); //bottom left
    glVertex2f(18,10); //bottom right
    glVertex2f(9,10); //top right

    glEnd();
    glPopMatrix();

    //vertical door line

    glPushMatrix();

    glColor3f(0.2, 0.000, 0.000);
    glTranslated(-1,0,0);
    glBegin(GL_POLYGON);

    glVertex2f(13.25,-10); //coordinates studied in documentation //top left
    glVertex2f(13.75,-10);
    glVertex2f(13.75,8);
    glVertex2f(13.25,8);

    glEnd();
    glPopMatrix();

    //door knob
    glPushMatrix();
    glTranslated(9,-2,0);
    glColor3f(0.502, 0.502, 0.502);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 0.45
        ;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle));
    }
    glEnd();
    glPopMatrix();





    ///fourth object : window
    ///-------------------------

    //window : frame
    glPushMatrix();

    glColor3f(0.098, 0.098, 0.439);

    glBegin(GL_POLYGON);

    glVertex2f(-16,15); //coordinates studied in documentation //top left
    glVertex2f(-16,-5); //bottom left
    glVertex2f(-6,-5); //bottom right
    glVertex2f(-6,15); //top right

    glEnd();
    glPopMatrix();

    glPushMatrix();//edges of window frame

    glColor3f(0.878, 1.000, 1.000);

    glBegin(GL_LINE_LOOP);

    glVertex2f(-16,15); //coordinates studied in documentation //top left
    glVertex2f(-16,-5); //bottom left
    glVertex2f(-6,-5); //bottom right
    glVertex2f(-6,15); //top right

    //glRecti(0.5,-20,-0.5,-15)

    glEnd();
    glPopMatrix();



    glPushMatrix();//shooting star
    glTranslatef(-18+star_step,star_step,0);
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);

    glVertex2f(-0.2,0);
    glVertex2f(0,0.5);
    glVertex2f(0.2,0);
    glVertex2f(0,-0.5);

    glEnd();

    glPopMatrix();

    glPushMatrix();//shooting star tail
    glTranslatef(-18+star_step,star_step,0);
    glColor3f(1.000, 0.271, 0.000);
    glBegin(GL_POLYGON);

    glVertex2f(-1.4,-0.9);
    glVertex2f(-0.23,-0.15);
    glVertex2f(-0.06,-0.45);
    glVertex2f(-1.2,-1.2);

    glEnd();

    glPopMatrix();

    glPushMatrix();//shooting star tail border
    glTranslatef(-18+star_step,star_step,0);
    glColor3f(1.000, 0.549, 0.000);
    glBegin(GL_LINE_LOOP);

    glVertex2f(-1.4,-0.9);
    glVertex2f(-0.23,-0.15);
    glVertex2f(-0.06,-0.45);
    glVertex2f(-1.2,-1.2);

    glEnd();

    glPopMatrix();

    glPushMatrix();//left curtain
    glColor3f(1.000, 0.714, 0.757);
    glBegin(GL_POLYGON);
    glVertex2f(-16.1,15); //coordinates studied in documentation //top left
    glVertex2f(-13,15);
    glVertex2f(-16.1,-5);

    glEnd();
    glPopMatrix();

    glPushMatrix();//right curtain
    glColor3f(1.000, 0.714, 0.757);
    glBegin(GL_POLYGON);
    glVertex2f(-5.9,15); //coordinates studied in documentation //top left
    glVertex2f(-9,15);
    glVertex2f(-5.9,-5);

    glEnd();
    glPopMatrix();



    glPushMatrix();//star hider right

    glColor3f(0,0,0);

    glBegin(GL_POLYGON);

    glVertex2f(-5.9,14); //coordinates studied in documentation //top left
    glVertex2f(-4,14); //bottom left
    glVertex2f(-4,10); //bottom right
    glVertex2f(-5.9,10); //top right

    glEnd();
    glPopMatrix();

    glPushMatrix();//star hider left

    glTranslatef(-12.05,-12,0);
    glColor3f(0,0,0);

    glBegin(GL_POLYGON);

    glVertex2f(-9,18); //coordinates studied in documentation //top left
    glVertex2f(-4,18); //bottom left
    glVertex2f(-4,10); //bottom right
    glVertex2f(-9,10); //top right

    glEnd();
    glPopMatrix();

    //window : frame-bar
    glPushMatrix();
    glColor3f(0.663, 0.663, 0.663);
    glBegin(GL_POLYGON);
    glVertex2f(-17,16); //coordinates studied in documentation //top left
    glVertex2f(-17,14.5); //bottom left
    glVertex2f(-5,14.5); //bottom right
    glVertex2f(-5,16); //top right

    //glRecti(0.5,-20,-0.5,-15)

    glEnd();
    glPopMatrix();


    //STARSSS

    glPushMatrix(); // star 1
    glTranslated(-8,1,0);
    glColor3f(0.85,0.9+sky_step,0.4+sky_step);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 0.1;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

        glPushMatrix(); // star 2
    glTranslated(-12,5,0);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 0.1;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();


        glPushMatrix(); // star 3
    glTranslated(-14,2,0);
    glColor3f(0.85,0.9+sky_step,0.4+sky_step);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 0.1;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPushMatrix(); // star 4
    glTranslated(-10,10,0);
    glColor3f(0.85,0.9+sky_step,0.4+sky_step);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 0.1;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();



    ///MOON


    glPushMatrix();

    glTranslated(-4.5,9.5,0);

    glPushMatrix(); // visible moon
    glTranslated(-8,1,0);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 1;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPushMatrix(); // moon border
    glTranslated(-8,1,0);
    glColor3f(0.902, 0.902, 0.980);
    glBegin(GL_LINE_LOOP);
        for(i=0;i<360; i++)
    {
        radius = 1;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPushMatrix(); // moon hider
    glTranslated(-7.8,1,0);
    glColor3f(0.098, 0.098, 0.439);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 1;
        angle = i*3.142/180;
        glVertex2d(0.8*radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();



    ///third object : cat
    ///-------------------------


    //cat : body
    glPushMatrix();
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-3,4); //coordinates studied in documentation //top left
    glVertex2f(-3,-13); //bottom left
    glVertex2f(3,-13); //bottom right
    glVertex2f(3,4); //top right

    //glRecti(0.5,-20,-0.5,-15)

    glEnd();
    glPopMatrix();

    //cat: eyes

    glPushMatrix();
    glTranslated(-1,1,0);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 1;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.8,1,0);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 1;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(eyes_step,0,0);


    glPushMatrix();
    glTranslated(-0.3,0.3,0);
    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 0.3;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.3,0);

    glBegin(GL_POLYGON);
        for(i=0;i<360; i++)
    {
        radius = 0.3;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3b(0,0,0);
    glTranslated(-0.3,0.3,0);
    glBegin(GL_LINE_LOOP);
        for(i=0;i<360; i++)
    {
        radius = 0.3;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.3,0);
    glColor3b(0,0,0);
    glBegin(GL_LINE_LOOP);
        for(i=0;i<360; i++)
    {
        radius = 0.3;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }
    glEnd();
    glPopMatrix();


    glPopMatrix();

    //cat: ears

    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP); //triangle 1 for ears (left)
    glVertex2f(-2,4);
    glVertex2f(0,4);
    glVertex2f(-2,6);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glRotated(180,0,1,0); //rotated left ear
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-2,4);
    glVertex2f(0,4);
    glVertex2f(-2,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES); //triangle 1 for ears (left)
    glVertex2f(-1.8,4);
    glVertex2f(-0.3,4);
    glVertex2f(-1.8,5.3);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glRotated(180,0,1,0); //rotated left ear
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.8,4);
    glVertex2f(-0.3,4);
    glVertex2f(-1.8,5.3);
    glEnd();
    glPopMatrix();
    ///first object: table
    ///---------------------


    //table base-3 : filling gap between circles
    glPushMatrix();
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-6,-12); //coordinates studies in documentation
    glVertex2f(-6,-13);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);
    glVertex2f(6,-12);
    glVertex2f(6,-13);
    glEnd();
    glPopMatrix();

    //table base-2 : circles

    for(int p=0;p<=3;p++){ //nested loops to have 2 layer base
    glPushMatrix();
     if (p==0) {
        radius = 4;
        glTranslated(0,-13,0);
        glBegin(GL_LINE_LOOP);
        glColor3f(1, 1, 1);
    }
    else if(p==1) {
        radius = 4;
        glTranslated(0,-12,0);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
    }
    else if(p==2) {
        radius = 3;
        glTranslated(0,-12,0);
        glColor3f(0, 0, 0);
        glBegin(GL_LINE_LOOP);
    }
    else{
        radius = 1;
        glTranslated(0,-12,0);
        glColor3f(0,0,0);
        glBegin(GL_LINE_LOOP);
    }

        for(i=0;i<360; i++)
        {
            angle = i*3.142/180;
            glVertex2d(1.5*radius*cos(angle),0.5*radius*sin(angle)); //stretching circle along X&Y to give ellipse look
        }

    if (p==0) {
        glEnd();
    }
    else if(p==1) {
        glEnd();
    }
    else if(p==2) {
        glEnd();
    }
    else{
        glEnd();
    }
    glPopMatrix();
    }

    glPushMatrix();
    radius = 2.75;
    glTranslated(2.5,-11.85,0);
    glColor4f(0,0,0,0.80);
    glBegin(GL_POLYGON);

    for(i=0;i<360; i++)
    {
        angle = i*3.142/180;
        glVertex2d(1.5*radius*cos(angle),0.5*radius*sin(angle)); //stretching circle along X&Y to give ellipse look
    }

    glPopMatrix();


    glPushMatrix();
    glColor4f(0,0,0,0.80);
    glVertex2f(-0.5,-10); //coordinates studied in documentation //top left
    glVertex2f(-0.5,-12); //bottom left
    glVertex2f(0.5,-10); //bottom right
    glVertex2f(0.5,-12); //top right

    glEnd();
    glPopMatrix();


    //table base-1 : table's leg

    glPushMatrix();
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,-15); //coordinates studied in documentation //top left
    glVertex2f(-0.5,-20); //bottom left
    glVertex2f(0.5,-20); //bottom right
    glVertex2f(0.5,-15); //top right

    //glRecti(0.5,-20,-0.5,-15)

    glEnd();
    glPopMatrix();






    //WINDOW LIGHTING
    glPushMatrix();

    glColor4f(0.95, 0.95, 0.95, 0.1);

    glBegin(GL_POLYGON);

    glVertex2f(-16,-5); //coordinates studied in documentation //top left
    glVertex2f(-6,-5); //bottom left
    glVertex2f(15,-25); //bottom right
    glVertex2f(-10,-30); //top right

    glEnd();
    glPopMatrix();


    ///second object : fish bowl
    ///-------------------------

    //bowl base-1 : container
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(0,-8.5,0);
    glBegin(GL_POLYGON);
    for(i=45;i>=-225; i--)
    {
        radius = 2;
        angle = i*3.142/180;
        glVertex2d(1.5*radius*cos(angle),1.8*radius*sin(angle));

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(0,-8.5,0);
    glBegin(GL_LINE_LOOP);
    for(i=45;i>=-225; i--)
        {
            radius = 2;
            angle = i*3.142/180;
            glVertex2d(1.5*radius*cos(angle),1.8*radius*sin(angle));
        }
    glEnd();
    glPopMatrix();


    //edges
    for(int p=0;p<=1;p++){ //nested loops to have 2 layer base
    glPushMatrix();
    glTranslated(0,-6,0);

     if (p==0) {
        glBegin(GL_POLYGON);
        radius = 2;
        glColor3f(1, 1, 1);

    }
    else{

        glBegin(GL_POLYGON);
        glEnable(GL_BLEND);
        radius = 1.5;
        glColor3f(0,0,0);

    }
        for(i=0;i<360; i++)
        {
            angle = i*3.142/180;
            glVertex2d(1.2*radius*cos(angle),0.7*radius*sin(angle)); //stretching circle along X&Y to give ellipse look
        }

    if (p==0) {
        glEnd();
    }
    else if(p==1) {
        glEnd();
    }
    else{
        glEnd();
    }
    glPopMatrix();
    }

    //bowl base-2 : container
    glPushMatrix();
    glTranslated(-1+fish_step,-1,0);

    glPushMatrix();
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_TRIANGLES); //triangle 1 for fish tail (back)
    glVertex2f(0,-8);
    glVertex2f(1.5,-8);
    glVertex2f(1,-9);
    glEnd();
    glPopMatrix();

    //tail-2
    glPushMatrix();
    glColor3f(0.9, 0.9, 0);
    glBegin(GL_TRIANGLES); //triangle 1 for fish tail (front)
    glVertex2f(0,-8);
    glVertex2f(1.5,-8);
    glVertex2f(1.5,-9);
    glPopMatrix();
    glEnd();

    //head
    glPushMatrix();
    glTranslatef(0,-8,0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
        for(i=0;i<360; i++)
    {
        radius = 0.5;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),1.5*radius*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();


    //base-3 : bubbles
    glPushMatrix();
    glTranslatef(-0.5,bubble_step,0);
    glPushMatrix();
    glTranslatef(2,-8.5,0);
    glBegin(GL_POLYGON);
    glColor4f(0,0.5,1,0.50);
        for(i=0;i<360; i++)
    {
        radius = 0.3;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5,-9,0);
    glBegin(GL_POLYGON);
    glColor4f(0,0.6,1,0.50);
        for(i=0;i<360; i++)
    {
        radius = 0.2;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,-9.5,0);
    glBegin(GL_POLYGON);
    glColor4f(0,0.5,1,0.50);
        for(i=0;i<360; i++)
    {
        radius = 0.15;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5,-9.7,0);
    glBegin(GL_POLYGON);
    glColor4f(0,0.5,1,0.50);
        for(i=0;i<360; i++)
    {
        radius = 0.1;
        angle = i*3.142/180;
        glVertex2d(radius*cos(angle),radius*sin(angle));
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();




    glFlush();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20,20,-20,20);
    glMatrixMode(GL_MODELVIEW);
}



void fish_anim(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,fish_anim,0);

    if(fish_state==0){
        if(fish_step<0.5)
            fish_step+=0.04;
        else
            fish_state=1;
    }
    else{
        if(fish_step>-0.5)
            fish_step-=0.04;
        else
            fish_state=0;
    }

}

void bubble_anim(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,bubble_anim,0);

    if(bubble_state==0){
        if(bubble_step<0.5){
                bubble_step+=0.0075;
        sky_step+=0.01;
        }

        else
            bubble_state=1;

    }
    else{
        if(bubble_step>0){
            bubble_step-=0.0075;
            sky_step-=0.01;
        }
        else
            bubble_state=0;
    }

}

void star_anim(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,star_anim,0);

    if(star_state==0){

        if(star_step<13)
            star_step+=0.1;
        else
            star_state=1;
    }
    else{star_step=0;star_state=0;}


}


void eyes_anim(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,eyes_anim,0);

    if(eyes_state==0){
        if(eyes_step<0.3)
            eyes_step+=0.018;
        else
            eyes_state=1;

    }
    else{
        if(eyes_step>-0.3)
            eyes_step-=0.018;
        else
            eyes_state=0;
    }

}
