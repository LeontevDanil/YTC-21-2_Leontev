#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include<cmath>

float pos_x = 0, pos_y = 0;
bool isRight = true;
float angle = 0.0;

bool isGetFlowers[3] = {false,false,false};



// блок объявлений функций
void drawCat(float x,float y,bool isRight,float a);
void renderScene(void);
void processKeys(unsigned char key, int x, int y); // определение фнкции перед фукнцией main
void drawQuadro();

int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(100, 100);
glutInitWindowSize(600, 600);
glutCreateWindow("OpenGL Start Application");
glutDisplayFunc(renderScene);

glutKeyboardFunc(processKeys);

glutMainLoop();
return 0;
}

  float fun(float x){
      float y;

      if (x>1)
          y = 3*x - 7;
      else if(x<1)
          y = 3 * fabs(x+2) - 7;
      else
          y = 3;

      return y;
  }

void processKeys(unsigned char key, int x, int y) {
if (key == 100) {
pos_x = pos_x + 0.1;
isRight = false;
}
if (key == 97) {
pos_x = pos_x - 0.1;
isRight = true;
}

if (key == 115) {
pos_y = pos_y - 0.1;
isRight = false;
}

if (key == 119) {
pos_y = pos_y + 0.1;
isRight = true;
}
if (key == 113) {
angle += 5;
}
if (key == 101) {
angle -= 5;
}
if (key == 13)
exit(0); // close app

//Логика поведения
if( (pos_x >= 0.15) && (pos_x <= 0.25) &&
    (pos_y >= -0.35) && (pos_y <= -0.25))
{
    isGetFlowers[0] = true;
}
if( (pos_x >= -1.45) && (pos_x <= -1.35) &&
    (pos_y >= -0.35) && (pos_y <= -0.25))
{
    isGetFlowers[1] = true;
}
if( (pos_x >= -1.45) && (pos_x <= -1.35) &&
    (pos_y >= 1.4) && (pos_y <= 1.5))
{
    isGetFlowers[2] = true;
}

glutPostRedisplay(); // отрисовка
}

void drawQuadro(float x,float y){
    glPushMatrix();
    glTranslatef(x,y,0);
    glScalef(.5,.5,1);
    glBegin(GL_QUADS);
    glColor3f(.6,.4,.2);
    glVertex2f(-.1,-.1);
    glVertex2f(-.1,.1);
    glVertex2f(.1,.1);
    glVertex2f(.1,-.1);
    glEnd();
    glPopMatrix();

}

void drawCat(float x, float y, bool isRight, float a) {
    glPushMatrix();
    glTranslatef(.5,-.7,0);
    glTranslatef(x,y,.55);
    glScalef(.35,.35,1);
    glBegin(GL_TRIANGLES);
    glColor3f(-.9,.3,-.7);
    glVertex2f(.1,0);
    glVertex2f(.4 ,.4);
    glVertex2f(  .7,0);

    glColor3f(.1,.2,.3);
    glVertex2f(.4,.4);
    glVertex2f(.2 ,.7);
    glVertex2f(  .6,.7);

    glVertex2f(.55,.15);
    glVertex2f(.7 ,.4);
    glVertex2f(  .9,.3);

    glVertex2f(.2,.7);
    glVertex2f(.3 ,.7);
    glVertex2f(  .25,.8);

    glVertex2f(.5,.7);
    glVertex2f(.6 ,.7);
    glVertex2f(  .55,.8);

    glColor3f(.8,.8,.8);
    glVertex2f(.3,.6);
    glVertex2f(.27 ,.65);
    glVertex2f(  .33,.65);

    glVertex2f(.5,.6);
    glVertex2f(.47,.65);
    glVertex2f(  .53,.65);

    glVertex2f(.35,.5);
    glVertex2f(.4 ,.55);
    glVertex2f(  .45,.5);

    glVertex2f(.28,.2);
    glVertex2f(.35 ,.2);
    glVertex2f(  .31,.1);

    glVertex2f(.45,.2);
    glVertex2f(.52 ,.2);
    glVertex2f(  .48,.1);

    glEnd();
    glPopMatrix();

}

