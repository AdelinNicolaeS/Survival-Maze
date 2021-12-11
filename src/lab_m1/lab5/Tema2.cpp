#include "lab_m1/lab5/Tema2.h"

#include <vector>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <lab_m1/lab3/transform2D.h>
#include <lab_m1/lab3/object2D.h>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
    
}


Tema2::~Tema2()
{
}

glm::vec2 Tema2::GetPlayerPosition() {
    return glm::vec2(startMazeX + 3 * 7, startMazeZ + 3 * 2);
}

void Tema2::LoadMazes() {
    ifstream fin("Labirint.txt");
    fin >> mazeNumber;
    fin.close();
    ofstream fout("Labirint.txt");
    fout << (mazeNumber + 1) % maze_Creator.numberOfMazes;
    fout.close();
    srand(time(NULL));
    switch (mazeNumber)
    {
    case 0:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze0[i][j];
            }
        }
        index = rand() % maze_Creator.pairs0.size();
        playerX = startMazeX + 3 * maze_Creator.pairs0.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs0.at(index).second;
        
        pickup1.X = startMazeX + 3 * maze_Creator.pairs0.at((index + 1) % maze_Creator.pairs0.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs0.at((index + 1) % maze_Creator.pairs0.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs0.at((index + 2) % maze_Creator.pairs0.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs0.at((index + 2) % maze_Creator.pairs0.size()).second;
        pickup2.radius = 0.3;

        break;
    case 1:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze1[i][j];
            }
        }
        index = rand() % maze_Creator.pairs1.size();
        playerX = startMazeX + 3 * maze_Creator.pairs1.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs1.at(index).second;

        pickup1.X = startMazeX + 3 * maze_Creator.pairs1.at((index + 1) % maze_Creator.pairs1.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs1.at((index + 1) % maze_Creator.pairs1.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs1.at((index + 2) % maze_Creator.pairs1.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs1.at((index + 2) % maze_Creator.pairs1.size()).second;
        pickup2.radius = 0.3;

        break;
    case 2:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze2[i][j];
            }
        }
        index = rand() % maze_Creator.pairs2.size();
        playerX = startMazeX + 3 * maze_Creator.pairs2.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs2.at(index).second;

        pickup1.X = startMazeX + 3 * maze_Creator.pairs2.at((index + 1) % maze_Creator.pairs2.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs2.at((index + 1) % maze_Creator.pairs2.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs2.at((index + 2) % maze_Creator.pairs2.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs2.at((index + 2) % maze_Creator.pairs2.size()).second;
        pickup2.radius = 0.3;
        break;
    case 3:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze3[i][j];
            }
        }
        index = rand() % maze_Creator.pairs3.size();
        playerX = startMazeX + 3 * maze_Creator.pairs3.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs3.at(index).second;

        pickup1.X = startMazeX + 3 * maze_Creator.pairs3.at((index + 1) % maze_Creator.pairs3.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs3.at((index + 1) % maze_Creator.pairs3.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs3.at((index + 2) % maze_Creator.pairs3.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs3.at((index + 2) % maze_Creator.pairs3.size()).second;
        pickup2.radius = 0.3;

        break;
    default:
        break;
    }
    srand(time(NULL));
}

void Tema2::ReinitMaze() {
    mazeNumber = (mazeNumber + 1) % maze_Creator.numberOfMazes;
    srand(time(NULL));
    switch (mazeNumber)
    {
    case 0:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze0[i][j];
            }
        }
        index = rand() % maze_Creator.pairs0.size();
        playerX = startMazeX + 3 * maze_Creator.pairs0.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs0.at(index).second;

        pickup1.X = startMazeX + 3 * maze_Creator.pairs0.at((index + 1) % maze_Creator.pairs0.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs0.at((index + 1) % maze_Creator.pairs0.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs0.at((index + 2) % maze_Creator.pairs0.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs0.at((index + 2) % maze_Creator.pairs0.size()).second;
        pickup2.radius = 0.3;

        break;
    case 1:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze1[i][j];
            }
        }
        index = rand() % maze_Creator.pairs1.size();
        playerX = startMazeX + 3 * maze_Creator.pairs1.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs1.at(index).second;

        pickup1.X = startMazeX + 3 * maze_Creator.pairs1.at((index + 1) % maze_Creator.pairs1.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs1.at((index + 1) % maze_Creator.pairs1.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs1.at((index + 2) % maze_Creator.pairs1.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs1.at((index + 2) % maze_Creator.pairs1.size()).second;
        pickup2.radius = 0.3;

        break;
    case 2:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze2[i][j];
            }
        }
        index = rand() % maze_Creator.pairs2.size();
        playerX = startMazeX + 3 * maze_Creator.pairs2.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs2.at(index).second;

        pickup1.X = startMazeX + 3 * maze_Creator.pairs2.at((index + 1) % maze_Creator.pairs2.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs2.at((index + 1) % maze_Creator.pairs2.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs2.at((index + 2) % maze_Creator.pairs2.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs2.at((index + 2) % maze_Creator.pairs2.size()).second;
        pickup2.radius = 0.3;
        break;
    case 3:
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 13; j++) {
                maze_matrix[i][j] = maze_Creator.maze3[i][j];
            }
        }
        index = rand() % maze_Creator.pairs3.size();
        playerX = startMazeX + 3 * maze_Creator.pairs3.at(index).first;
        playerZ = startMazeZ + 3 * maze_Creator.pairs3.at(index).second;

        pickup1.X = startMazeX + 3 * maze_Creator.pairs3.at((index + 1) % maze_Creator.pairs3.size()).first;
        pickup1.Y = 0.75;
        pickup1.Z = startMazeZ + 3 * maze_Creator.pairs3.at((index + 1) % maze_Creator.pairs3.size()).second;
        pickup1.radius = 0.3;

        pickup2.X = startMazeX + 3 * maze_Creator.pairs3.at((index + 2) % maze_Creator.pairs3.size()).first;
        pickup2.Y = 0.75;
        pickup2.Z = startMazeZ + 3 * maze_Creator.pairs3.at((index + 2) % maze_Creator.pairs3.size()).second;
        pickup2.radius = 0.3;

        break;
    default:
        break;
    }
    srand(time(NULL));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    camera = new implemented::Camera();
    camera->Set(glm::vec3(playerX, 1.1, playerZ - camera->distanceToTarget), glm::vec3(playerX, 1, 0), glm::vec3(0, 1, 0)); // 1.1 = centrul capului
    enemies.clear();
    obstacles.clear();
    bullets.clear();
    for (int i = 0; i < lines_maze; i++) {
        for (int j = 0; j < columns_maze; j++) {
            if (maze_matrix[i][j] == 2) {
                Enemy enemy;
                enemy.centerX = startMazeX + 3 * i;
                enemy.centerY = 0.75; // centrul body-ului
                enemy.centerZ = startMazeZ + 3 * j;
                enemy.speed = 3.f;
                enemy.radius = 0.75f;
                enemies.push_back(enemy);
            }
            else if (maze_matrix[i][j] == 1) {
                Obstacle obstacle;
                obstacle.radius = 3;
                obstacle.X = startMazeX + obstacle.radius * i;
                obstacle.Y = obstacle.radius / 2;
                obstacle.Z = startMazeZ + obstacle.radius * j;
                obstacles.push_back(obstacle);
            }
        }
    }
}

void Tema2::Init()
{
    LoadMazes();

    {
        maze.minX = startMazeX - 1;
        maze.maxX = startMazeX + 3 * (lines_maze - 1) + 1;
        maze.minZ = startMazeZ - 1;
        maze.maxZ = startMazeZ + 3 * (columns_maze - 1) + 1;
    }
    numberOfLives = initialNumberOfLives;
    start = high_resolution_clock::now();
    start_regenerate = high_resolution_clock::now();
   
    camera = new implemented::Camera();
    camera->Set(glm::vec3(playerX , 1.1, playerZ - camera->distanceToTarget), glm::vec3(playerX, 1, 0), glm::vec3(0, 1, 0)); // 1.1 = centrul capului
    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* square_full = object2D::CreateSquare("square_full", glm::vec3(0, 0, 0), 0.5 , glm::vec3(1, 0, 0), true);
        AddMeshToList(square_full);
    }
    {
        Mesh* square = object2D::CreateSquare("square", glm::vec3(0, 0, 0), 0.5, glm::vec3(1, 0, 0));
        AddMeshToList(square);
    }
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
    right = 5;
    left = -5;
    bottom = -5;
    top = 5;
    zNear = 0.1f;
    zFar = 200.0f;
    fov = 60;
    aspect = window->props.aspectRatio;

    for (int i = 0; i < lines_maze; i++) {
        for (int j = 0; j < columns_maze; j++) {
            if (maze_matrix[i][j] == 2) {
                Enemy enemy;
                enemy.centerX = startMazeX + 3 * i;
                enemy.centerY = 0.75; // centrul body-ului
                enemy.centerZ = startMazeZ + 3 * j;
                enemy.speed = 3.f;
                enemy.radius = 0.75f;
                enemies.push_back(enemy);
            }
            else if (maze_matrix[i][j] == 1) {
                Obstacle obstacle;
                obstacle.radius = 3;
                obstacle.X = startMazeX + obstacle.radius * i;
                obstacle.Y = obstacle.radius / 2;
                obstacle.Z = startMazeZ + obstacle.radius * j;
                obstacles.push_back(obstacle);
            }
        }
    }

    {
        Shader* shader = new Shader("Enemy3LivesMoving");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "FragmentShader3Lives.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
    {
        Shader* shader = new Shader("Enemy2LivesMoving");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "FragmentShader2Lives.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
    {
        Shader* shader = new Shader("Enemy1LifeMoving");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "FragmentShader1Life.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
    {
        Shader* shader = new Shader("Enemy3Lives");
        shader->AddShader(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::SHADERS, "MVP.Texture.VS.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "FragmentShader3Lives.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
    {
        Shader* shader = new Shader("Enemy2Lives");
        shader->AddShader(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::SHADERS, "MVP.Texture.VS.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "FragmentShader2Lives.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
    {
        Shader* shader = new Shader("Enemy1Life");
        shader->AddShader(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::SHADERS, "MVP.Texture.VS.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "FragmentShader1Life.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
    
}


void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    glUseProgram(shader->program);

    GLint modelLocation = glGetUniformLocation(shader->program, "Model");

    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    GLint viewLocation = glGetUniformLocation(shader->program, "View");

    glm::mat4 viewMatrix = camera->GetViewMatrix();
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    GLint projectionLocation = glGetUniformLocation(shader->GetProgramID(), "Projection");

    glm::mat4 projectionMatrix2 = projectionMatrix;
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix2));

    GLint timeLocation = glGetUniformLocation(shader->GetProgramID(), "Time");
    glUniform1f(timeLocation, (GLfloat)Engine::GetElapsedTime());

    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}

void Tema2::CalculatePlayerCoordinates() {
    if (third_person) {
        playerX = camera->GetTargetPosition().x;
        playerZ = camera->GetTargetPosition().z;
    }
    else {
        camera->TranslateForward(-camera->distanceToTarget);
        playerX = camera->GetTargetPosition().x;
        playerZ = camera->GetTargetPosition().z;
        camera->TranslateForward(camera->distanceToTarget);
    }
}

void Tema2::RenderPlayer(float x, float y, float z) {
    // left foot
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));

    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.75, 0));
    modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(0, 1, 0));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.75, 0));
    
    modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.05 * 2, 0.25, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05, 0.5, 0.05));
    RenderMesh(meshes["box"], shaders["Green"], modelMatrix);

    // right foot
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));

    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.75, 0));
    modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(0, 1, 0));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.75, 0));
    
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.05 * 2, 0.25, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05, 0.5, 0.05));
    RenderMesh(meshes["box"], shaders["Green"], modelMatrix);

    // body
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.75, 0));
    modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(0, 1, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4, 0.5, 0.3));
    RenderMesh(meshes["box"], shaders["Violet"], modelMatrix);

    // head
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.1 + 0.5 + 0.5, 0));
    modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(0, 1, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2, 0.2, 0.2));
    RenderMesh(meshes["box"], shaders["Pink"], modelMatrix);

    // right arm
    modelMatrix = glm::mat4(1);
    
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
    
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.75, 0));
    modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(0, 1, 0));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.75, 0));

    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.25, 0.5 + 0.5 - 0.3 / 2, 0));

    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1, 0.3, 0.1));
    RenderMesh(meshes["box"], shaders["Green"], modelMatrix);

    // left arm
    modelMatrix = glm::mat4(1);

    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));

    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, -0.75, 0));
    modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(0, 1, 0));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.75, 0));

    modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.25, 0.5 + 0.5 - 0.3 / 2, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1, 0.3, 0.1));
    RenderMesh(meshes["box"], shaders["Green"], modelMatrix);
}

