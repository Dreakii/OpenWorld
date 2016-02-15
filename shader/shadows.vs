#330
attribute vec4 vVertex;

uniform mat4x4 mvp;


void main(void)
{
	gl_Position = mvp * vVertex;
}