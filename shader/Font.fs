#330
 
smooth in vec2 texcoord;

uniform vec4 col;
uniform sampler2D Color;
 
void main(void)
{
	if(texture(Color, texcoord).a == 1)
		gl_FragColor = col;
	else
		discard;
}