bool Tema2::BulletWallCollision(Bullet bullet, glm::vec3 wall) {
    auto x = max(wall.x - 1.5f, min(bullet.X, wall.x + 1.5f));
    auto y = max(wall.y - 1.5f, min(bullet.Y, wall.y + 1.5f));
    auto z = max(wall.z - 1.5f, min(bullet.Z, wall.z + 1.5f));
    
    auto distance = sqrt((x - bullet.X) * (x - bullet.X) +
        (y - bullet.Y) * (y - bullet.Y) +
        (z - bullet.Z) * (z - bullet.Z));
    return distance < bullet.radius;
}

bool Tema2::BulletAllWallsCollision(Bullet bullet) {
    for (int i = 0; i < lines_maze; i++) {
        for (int j = 0; j < columns_maze; j++) {
            if (maze_matrix[i][j] != 1) {
                continue;
            }
            auto wall = glm::vec3(startMazeX + 3 * i, 0, startMazeZ + j * 3);
            if (BulletWallCollision(bullet, wall)) {
                return true;
            }
        }
    }
    return false;
}

bool Tema2::PlayerEnemyCollision(Enemy enemy) {
    // reducem la sfera vs sfera
    // inamicul e deja sfera, are propria raza
    // pentru jucator vom alege raza ca fiind jumatate din grosimea sa
    // adica presupunem ca jucatorul merge drept inainte sau usor in unghi ;)
    // eventual adaug un offset pentru o mica rotire 
    float offset = 0;
    float player_radius = 0.6 / 2.f + offset;
    auto distance = sqrt((playerX - enemy.currentX) * (playerX - enemy.currentX) +
        (playerY - enemy.currentY) * (playerY - enemy.currentY) +
        (playerZ - enemy.currentZ) * (playerZ - enemy.currentZ));
    return distance < (player_radius + enemy.radius);
}

