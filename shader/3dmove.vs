#330
attribute vec4 vVertex;
attribute vec2 texcoord;
attribute vec3 Normal;

uniform mat4x4 mvp;
uniform mat4x4 rotate;
uniform vec4 move;
uniform vec4 sun;

varying vec2 UV;
varying vec3 Light;
varying vec3 sunner;

void main(void)
{
	gl_Position = mvp * (move + (vec4(vVertex.xyz , 1)  * rotate));
	UV = texcoord;
	Light = vec4(vec4(Normal , 1) * rotate).xyz;
	sunner = sun.xyz;
}