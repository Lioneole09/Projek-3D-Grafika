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
    glBegin(GL_QUADS); //+8 biru
    glColor3ub(106, 121, 247);
    glVertex3f(-10.0, -4.0, 10.0);
    glVertex3f(-10.0, -5.0, 10.0);
    glVertex3f(10.0, -5.0, 10.0);
    glVertex3f(10.0, -4.0, 10.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8 biru
    glColor3ub(106, 121, 247);
    glVertex3f(-10.0, -4.0, -10.0);
    glVertex3f(-10.0, -5.0, -10.0);
    glVertex3f(10.0, -5.0, -10.0);
    glVertex3f(10.0, -4.0, -10.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8 biru
    glColor3ub(106, 121, 247);
    glVertex3f(10.0, -4.0, 10.0);
    glVertex3f(10.0, -5.0, 10.0);
    glVertex3f(10.0, -5.0, -10.0);
    glVertex3f(10.0, -4.0, -10.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(106, 121, 247);
    glVertex3f(-10.0, -4.0, 10.0);
    glVertex3f(-10.0, -5.0, 10.0);
    glVertex3f(-10.0, -5.0, -10.0);
    glVertex3f(-10.0, -4.0, -10.0);
    glEnd();
    //atas 
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(-10.0, -4.0, -9.0);
    glVertex3f(-10.0, -4.0, 10.0);
    glVertex3f(9.0, -4.0, 10.0);
    glVertex3f(9.0, -4.0, -9.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(-10.0, -5.0, -10.0);
    glVertex3f(-10.0, -5.0, 10.0);
    glVertex3f(10.0, -5.0, 10.0);
    glVertex3f(10.0, -5.0, -10.0);
    glEnd();
    
//tembok belakang
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(-10.0, 4.0, -9.0);
    glVertex3f(-10.0, -4.0, -9.0);
    glVertex3f(9.0, -4.0, -9.0);
    glVertex3f(9.0, 4.0, -9.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(-10.0, 4.0, -10.0);
    glVertex3f(-10.0, -4.0, -10.0);
    glVertex3f(10.0, -4.0, -10.0);
    glVertex3f(10.0, 4.0, -10.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(-10.0, 4.0, -10.0);
    glVertex3f(-10.0, 4.0, -9.0);
    glVertex3f(10.0, 4.0, -9.0);
    glVertex3f(10.0, 4.0, -10.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(-10.0, -4.0, -10.0);
    glVertex3f(-10.0, -4.0, -9.0);
    glVertex3f(10.0, -4.0, -9.0);
    glVertex3f(10.0, -4.0, -10.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(-10.0, 4.0, -9.0);
    glVertex3f(-10.0, -4.0, -9.0);
    glVertex3f(-10.0, -4.0, -10.0);
    glVertex3f(-10.0, 4.0, -10.0);
    glEnd();

//tembok kanan
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(9.0, 4.0, 10.0);
    glVertex3f(9.0, -4.0, 10.0);
    glVertex3f(10.0, -4.0, 10.0);
    glVertex3f(10.0, 4.0, 10.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(9.0, 4.0, -9.0);
    glVertex3f(9.0, 4.0, 10.0);
    glVertex3f(10.0, 4.0, 10.0);
    glVertex3f(10.0, 4.0, -9.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS); //+8
    glColor3ub(117, 117, 117);
    glVertex3f(9.0, -4.0, -9.0);
    glVertex3f(9.0, -4.0, 10.0);
    glVertex3f(10.0, -4.0, 10.0);
    glVertex3f(10.0, -4.0, -9.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(10.0, 4.0, 10.0);
    glVertex3f(10.0, -4.0, 10.0);
    glVertex3f(10.0, -4.0, -10.0);
    glVertex3f(10.0, 4.0, -10.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(143, 143, 143);
    glVertex3f(9.0, 4.0, 10.0);
    glVertex3f(9.0, -4.0, 10.0);
    glVertex3f(9.0, -4.0, -9.0);
    glVertex3f(9.0, 4.0, -9.0);
    glEnd();
    
//meja
    //batang 1
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -8.8);
    glVertex3f(5.1, -4.0, -8.8);
    glVertex3f(5.5, -4.0, -8.8);
    glVertex3f(5.5, 0.0, -8.8);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -8.4);
    glVertex3f(5.1, -4.0, -8.4);
    glVertex3f(5.5, -4.0, -8.4);
    glVertex3f(5.5, 0.0, -8.4);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.5, 0.0, -8.4);
    glVertex3f(5.5, -4.0, -8.4);
    glVertex3f(5.5, -4.0, -8.8);
    glVertex3f(5.5, 0.0, -8.8);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -8.4);
    glVertex3f(5.1, -4.0, -8.4);
    glVertex3f(5.1, -4.0, -8.8);
    glVertex3f(5.1, 0.0, -8.8);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -8.8);
    glVertex3f(5.1, 0.0, -8.4);
    glVertex3f(5.5, 0.0, -8.4);
    glVertex3f(5.5, 0.0, -8.8);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, -4.0, -8.8);
    glVertex3f(5.1, -4.0, -8.4);
    glVertex3f(5.5, -4.0, -8.4);
    glVertex3f(5.5, -4.0, -8.8);
    glEnd();
    //batang 2
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -8.8);
    glVertex3f(-2.1, -4.0, -8.8);
    glVertex3f(-2.5, -4.0, -8.8);
    glVertex3f(-2.5, 0.0, -8.8);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -8.4);
    glVertex3f(-2.1, -4.0, -8.4);
    glVertex3f(-2.5, -4.0, -8.4);
    glVertex3f(-2.5, 0.0, -8.4);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.5, 0.0, -8.4);
    glVertex3f(-2.5, -4.0, -8.4);
    glVertex3f(-2.5, -4.0, -8.8);
    glVertex3f(-2.5, 0.0, -8.8);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -8.4);
    glVertex3f(-2.1, -4.0, -8.4);
    glVertex3f(-2.1, -4.0, -8.8);
    glVertex3f(-2.1, 0.0, -8.8);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -8.8);
    glVertex3f(-2.1, 0.0, -8.4);
    glVertex3f(-2.5, 0.0, -8.4);
    glVertex3f(-2.5, 0.0, -8.8);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, -4.0, -8.8);
    glVertex3f(-2.1, -4.0, -8.4);
    glVertex3f(-2.5, -4.0, -8.4);
    glVertex3f(-2.5, -4.0, -8.8);
    glEnd();
    //batang 3
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -6.0);
    glVertex3f(-2.1, -4.0, -6.0);
    glVertex3f(-2.5, -4.0, -6.0);
    glVertex3f(-2.5, 0.0, -6.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -5.6);
    glVertex3f(-2.1, -4.0, -5.6);
    glVertex3f(-2.5, -4.0, -5.6);
    glVertex3f(-2.5, 0.0, -5.6);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.5, 0.0, -5.6);
    glVertex3f(-2.5, -4.0, -5.6);
    glVertex3f(-2.5, -4.0, -6.0);
    glVertex3f(-2.5, 0.0, -6.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -5.6);
    glVertex3f(-2.1, -4.0, -5.6);
    glVertex3f(-2.1, -4.0, -6.0);
    glVertex3f(-2.1, 0.0, -6.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, 0.0, -6.0);
    glVertex3f(-2.1, 0.0, -5.6);
    glVertex3f(-2.5, 0.0, -5.6);
    glVertex3f(-2.5, 0.0, -6.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(-2.1, -4.0, -6.0);
    glVertex3f(-2.1, -4.0, -5.6);
    glVertex3f(-2.5, -4.0, -5.6);
    glVertex3f(-2.5, -4.0, -6.0);
    glEnd();
    //batang 4
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -6.0);
    glVertex3f(5.1, -4.0, -6.0);
    glVertex3f(5.5, -4.0, -6.0);
    glVertex3f(5.5, 0.0, -6.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -5.6);
    glVertex3f(5.1, -4.0, -5.6);
    glVertex3f(5.5, -4.0, -5.6);
    glVertex3f(5.5, 0.0, -5.6);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.5, 0.0, -5.6);
    glVertex3f(5.5, -4.0, -5.6);
    glVertex3f(5.5, -4.0, -6.0);
    glVertex3f(5.5, 0.0, -6.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -5.6);
    glVertex3f(5.1, -4.0, -5.6);
    glVertex3f(5.1, -4.0, -6.0);
    glVertex3f(5.1, 0.0, -6.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, 0.0, -6.0);
    glVertex3f(5.1, 0.0, -5.6);
    glVertex3f(5.5, 0.0, -5.6);
    glVertex3f(5.5, 0.0, -6.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(5.1, -4.0, -6.0);
    glVertex3f(5.1, -4.0, -5.6);
    glVertex3f(5.5, -4.0, -5.6);
    glVertex3f(5.5, -4.0, -6.0);
    glEnd();
    //papan meja
    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(-2.7, 0.3, -5.6);
    glVertex3f(-2.7, 0.0, -5.6);
    glVertex3f(5.7, 0.0, -5.6);
    glVertex3f(5.7, 0.3, -5.6);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(-2.7, 0.3, -9.0);
    glVertex3f(-2.7, 0.0, -9.0);
    glVertex3f(5.7, 0.0, -9.0);
    glVertex3f(5.7, 0.3, -9.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(5.7, 0.3, -5.4);
    glVertex3f(5.7, 0.0, -5.4);
    glVertex3f(5.7, 0.0, -9.0);
    glVertex3f(5.7, 0.3, -9.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(-2.7, 0.3, -5.4);
    glVertex3f(-2.7, 0.0, -5.4);
    glVertex3f(-2.7, 0.0, -9.0);
    glVertex3f(-2.7, 0.3, -9.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(-2.7, 0.3, -9.0);
    glVertex3f(-2.7, 0.3, -5.4);
    glVertex3f(5.7, 0.3, -5.4);
    glVertex3f(5.7, 0.3, -9.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(-2.7, 0.0, -9.0);
    glVertex3f(-2.7, 0.0, -5.4);
    glVertex3f(5.7, 0.0, -5.4);
    glVertex3f(5.7, 0.0, -9.0);
    glEnd();

//leptop
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 0.4, -6.5);
    glVertex3f(0.5, 0.3, -6.5);
    glVertex3f(2.5, 0.3, -6.5);
    glVertex3f(2.5, 0.4, -6.5);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 0.4, -8.1);
    glVertex3f(0.5, 0.3, -8.1);
    glVertex3f(2.5, 0.3, -8.1);
    glVertex3f(2.5, 0.4, -8.1);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.5, 0.4, -6.5);
    glVertex3f(2.5, 0.3, -6.5);
    glVertex3f(2.5, 0.3, -8.1);
    glVertex3f(2.5, 0.4, -8.1);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 0.4, -6.5);
    glVertex3f(0.5, 0.3, -6.5);
    glVertex3f(0.5, 0.3, -8.1);
    glVertex3f(0.5, 0.4, -8.1);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 0.4, -8.1);
    glVertex3f(0.5, 0.4, -6.5);
    glVertex3f(2.5, 0.4, -6.5);
    glVertex3f(2.5, 0.4, -8.1);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 0.3, -8.1);
    glVertex3f(0.5, 0.3, -6.5);
    glVertex3f(2.5, 0.3, -6.5);
    glVertex3f(2.5, 0.3, -8.1);
    glEnd();
    //layar
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 1.8, -8.4);
    glVertex3f(0.5, 0.4, -8.1);
    glVertex3f(2.5, 0.4, -8.1);
    glVertex3f(2.5, 1.8, -8.4);
    glEnd();
    //depan kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.4, 1.8, -8.3);
    glVertex3f(2.4, 0.4, -8.0);
    glVertex3f(2.5, 0.4, -8.0);
    glVertex3f(2.5, 1.8, -8.3);
    glEnd();
    //depan kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 1.8, -8.3);
    glVertex3f(0.5, 0.4, -8.0);
    glVertex3f(0.6, 0.4, -8.0);
    glVertex3f(0.6, 1.8, -8.3);
    glEnd();
    //monitor
    glBegin(GL_QUADS);
    glColor3ub(106, 121, 247);
    glVertex3f(0.5, 1.8, -8.3);
    glVertex3f(0.5, 0.4, -8.0);
    glVertex3f(2.5, 0.4, -8.0);
    glVertex3f(2.5, 1.8, -8.3);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 1.8, -8.4);
    glVertex3f(0.5, 1.8, -8.3);
    glVertex3f(2.5, 1.8, -8.3);
    glVertex3f(2.5, 1.8, -8.4);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 0.4, -8.1);
    glVertex3f(0.5, 0.4, -8.0);
    glVertex3f(2.5, 0.4, -8.0);
    glVertex3f(2.5, 0.4, -8.1);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.5, 1.8, -8.3);
    glVertex3f(2.5, 0.4, -8.0);
    glVertex3f(2.5, 0.4, -8.1);
    glVertex3f(2.5, 1.8, -8.4);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.5, 1.8, -8.3);
    glVertex3f(0.5, 0.4, -8.0);
    glVertex3f(0.5, 0.4, -8.1);
    glVertex3f(0.5, 1.8, -8.4);
    glEnd();