bool Tema2::EnemyBulletCollision(Enemy enemy, Bullet bullet) {
    auto distance = sqrt((enemy.currentX - bullet.X) * (enemy.currentX - bullet.X) /*+ (enemy.currentY - bullet.Y) * (enemy.currentY - bullet.Y)*/
        + (enemy.currentZ - bullet.Z) * (enemy.currentZ - bullet.Z));
    return distance + 0.1f < (enemy.radius + bullet.radius);
}

void Tema2::EnemiesBulletsCollisions() {
    for (auto &enemy : enemies) {
        for (auto& bullet : bullets) {
            if (!enemy.isDead && !bullet.isDead && EnemyBulletCollision(enemy, bullet)) {
                bullet.isDead = true;

                enemy.isDead = true;
                enemy.isKilledByBullet = true;
                enemy.shootedTime = high_resolution_clock::now();
            }
        }
    }
}

bool Tema2::PointObstacleCollision(float X, float Z, Obstacle obstacle) {
    auto minX = obstacle.X - obstacle.radius / 2;
    auto maxX = obstacle.X + obstacle.radius / 2;

    auto minZ = obstacle.Z - obstacle.radius / 2;
    auto maxZ = obstacle.Z + obstacle.radius / 2;

    return (X >= minX && X <= maxX) && (Z >= minZ && Z <= maxZ);
}

