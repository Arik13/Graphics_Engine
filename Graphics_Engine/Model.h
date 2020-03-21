#pragma once

#include "Mesh.h"
#include "Shader.h"

class Model {
public:
    /*  Functions   */
    Model(char* path) {
        loadModel(path);
    }
    void Draw(Shader shader);
private:
    /*  Model Data  */
    std::vector<Mesh> meshes;
    std::string directory;
    /*  Functions   */
    void loadModel(std::string path);
    //void processNode(aiNode* node, const aiScene* scene);
    //Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    //std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

