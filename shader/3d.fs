#330
in vec2 UV;
in vec3 Light;
in vec3 sunner;
in vec4 shadow;

uniform sampler2D Color;
uniform sampler2D Shad;
void main(void)
{
	float force = dot( normalize(Light) , normalize(-sunner));
	vec4 tmp;
	if(force > 0.05)
		if(texture(Shad,shadow.xy).z < shadow.z-0.001)
			tmp = texture(Color, UV);
		else
			tmp = vec4(texture(Color, UV).rgb * max( force*0.6 + 1 , 1 ) , 1 );
	else
		tmp = texture(Color, UV);
	gl_FragColor = tmp;	
}