bool Tema2::PlayerObstaclesCollision(float X, float Z) {
    float OX_length = 0.6;
    float OZ_length = 0.3;
    float radius = sqrt(OX_length * OX_length + OZ_length * OZ_length) / 2;
    float aux_angle = atan(OZ_length / OX_length);

    float trX_angle = X + radius * cos(angle + aux_angle);
    float trZ_angle = Z + radius * sin(angle + aux_angle);

    float tlX_angle = X + radius * cos(angle + (M_PI - aux_angle));
    float tlZ_angle = Z + radius * sin(angle + (M_PI - aux_angle));

    float blX_angle = X + radius * cos(angle + (M_PI + aux_angle));
    float blZ_angle = Z + radius * sin(angle + (M_PI + aux_angle));

    float brX_angle = X + radius * cos(angle - aux_angle);
    float brZ_angle = Z + radius * sin(angle - aux_angle);

    for(auto obstacle : obstacles) {
        bool collision = PointObstacleCollision(trX_angle, trZ_angle, obstacle) || PointObstacleCollision(tlX_angle, tlZ_angle, obstacle)
            || PointObstacleCollision(blX_angle, blZ_angle, obstacle) || PointObstacleCollision(brX_angle, brZ_angle, obstacle);
        if (collision) {
            return true;
        }
    }
    return false;
}