//buku
//depan
    glBegin(GL_QUADS);
    glColor3ub(92, 92, 92);
    glVertex3f(3.0, 0.4, -6.6);
    glVertex3f(3.0, 0.3, -6.6);
    glVertex3f(4.5, 0.3, -6.6);
    glVertex3f(4.5, 0.4, -6.6);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(3.0, 0.4, -7.6);
    glVertex3f(3.0, 0.3, -7.6);
    glVertex3f(4.5, 0.3, -7.6);
    glVertex3f(4.5, 0.4, -7.6);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(92, 92, 92);
    glVertex3f(4.5, 0.4, -6.4);
    glVertex3f(4.5, 0.3, -6.4);
    glVertex3f(4.5, 0.3, -7.6);
    glVertex3f(4.5, 0.4, -7.6);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(92, 92, 92);
    glVertex3f(3.0, 0.4, -6.4);
    glVertex3f(3.0, 0.3, -6.4);
    glVertex3f(3.0, 0.3, -7.6);
    glVertex3f(3.0, 0.4, -7.6);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(3.0, 0.4, -7.6);
    glVertex3f(3.0, 0.4, -6.5);
    glVertex3f(4.5, 0.4, -6.5);
    glVertex3f(4.5, 0.4, -7.6);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(3.0, 0.3, -7.6);
    glVertex3f(3.0, 0.3, -6.5);
    glVertex3f(4.5, 0.3, -6.5);
    glVertex3f(4.5, 0.3, -7.6);
    glEnd();

