#include <iostream>
using namespace std;

#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <windows.h>
#include <mmsystem.h>
#define pi 3.14159265358979323846

int mode = 1; // 1 for day ; 0 for night
bool light=false;
float theta;
float cp1=0.5f;
float csp1=1.0f;

float cp2=0.5f;
float csp2=1.0f;

float cp3=0.5f;
float csp3=1.0f;

float Hp1=3.5f;
float Hsp1=4.5f;

float carp=1.5f;
float carsp=1.5f;

float rain = 0.0;
bool rainday = false;

float bird=2.5f;
float birdsp=2.5f;




void Rain(int value){

if(rainday){

    rain += 0.001f;

    glBegin(GL_POINTS);
    for(int i=1;i<=300;i++)
    {
        int x=rand(),y=rand();
        x%=320; y%=240;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+10,y+10);
        glEnd();


        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(-x,y);
        glVertex2d(-x+10,y+10);
        glEnd();


        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(-x,-y);
        glVertex2d(-x+10,-y+10);
        glEnd();


        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,-y);
        glVertex2d(x+10,-y+10);
        glEnd();




    }

	glutPostRedisplay();
	glutTimerFunc(25, Rain, 0);

    glFlush();

}
}


void Control_Through_Keyboard(unsigned char key, int x, int y) {

    switch (key)
    {


    case 'r':
        rainday = true;
        Rain(rain);


        break;

    case 'e':
        rainday = false;


        break;

    case 'n':
        mode = 0;

        break;

    case 'd':
        mode = 1;

        break;

    case 27:
        exit(0);
        break;

    default:
    break;

    }
}

void update(int value) {

    if(cp1 < -320)
       {
         cp1 = 320; //cloud 1
       }

    cp1 -= csp1;

    if(cp2 < -320)
       {
         cp2 = 320;
       }

    cp2 -= csp2;

    if(cp3 < -320)
       {
         cp3 = 320;
       }

    cp3 -= csp3;

        if(Hp1 < -450)
       {
         Hp1 = 320;//helicopter
       }

    Hp1 -= Hsp1;


     if(bird > 360)
       {
         bird = -320;

       }

    bird += birdsp;

	glutPostRedisplay();

	glutTimerFunc(100, update, 0);
}

