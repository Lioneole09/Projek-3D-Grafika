//Projek 3D Objek Grafika Komputer
// Anggota Tim :
// 1. Abdul Katsir (2101020044)
// 2. Cici (2101020043)

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>

GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture5;
GLuint texture6;
GLuint texture7;
GLuint texture8;
GLuint texture9;

float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 60.0f;
float cameraYaw = 0.0f, cameraPitch = 0.0f;
int lastMouseX, lastMouseY;
bool firstMouse = true;

float objTranslateX = 0.0f, objTranslateY = 0.0f, objTranslateZ = 0.0f;
float objRotateX = 0.0f, objRotateY = 0.0f, objRotateZ = 0.0f;

GLuint loadBMP(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Image could not be opened\n");
        return 0;
    }

    unsigned char header[54];
    if (fread(header, 1, 54, file) != 54) {
        printf("Not a correct BMP file\n");
        fclose(file);
        return 0;
    }

    unsigned int dataPos = *(int*)&(header[0x0A]);
    unsigned int imageSize = *(int*)&(header[0x22]);
    unsigned int width = *(int*)&(header[0x12]);
    unsigned int height = *(int*)&(header[0x16]);

    if (imageSize == 0) imageSize = width * height * 3;
    if (dataPos == 0) dataPos = 54;

    unsigned char* data = new unsigned char[imageSize];
    fread(data, 1, imageSize, file);
    fclose(file);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    delete[] data;

    return textureID;
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    texture1 = loadBMP("textures/buku.bmp");
    texture2 = loadBMP("textures/busa.bmp");
    texture3 = loadBMP("textures/case.bmp");
    texture4 = loadBMP("textures/dinding.bmp");
    texture5 = loadBMP("textures/karpet.bmp");
    texture6 = loadBMP("textures/kayu.bmp");
    texture7 = loadBMP("textures/lantai.bmp");
    texture8 = loadBMP("textures/lukisan.bmp");
    texture9 = loadBMP("textures/lukisan2.bmp");
}

void drawTexture(float size, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4) {
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x1 * size, y1 * size, z1 * size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x2 * size, y2 * size, z2 * size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x3 * size, y3 * size, z3 * size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x4 * size, y4 * size, z4 * size);
    glEnd();
}

void drawCube(float width, float height, float depth) {
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    float halfDepth = depth / 2.0f;

    drawTexture(1.0f, -halfWidth, -halfHeight, halfDepth, halfWidth, -halfHeight, halfDepth, halfWidth, halfHeight, halfDepth, -halfWidth, halfHeight, halfDepth);
    drawTexture(1.0f, -halfWidth, -halfHeight, -halfDepth, halfWidth, -halfHeight, -halfDepth, halfWidth, halfHeight, -halfDepth, -halfWidth, halfHeight, -halfDepth);
    drawTexture(1.0f, -halfWidth, halfHeight, -halfDepth, halfWidth, halfHeight, -halfDepth, halfWidth, halfHeight, halfDepth, -halfWidth, halfHeight, halfDepth);
    drawTexture(1.0f, -halfWidth, -halfHeight, -halfDepth, halfWidth, -halfHeight, -halfDepth, halfWidth, -halfHeight, halfDepth, -halfWidth, -halfHeight, halfDepth);
    drawTexture(1.0f, halfWidth, -halfHeight, -halfDepth, halfWidth, halfHeight, -halfDepth, halfWidth, halfHeight, halfDepth, halfWidth, -halfHeight, halfDepth);
    drawTexture(1.0f, -halfWidth, -halfHeight, -halfDepth, -halfWidth, halfHeight, -halfDepth, -halfWidth, halfHeight, halfDepth, -halfWidth, -halfHeight, halfDepth);
}

void drawCircle(float radius, int numSegments, float z) {
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, 0.0f, z);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * M_PI * float(i) / float(numSegments);
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glTexCoord2f(cosf(angle) * 0.5f + 0.5f, sinf(angle) * 0.5f + 0.5f);
        glVertex3f(x, y, z);
    }
    glEnd();
}

void drawTable() {
    // Meja
    glBindTexture(GL_TEXTURE_2D, texture6);
    glPushMatrix();
    glTranslatef(1.5f, 0.15f, -7.2f);
    drawCube(8.4f, 0.3f, 3.6f);
    glPopMatrix();

    // Kaki meja
    float legPositions[4][3] = {
        {5.3f, -2.0f, -8.6f},
        {-2.3f, -2.0f, -8.6f},
        {5.3f, -2.0f, -5.8f},
        {-2.3f, -2.0f, -5.8f}
    };

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(legPositions[i][0], legPositions[i][1], legPositions[i][2]);
        drawCube(0.4f, 4.0f, 0.4f);
        glPopMatrix();
    }
}

void drawLaptop() {
    // papan laptop
    glBindTexture(GL_TEXTURE_2D, texture3);
    glPushMatrix();
    glTranslatef(1.5f, 0.35f, -7.3f);
    drawCube(2.0f, 0.1f, 1.4f);
    glPopMatrix();

    // layar laptop
    glBindTexture(GL_TEXTURE_2D, texture1);
    glPushMatrix();
    glTranslatef(1.5f, 1.1f, -8.0f);
    glRotatef(-5.0f, 1.0f, 0.0f, 0.0f);
    drawCube(2.0f, 1.4f, 0.1f);
    glPopMatrix();
}

