#ifndef MESH_HPP
#define MESH_HPP

#include <glm/glm.hpp>
#include <string>
#include <vector>

#include "shader.hpp"

using namespace std;

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture
{
    unsigned int id;
    string type; // diffuse ou specular
    string path; // On stocke le chemin du fichier pour vérifier si la texture est déjà chargée
};

class Mesh
{
public:
    // Données du mesh
    vector<Vertex> vertices;
    vector<unsigned int> indices; // Les indices des vertices pour l’EBO
    vector<Texture> textures;


    // Constructeur
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    // Méthode pour dessiner le mesh
    void Draw(Shader &shader);
    void CleanUp();


private:
    // Identifiants des buffers
    unsigned int VAO, VBO, EBO;
    // Initialisation des buffers
    void setupMesh();
};

#endif