#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "Mesh.h"


void loadObject(std::string path) {
    std::ifstream objFileStream(path, std::ifstream::in);

    if (!objFileStream) return;
   
    if (objFileStream.is_open()) {
        // Tokenizer data
        const int MAX_LINE_SIZE = 256;
        char line[MAX_LINE_SIZE];
        const char* delim = " ";
        char* nextToken;

        // Line Data
        std::string lineTypeStrings[] = {"g", "s", "usemtl", "mtllib", "#", "v", "vt", "vn", "f"};
        enum LineType {OTHER, GROUP, S, USEMATERIAL, MATERIALLIB, COMMENT, VERTEX, TEXTURE, NORMAL, FACE};
        std::unordered_map<std::string, LineType> lineTypeMap;

        for (int i = 0; i < 9; i++) {
            lineTypeMap.emplace(lineTypeStrings[i], LineType(i + 1));
        }
        LineType currentLineType = OTHER;

        // Binary data
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec2> textureCoords;
        std::vector<glm::vec3> normals;
        std::vector<glm::vec3> faces;

        // Parse loop
        while (objFileStream.getline(line, MAX_LINE_SIZE)) {
            // Get the line data type
            char* dataTypeToken = strtok_s(line, delim, &nextToken);
            if (!dataTypeToken || !strcmp(dataTypeToken, "#")) {
                continue;
            }

            // Handle line data
            char* dataToken = strtok_s(NULL, delim, &nextToken);    // First data token
            switch (lineTypeMap[dataTypeToken]) {
            case GROUP: {
                printf("GROUP\n");
                break;
            }
            case S: {
                printf("S\n");
                break;
            }
            case USEMATERIAL: {
                printf("USE MATERIAL\n");
                break;
            }
            case MATERIALLIB: {
                printf("MATERIALLIB\n");
                break;
            }
            case VERTEX: {
                printf("VERTEX:");
                glm::vec3 newVertex;
                vertices.push_back(newVertex);

                int i = 0;
                while (dataToken) {
                    vertices[vertices.size() - 1][i] = std::stof(dataToken);
                    dataToken = strtok_s(NULL, delim, &nextToken);
                    i++;
                }
                break;
            }
            case TEXTURE: {
                printf("TEXTURE\n");
                glm::vec2 newVertex;
                textureCoords.push_back(newVertex);

                int i = 0;
                while (dataToken) {
                    textureCoords[textureCoords.size() - 1][i] = std::stof(dataToken);
                    dataToken = strtok_s(NULL, delim, &nextToken);
                    i++;
                }
                break;
            }
            case NORMAL: {
                printf("NORMAL\n");
                glm::vec3 newVertex;
                normals.push_back(newVertex);

                int i = 0;
                while (dataToken) {
                    normals[normals.size() - 1][i] = std::stof(dataToken);
                    dataToken = strtok_s(NULL, delim, &nextToken);
                    i++;
                }
                break;
            }
            case FACE: {
                printf("FACE\n");
                break;
            }
            case OTHER: {
                printf("OTHER\n");
                break;
            }
        }
        }

        //for (int i = 0; i < vertices.size(); i++) {
        //    printf("%2f : %2f : %2f\n", vertices[i][0], vertices[i][1], vertices[i][2]);
        //}

        //for (int i = 0; i < textureCoords.size(); i++) {
        //    printf("%2f : %2f\n", textureCoords[i][0], textureCoords[i][1]);
        //}

        //for (int i = 0; i < normals.size(); i++) {
        //    printf("%2f : %2f : %2f\n", normals[i][0], normals[i][1], normals[i][2]);
        //}
    }


    objFileStream.close();
}

int main() {
    loadObject("Well.obj");

    /*
    // create the window
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

    // load resources, initialize the OpenGL states, ...

    // run the main loop
    bool running = true;
    while (running) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized) {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw...

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...
    */
    return 0;
}