//header
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
//deklarasi fungsi
void display();
void init();
void reshape(int, int);
void keyboard(unsigned char, int, int); //+1
//main program
int main (int argc, char** argv){
 //inisialisasi
 glutInit(&argc, argv);
 glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); //+2 GLUT_DEPTH : mengalokasikan sumbu z
 glutInitWindowPosition(200, 200); //atur sumbu x dan y
 glutInitWindowSize(500, 500); //atur lebar dan tinggi jendela
 glutCreateWindow("Projek 3D Grafika");
 glutDisplayFunc(display); //memanggil fungsi display
 glutReshapeFunc(reshape); //memanggil fungsi reshape
 glutKeyboardFunc(keyboard); // +3 memanggil fungsi keyboard
 init();
 glutMainLoop(); //menjalankan program utama

}void init(){
 glEnable(GL_DEPTH_TEST); //+4
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
}
void display(){
 //reset
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //+5
 //alas
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(184, 178, 178);
    glVertex3f(-15.0, -5.0, 10.0);
    glVertex3f(-15.0, -6.0, 10.0);
    glVertex3f(15.0, -6.0, 10.0);
    glVertex3f(15.0, -5.0, 10.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(204, 196, 196);
    glVertex3f(-15.0, -5.0, -10.0);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, -5.0, -10.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(204, 196, 196);
    glVertex3f(-15.0, -5.0, -10.0);
    glVertex3f(-15.0, -5.0, 10.0);
    glVertex3f(15.0, -5.0, 10.0);
    glVertex3f(15.0, -5.0, -10.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS); //+8
    glColor3ub(204, 196, 196);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(-15.0, -6.0, 10.0);
    glVertex3f(15.0, -6.0, 10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(204, 196, 196);
    glVertex3f(15.0, -5.0, 10.0);
    glVertex3f(15.0, -6.0, 10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, -5.0, -10.0);
    glEnd();

//tembok depan
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(-15.0, 8.0, -10.0);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, 8.0, -10.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, -6.0, -11.0);
    glVertex3f(15.0, -6.0, -11.0);
    glVertex3f(15.0, 8.0, -11.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, 8.0, -10.0);
    glVertex3f(15.0, 8.0, -10.0);
    glVertex3f(15.0, 8.0, -11.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(15.0, 8.0, -10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, -6.0, -11.0);
    glVertex3f(15.0, 8.0, -11.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, -6.0, -11.0);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(-15.0, 8.0, -10.0);
    glEnd();

//tembok kanan
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(15.0, 8.0, -11.0);
    glVertex3f(15.0, -6.0, -11.0);
    glVertex3f(15.0, -6.0, 0.0);
    glVertex3f(15.0, 8.0, 0.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(16.0, 8.0, -11.0);
    glVertex3f(16.0, -6.0, -11.0);
    glVertex3f(16.0, -6.0, 0.0);
    glVertex3f(16.0, 8.0, 0.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(16.0, 8.0, -11.0);
    glVertex3f(15.0, 8.0, -11.0);
    glVertex3f(15.0, 8.0, 0.0);
    glVertex3f(16.0, 8.0, 0.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(15.0, 8.0, -11.0);
    glVertex3f(15.0, -6.0, -11.0);
    glVertex3f(16.0, -6.0, -11.0);
    glVertex3f(16.0, 8.0, -11.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(15.0, 8.0, 0.0);
    glVertex3f(15.0, -6.0, 0.0);
    glVertex3f(16.0, -6.0, 0.0);
    glVertex3f(16.0, 8.0, 0.0);
    glEnd();
    //kanan (kiri)
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(15.0, 8.0, 8.0);
    glVertex3f(15.0, -6.0, 8.0);
    glVertex3f(15.0, -6.0, 10.0);
    glVertex3f(15.0, 8.0, 10.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(16.0, 8.0, 8.0);
    glVertex3f(16.0, -6.0, 8.0);
    glVertex3f(16.0, -6.0, 10.0);
    glVertex3f(16.0, 8.0, 10.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(16.0, 8.0, 8.0);
    glVertex3f(15.0, 8.0, 8.0);
    glVertex3f(15.0, 8.0, 10.0);
    glVertex3f(16.0, 8.0, 10.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(15.0, 8.0, 8.0);
    glVertex3f(15.0, -6.0, 8.0);
    glVertex3f(16.0, -6.0, 8.0);
    glVertex3f(16.0, 8.0, 8.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(15.0, 8.0, 10.0);
    glVertex3f(15.0, -6.0, 10.0);
    glVertex3f(16.0, -6.0, 10.0);
    glVertex3f(16.0, 8.0, 10.0);
    glEnd();

glFlush();
glutSwapBuffers();
}//fungsi untuk setting viewport
void reshape(int w, int h){
 glViewport(0,0, (GLsizei)w, (GLsizei)h); //membuat viewport sesuai ukuran jendela
 glMatrixMode(GL_PROJECTION); //merubah matrix mode menjadi gl_projection
 glLoadIdentity(); //reset transformasi misalnya rotasi pada display
 //gluOrtho2D(-10, 10, -10, 10); //setting spesifikasi proyeksi yang diinginkan (2D)
 //glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); //+6 proyeksi orthografik 3D
 gluPerspective(30.0, w / h, 1.0, 100.0); //proyeksi perspektif
/* set initial position */
glTranslatef(0.0, -5.0, -100.0);
 glMatrixMode(GL_MODELVIEW); //merubah matrix mode menjadi gl_modelview
}
//+7
void keyboard(unsigned char key, int x, int y)
{
/* this is the keyboard event handler
 the x and y parameters are the mouse
 coordinates when the key was struck */
switch (key)
{
case 'a':
 case 'A':
 glTranslated(-1.0, 0.0, 0.0);//geser kiri
 break;
 case 'd':
 case 'D':
 glTranslated(1.0, 0.0, 0.0);//geser kanan
 break;
 case 's':
 case 'S':
 glTranslated(0.0, 1.0, 0.0);//geser atas
 break;
 case 'w':
 case 'W':
 glTranslated(0.0, -1.0, 0.0);//geser bawah
 break;
}
display(); //memanggil fungsi display atau bisa pakai glutPostRedisplay();
}
