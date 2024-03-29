#include "Renderer/Shape.h"
#include "Utility/Utility.h"
#include <glm/gtc/matrix_transform.inl>

namespace Eucolus
{
	Shape::Shape()
	{
	}

	Shape::~Shape()
	{
	}

	//
	//Rect
	//

	DrawableRect::DrawableRect()
	{
	}

	DrawableRect::~DrawableRect()
	{
	}

	DrawableRect::DrawableRect(Vector2f position, Vector2f size, Color color)
	{
		Colorf fillColor = ToColorf(color);

		fillColor = Colorf(1.0f, 1.0f, 1.0f, 1.0f);

		Vertex vertices[] = {
			Vertex(Vector2f(position.m_x,				position.m_y),				fillColor, Vector2f(0.0f, 0.0f)), //Top left
			Vertex(Vector2f(position.m_x + size.m_x,	position.m_y),				fillColor, Vector2f(1.0f, 0.0f)), //Top right
			Vertex(Vector2f(position.m_x + size.m_x,	position.m_y + size.m_y),	fillColor, Vector2f(1.0f, 1.0f)), //Bottom right
			Vertex(Vector2f(position.m_x,				position.m_y + size.m_y),	fillColor, Vector2f(0.0f, 1.0f)) //Bottom left
		};

		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		Vector3ui indexes[] = {
			Vector3ui(0, 1, 2),
			Vector3ui(2, 3, 0)
		};

		glGenBuffers(1, &m_ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
	}

	void DrawableRect::Render()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		//Position - 0
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0); //8 values in vertex

		//Color - 1
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(2 * sizeof(float))); //pointer to offset

		//TextureCoords - 2
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); //pointer to offset

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //Actually signed int

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void DrawableRect::RenderBorder()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		//Position - 0
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0); //8 values in vertex

																			   //Color - 1
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(2 * sizeof(float))); //pointer to offset

																										//TextureCoords - 2
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); //pointer to offset

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //Actually signed int

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