void drawHouse() {
    glPushMatrix();
    glTranslatef(.25,-.4,-.55);
    glScalef(1,1,1);
    glBegin(GL_QUADS);//дом
    glColor3f(.8,.5,.9);
    glVertex2f(-.3,0);
    glVertex2f(-.3,.4);
    glVertex2f(-.8,.4);
    glVertex2f(-.8,.0);

    glColor3f(.1,.9,.4);
    glVertex2f(-.4,.1);
    glVertex2f(-.4,.3);
    glVertex2f(-.6,.3);
    glVertex2f(-.6,.1);

    glColor3f(.8,.2,.1);
    glVertex2f(-.3,.5);
    glVertex2f(-.3,.8);
    glVertex2f(-.4,.8);
    glVertex2f(-.4,.5);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(.8,.8,.8);
    glVertex2f(-.1,.4);
    glVertex2f(-.55 ,.8);
    glVertex2f(  -1,.4);

    glEnd();
    glPopMatrix();
}

void drawCar(float x, float y){
    glPushMatrix();
    glTranslatef(x,y,0);
    glScalef(.4,.4,.4);
    glBegin(GL_QUADS);//машина
    glColor3f(.7,.5,.2);
    glVertex2f(0,-.9);
    glVertex2f(0,-.6);
    glVertex2f(.9,-.6);
    glVertex2f(.9,-.9);

    glColor3f(.4,.3,.2);
    glVertex2f(.1,-1);
    glVertex2f(.1,-.9);
    glVertex2f(.3,-.9);
    glVertex2f(.3,-1);

    glColor3f(.4,.3,.2);
    glVertex2f(.6,-1);
    glVertex2f(.6,-.9);
    glVertex2f(.8,-.9);
    glVertex2f(.8,-1);

    glColor3f(.7,.5,.2);
    glVertex2f(.2,-.6);
    glVertex2f(.2,-.4);
    glVertex2f(.4,-.4);
    glVertex2f(.4,-.6);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(.9,.9,.9);
    glVertex2f(.4,-.6);
    glVertex2f(.4 ,-.4);
    glVertex2f(  .6,-.6);

    glEnd();
    glPopMatrix();

}
void drawShip(){
    glPushMatrix();
    glTranslatef(-.1,-.3,.2);
    glScalef(.35,.35,.35);
    glBegin(GL_TRIANGLES);//яхта
    glColor3f(.9,.9,.9);
    glVertex2f(-.6,-.9);
    glVertex2f(-.9,-.8);
    glVertex2f(-.3,-.8);

    glColor3f(.9,.9,.9);
    glVertex2f(-.75,-.8);
    glVertex2f(-.7,-.5);
    glVertex2f(-.65,-.8);

    glColor3f(.9,.9,.9);
    glVertex2f(-.7,-.75);
    glVertex2f(-.7,-.5);
    glVertex2f(-.55,-.6);

    glEnd();
    glPopMatrix();
}
void drawDog(float x,float y) {

    glPushMatrix();
    glTranslatef(-.3,-.3,0);
    glTranslatef(x,y,0);
    glScalef(.25,.25,.25);
    glBegin(GL_QUADS);//собака
    glColor3f(.4,.6,.8);
    glVertex2f(.3,-.7);
    glVertex2f(.3,-.5);
    glVertex2f(.8,-.5);
    glVertex2f(.8,-.7);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(.4,.6,.8);
    glVertex2f(.3,-.5);
    glVertex2f(.1,-.2);
    glVertex2f(.4,-.5);

    glVertex2f(.8,-.6);
    glVertex2f(.8,-.3);
    glVertex2f(1,-.6);

    glVertex2f(.3,-.7);
    glVertex2f(.3,-.9);
    glVertex2f(.4,-.7);

    glVertex2f(.6,-.7);
    glVertex2f(.7,-.7);
    glVertex2f(.7,-.9);

    glEnd();
    glPopMatrix();
}
    void drawGp() {
    glBegin(GL_LINES);
    glVertex2f(0,100000);
    glVertex2f(0,-100000);
    glVertex2f(100000,0);
    glVertex2f(-100000,0);
    glEnd();

    glScalef(.5,.5,0);
    glBegin(GL_LINE_STRIP);
   // for(float i=0;i<100;i+=0.1){
   //     glVertex2f(i,sqrt(15+4/i)+13*i+sin(3*i+13));
   // }
    float x = -100.0;
    while(x<100){
        glVertex2f(x,fun(x));
        x +=0.01;
    }
    glEnd();

}


void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна здесь жить


    drawCat(pos_x, pos_y, isRight, angle);
    if(!isGetFlowers[0])
       drawQuadro(.8,-.9);
    if(!isGetFlowers[1])
       drawQuadro(-.8,-.9);
    if(!isGetFlowers[2])
       drawQuadro(-.8,.9);
    if(isGetFlowers[0] && isGetFlowers[1] && isGetFlowers[2])
        drawQuadro(0,0);

    glutSwapBuffers();
}

