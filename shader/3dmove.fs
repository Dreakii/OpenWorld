#330
in vec2 UV;
in vec3 Light;
in vec3 sunner;

uniform sampler2D Color;
void main(void)
{
	float force = dot( normalize(Light) , normalize(sunner));
	vec4 tmp;
	if(force > 0.0001)
		tmp = vec4(texture(Color, UV).rgb * max( force*0.6 + 1 , 1 ) , 1 );
	else
		tmp = texture(Color, UV);
	gl_FragColor = tmp;
}