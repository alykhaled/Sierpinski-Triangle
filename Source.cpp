#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>    
#include <GL/glut.h>
using namespace std;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0.0, 800, 0.0, 800);
    glPolygonMode(GL_FRONT, GL_LINE);
    vector<pair<int, int>> vertices(3);
    vertices[0] = { 0,0 };      //First  vertex coordinates
    vertices[1] = { 800,0 };    //Second vertex coordinates
    vertices[2] = { 400,800 };  //Third  vertex coordinates

    glBegin(GL_POINTS);
    glVertex2i(vertices[0].first, vertices[0].second); //Draw First  Vertex
    glVertex2i(vertices[1].first, vertices[1].second); //Draw Second Vertex
    glVertex2i(vertices[2].first, vertices[2].second); //Draw Third  Vertex
    glVertex2i((vertices[0].first + vertices[1].first) / 2, (vertices[0].second + vertices[1].second) / 2); //Draw Midpoint between First vertex and second vertex 
    
    pair<int, int> lastPoint = { (vertices[0].first + vertices[1].first) / 2, (vertices[0].second + vertices[1].second) / 2 }; //Store the last point
    for (int i = 0; i < 10000; i++)
    {
        int randomIndex = rand() % 3; //Get random number between 0 and 2
        glVertex2i((vertices[randomIndex].first + lastPoint.first) / 2, (vertices[randomIndex].second + lastPoint.second) / 2); //Draw Midpoint between random vertix and the last point
        lastPoint.first = (vertices[randomIndex].first + lastPoint.first) / 2;      //Store the new last point X
        lastPoint.second = (vertices[randomIndex].second + lastPoint.second) / 2;   //Store the new last point Y
    }
    glEnd();
    glFlush();  
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("The Sierpinski Triangle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}