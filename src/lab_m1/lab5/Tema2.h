#pragma once

#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"
#include <chrono>
#include <vector>
#include <iostream>
#include <lab_m1/lab5/Maze_Creator.cpp>

using namespace std::chrono;
using namespace std;

namespace m1
{
    struct Maze {
        float minX, maxX, minZ, maxZ;
       // std::vector<std::vector<int>> maze_matrix;
       // vector<pair<int, int>> possibleStart;
   };

    struct Bullet {
        float X, Y, Z;
        float speed;
        steady_clock::time_point start;
        float angle;
        int duration;
        bool isDead = false;
        float radius;
    };
    
    struct Enemy {
        float centerX, centerY, centerZ;
        float currentX, currentY, currentZ;
        float angle = 0;
        float speed;
        float radius;
        glm::mat4 modelMatrix;
        steady_clock::time_point shootedTime;
        bool isDead = false;
        bool isKilledByBullet = false;
    };
    struct Obstacle {
        float X, Y, Z;
        float radius;
    };

    struct TimePickUp {
        float X, Y, Z;
        float radius;
        bool isDead = false;
    };

    class Tema2 : public gfxc::SimpleScene
    {
    public:
        Tema2();
        ~Tema2();

        void Init() override;

    private:
        glm::vec2 GetPlayerPosition();
        void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix);
        void CalculatePlayerCoordinates();
        void RenderPlayer(float x, float y, float z);
        bool PlayerInsideMaze();
        bool BulletWallCollision(Bullet bullet, glm::vec3 wall);

        void LoadMazes();

        void ReinitMaze();

        bool BulletAllWallsCollision(Bullet bullet);

        bool PlayerEnemyCollision(Enemy enemy);

        bool EnemyBulletCollision(Enemy enemy, Bullet bullet);

        void EnemiesBulletsCollisions();

        bool PointObstacleCollision(float X, float Z, Obstacle obstacle);

        bool PlayerObstaclesCollision(float X, float Z);

        void RenderBar();

        bool PlayerPickUpCollision(TimePickUp pickup);

        void RenderPickUps();

        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix) override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        

        implemented::Camera* camera;
        glm::mat4 projectionMatrix;

        float left;
        float right;
        float bottom;
        float top;
        float zNear;
        float zFar;
        float fov;
        float aspect;
        bool projection;


        bool third_person = true;
        int lines_maze = 9, columns_maze = 13;
        int maze_matrix[9][13] =  { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                    0, 0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0, 1,
                                    1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1,
                                    1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1,
                                    1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1,
                                    1, 0, 0, 0, 0, 2, 1, 0, 0, 1, 0, 0, 1,
                                    1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
                                    1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0,
                                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
        float startMazeX = -10, startMazeZ = -10;
        float playerX, playerZ, playerY = 0.75;
        float angle = 0;
        std::vector<struct Bullet> bullets;
        std::vector<struct Enemy> enemies;
        std::vector<struct Obstacle> obstacles;
        steady_clock::time_point start;
        int numberOfLives;
        int initialNumberOfLives = 3;
        Maze_Creator maze_Creator;
        struct Maze maze;
        int mazeNumber;
        int index;

        struct TimePickUp pickup1, pickup2;

        steady_clock::time_point start_regenerate;
    };
}   // namespace m1
