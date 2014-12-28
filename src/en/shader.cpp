#include "../h.h"
#include "shader.h"
#include "../ll/files.h"

//#include "shaders/FontVertexShader.txt"
//#include "shaders/FontFragmentShader.txt"

en::Shader::Shader(const char *vertex, const char *fragment) :
	vertex(vertex),
	fragment(fragment)
	{
	create();
}

en::Shader::~Shader() {}

void en::Shader::create() {
	vid = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vid, 1, &vertex, NULL);
    glCompileShader(vid);
	
	fid = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fid, 1, &fragment, NULL);
    glCompileShader(fid);
	
	pid = glCreateProgram();
	glAttachShader(pid, vid);
	glAttachShader(pid, fid);
    glLinkProgram(pid);
	
    if ( GL_NO_ERROR != glGetError() ) {
		
	}
}

void en::Shader::link() {
	// asd
}

/*void en::CreateShaders(void)
{
    GLenum ErrorCheckValue = glGetError();
     
    VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShaderId, 1, &VertexShader, NULL);
    glCompileShader(VertexShaderId);
 
    FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShaderId, 1, &FragmentShader, NULL);
    glCompileShader(FragmentShaderId);
	
	ProgramId = glCreateProgram();
	glAttachShader(ProgramId, VertexShaderId);
	glAttachShader(ProgramId, FragmentShaderId);
    glLinkProgram(ProgramId);
    //glUseProgram(ProgramId);
	
	//
	fntvrtxshdr = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(fntvrtxshdr, 1, &fntvrtxshdrtxt, NULL);
    glCompileShader(fntvrtxshdr);
	bool vrtxerr = shadererrors(fntvrtxshdr);
	
	fntfrgmntshdr = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fntfrgmntshdr, 1, &fntfrgmntshdrtxt, NULL);
    glCompileShader(fntfrgmntshdr);
	bool frgmnterr = shadererrors(fntfrgmntshdr);
 	
	if (  frgmnterr ) {
		fntprgrm = glCreateProgram();
		//glAttachShader(fntprgrm, fntvrtxshdr);
		glAttachShader(fntprgrm, fntfrgmntshdr);
		glLinkProgram(fntprgrm);
	}
	
	ErrorCheckValue = glGetError();
    if (ErrorCheckValue != GL_NO_ERROR)
    {
        fprintf(
            stderr,
            "shaders error: %s \n",
            gluErrorString(ErrorCheckValue)
        );
 
        //exit(-1);
    }
}*/

/*void en::DestroyShaders(void)
{
    GLenum ErrorCheckValue = glGetError();
 
    glUseProgram(0);
 
    glDetachShader(ProgramId, VertexShaderId);
    glDetachShader(ProgramId, FragmentShaderId);
 
    glDeleteShader(FragmentShaderId);
    glDeleteShader(VertexShaderId);
 
    glDeleteProgram(ProgramId);
	
	glDetachShader(fntprgrm, fntvrtxshdr);
    glDetachShader(fntprgrm, fntfrgmntshdr);
 
    glDeleteShader(fntfrgmntshdr);
    glDeleteShader(fntvrtxshdr);
 
    glDeleteProgram(fntprgrm);
 
    ErrorCheckValue = glGetError();
    if (ErrorCheckValue != GL_NO_ERROR)
    {
        fprintf(
            stderr,
            "ERROR: Could not destroy the shaders: %s \n",
            gluErrorString(ErrorCheckValue)
        );
 
        exit(-1);
    }
}*/

bool en::shadererrors(GLuint &s) {
	GLint isCompiled = 0;
	glGetShaderiv(s, GL_COMPILE_STATUS, &isCompiled);
	if(isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(s, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(s, maxLength, &maxLength, &errorLog[0]);
		//fwrite(&errorLog[0], sizeof(char), maxLength, log);
		//Exit with failure.? =/=
		glDeleteShader(s); //Don't leak the shader.
		return true;
	}
	return false;
}