void drawCircle (GLfloat x, GLfloat y, GLfloat rad, GLfloat a, GLfloat b, GLfloat c) {

	       glColor3ub (a, b, c);
           glPointSize(5.0);
           glBegin(GL_POLYGON);
          for(int i=0; i<360 ; i++)
           {
             theta=i*3.142/180;
          glVertex2f(x+rad*cos(theta),y+rad*sin(theta));
           }

            glEnd();

}
void drawTriangle (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat a, GLfloat b, GLfloat c) {

    glBegin(GL_TRIANGLES);
    glColor3ub(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawQuad (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, GLfloat a, GLfloat b, GLfloat c) {

    glBegin(GL_QUADS);
    glColor3ub(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}



void myDisplay(void)

{

glClear (GL_COLOR_BUFFER_BIT);




glPointSize(5.0);

//sky
if(mode)
    drawQuad(-320,90,320,-90,320,240,-320,240,82, 255, 246);
    else
    drawQuad(-320,90,320,-90,320,240,-320,240,4, 7, 94);
//star
if(!mode){
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    int xvalue=-300,yvalue=220;
    for(int j=0;j<3;j++){
            if(j) { xvalue=-275; yvalue=190; }
            if(j==2) { xvalue=-320; yvalue=150; }
    for(int i=0;i<11;i++){
    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glColor3ub (255,255,255);
    glVertex2i(xvalue,yvalue);
    xvalue+=50;
    glEnd();
    }
        }
}
//sun
if(mode)
drawCircle(270,200,25,252, 232, 3);
else{
    drawCircle(270,200,25,254, 255, 191);
    drawCircle(285,215,30,4, 7, 94);
}
//pahar line
if(mode){
glColor3ub (85, 107, 47);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(320, 90);

glVertex2i(-320 , 90);

glEnd();
}
else{
        glColor3ub (105, 139, 34);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(320, 90);

glVertex2i(-320 , 90);

glEnd();

}


//LEFT 1 PAHAR
if(mode){

glColor3ub (69, 139, 0);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-320, 90);

glVertex2i(-100 , 90);

glVertex2i(-200 , 150);

glEnd();
}
else{

glColor3ub (0,139, 69);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-320, 90);

glVertex2i(-100 , 90);

glVertex2i(-200 , 150);

glEnd();

}
//LEFT 2 PAHAR
if(mode){

    glColor3ub (69, 139, 0);

    glPointSize(5.0);

    glBegin(GL_QUADS);

    glVertex2i(-160, 120);

    glVertex2i(-90 , 150);

    glVertex2i(-60 , 90);

    glVertex2i(-100 , 90);
    glEnd();
}
else{

    glColor3ub (0,139, 69);

    glPointSize(5.0);

    glBegin(GL_QUADS);

    glVertex2i(-160, 120);

    glVertex2i(-90 , 150);

    glVertex2i(-60 , 90);

    glVertex2i(-100 , 90);
    glEnd();


}

//LEFT 3 PAHAR
if(mode){
glColor3ub (69, 139, 0);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(-70, 100);

glVertex2i(-10 , 150);

glVertex2i(60 , 90);

glVertex2i(-60 , 90);

glEnd();

}
else{

glColor3ub (0,139, 69);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(-70, 100);

glVertex2i(-10 , 150);

glVertex2i(60 , 90);

glVertex2i(-60 , 90);

glEnd();


}

//LEFT 4 PAHAR
if(mode){
glColor3ub (69, 139, 0);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(60, 90);

glVertex2i(150 , 150);

glVertex2i(210 , 90);

glEnd();
}
else{

glColor3ub (0,139, 69);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(60, 90);

glVertex2i(150 , 150);

glVertex2i(210 , 90);

glEnd();
}
//LEFT 5 PAHAR
if(mode){
glColor3ub (69, 139, 0);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(190, 100);

glVertex2i(240 , 150);

glVertex2i(300 , 155);

glVertex2i(210 , 90);

glEnd();
}
else{

glColor3ub (0,139, 69);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(190, 100);

glVertex2i(240 , 150);

glVertex2i(300 , 155);

glVertex2i(210 , 90);

glEnd();
}

//LEFT 6 PAHAR
if(mode){
glColor3ub (69, 139, 0);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(290, 100);

glVertex2i(320 , 170);

glVertex2i(320 , 90);

glVertex2i(210 , 90);
glEnd();
}
else{

glColor3ub (0, 139, 69);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(290, 100);

glVertex2i(320 , 170);

glVertex2i(320 , 90);

glVertex2i(210 , 90);
glEnd();



}
//cloud
if(mode)
{
    glPushMatrix();

glTranslatef(cp1, 0.0, 0.0);
drawCircle(230,180,20,255, 255, 255);
drawCircle(180,180,20,255, 255, 255);
drawCircle(210,180,30,255, 255, 255);

glPopMatrix();

glPushMatrix();

glTranslatef(cp2, 0.0, 0.0);
drawCircle(-250,190,20,255, 255, 255);
drawCircle(-200,190,20,255, 255, 255);
drawCircle(-225,190,30,255, 255, 255);
glPopMatrix();

glPushMatrix();

glTranslatef(cp3, 0.0, 0.0);
drawCircle(-20,210,15,255, 255, 255);
drawCircle(20,210,15,255, 255, 255);
drawCircle(0,210,25,255, 255, 255);
glPopMatrix();
}
else{

       int x=320,y=240;
    for(int i=1;i<=50;i++)
    {


        glBegin(GL_POINT);
        glPointSize(5.0);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x-5,y-5);


    }  glEnd();

}

//bird
if (mode)
{

    if(!rainday)

    {
         glPushMatrix();

    glTranslatef(bird, 0.0, 0.0);
    drawTriangle(7,205,18,195,13,215,107, 16, 7);//bird1
    drawCircle(10,210,5,107, 16, 7);
    drawCircle(18,195,2,107, 16, 7);
    drawTriangle(25,215,18,195,31,205,107, 16, 7);
    drawCircle(28,210,5,107, 16, 7);

    drawTriangle(27,190,38,180,33,200,107, 16, 7);//bird2
    drawCircle(30,195,5,107, 16, 7);
    drawCircle(38,180,2,107, 16, 7);
    drawTriangle(45,200,38,180,51,190,107, 16, 7);
    drawCircle(48,195,5,107, 16, 7);



    drawTriangle(37,215,48,205,43,225,107, 16, 7);//bird3
    drawCircle(40,220,5,107, 16, 7);
    drawCircle(48,205,2,107, 16, 7);
    drawTriangle(55,225,48,205,61,215,107, 16, 7);
    drawCircle(58,220,5,107, 16, 7);
glPopMatrix();
    }


}
//helicopter


glPushMatrix();

glTranslatef(Hp1, 0.0, 0.0);
drawCircle(20,160,10,41, 77, 37);
drawCircle(45,160,30,41, 77, 37);
drawQuad(60,170,60,140,120,160,120,170,41, 77, 37);
drawCircle(120,165,5,41, 77, 37);
drawTriangle(8,160,10,160,10,180,0,0,0);
drawTriangle(8,160,10,160,10,140,0,0,0);
drawQuad(45,180,50,180,50,200,45,200,41, 77, 37);
drawTriangle(45,195,45,200,5,195,0,0,0);
drawTriangle(50,195,90,200,50,200,0,0,0);
drawTriangle(125,165,127,165,126,180,0,0,0);

drawTriangle(125,165,126,150,127,165,0,0,0);

drawQuad(35,135,30,120,35,120,40,135,41, 77, 37);
drawQuad(55,135,60,120,65,120,60,135,41, 77, 37);
drawQuad(33,122,63,122,63,125,33,125,41, 77, 37);
drawQuad(25,160,40,160,40,180,25,180,245, 242, 76);
drawCircle(32,175,8,245, 242, 76);
drawCircle(30,170,10,245, 242, 76);
glPopMatrix();




//field
if (mode)
drawQuad(-320,-240,320,-240,320,90,-320,90,235, 191, 115);
else{drawQuad(-320,-240,320,-240,320,90,-320,90,89, 52, 18);}



//helipad Circle circle
if(mode){
drawCircle(-303,72,12,240, 248, 255);


drawQuad(-315,15,-290,15,-290,76,-315,76,139,69, 19);//small container
//drawQuad(-48,18,-72,18,-72,73,-48,73,85, 77, 37);
drawCircle(140,-155,70,0,0,0);
drawCircle(140,-155,60,255, 255, 255);
}
else{

drawCircle(-303,72,12,240, 248, 255);


drawQuad(-315,15,-290,15,-290,76,-315,76,139,69, 19);
//small container
//drawQuad(-48,18,-72,18,-72,73,-48,73,85, 77, 37);
drawCircle(140,-155,70,0,0,0);
drawCircle(140,-155,60,122 ,122, 122);

}

//helipad

drawQuad(80,-130,200,-130,200,-120,80,-120,0,0,0);
drawQuad(80,-190,200,-190,200,-180,80,-180,0,0,0);
drawQuad(135,-190,143,-190,143,-120,135,-120,0,0,0);
//watch tower-left

   //roof tower
if (mode)
{
  glBegin(GL_TRIANGLES);
    glColor3ub(205, 155, 29);

    glVertex2i(-270, 45);

    glVertex2i(-230, 45);

    glVertex2i(-250, 75);

    glEnd();
}

else{
    glBegin(GL_TRIANGLES);
    glColor3ub(33, 24, 1);

    glVertex2i(-270, 45);

    glVertex2i(-230, 45);

    glVertex2i(-250, 75);

    glEnd();
}


//square tower
if(mode)
{
    glBegin(GL_POLYGON);

    glColor3ub(85, 107, 47);

    glVertex2i(-265, 0);

    glVertex2i(-235, 0);

    glVertex2i(-235, 45);

    glVertex2i(-265, 45);

    glEnd();

}

  else{
          glBegin(GL_POLYGON);

    glColor3ub(33, 48, 5);

    glVertex2i(-265, 0);

    glVertex2i(-235, 0);

    glVertex2i(-235, 45);

    glVertex2i(-265, 45);

    glEnd();


  }



 //window tower

 if (mode){
    glBegin(GL_POLYGON);

    glColor3ub(224, 255, 255);

    glVertex2i(-258, 12);

    glVertex2i(-242, 12);

    glVertex2i(-242, 28);

    glVertex2i(-258, 28);

    glEnd();
 }
 else{

    glBegin(GL_POLYGON);

    glColor3ub(25, 25, 112);

    glVertex2i(-258, 12);

    glVertex2i(-242, 12);

    glVertex2i(-242, 28);

    glVertex2i(-258, 28);

    glEnd();


 }


   //Right WC Leg tower
   if(mode){
    glBegin(GL_POLYGON);

    glColor3ub(139,69,19);

    glVertex2i(-235,-0);

    glVertex2i(-238,0);

    glVertex2i(-238,-65);

    glVertex2i(-235,-65);

    glEnd();
   }
   else{
        glBegin(GL_POLYGON);

    glColor3ub(139, 101, 8);

    glVertex2i(-235,-0);

    glVertex2i(-238,0);

    glVertex2i(-238,-65);

    glVertex2i(-235,-65);

    glEnd();

   }


    // WC Leg
    if(mode){
    glBegin(GL_POLYGON);

    glColor3ub(139,69,19);

    glVertex2i(-265,0);

    glVertex2i(-262,0);

    glVertex2i(-262,-65);

    glVertex2i(-265,-65);

    glEnd();
    }
    else{
    glBegin(GL_POLYGON);

    glColor3ub(139, 101, 8);

    glVertex2i(-265,0);

    glVertex2i(-262,0);

    glVertex2i(-262,-65);

    glVertex2i(-265,-65);

    glEnd();

    }

 //WC Leg
 if(mode){
    glBegin(GL_POLYGON);

    glColor3ub(139,69,19);

    glVertex2i(-265,0);

    glVertex2i(-235,-30);

    glVertex2i(-235,-25);

    glVertex2i(-265,5);

    glEnd();
 }
 else{
    glBegin(GL_POLYGON);

    glColor3ub(139, 101, 8);

    glVertex2i(-265,0);

    glVertex2i(-235,-30);

    glVertex2i(-235,-25);

    glVertex2i(-265,5);

    glEnd();



 }
//WC legs
 if(mode){
    glBegin(GL_POLYGON);

    glColor3ub(139,69,19);

    glVertex2i(-235,0);

    glVertex2i(-265,-30);

    glVertex2i(-265,-25);

    glVertex2i(-235,5);

    glEnd();
 }
 else{
    glBegin(GL_POLYGON);

    glColor3ub(139, 101, 8);

    glVertex2i(-235,0);

    glVertex2i(-265,-30);

    glVertex2i(-265,-25);

    glVertex2i(-235,5);

    glEnd();


 }


 //wc legs
 if(mode){
    glBegin(GL_POLYGON);

    glColor3ub(139,69,19);

    glVertex2i(-265,-30);

    glVertex2i(-235,-60);

    glVertex2i(-235,-55);

    glVertex2i(-265,-25);

    glEnd();
 }
 else{
    glBegin(GL_POLYGON);

    glColor3ub(139, 101, 8);

    glVertex2i(-265,-30);

    glVertex2i(-235,-60);

    glVertex2i(-235,-55);

    glVertex2i(-265,-25);

    glEnd();



 }



//WC LEGS 4th
if(mode){

    glBegin(GL_POLYGON);

    glColor3ub(139,69,19);

    glVertex2i(-265,-60);

    glVertex2i(-235,-30);

    glVertex2i(-235,-25);

    glVertex2i(-265,-55);

    glEnd();
}

else{
    glBegin(GL_POLYGON);

    glColor3ub(139, 101, 8);

    glVertex2i(-265,-60);

    glVertex2i(-235,-30);

    glVertex2i(-235,-25);

    glVertex2i(-265,-55);

    glEnd();


}


 //4th
if(mode){
    glBegin(GL_POLYGON);

    glColor3ub(139,69,19);

    glVertex2i(-270,-70);

    glVertex2i(-230,-70);

    glVertex2i(-230,-60);

    glVertex2i(-270,-60);

    glEnd();
}
else{
        glBegin(GL_POLYGON);

    glColor3ub(139, 101, 8);

    glVertex2i(-270,-70);

    glVertex2i(-230,-70);

    glVertex2i(-230,-60);

    glVertex2i(-270,-60);

    glEnd();

}

//tree
if(mode)
{
    drawQuad(30,0,40,0,40,50,30,50,92, 26, 3);//tree1
    drawCircle(40,50,15,51, 140, 18);
    drawCircle(30,50,15,51, 140, 18);
    drawCircle(35,60,15,51, 140, 18);


     drawQuad(80,0,90,0,90,50,80,50,92, 26, 3);//tree2
    drawCircle(80,50,15,51, 140, 18);
    drawCircle(90,50,15,51, 140, 18);
    drawCircle(85,60,15,51, 140, 18);


     drawQuad(120,0,130,0,130,50,120,50,92, 26, 3);//tree2
    drawCircle(120,50,15,51, 140, 18);
    drawCircle(130,50,15,51, 140, 18);
    drawCircle(125,60,15,51, 140, 18);



     drawQuad(160,0,170,0,170,50,160,50,92, 26, 3);//tree3
    drawCircle(160,50,15,51, 140, 18);
    drawCircle(170,50,15,51, 140, 18);
    drawCircle(165,60,15,51, 140, 18);


     drawQuad(200,0,210,0,210,50,200,50,92, 26, 3);//tree4
    drawCircle(200,50,15,51, 140, 18);
    drawCircle(210,50,15,51, 140, 18);
    drawCircle(205,60,15,51, 140, 18);


     drawQuad(-10,0,0,0,0,50,-10,50,92, 26, 3);//tree5
    drawCircle(-10,50,15,51, 140, 18);
    drawCircle(0,50,15,51, 140, 18);
    drawCircle(-5,60,15,51, 140, 18);


    drawQuad(-50,0,-40,0,-40,50,-50,50,92, 26, 3);//tree5
    drawCircle(-50,50,15,51, 140, 18);
    drawCircle(-40,50,15,51, 140, 18);
    drawCircle(-45,60,15,51, 140, 18);


    drawQuad(-90,0,-80,0,-80,50,-90,50,92, 26, 3);//tree6
    drawCircle(-90,50,15,51, 140, 18);
    drawCircle(-80,50,15,51, 140, 18);
    drawCircle(-85,60,15,51, 140, 18);



    drawQuad(-130,0,-120,0,-120,50,-130,50,92, 26, 3);//tree6
    drawCircle(-130,50,15,51, 140, 18);
    drawCircle(-120,50,15,51, 140, 18);
    drawCircle(-125,60,15,51, 140, 18);





}

else{
    drawQuad(30,0,40,0,40,50,30,50,66, 31, 27);//tree1
    drawCircle(40,50,15,22, 46, 25);
    drawCircle(30,50,15,22, 46, 25);
    drawCircle(35,60,15,22, 46, 25);


     drawQuad(80,0,90,0,90,50,80,50,66, 31, 27);//tree2
    drawCircle(80,50,15,22, 46, 25);
    drawCircle(90,50,15,22, 46, 25);
    drawCircle(85,60,15,22, 46, 25);


     drawQuad(120,0,130,0,130,50,120,50,66, 31, 27);//tree2
    drawCircle(120,50,15,22, 46, 25);
    drawCircle(130,50,15,22, 46, 25);
    drawCircle(125,60,15,22, 46, 25);



     drawQuad(160,0,170,0,170,50,160,50,66, 31, 27);//tree3
    drawCircle(160,50,15,22, 46, 25);
    drawCircle(170,50,15,22, 46, 25);
    drawCircle(165,60,15,22, 46, 25);


     drawQuad(200,0,210,0,210,50,200,50,66, 31, 27);//tree4
    drawCircle(200,50,15,22, 46, 25);
    drawCircle(210,50,15,22, 46, 25);
    drawCircle(205,60,15,22, 46, 25);


     drawQuad(-10,0,0,0,0,50,-10,50,66, 31, 27);//tree5
    drawCircle(-10,50,15,22, 46, 25);
    drawCircle(0,50,15,22, 46, 25);
    drawCircle(-5,60,15,22, 46, 25);


    drawQuad(-50,0,-40,0,-40,50,-50,50,66, 31, 27);//tree5
    drawCircle(-50,50,15,22, 46, 25);
    drawCircle(-40,50,15,22, 46, 25);
    drawCircle(-45,60,15,22, 46, 25);


    drawQuad(-90,0,-80,0,-80,50,-90,50,66, 31, 27);//tree6
    drawCircle(-90,50,15,22, 46, 25);
    drawCircle(-80,50,15,22, 46, 25);
    drawCircle(-85,60,15,22, 46, 25);



    drawQuad(-130,0,-120,0,-120,50,-130,50,66, 31, 27);//tree6
    drawCircle(-130,50,15,22, 46, 25);
    drawCircle(-120,50,15,22, 46, 25);
    drawCircle(-125,60,15,22, 46, 25);

}
//window
//windmill
// windmill RIGHT BELLOW TRIANGLE 1


// TENT 4 TOP VIEW
if(mode){
glColor3ub (0, 128, 0);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(-45, -60);
glVertex2i(-45 , -15);
glVertex2i(50, -15);
glVertex2i(50 , -60);




glEnd();
}

// TENT 4 TOP VIEW
if(mode){
glColor3ub (0, 128, 0);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(-45, -60);
glVertex2i(-45 , -15);
glVertex2i(50, -15);
glVertex2i(50 , -60);




glEnd();
}
else{
glColor3ub (85, 107, 47);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(-45, -60);
glVertex2i(-45 , -15);
glVertex2i(50, -15);
glVertex2i(50 , -60);




glEnd();


}

//TENT 4 UPPER TRIANGLE

if(mode){
glColor3ub (0, 128, 0);
glPointSize(5.0);
glBegin(GL_TRIANGLES);
glVertex2i(-45, -15);
glVertex2i(50 , -15);
glVertex2i(2.5, 30);




glEnd();
}
else{
glColor3ub (0, 100,0);
glPointSize(5.0);
glBegin(GL_TRIANGLES);
glVertex2i(-45, -15);
glVertex2i(50 , -15);
glVertex2i(2.5, 30);




glEnd();

}

//DOOR TENT 4
if(mode){
glColor3ub (184, 184, 148);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(-25, -60);
glVertex2i(-25 , -30);
glVertex2i(30, -30);
glVertex2i(30, -60);



glEnd();
}
else{
        glColor3ub (74, 74, 74);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(-25, -60);
glVertex2i(-25 , -30);
glVertex2i(30, -30);
glVertex2i(30, -60);



glEnd();

}


//DOOR LEFT
if(mode){
glColor3ub (255, 255, 255);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(-25, -60);
glVertex2i(-25 , -30);
glVertex2i(-22, -30);
glVertex2i(-22, -60);



glEnd();
}
else{
    glColor3ub (145, 145, 145);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(-25, -60);
glVertex2i(-25 , -30);
glVertex2i(-22, -30);
glVertex2i(-22, -60);



glEnd();

}

//DOOR RIGHT
if(mode){
glColor3ub (255, 255, 255);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(30, -30);
glVertex2i(30 , -60);
glVertex2i(27, -60);
glVertex2i(27, -30);



glEnd();
}
else{
        glColor3ub (145, 145, 145);
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(30, -30);
glVertex2i(30 , -60);
glVertex2i(27, -60);
glVertex2i(27, -30);



glEnd();

}

//TENT 4 DOOR LEFT TRIANGLE
if(mode){
glColor3ub (0, 255, 128);
glPointSize(5.0);
glBegin(GL_TRIANGLES);
glVertex2i(2.5, -30);
glVertex2i(-25 , -30);
glVertex2i(-25, -45);



glEnd();
}
else{
        glColor3ub (69 ,139 ,116);
glPointSize(5.0);
glBegin(GL_TRIANGLES);
glVertex2i(2.5, -30);
glVertex2i(-25 , -30);
glVertex2i(-25, -45);



glEnd();

}


//TENT 4 DOOR RIGHT TRIANGLE
if(mode){
glColor3ub (0, 255, 128);
glPointSize(5.0);
glBegin(GL_TRIANGLES);
glVertex2i(-2.5, -30);
glVertex2i(30 , -30);
glVertex2i(30, -45);



glEnd();
}
else{
        glColor3ub (69 ,139 ,116);
glPointSize(5.0);
glBegin(GL_TRIANGLES);
glVertex2i(-2.5, -30);
glVertex2i(30 , -30);
glVertex2i(30, -45);



glEnd();

}

//TENT LINE PAR
if(mode){
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(70, -60);
glVertex2i(70 , -70);

glEnd();
}
else{
        glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(70, -60);
glVertex2i(70 , -70);

glEnd();

}



//TENT LINE PAR UPPER
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(70, -60);
glVertex2i(50 , -15);

glEnd();


//TENT LINE PAR LOWER
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(70, -60);
glVertex2i(30 , -30);

glEnd();



//TENT LINE LEFT PAR
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(-65 ,-60);
glVertex2i(-65 , -70);

glEnd();



//TENT LINE LEFT PAR UPPER
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(-65 ,-60);
glVertex2i(-45 , -15);

glEnd();


//TENT LINE LEFT PAR LOWER
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(-65 ,-60);
glVertex2i(-25 , -30);

glEnd();


// TENT 4 TOP VIEW LINE
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
glVertex2i(-45, -60);
glVertex2i(-45 , -15);
glVertex2i(50, -15);
glVertex2i(50 , -60);
glVertex2i(50 , -60);
glVertex2i(-45, -60);


glEnd();


//TENT 4 UPPER TRIANGLE LINE
glColor3ub (0, 0, 0);
glPointSize(5.0);
glBegin(GL_LINES);
//glVertex2i(-45, -15);
//glVertex2i(50 , -15);
glVertex2i(50 , -15);
glVertex2i(2.5, 30);
glVertex2i(2.5, 30);
glVertex2i(-45, -15);

glEnd();

//watch tower end

//LEFT LOWER CORNER TENT
if(mode){
glColor3ub (107, 142, 35);

glBegin(GL_POLYGON);

glVertex2i(-280, -100);

glVertex2i(-170 , -100);

glVertex2i(-170 , -160);

glVertex2i(-280 , -160);

glEnd();
}
else{
        glColor3ub (0,100, 0);

glBegin(GL_POLYGON);

glVertex2i(-280, -100);

glVertex2i(-170 , -100);

glVertex2i(-170 , -160);

glVertex2i(-280 , -160);

glEnd();

}

//flag
if(mode)
{

    drawQuad(-210,-100,-205,-100,-205,-10,-210,-10,194, 75, 2);
    drawQuad(-205,-50,-170,-50,-170,-10,-205,-10,26, 79, 4);
    drawCircle(-190,-30,8,189, 9, 9);

}
else
    drawQuad(-210,-100,-205,-100,-205,-10,-210,-10,38, 16, 1);

////LEFT LOWER CORNER TENT TOP
if(mode){
glColor3ub (51, 102, 0);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-280, -100);

glVertex2i(-220 , -50);

glVertex2i(-170 , -100);

glEnd();
}
else{
        glColor3ub (85,107, 47);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-280, -100);

