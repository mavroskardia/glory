#include "includes.h"

ShaderManager::~ShaderManager() {

    for (auto prog : programs) {
        glDeleteProgram(prog.second);
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

GLuint ShaderManager::create_program(const char* program_name,
                                     const char* vertex_shader_fname,
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

    programs[program_name] = prog;

    debugout("Created shader program with id " << prog << " -- calling it " << program_name << " with id " << programs[program_name])

    return prog;
}

GLuint ShaderManager::get_uniform_location(const char* program_name,
                                           const char* uniform_name) {

    GLuint loc = glGetUniformLocation(programs[program_name], uniform_name);

    debugout("get_uniform_location: " << program_name << " has uniform " << uniform_name << " at " << loc);

    return loc;

}
