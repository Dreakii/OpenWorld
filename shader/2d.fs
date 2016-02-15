#330
 
in vec2 texcoord;
uniform sampler2D Color;
 
void main(void)
{
	if(texture(Color, texcoord) != vec3(1,1,1))
		gl_FragColor = texture(Color, texcoord);
	else
		discard;
}