glVertex2i(-220 , -50);

glVertex2i(-170 , -100);

glEnd();

}

//TENT DOOR
if(mode){
glColor3ub (102, 102, 102);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-250, -115);

glVertex2i(-200 , -115);

glVertex2i(-200 , -160);

glVertex2i(-250 , -160);

glEnd();
}
else{
        glColor3ub (69 ,139 ,116);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-250, -115);

glVertex2i(-200 , -115);

glVertex2i(-200 , -160);

glVertex2i(-250 , -160);

glEnd();


}

// DOOR SIDE LEFT
if(mode){
glColor3ub (255, 242, 204);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-250, -160);

glVertex2i(-250 , -115);

glVertex2i(-247 , -115);

glVertex2i(-247 , -160);

glEnd();
}
else{
        glColor3ub (105 ,139 ,105);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-250, -160);

glVertex2i(-250 , -115);

glVertex2i(-247 , -115);

glVertex2i(-247 , -160);

glEnd();

}

//DOOR SIDE RIGHT
if(mode){

glColor3ub (255, 255, 225);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-200, -160);

glVertex2i(-200 , -115);

glVertex2i(-203 , -115);

glVertex2i(-203 , -160);

glEnd();
}
else{
        glColor3ub (105, 139 ,105);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-200, -160);