bool Tema2::PlayerInsideMaze() {
    return (playerX >= maze.minX && playerX <= maze.maxX) && (playerZ >= maze.minZ && playerZ <= maze.maxZ);
}

void Tema2::RenderBar() {
    projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);

    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<milliseconds>(stop - start)).count();
    float time_left = (float) (60 * 1000 - duration);
    float percent = time_left / 60000.f;
    if (percent < 0) {
        cout << "Game Over!\n";
        exit(0);
    }
    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-2.3, 2);
    modelMatrix *= transform2D::Scale(1, 0.4);
    RenderMesh2D(meshes["square"], modelMatrix, glm::vec3(1, 0, 0));

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(-2.3, 2);
    modelMatrix *= transform2D::Scale(percent, 0.4);
    RenderMesh2D(meshes["square_full"], modelMatrix, glm::vec3(1, 0, 0));
    
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1.8, 2.01);
    modelMatrix *= transform2D::Scale(1, 0.4);
    RenderMesh2D(meshes["square"], modelMatrix, glm::vec3(0, 1, 0));

    percent = (float) numberOfLives / 3;
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1.8, 2.01);
    modelMatrix *= transform2D::Scale(percent, 0.4);
    RenderMesh2D(meshes["square_full"], modelMatrix, glm::vec3(0, 1, 0));

    projectionMatrix = glm::perspective(RADIANS(fov), aspect, zNear, zFar);
    
}

bool Tema2::PlayerPickUpCollision(TimePickUp pickup) {
    float offset = 0;
    float player_radius = 0.6 / 2.f + offset;
    auto distance = sqrt((playerX - pickup.X) * (playerX - pickup.X) +
        (playerY - pickup.Y) * (playerY - pickup.Y) +
        (playerZ - pickup.Z) * (playerZ - pickup.Z));
    return distance < (player_radius + pickup.radius);
}

void Tema2::RenderPickUps() {
    glm::mat4 modelMatrix = glm::mat4(1);

    if (!pickup1.isDead) {
        modelMatrix = glm::translate(modelMatrix, glm::vec3(pickup1.X, pickup1.Y, pickup1.Z));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(pickup1.radius));
        RenderMesh(meshes["sphere"], shaders["Pink"], modelMatrix);
    }
    if (!pickup2.isDead) {
        modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(pickup2.X, pickup2.Y, pickup2.Z));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(pickup2.radius));
        RenderMesh(meshes["sphere"], shaders["Pink"], modelMatrix);
    }
}