//kursi
    //batang 1
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -6.5);
    glVertex3f(2.3, -4.0, -6.5);
    glVertex3f(2.6, -4.0, -6.5);
    glVertex3f(2.6, -1.7, -6.5);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -6.2);
    glVertex3f(2.3, -4.0, -6.2);
    glVertex3f(2.6, -4.0, -6.2);
    glVertex3f(2.6, -1.7, -6.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.6, -1.7, -6.2);
    glVertex3f(2.6, -4.0, -6.2);
    glVertex3f(2.6, -4.0, -6.5);
    glVertex3f(2.6, -1.7, -6.5);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -6.2);
    glVertex3f(2.3, -4.0, -6.2);
    glVertex3f(2.3, -4.0, -6.5);
    glVertex3f(2.3, -1.7, -6.5);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -6.5);
    glVertex3f(2.3, -1.7, -6.2);
    glVertex3f(2.6, -1.7, -6.2);
    glVertex3f(2.6, -1.7, -6.5);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -4.0, -6.5);
    glVertex3f(2.3, -4.0, -6.2);
    glVertex3f(2.6, -4.0, -6.2);
    glVertex3f(2.6, -4.0, -6.5);
    glEnd();
    //batang 2
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -6.5);
    glVertex3f(0.3, -4.0, -6.5);
    glVertex3f(0.6, -4.0, -6.5);
    glVertex3f(0.6, -1.7, -6.5);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -6.2);
    glVertex3f(0.3, -4.0, -6.2);
    glVertex3f(0.6, -4.0, -6.2);
    glVertex3f(0.6, -1.7, -6.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.6, -1.7, -6.2);
    glVertex3f(0.6, -4.0, -6.2);
    glVertex3f(0.6, -4.0, -6.5);
    glVertex3f(0.6, -1.7, -6.5);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -6.2);
    glVertex3f(0.3, -4.0, -6.2);
    glVertex3f(0.3, -4.0, -6.5);
    glVertex3f(0.3, -1.7, -6.5);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -6.5);
    glVertex3f(0.3, -1.7, -6.2);
    glVertex3f(0.6, -1.7, -6.2);
    glVertex3f(0.6, -1.7, -6.5);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -4.0, -6.5);
    glVertex3f(0.3, -4.0, -6.2);
    glVertex3f(0.6, -4.0, -6.2);
    glVertex3f(0.6, -4.0, -6.5);
    glEnd();
    //batang 3
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -4.5);
    glVertex3f(0.3, -4.0, -4.5);
    glVertex3f(0.6, -4.0, -4.5);
    glVertex3f(0.6, -1.7, -4.5);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -4.2);
    glVertex3f(0.3, -4.0, -4.2);
    glVertex3f(0.6, -4.0, -4.2);
    glVertex3f(0.6, -1.7, -4.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.6, -1.7, -4.2);
    glVertex3f(0.6, -4.0, -4.2);
    glVertex3f(0.6, -4.0, -4.5);
    glVertex3f(0.6, -1.7, -4.5);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -4.2);
    glVertex3f(0.3, -4.0, -4.2);
    glVertex3f(0.3, -4.0, -4.5);
    glVertex3f(0.3, -1.7, -4.5);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -1.7, -4.5);
    glVertex3f(0.3, -1.7, -4.2);
    glVertex3f(0.6, -1.7, -4.2);
    glVertex3f(0.6, -1.7, -4.5);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.3, -4.0, -4.5);
    glVertex3f(0.3, -4.0, -4.2);
    glVertex3f(0.6, -4.0, -4.2);
    glVertex3f(0.6, -4.0, -4.5);
    glEnd();
    //batang 4
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -4.5);
    glVertex3f(2.3, -4.0, -4.5);
    glVertex3f(2.6, -4.0, -4.5);
    glVertex3f(2.6, -1.7, -4.5);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -4.2);
    glVertex3f(2.3, -4.0, -4.2);
    glVertex3f(2.6, -4.0, -4.2);
    glVertex3f(2.6, -1.7, -4.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.6, -1.7, -4.2);
    glVertex3f(2.6, -4.0, -4.2);
    glVertex3f(2.6, -4.0, -4.5);
    glVertex3f(2.6, -1.7, -4.5);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -4.2);
    glVertex3f(2.3, -4.0, -4.2);
    glVertex3f(2.3, -4.0, -4.5);
    glVertex3f(2.3, -1.7, -4.5);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -1.7, -4.5);
    glVertex3f(2.3, -1.7, -4.2);
    glVertex3f(2.6, -1.7, -4.2);
    glVertex3f(2.6, -1.7, -4.5);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(2.3, -4.0, -4.5);
    glVertex3f(2.3, -4.0, -4.2);
    glVertex3f(2.6, -4.0, -4.2);
    glVertex3f(2.6, -4.0, -4.5);
    glEnd();
    //papan kursi
    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(0.2, -1.5, -4.1);
    glVertex3f(0.2, -1.7, -4.1);
    glVertex3f(2.7, -1.7, -4.1);
    glVertex3f(2.7, -1.5, -4.1);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(0.2, -1.5, -6.6);
    glVertex3f(0.2, -1.7, -6.6);
    glVertex3f(2.7, -1.7, -6.6);
    glVertex3f(2.7, -1.5, -6.6);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(2.7, -1.7, -4.1);
    glVertex3f(2.7, -1.5, -4.1);
    glVertex3f(2.7, -1.5, -6.6);
    glVertex3f(2.7, -1.7, -6.6);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(0.2, -1.5, -4.1);
    glVertex3f(0.2, -1.7, -4.1);
    glVertex3f(0.2, -1.7, -6.6);
    glVertex3f(0.2, -1.5, -6.6);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(0.2, -1.5, -6.6);
    glVertex3f(0.2, -1.5, -4.1);
    glVertex3f(2.7, -1.5, -4.1);
    glVertex3f(2.7, -1.5, -6.6);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(0.2, -1.7, -6.6);
    glVertex3f(0.2, -1.7, -4.1);
    glVertex3f(2.7, -1.7, -4.1);
    glVertex3f(2.7, -1.7, -6.6);
    glEnd();
    //sandaran
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.2, 1.0, -3.8);
    glVertex3f(0.2, -1.5, -4.1);
    glVertex3f(2.7, -1.5, -4.1);
    glVertex3f(2.7, 1.0, -3.8);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48, 52, 59);
    glVertex3f(0.2, 1.0, -4.0);
    glVertex3f(0.2, -1.5, -4.3);
    glVertex3f(2.7, -1.5, -4.3);
    glVertex3f(2.7, 1.0, -4.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(0.2, 1.0, -4.0);
    glVertex3f(0.2, -1.5, -4.3);
    glVertex3f(0.2, -1.5, -4.1);
    glVertex3f(0.2, 1.0, -3.8);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(2.7, 1.0, -4.0);
    glVertex3f(2.7, -1.5, -4.3);
    glVertex3f(2.7, -1.5, -4.1);
    glVertex3f(2.7, 1.0, -3.8);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(0.2, 1.0, -4.0);
    glVertex3f(0.2, 1.0, -3.8);
    glVertex3f(2.7, 1.0, -3.8);
    glVertex3f(2.7, 1.0, -4.0);
    glEnd();

//papan hias 1
    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.2, -9.0);
    glVertex3f(7.0, 0.1, -9.0);
    glVertex3f(9.0, 0.1, -7.0);
    glVertex3f(9.0, 0.2, -7.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.2, -9.0);
    glVertex3f(7.0, 0.1, -9.0);
    glVertex3f(9.0, 0.1, -9.0);
    glVertex3f(9.0, 0.2, -9.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(9.0, 0.2, -7.0);
    glVertex3f(9.0, 0.1, -7.0);
    glVertex3f(9.0, 0.1, -9.0);
    glVertex3f(9.0, 0.2, -9.0);
    glEnd();
    //atas
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.2, -9.0);
    glVertex3f(9.0, 0.2, -7.0);
    glVertex3f(9.0, 0.2, -9.0);
    glEnd();
    //bawah
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.1, -9.0);
    glVertex3f(9.0, 0.1, -7.0);
    glVertex3f(9.0, 0.1, -9.0);
    glEnd();