glVertex2i(-200 , -115);

glVertex2i(-203 , -115);

glVertex2i(-203 , -160);

glEnd();


}

//DOOR LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-250, -115);

glVertex2i(-200 , -115);

glEnd();

//LEFT DOOR TRIANGLE
if(mode){
glColor3ub (128, 255, 128);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-250, -135);

glVertex2i(-250 , -115);

glVertex2i(-225 , -115);

glEnd();
}

else{
        glColor3ub (105, 139, 105);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-250, -135);

glVertex2i(-250 , -115);

glVertex2i(-225 , -115);

glEnd();




}

//RIGHT DOOR TRIANGLE
if(mode){
glColor3ub (128, 255, 128);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-203, -135);

glVertex2i(-203 , -115);

glVertex2i(-228 , -115);

glEnd();
}
else{
        glColor3ub (105, 139, 105);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-203, -135);

glVertex2i(-203 , -115);

glVertex2i(-228 , -115);

glEnd();

}

// TENT LINE RIGHT 1

if(mode){

glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-120, -175);

glVertex2i(-120 , -180);

glEnd();

//LINE1

glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-120, -175);

glVertex2i(-170 , -100);

glEnd();
}
else{

glColor3ub (0,0,0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-120, -175);

glVertex2i(-170 , -100);

glEnd();


}