void Tema2::Update(float deltaTimeSeconds)
{
    auto stop_regenerate = high_resolution_clock::now();
    auto duration = (duration_cast<milliseconds>(stop_regenerate - start_regenerate)).count();
    if (duration > 30 * 1000) {
        ReinitMaze();
        start_regenerate = high_resolution_clock::now();
    }
    if (!PlayerInsideMaze()) {
        _sleep(1000);
        cout << "Jucatorul a castigat!\n";
        exit(0);
    }
    if (numberOfLives <= 0) {
        cout << "Game Over!\n";
        exit(0);
    }
    angle = atan2(camera->forward.x, camera->forward.z);
    camera->forward.y = 0;
    camera->position.y = 1.5;
    
    RenderBar();
    
    if (third_person) {
        CalculatePlayerCoordinates();
    }
    if (third_person) {
        RenderPlayer(playerX, 0, playerZ);
    }
    if (!pickup1.isDead) {
        auto x = PlayerPickUpCollision(pickup1);
        if (x) {
            start = high_resolution_clock::now();
            pickup1.isDead = true;
        }
    }
    if (!pickup2.isDead) {
        auto x = PlayerPickUpCollision(pickup2);
        if (x) {
            start = high_resolution_clock::now();
            pickup2.isDead = true;
        }
    }
    RenderPickUps();
    for (int i = 0; i < lines_maze; i++) {
        for (int j = 0; j < columns_maze; j++) {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(startMazeX + i * 3, 0, startMazeZ + j * 3));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(3, 0, 3));
            RenderMesh(meshes["box"], shaders["Simple"], modelMatrix);
        }
    }
    for (auto obstacle : obstacles) {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(obstacle.X, 0.75, obstacle.Z));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(3, 1.5, 3));
        RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);
    }
    EnemiesBulletsCollisions();
    for (auto &bullet : bullets) {
        if (bullet.isDead) {
            continue;
        }
        auto stop = high_resolution_clock::now();
        auto duration = (duration_cast<seconds>(stop - bullet.start)).count();
        if (duration > bullet.duration) {
            bullet.isDead = true;
            continue;
        }
        bullet.isDead = BulletAllWallsCollision(bullet);
        if (bullet.isDead) {
            continue;
        }
        bullet.X += bullet.speed * deltaTimeSeconds * cos(-bullet.angle + M_PI_2);
        bullet.Z += bullet.speed * deltaTimeSeconds * sin(-bullet.angle + M_PI_2);
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(bullet.X, bullet.Y, bullet.Z));
        modelMatrix = glm::scale(modelMatrix , glm::vec3(bullet.radius));
        RenderMesh(meshes["sphere"], shaders["VertexColor"], modelMatrix);
    }
    for (auto& enemy : enemies) {
        if (enemy.isDead && enemy.isKilledByBullet) {
            auto stop = high_resolution_clock::now();
            auto duration = (duration_cast<milliseconds>(stop - enemy.shootedTime)).count();
            if (duration < 1000) { // o las 1 secunda 

                if (numberOfLives == 3) {
                    RenderSimpleMesh(meshes["sphere"], shaders["Enemy3LivesMoving"], enemy.modelMatrix);
                }
                else if (numberOfLives == 2) {
                    RenderSimpleMesh(meshes["sphere"], shaders["Enemy2LivesMoving"], enemy.modelMatrix);
                }
                else {
                    RenderSimpleMesh(meshes["sphere"], shaders["Enemy1LifeMoving"], enemy.modelMatrix);
                }
            }
            continue;
        }
        else if (enemy.isDead) {
            continue;
        }
        if (PlayerEnemyCollision(enemy)) {
            enemy.isDead = true;
            numberOfLives--;
            continue;
        }
        enemy.angle += enemy.speed * deltaTimeSeconds;
        glm::mat4 modelMatrix = glm::mat4(1);

        enemy.currentX = enemy.centerX + 0.5 * cos(enemy.angle);
        enemy.currentY = enemy.centerY;
        enemy.currentZ = enemy.centerZ + 0.5 * sin(enemy.angle);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(enemy.currentX, enemy.currentY, enemy.currentZ));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(enemy.radius));
        enemy.modelMatrix = modelMatrix;
        if (numberOfLives == 3) {
            RenderMesh(meshes["sphere"], shaders["Enemy3Lives"], enemy.modelMatrix);
        }
        else if (numberOfLives == 2) {
            RenderMesh(meshes["sphere"], shaders["Enemy2Lives"], enemy.modelMatrix);
        }
        else {
            RenderMesh(meshes["sphere"], shaders["Enemy1Life"], enemy.modelMatrix);
        }
    }
}


void Tema2::FrameEnd()
{
    DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
}


