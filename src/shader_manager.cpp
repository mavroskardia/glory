#include "includes.h"

ShaderManager::~ShaderManager() {

    for (GLuint prog : programs) {
        glDeleteProgram(prog);
    }

    for (GLuint shader : shaders) {
        glDeleteShader(shader);
    }

}

std::string ShaderManager::readfile(const char* fname) {

    std::ifstream ifs(fname);
    std::string ret = std::string(std::istreambuf_iterator<char>(ifs),
                                  std::istreambuf_iterator<char>());

    return ret;

}

GLuint ShaderManager::compile_shader_from_string(const std::string prog, GLint type) {

	const char* src = prog.c_str();

    GLuint ret = glCreateShader(type);
    glShaderSource(ret, 1, &src, NULL);
    glCompileShader(ret);

    GLint status;
    glGetShaderiv(ret, GL_COMPILE_STATUS, &status);

    if (status != GL_TRUE) {
        std::cerr << "Failed to compile shader:" << std::endl;
        char buffer[512];
        glGetShaderInfoLog(ret, 512, NULL, buffer);
        std::cerr << buffer << std::endl;
        return -1;
    }

    return ret;
}

GLuint ShaderManager::load_vertex_shader(const char* fname) {

	return compile_shader_from_string(readfile(fname), GL_VERTEX_SHADER);

}

GLuint ShaderManager::load_fragment_shader(const char* fname) {

	return compile_shader_from_string(readfile(fname), GL_FRAGMENT_SHADER);

}

GLuint ShaderManager::create_program(const char* vertex_shader_fname,
                                     const char* fragment_shader_fname) {

    GLuint vshader = load_vertex_shader(vertex_shader_fname);
    GLuint fshader = load_fragment_shader(fragment_shader_fname);

    GLuint prog = glCreateProgram();
    glAttachShader(prog, vshader);
    glAttachShader(prog, fshader);

    // this will need to be parameterized
    glBindFragDataLocation(prog, 0, "outColor");
    glLinkProgram(prog);

    shaders.push_back(vshader);
    shaders.push_back(fshader);

    programs.push_back(prog);

    return prog;

}