//LINE2
if(mode){
glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-120, -175);

glVertex2i(-200 , -115);

glEnd();
}
else{

glColor3ub (0,0,0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-120, -175);

glVertex2i(-200 , -115);

glEnd();

}

// TENT LINE LEFT 1
if(mode){

glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-310, -175);

glVertex2i(-310 , -180);

glEnd();
}
else{

glColor3ub (0,0,0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-310, -175);

glVertex2i(-310 , -180);

glEnd();

}

//LINE1 FOR LEFT
if(mode){
glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-310, -175);

glVertex2i(-280 , -100);

glEnd();
}
else{
        glColor3ub (0,0,0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-310, -175);

glVertex2i(-280 , -100);

glEnd();

}

//LINE2 FOR LEFT
if(mode){

glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-310, -175);

glVertex2i(-250 , -115);

glEnd();
}
else{

glColor3ub (0,0,0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-310, -175);

glVertex2i(-250 , -115);

glEnd();

}

// BOX 1 TOP SIDE

if(mode){

glColor3ub (255, 140, 26);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(80, -80);

glVertex2i(120 , -80);

glVertex2i(120 , -40);

glVertex2i(80 , -40);

glEnd();
}
else{


glColor3ub (139, 117, 0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(80, -80);

glVertex2i(120 , -80);

glVertex2i(120 , -40);

glVertex2i(80 , -40);

glEnd();


}

// BOX 1 RIGHT SIDE
if(mode){
glColor3ub (204, 102, 0);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(120, -40);

glVertex2i(140 , -30);

glVertex2i(140 , -60);

glVertex2i(120 , -80);

glEnd();
}
else{

glColor3ub (139, 105, 20);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(120, -40);

glVertex2i(140 , -30);

glVertex2i(140 , -60);

glVertex2i(120 , -80);

glEnd();


}

// BOX 1 TOP DOWN SIDE

glColor3ub (204, 153, 0);

glPointSize(5.0);

glBegin(GL_QUADS);

glVertex2i(80, -40);

glVertex2i(120 , -40);

glVertex2i(140 , -30);

glVertex2i(100 , -30);
glEnd();

// BOX 1 TOP SIDE LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(80, -80);

glVertex2i(120 , -80);

glVertex2i(120 , -80);

glVertex2i(120 , -40);

glVertex2i(120 , -40);

glVertex2i(80 , -40);

glVertex2i(80 , -40);

glVertex2i(80, -80);



glEnd();

// BOX 1 TOP DOWN SIDE LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(80, -40);

glVertex2i(120 , -40);

glVertex2i(120 , -40);

glVertex2i(140 , -30);

glVertex2i(140 , -30);

glVertex2i(100 , -30);

glVertex2i(100 , -30);

glVertex2i(80, -40);

glEnd();

// BOX 1 RIGHT SIDE LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(120, -40);

glVertex2i(140 , -30);

glVertex2i(140 , -30);

glVertex2i(140 , -60);

glVertex2i(140 , -60);

glVertex2i(120 , -80);

glVertex2i(120 , -80);

glVertex2i(120, -40);

glEnd();

//BOX 2 TOP SIDE
if(mode){
glColor3ub (255, 140, 26);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(140, -60);

glVertex2i(180 , -60);

glVertex2i(180 , -30);

glVertex2i(140 , -30);

glEnd();

}
else{

glColor3ub (139, 105, 20);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(140, -60);

glVertex2i(180 , -60);

glVertex2i(180 , -30);

glVertex2i(140 , -30);

glEnd();

}

//BOX 2 TOPDOWN SIDE

glColor3ub (204, 153, 0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(140, -30);

glVertex2i(180 , -30);

glVertex2i(200 , -20);

glVertex2i(160 , -20);

glEnd();


//BOX 2 right SIDE
if(mode){
glColor3ub (204, 102, 0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(180, -60);

glVertex2i(180 , -30);

glVertex2i(200 , -20);

glVertex2i(200 , -40);
glEnd();
}
else{

glColor3ub (139 ,105, 20);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(180, -60);

glVertex2i(180 , -30);

glVertex2i(200 , -20);

glVertex2i(200 , -40);
glEnd();

}

//BOX 2 right SIDE line

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(180, -60);

glVertex2i(180 , -30);

glVertex2i(180 , -30);

glVertex2i(200 , -20);

glVertex2i(200 , -20);

glVertex2i(200 , -40);

glVertex2i(200 , -40);

glVertex2i(180, -60);

glEnd();




//BOX 2 TOPDOWN SIDE LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(140, -30);

glVertex2i(180 , -30);

glVertex2i(180 , -30);

glVertex2i(200 , -20);

glVertex2i(200 , -20);

glVertex2i(160 , -20);

glVertex2i(160 , -20);

glVertex2i(140, -30);

glEnd();


//BOX 2 TOP SIDE LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(140, -60);

glVertex2i(180 , -60);

glVertex2i(180 , -60);

glVertex2i(180 , -30);

glVertex2i(180 , -30);

glVertex2i(140 , -30);

glVertex2i(140 , -30);

glVertex2i(140, -60);

glEnd();


// BOX 3 TOP SIDE
if(mode){
glColor3ub (255, 140, 26);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(140, -30);

glVertex2i(105 , -30);

glVertex2i(105 , -10);

glVertex2i(140 , -10);

glEnd();

}
else{


glColor3ub (139, 139, 0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(140, -30);

glVertex2i(105 , -30);

glVertex2i(105 , -10);

glVertex2i(140 , -10);

glEnd();
}

// BOX 3 RIGHT SIDE
if(mode){
glColor3ub (204, 102, 0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(140, -30);

glVertex2i(140 , -10);

glVertex2i(155 , -5);

glVertex2i(155 , -22);

glEnd();
}
else{

glColor3ub (139, 117 ,0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(140, -30);

glVertex2i(140 , -10);

glVertex2i(155 , -5);

glVertex2i(155 , -22);

glEnd();


}

// BOX 3 TOP DOWN SIDE

glColor3ub (204, 153, 0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(105, -10);

glVertex2i(140 , -10);

glVertex2i(155 , -5);

glVertex2i(115 , -5);
glEnd();

// BOX 3 TOP SIDE LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(140, -30);

glVertex2i(105 , -30);

glVertex2i(105 , -30);

glVertex2i(105 , -10);

glVertex2i(105 , -10);

glVertex2i(140 , -10);

glVertex2i(140 , -10);

glVertex2i(140, -30);

glEnd();

// BOX 3 TOP DOWN SIDE LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(105, -10);

glVertex2i(140 , -10);

glVertex2i(140 , -10);

glVertex2i(155 , -5);

glVertex2i(155 , -5);

glVertex2i(115 , -5);

glVertex2i(115 , -5);

glVertex2i(105, -10);
glEnd();




   // glPushMatrix();//roof


    //glPopMatrix();

//tank-start


drawCircle(-20,-75,10,0,0,0);
  drawQuad(25,-100,25,-116,75,-116,75,-100,0,0,0);//upper body
  drawQuad(-60,-90,-60,-120,25,-120,25,-90,50,56,6);
  drawQuad(-35,-75,-35,-90,0,-90,0,-75,50,56,6);
  drawCircle(75,-108,8,0,0,0);


    //tankbase

    glBegin(GL_POLYGON);
  glColor3ub(79,68,31);
  for(int i=180;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(-20+cos(angle)*60,-160+sin(angle)*45);
    }
    glEnd();

      //tankbase

    glBegin(GL_POLYGON);
  glColor3ub(50,56,6);
  for(int i=180;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(-20+cos(angle)*39,-160+sin(angle)*24);
    }
    glEnd();

//tank wheel
    drawCircle(-67,-165,10,0,0,0);
     drawCircle(-47,-185,10,0,0,0);
     drawCircle(-17,-193,10,0,0,0);
      drawCircle(12,-185,10,0,0,0);
       drawCircle(27,-165,10,0,0,0);


drawQuad(-90,-160,50,-160,40,-120,-80,-120,50,56,6);
//tank-end



// TENT 2 TOP VIEW
if(mode){
glColor3ub (107, 142, 35);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-165, -15);

glVertex2i(-70 , -15);

glVertex2i(-70 , 30);

glVertex2i(-165 , 30);
glEnd();
}
else{

glColor3ub (0, 100 ,0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-165, -15);

glVertex2i(-70 , -15);

glVertex2i(-70 , 30);

glVertex2i(-165 , 30);
glEnd();

}

// TENT 2 TRIANGLE
if(mode){
glColor3ub (51, 102, 0);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-165, 30);

glVertex2i(-70 , 30);

glVertex2i(-117 , 70);
glEnd();
}
else{

glColor3ub (85, 107, 47);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-165, 30);

glVertex2i(-70 , 30);

glVertex2i(-117 , 70);
glEnd();

}


// TENT 2 DOOR

if(mode){
glColor3ub (102, 102, 102);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-140, -15);

glVertex2i(-95 , -15);

glVertex2i(-95 , 20);

glVertex2i(-140 , 20);
glEnd();
}
else{

glColor3ub (84, 84 ,84);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-140, -15);

glVertex2i(-95 , -15);

glVertex2i(-95 , 20);

glVertex2i(-140 , 20);
glEnd();

}

// TENT 2 DOOR left pipe
if(mode){
glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-140, -15);

glVertex2i(-137 , -15);

glVertex2i(-137 , 20);

glVertex2i(-140 , 20);

glEnd();
}
else{

glColor3ub (117, 117, 117);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-140, -15);

glVertex2i(-137 , -15);

glVertex2i(-137 , 20);

glVertex2i(-140 , 20);

glEnd();
}


