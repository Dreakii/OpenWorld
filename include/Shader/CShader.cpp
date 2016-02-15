//CShader.cpp

#include"CShader.hpp"

CShader::CShader()
{
    Program = glCreateProgram();
}

void CShader::addShaders(string vShader , string fShader)
{
    Vshader = glCreateShader(GL_VERTEX_SHADER);
    Fshader = glCreateShader(GL_FRAGMENT_SHADER);

    vShader = DownloadFile(vShader);

    GLchar *VStringPtr[1];
    VStringPtr[0] = (GLchar *)vShader.c_str();
    glShaderSource(Vshader , 1 ,  (const GLchar **)VStringPtr , NULL);

    fShader = DownloadFile(fShader);

    GLchar *FStringPtr[1];
    FStringPtr[0] = (GLchar *)fShader.c_str();
    glShaderSource(Fshader , 1 ,  (const GLchar **)FStringPtr , NULL);

    glCompileShader(Vshader);

    char vtex[9999];
    glGetShaderInfoLog(Vshader, 9999, NULL, &vtex[0]);
    fprintf(stdout, "%s\n", &vtex[0]);

    glCompileShader(Fshader);

    char ftex[9999];
    glGetShaderInfoLog(Fshader, 9999, NULL, &ftex[0]);
    fprintf(stdout, "%s\n", &ftex[0]);

    testVal = GL_FALSE;

    glGetShaderiv(Vshader, GL_COMPILE_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
        cout << "nie udalo sie skompilowac shadera!";
    }
    glGetShaderiv(Fshader, GL_COMPILE_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
        cout << "nie udalo sie skompilowac shadera!";
    }

    Program = glCreateProgram();

    glAttachShader(Program , Vshader);
    glAttachShader(Program , Fshader);

    glLinkProgram(Program);

    glDeleteShader(Vshader);
    glDeleteShader(Fshader);
}

string CShader::DownloadFile(string ShaderFile)
{
    fstream file(ShaderFile.c_str() , ios::in);

    string shader;
    string line;

    while( file >> line)
    {
        shader += line + "\n";
    }

    return shader;
}

GLuint CShader::GetProgram() {return Program;}

void CShader::set(string filename , SUniform& uni)
{
    fstream file(filename , ios::in);
    int count;
    file >> count;
    string parm;
    for(int i = 0 ; i < count ; i++)
    {
        glEnableVertexAttribArray(i);
        file >> parm;
        glBindAttribLocation(Program, i , parm.c_str());
    }
    glLinkProgram(Program);

    file >> count;
    for(int i = 0 ; i < count ; i++)
    {
        file >> parm;
        if(parm == "mvp")
            uni.matrix = glGetUniformLocation(Program, parm.c_str());
        if(parm == "mvp_depth")
            uni.matrix_depth = glGetUniformLocation(Program, parm.c_str());
        if(parm == "move")
            uni.move = glGetUniformLocation(Program, parm.c_str());
        if(parm == "rotate")
            uni.rotate = glGetUniformLocation(Program, parm.c_str());
        if(parm == "sun")
            uni.sun = glGetUniformLocation(Program, parm.c_str());
        if(parm == "Color")
            uni.Color = glGetUniformLocation(Program, parm.c_str());
        if(parm == "Shad")
            uni.Shad = glGetUniformLocation(Program, parm.c_str());
        if(parm == "flow")
            uni.flow = glGetUniformLocation(Program, parm.c_str());
    }
}