void drawChair() {
    // Kursi  
    // Kaki kursi
    float legPositions[4][3] = {
        {2.40f, -2.8f, -5.75f},
        {0.50f, -2.8f, -5.75f},
        {0.50f, -2.8f, -4.0f},
        {2.40f, -2.8f, -4.0f}
    };

    for (int i = 0; i < 4; i++) {
        glBindTexture(GL_TEXTURE_2D, texture6);
        glPushMatrix();
        glTranslatef(legPositions[i][0], legPositions[i][1], legPositions[i][2]);
        drawCube(0.3f, 2.4f, 0.3f);
        glPopMatrix();
    }

    // dudukan kursi
    glBindTexture(GL_TEXTURE_2D, texture2);
    glPushMatrix();
    glTranslatef(1.45f, -1.45f, -4.85f);
    drawCube(2.3f, 0.3f, 2.2f);
    glPopMatrix();
    
    // Sandaran kursi
    glBindTexture(GL_TEXTURE_2D, texture2);
    glPushMatrix();
    glTranslatef(1.45f, -0.1f, -3.75f);
    glRotatef(5.0f, 1.0f, 0.0f, 0.0f);
    drawCube(2.3f, 2.6f, 0.2f);
    glPopMatrix();
}

void drawBuilding() {
    // Lantai
    glBindTexture(GL_TEXTURE_2D, texture7);
    glPushMatrix();
    glTranslatef(0.0f, -4.5f, 0.0f);
    drawCube(21.0f, 1.0f, 21.0f);
    glPopMatrix();

    // Tembok belakang
    glBindTexture(GL_TEXTURE_2D, texture4);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    drawCube(21.0f, 8.0f, 1.0f);
    glPopMatrix();

    // Tembok kanan
    glBindTexture(GL_TEXTURE_2D, texture4);
    glPushMatrix();
    glTranslatef(10.0f, 0.0f, 0.0f);
    drawCube(1.0f, 8.0f, 21.0f);
    glPopMatrix();
}

void drawAcces() {
    // buku
    glBindTexture(GL_TEXTURE_2D, texture1);
    glPushMatrix();
    glTranslatef(-1.0f, 0.35f, -7.3f);
    glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
    glScalef(-1.0f, 1.0f, 1.0f);
    drawCube(1.0f, 0.1f, 1.3f);
    glPopMatrix();

    // lukisan pertama
    glBindTexture(GL_TEXTURE_2D, texture8);
    glPushMatrix();
    glTranslatef(9.4f, 2.0f, -1.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.5f, -1.5f, 1.0f);
    drawCube(0.1f, 2.0f, 3.0f);
    glPopMatrix();

    // lukisan kedua
    glBindTexture(GL_TEXTURE_2D, texture9);
    glPushMatrix();
    glTranslatef(9.4f, 2.0f, 4.5f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.5f, -1.5f, 1.0f);
    drawCube(0.1f, 2.0f, 3.0f);
    glPopMatrix();

    // Karpet
    glBindTexture(GL_TEXTURE_2D, texture5);
    glPushMatrix();
    glTranslatef(-2.0f, -3.99f, 1.5f);
    glRotatef(90.0f, 1.0f, .0f, 0.0f);
    drawCircle(4.0f, 50, 0.0f); 
    glPopMatrix();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, cameraY, cameraZ,
              cameraX + sinf(cameraYaw * M_PI / 180.0f), 
              cameraY + sinf(cameraPitch * M_PI / 180.0f),
              cameraZ - cosf(cameraYaw * M_PI / 180.0f),
              0.0f, 1.0f, 0.0f);

    glTranslatef(objTranslateX, objTranslateY, objTranslateZ);
    glRotatef(objRotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(objRotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(objRotateZ, 0.0f, 0.0f, 1.0f);

    drawBuilding();
    drawAcces();
    drawTable();
    drawLaptop();
    drawChair();

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    float cameraSpeed = 0.5f;
    switch (key) {
        case 'w': case 'W':
            cameraX += cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
            cameraZ -= cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
            break;
        case 'a': case 'A':
            cameraX -= cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
            cameraZ -= cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
            break;
        case 's': case 'S':
            cameraX -= cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
            cameraZ += cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
            break;
        case 'd': case 'D':
            cameraX += cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
            cameraZ += cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
            break;
        case 'q': case 'Q':
            objTranslateY += 1.0f;
            break;
        case 'e': case 'E':
            objTranslateY -= 1.0f;
            break;
        case 'i': case 'I':
            objRotateX += 2.0f;
            break;
        case 'k': case 'K':
            objRotateX -= 2.0f;
            break;
        case 'j': case 'J':
            objRotateY += 2.0f;
            break;
        case 'l': case 'L':
            objRotateY -= 2.0f;
            break;
    }
    glutPostRedisplay();
}

void mouseMovement(int x, int y) {
    if (firstMouse) {
        lastMouseX = x;
        lastMouseY = y;
        firstMouse = false;
    }

    int deltaX = x - lastMouseX;
    int deltaY = y - lastMouseY;
    lastMouseX = x;
    lastMouseY = y;

    float sensitivity = 0.1f;
    cameraYaw += deltaX * sensitivity;
    cameraPitch += deltaY * sensitivity;

    if (cameraPitch > 89.0f) cameraPitch = 89.0f;
    if (cameraPitch < -89.0f) cameraPitch = -89.0f;

    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Projek 3D Grafika");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mouseMovement);

    glewInit();

    init();
    glutMainLoop();
    return 0;
}