// TENT 2 DOOR right pipe
if(mode){
glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-95, -15);

glVertex2i(-95 , 20);

glVertex2i(-98 , 20);

glVertex2i(-98 , -15);
glEnd();
}
else{

glColor3ub (117, 117, 117);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(-95, -15);

glVertex2i(-95 , 20);

glVertex2i(-98 , 20);

glVertex2i(-98 , -15);
glEnd();



}



// TENT 2 DOOR left triangle
if(mode){
glColor3ub (128, 255, 128);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-140, 20);

glVertex2i(-120, 20);

glVertex2i(-140 , 0);

glEnd();

}
else{


glColor3ub (105, 139,105);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-140, 20);

glVertex2i(-120, 20);

glVertex2i(-140 , 0);

glEnd();
}



// TENT 2 DOOR RIGHT triangle
if(mode){
glColor3ub (128, 255, 128);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-95, 20);

glVertex2i(-95, 0);

glVertex2i(-117 , 20);

glEnd();
}
else{

glColor3ub (105, 139,105);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(-95, 20);

glVertex2i(-95, 0);

glVertex2i(-117 , 20);

glEnd();


}


// TENT PAL LAND RIGHT

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-50, 3);

glVertex2i(-50, 10);

glEnd();






// TENT PAL  LEFT

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-175, 17);