void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    // move the camera only if MOUSE_RIGHT button is pressed
    if (third_person && window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
    {
        float cameraSpeed = 2.0f * 2;

        if (window->KeyHold(GLFW_KEY_W)) {
            float copy_X = playerX, copy_Z = playerZ, copy_angle = angle;
            camera->TranslateForward(cameraSpeed * deltaTime);
            angle = atan2(camera->forward.x, camera->forward.z);
            CalculatePlayerCoordinates();
            if (PlayerObstaclesCollision(playerX, playerZ)) {
                playerX = copy_X;
                playerZ = copy_Z;
                angle = copy_angle;
                camera->TranslateForward(-cameraSpeed * deltaTime);
            }
        }
        
        if (window->KeyHold(GLFW_KEY_A)) {
            float copy_X = playerX, copy_Z = playerZ, copy_angle = angle;
            camera->TranslateRight(-cameraSpeed * deltaTime);
            angle = atan2(camera->forward.x, camera->forward.z);
            CalculatePlayerCoordinates();
            if (PlayerObstaclesCollision(playerX, playerZ)) {
                playerX = copy_X;
                playerZ = copy_Z;
                angle = copy_angle;
                camera->TranslateRight(cameraSpeed * deltaTime);
            }
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            float copy_X = playerX, copy_Z = playerZ, copy_angle = angle;
            camera->TranslateForward(-cameraSpeed * deltaTime);
            angle = atan2(camera->forward.x, camera->forward.z);
            CalculatePlayerCoordinates();
            if (PlayerObstaclesCollision(playerX, playerZ)) {
                playerX = copy_X;
                playerZ = copy_Z;
                angle = copy_angle;
                camera->TranslateForward(cameraSpeed * deltaTime);
            }
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            float copy_X = playerX, copy_Z = playerZ, copy_angle = angle;
            camera->TranslateRight(cameraSpeed * deltaTime);
            angle = atan2(camera->forward.x, camera->forward.z);
            CalculatePlayerCoordinates();
            if (PlayerObstaclesCollision(playerX, playerZ)) {
                playerX = copy_X;
                playerZ = copy_Z;
                angle = copy_angle;
                camera->TranslateRight(-cameraSpeed * deltaTime);
            }
        }
    }    
}


void Tema2::OnKeyPress(int key, int mods)
{
    if (key == GLFW_KEY_LEFT_CONTROL) {
        if (third_person) {
            camera->TranslateForward(camera->distanceToTarget);
        }
        else {
            camera->TranslateForward(-camera->distanceToTarget);
        }
        third_person = !third_person;
    }
    if (!third_person && key == GLFW_KEY_SPACE) {
        Bullet bullet;
        bullet.X = playerX;
        bullet.Y = 0.75;
        bullet.Z = playerZ;
        bullet.start = high_resolution_clock::now();
        bullet.speed = 10;
        bullet.angle = angle;
        bullet.duration = 5; // in seconds
        bullet.radius = 0.15f;
        bullets.push_back(bullet);
    }
}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
    {
        float sensivityOX = 0.0015f;
        float sensivityOY = 0.0015f;
        if (third_person) {
            float copy_X = playerX, copy_Z = playerZ, copy_angle = angle;
            camera->RotateThirdPerson_OX(-sensivityOX * deltaY);
            camera->RotateThirdPerson_OY(-sensivityOY * deltaX);
            angle = atan2(camera->forward.x, camera->forward.z);
            CalculatePlayerCoordinates();
            if (PlayerObstaclesCollision(playerX, playerZ)) {
                playerX = copy_X;
                playerZ = copy_Z;
                angle = copy_angle;

                camera->RotateThirdPerson_OX(sensivityOX * deltaY);
                camera->RotateThirdPerson_OY(sensivityOY * deltaX);
            }
        }
        else {
            float copy_X = playerX, copy_Z = playerZ, copy_angle = angle;
            camera->RotateFirstPerson_OX(-sensivityOX * deltaY);
            camera->RotateFirstPerson_OY(-sensivityOY * deltaX);
            angle = atan2(camera->forward.x, camera->forward.z);
            CalculatePlayerCoordinates();
            if (PlayerObstaclesCollision(playerX, playerZ)) {
                playerX = copy_X;
                playerZ = copy_Z;
                angle = copy_angle;
                camera->RotateFirstPerson_OX(sensivityOX * deltaY);
                camera->RotateFirstPerson_OY(sensivityOY * deltaX);
            }
        }
        //if (window->GetSpecialKeyState() == 0) {
        //    renderCameraTarget = false;
        //    // TODO(student): Rotate the camera in first-person mode around
        //    // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
        //    // variables for setting up the rotation speed.
        //    camera->RotateThirdPerson_OX(-sensivityOX * deltaY);
        //    camera->RotateThirdPerson_OY(-sensivityOY * deltaX);
        //}
    }
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
   
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
