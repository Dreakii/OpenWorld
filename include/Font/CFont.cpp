//CFont.cpp

#include"CFont.hpp"

/*CFont::CFont(char* filename) : tex()
{
	FT_Init_FreeType(&ft);
	FT_New_Face(ft, filename, 0, &face);
	FT_Set_Pixel_Sizes(face, 0, 1000);

	glGenBuffers(1, &buf);
	glBindBuffer(GL_ARRAY_BUFFER, buf);

	glEnableVertexAttribArray(0);
	//glGenTextures(1, &tex);
	//glBindTexture(GL_TEXTURE_2D, tex);
	//glUniform1i(Color, 0);
}

void CFont::draw(string sub , float x , float y , float size)
{
	glBindTexture(GL_TEXTURE_2D , tex.texId);
	glBindBuffer(GL_ARRAY_BUFFER, buf);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	GLfloat shift = 0.0;

	float width;
	float top;
	float down;

	for(char& X : sub)
	{
		FT_Load_Char(face, X , FT_LOAD_RENDER);
		glTexImage2D(GL_TEXTURE_2D,0,GL_ALPHA,face->glyph->bitmap.width,face->glyph->bitmap.rows,0,GL_ALPHA,GL_UNSIGNED_BYTE,face->glyph->bitmap.buffer);

		if(X != ' ')
			width =  (float)(face->glyph->bitmap.width)/(1000);
		else
			width = 0.5;

		top = (float)(face->glyph->bitmap_top)/(1000);

		down = (float)(face->glyph->bitmap_top - face->glyph->bitmap.rows)/1000;



		GLfloat box[4][4] = {
			{ x + size * width + shift , y - size + size * top  , 1 , 0},
			{ x + size * width + shift , y - size + size * down , 1 , 1},
			{ x                + shift , y - size + size * top  , 0 , 0},
			{ x                + shift , y - size + size * down , 0 , 1},
		};

		glBindBuffer(GL_ARRAY_BUFFER, buf);
		glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_DYNAMIC_DRAW);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		shift += size * width;
	}
}*/
