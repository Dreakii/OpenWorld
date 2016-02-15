#330
in vec3 UV;
in vec3 Light;
in vec3 sunner;
in vec4 shadow;
in float flower;

uniform sampler2DArray Color;
uniform sampler2D Shad;
void main(void)
{
	vec3 texpos;
	texpos = UV;
	if(UV.z == 6)
	{
		texpos.y -= flower;
		if(texpos.y < 0)
			texpos.y += 1;
	}
	if(texture(Color, texpos).rgb == vec3(0,1,0))
		discard;
	float force = dot( normalize(Light) , normalize(-sunner));
	vec4 tmp;
	if(force > 0.05)
		if(texture(Shad,shadow.xy).z < shadow.z-0.001)
			tmp = texture(Color, texpos);
		else
			tmp = vec4(texture(Color, texpos).rgb * max( force*0.6 + 1 , 1 ) , 1 );
	else
		tmp = texture(Color, texpos);
	gl_FragColor = tmp;
}
