#include "includes.h"

class ShaderManager {

	std::string readfile(const char* fname);
	GLuint compile_shader_from_string(const std::string prog, GLint type);

	std::vector<GLuint> programs;
	std::vector<GLuint> shaders;

public:

	~ShaderManager();

    GLuint load_vertex_shader(const char* fname);
    GLuint load_fragment_shader(const char* fname);
    GLuint create_program(const char* vertex_shader_fname, const char* fragment_shader_fname);

};