glVertex2i(-175, 10);
glEnd();

// TENT PAL  LEFT UPPER

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-175, 17);

glVertex2i(-165, 30);
glEnd();


// TENT PAL  LEFT LOWER



// TENT 2 TRIANGLE LINE

// TENT 2 TOP VIEW LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-165, -15);

glVertex2i(-70 , -15);

glVertex2i(-70 , -15);

glVertex2i(-70 , 30);

//glVertex2i(-70 , 30);

//glVertex2i(-165 , 30);

glVertex2i(-165 , 30);

glVertex2i(-165, -15);

glEnd();


// TENT 2 DOOR LINE

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(-140, -15);

glVertex2i(-95 , -15);

glVertex2i(-95 , -15);

glVertex2i(-95 , 20);

glVertex2i(-95 , 20);

glVertex2i(-140 , 20);

glVertex2i(-140 , 20);

glVertex2i(-140, -15);

glEnd();



glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

//glVertex2i(-280, -100);

glVertex2i(-170 , -100);

//glVertex2i(-170 , -100);

glVertex2i(-170 , -160);

glVertex2i(-170 , -160);

glVertex2i(-280 , -160);

glVertex2i(-280 , -160);

glVertex2i(-280, -100);

glEnd();




// LINE 2

// TENT 3 TOP VIEW
if(mode){
glColor3ub (107, 142, 35);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(45, 0);

glVertex2i(140 , 0);

glVertex2i(140 , 40);

glVertex2i(45 , 40);

glEnd();
}
else{

glColor3ub (0, 139, 0);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(45, 0);

glVertex2i(140 , 0);

glVertex2i(140 , 40);

glVertex2i(45 , 40);

glEnd();

}



