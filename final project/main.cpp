///week12-5_TRT_keyboard_mouse 要用 keyboard mouse 來操控
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL; ///step02-2 一開始,檔案沒有開, NULL
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL; ///step02-2 要讀檔用的指標, 一開始也是 NULL
int show[4]={1,1,1,1};
int ID=2;///0:頭 1:身體 2:上手臂 3:下手臂
void keyboard(unsigned char key,int x,int y){
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;

    ///if(key=='0') show[0] = !show[0];
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0, teapotY=0; ///幫我們看移動值
float angle=0, angle2=0, angle3=0;///step03-2 擺動作
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);
        if(body==NULL){
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");
            uparmR = glmReadOBJ("model/uparmR.obj");
            lowarmR = glmReadOBJ("model/lowarmR.obj");
        }
        if(ID==0) glColor3f(1,0,0);///選定設紅色
        else glColor3f(1,1,1);///沒選定設白色
        if(show[0]) glmDraw(head, GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);///選定設紅色
        else glColor3f(1,1,1);///沒選定設白色
        if(show[1]) glmDraw(body, GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(-1.200000, +0.460000, 0);
            glRotatef(angle,0,0,1);
            glTranslatef(1.200000, -0.460000, 0);

            if(ID==2) glColor3f(1,0,0);///選定設紅色
            else glColor3f(1,1,1);///沒選定設白色
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);

            glPushMatrix();
                glTranslatef(-1.933332, 0.093333, 0);
                glRotatef(angle,0,0,1);
                glTranslatef(1.933332, -0.093333, 0);
                if(ID==3) glColor3f(1,0,0);///選定設紅色
                else glColor3f(1,1,1);///沒選定設白色
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();
    ///glTranslatef(teapotX, teapotY, 0);
        ///glTranslatef(????); ///step03-2 擺動作
        ///glRotatef(angle, 0, 0, 1);///step03-2 擺動作
        ///glTranslatef(0.400000, -0.060000, 0);///step03-2
        ///glTranslatef(teapotX, teapotY, 0);///step03-2 擺動作
        ///glutSolidTeapot( 0.3 );
}
int oldX=0,oldY=0;
void motion(int x,int y){
    teapotX+=(x-oldX)/150.0;
    teapotY-=(y-oldY)/150.0;
    oldX=x;
    oldY=y;
    angle=x;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
        angle = x;
        ///teapotX = (x-150)/150.0;
        ///teapotY = (150-y)/150.0;
        ///if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 沒開檔,就開
        ///fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 要再存座標
    }
    display();
}
///void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard函式
///{
   /// if(fin==NULL){ ///step02-2 如果檔案還沒 fopen(), 就開它
      ///  fclose(fout); ///前面mouse會開fout指標, 所以要關掉
        ///fin = fopen("file4.txt", "r"); ///step02-2 沒開檔,就開
 ///   }
    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 真的讀檔
    ///display(); ///step02-2 重畫畫面
///}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard要做事囉(開檔、讀檔)

    glutMainLoop();
}