//papan hias 2
    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 3.1, -9.0);
    glVertex3f(7.0, 3.0, -9.0);
    glVertex3f(9.0, 3.0, -7.0);
    glVertex3f(9.0, 3.1, -7.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 3.1, -9.0);
    glVertex3f(7.0, 3.0, -9.0);
    glVertex3f(9.0, 3.0, -9.0);
    glVertex3f(9.0, 3.1, -9.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(9.0, 3.1, -7.0);
    glVertex3f(9.0, 3.0, -7.0);
    glVertex3f(9.0, 3.0, -9.0);
    glVertex3f(9.0, 3.1, -9.0);
    glEnd();
    //atas
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 3.1, -9.0);
    glVertex3f(9.0, 3.1, -7.0);
    glVertex3f(9.0, 3.1, -9.0);
    glEnd();
    //bawah
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 3.0, -9.0);
    glVertex3f(9.0, 3.0, -7.0);
    glVertex3f(9.0, 3.0, -9.0);
    glEnd();

//papan rias 
    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.3, 2.0);
    glVertex3f(7.0, 0.0, 2.0);
    glVertex3f(9.0, 0.0, 2.0);
    glVertex3f(9.0, 0.3, 2.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.3, -1.0);
    glVertex3f(7.0, 0.0, -1.0);
    glVertex3f(9.0, 0.0, -1.0);
    glVertex3f(9.0, 0.3, -1.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(9.0, 0.3, 2.0);
    glVertex3f(9.0, 0.0, 2.0);
    glVertex3f(9.0, 0.0, -1.0);
    glVertex3f(9.0, 0.3, -1.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.3, 2.0);
    glVertex3f(7.0, 0.0, 2.0);
    glVertex3f(7.0, 0.0, -1.0);
    glVertex3f(7.0, 0.3, -1.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.3, -1.0);
    glVertex3f(7.0, 0.3, 2.0);
    glVertex3f(9.0, 0.3, 2.0);
    glVertex3f(9.0, 0.3, -1.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3ub(255, 240, 150);
    glVertex3f(7.0, 0.0, -1.0);
    glVertex3f(7.0, 0.0, 2.0);
    glVertex3f(9.0, 0.0, 2.0);
    glVertex3f(9.0, 0.0, -1.0);
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
 case 'w':
 case 'W':
 glTranslated(0.0, 0.0, -1.0);//geser maju
 break;
 case 'a':
 case 'A':
 glTranslated(-1.0, 0.0, 0.0);//geser kiri
 break;
 case 's':
 case 'S':
 glTranslated(0.0, 0.0, 1.0);//geser mundur
 break;
 case 'd':
 case 'D':
 glTranslated(1.0, 0.0, 0.0);//geser kanan
 break;
 case 'q':
 case 'Q':
 glTranslated(0.0, 1.0, 0.0); // geser atas
 break;
 case 'e':
 case 'E':
 glTranslated(0.0, -1.0, 0.0); // geser bawah
 break;
 case 'i':
 case 'I':
 glRotatef(2.0, 1.0, 0.0, 0.0);//rotate kanan
 break;
 case 'k':
 case 'K':
 glRotatef(2.0, -1.0, 0.0, 0.0);//rotate kanan
 break;
 case 'j':
 case 'J':
  glRotatef(2.0, 0.0, 1.0, 0.0);//rotate atas
 break;
 case 'l':
 case 'L':
  glRotatef(2.0, 0.0, -1.0, 0.0);//rotate atas
 break;
}
display(); //memanggil fungsi display atau bisa pakai glutPostRedisplay();
}