// TENT 3 triangle
if(mode){
glColor3ub (51, 102, 0);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(45, 40);

glVertex2i(140 , 40);

glVertex2i(92 , 70);
glEnd();
}
else{


glColor3ub (30, 69, 38);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(45, 40);

glVertex2i(140 , 40);

glVertex2i(92 , 70);
glEnd();
}




// TENT 3 DOOR
if(mode){
glColor3ub (133, 173, 173);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(65, 0);

glVertex2i(120 , 0);

glVertex2i(120 , 30);

glVertex2i(65 , 30);
glEnd();
}
else{

glColor3ub (139, 137, 137);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(65, 0);

glVertex2i(120 , 0);

glVertex2i(120 , 30);

glVertex2i(65 , 30);
glEnd();

}


// TENT 3 DOOR LEFT
if(mode){
glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(65, 0);

glVertex2i(68 , 0);

glVertex2i(68 , 30);

glVertex2i(65 , 30);
glEnd();
}
else{

glColor3ub (110,110, 110);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(65, 0);

glVertex2i(68 , 0);

glVertex2i(68 , 30);

glVertex2i(65 , 30);
glEnd();


}

// TENT 3 DOOR RIGHT
if(mode){
glColor3ub (255, 255, 255);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(120, 0);

glVertex2i(120 , 30);

glVertex2i(117 , 30);

glVertex2i(117, 0);

glEnd();
}
else{

glColor3ub (110, 110 ,110);

glPointSize(5.0);

glBegin(GL_POLYGON);

glVertex2i(120, 0);

glVertex2i(120 , 30);

glVertex2i(117 , 30);

glVertex2i(117, 0);

glEnd();

}


// TENT 3 DOOR LEFT TRIANGLE
if(mode){
glColor3ub (153, 255, 102);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(65, 30);

glVertex2i(92 , 30);

glVertex2i(65 , 15);
glEnd();
}
else{

glColor3ub (69 ,139, 116);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(65, 30);

glVertex2i(92 , 30);

glVertex2i(65 , 15);
glEnd();

}

// TENT 3 DOOR RIGHT TRIANGLE
if(mode){
glColor3ub (153, 255, 102);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(120, 30);

glVertex2i(93 , 30);

glVertex2i(120 , 15);
glEnd();
}
else{

glColor3ub (69,139, 116);

glPointSize(5.0);

glBegin(GL_TRIANGLES);

glVertex2i(120, 30);

glVertex2i(93 , 30);

glVertex2i(120 , 15);
glEnd();

}

// TENT 3 PAL STRICK RIGHT

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(160, 10);

glVertex2i(160 , 0);

glEnd();

// TENT 3 PAL RIGHT upper

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(120, 30);

glVertex2i(160 , 10);

glEnd();

// TENT 3 PAL RIGHT lower

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(160, 10);

glVertex2i(140 , 40);
glEnd();
// TENT 3 PAL left stick

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(35, 20);

glVertex2i(35 , 30);
glEnd();

// TENT 3 PAL left upper

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(45, 40);

glVertex2i(35 , 20);

glEnd();

// TENT 3 PAL left lower

glColor3ub (0, 0, 0);

glPointSize(5.0);

glBegin(GL_LINES);

glVertex2i(65, 30);

glVertex2i(35 , 20);

glEnd();



glFlush ();


}



void myInit (void)

{

glClearColor(0.6, 0.9, 0.8, 0.0);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

gluOrtho2D(-320.0, 320.0, -240.0, 240.0);

}

int main(int argc, char** argv){

glutInit(&argc, argv);

glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

glutInitWindowSize (800, 340);

//glutInitWindowPosition (100, 150);

glutCreateWindow ("Army CAMP");
cout << "1. Press \"n\" for Night Mode View \n";
cout << "2. Press \"d\" for Day Mode View \n";
cout << "3. Press \"r\" for Rain \n";
cout << "4. Press \"e\" to stop Rain \n";


glutDisplayFunc(myDisplay);
glutTimerFunc(25, update, 0);
myInit ();

glutKeyboardFunc(Control_Through_Keyboard);

glutMainLoop();

}
