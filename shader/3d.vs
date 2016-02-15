#330

attribute vec4 vVertex;
attribute vec3 texcoord;
attribute vec3 Normal;

uniform mat4x4 mvp;
uniform mat4x4 mvp_depth;
uniform vec4 sun;
uniform float flow;

varying vec3 UV;
varying vec3 Light;
varying vec3 sunner;
varying vec4 shadow;
varying float flower;

void main(void)
{
	const mat4  biasMatrix = mat4(
	0.5, 0.0, 0.0, 0.0,
	0.0, 0.5, 0.0, 0.0,
	0.0, 0.0, 0.5, 0.0,
	0.5, 0.5, 0.5, 1.0
	); 
	
	gl_Position =  mvp * vec4(vVertex.xyz , 1);
	UV = texcoord;
	Light = Normal;
	sunner = sun.xyz;
	flower = flow;
	shadow = biasMatrix * mvp_depth * vec4(vVertex.xyz,1);
}
