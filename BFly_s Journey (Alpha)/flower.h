#include <GL/gl.h>
#include <GL/glut.h>
#include <OBJ_Loader.h>
#include <cstdlib>

GLfloat translateFlowerZ = 350;
GLfloat translateFlowerX = 0;
GLfloat laneSelection = (rand() % 3);

void desenhaFlor()
{

    //Transformações da flor
    glScalef(0.32f, 0.32f, 0.32f);

    if (laneSelection == 0)
    {
        translateFlowerX = 10;
    }
    else if (laneSelection == 1)
    {
        translateFlowerX = 0;
    }
    else if (laneSelection == 2)
    {
        translateFlowerX = -10;
    }

    glTranslatef(translateFlowerX, 1.0f, translateFlowerZ);

    glRotatef(-10, 1.0f, 0.0f, 0.0f);

    translateFlowerZ -= 5;

    if (translateFlowerZ == -10)
    {
        translateFlowerZ = 350;
        laneSelection = (rand() % 3);
    }

    objl::Loader loader;

    loader.LoadFile("Assets/miolo.obj");

    objl::Mesh curMesh = loader.LoadedMeshes[0];

    glBegin(GL_TRIANGLES);
    for (int j = 0; j < curMesh.Indices.size(); j += 3)
    {

        glColor3f(curMesh.MeshMaterial.Kd.X, curMesh.MeshMaterial.Kd.Y, curMesh.MeshMaterial.Kd.Z);
        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.Y);
        //glNormal3f(curMesh.Vertices[curMesh.Indices[j]].Normal.X, curMesh.Vertices[curMesh.Indices[j]].Normal.Y, curMesh.Vertices[curMesh.Indices[j]].Normal.Z);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j]].Position.X, curMesh.Vertices[curMesh.Indices[j]].Position.Y, curMesh.Vertices[curMesh.Indices[j]].Position.Z);

        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.Y);
        //glNormal3f(curMesh.Vertices[curMesh.Indices[j + 1]].Normal.X, curMesh.Vertices[curMesh.Indices[j + 1]].Normal.Y, curMesh.Vertices[curMesh.Indices[j + 1]].Normal.Z);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 1]].Position.X, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Z);

        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.Y);
        //glNormal3f(curMesh.Vertices[curMesh.Indices[j + 2]].Normal.X, curMesh.Vertices[curMesh.Indices[j + 2]].Normal.Y, curMesh.Vertices[curMesh.Indices[j + 2]].Normal.Z);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 2]].Position.X, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Z);
    }
    glEnd();

    loader.LoadFile("Assets/petalas.obj");

    curMesh = loader.LoadedMeshes[0];

    glBegin(GL_TRIANGLES);
    for (int j = 0; j < curMesh.Indices.size(); j += 3)
    {

        glColor3f(curMesh.MeshMaterial.Kd.X, curMesh.MeshMaterial.Kd.Y, curMesh.MeshMaterial.Kd.Z);
        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.Y);
        //glNormal3f(curMesh.Vertices[curMesh.Indices[j]].Normal.X, curMesh.Vertices[curMesh.Indices[j]].Normal.Y, curMesh.Vertices[curMesh.Indices[j]].Normal.Z);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j]].Position.X, curMesh.Vertices[curMesh.Indices[j]].Position.Y, curMesh.Vertices[curMesh.Indices[j]].Position.Z);

        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.Y);
        //glNormal3f(curMesh.Vertices[curMesh.Indices[j + 1]].Normal.X, curMesh.Vertices[curMesh.Indices[j + 1]].Normal.Y, curMesh.Vertices[curMesh.Indices[j + 1]].Normal.Z);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 1]].Position.X, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Z);

        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.Y);
        //glNormal3f(curMesh.Vertices[curMesh.Indices[j + 2]].Normal.X, curMesh.Vertices[curMesh.Indices[j + 2]].Normal.Y, curMesh.Vertices[curMesh.Indices[j + 2]].Normal.Z);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 2]].Position.X, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Z);
    }
    glEnd();
}