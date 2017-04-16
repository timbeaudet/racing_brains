///
///
///

#include "visualizer.h"
#include "graphics/tb_line.h"
#include "graphics/implementation/tbi_renderer.h"

//--------------------------------------------------------------------------------------------------------------------//

Visualizer::VisualizerInterface::VisualizerInterface(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

Visualizer::VisualizerInterface::~VisualizerInterface(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

void Visualizer::VisualizerInterface::DrawBox(const float x, const float y, const float width, const float height, const Color& color)
{
	Vertex triVertices[6];
	
	triVertices[0].x = x;         triVertices[0].y = y;          triVertices[0].z = 0.0f;
	triVertices[1].x = x + width; triVertices[1].y = y;          triVertices[1].z = 0.0f;
	triVertices[2].x = x + width; triVertices[2].y = y + height; triVertices[2].z = 0.0f;
	triVertices[3].x = x + width; triVertices[3].y = y + height; triVertices[3].z = 0.0f;
	triVertices[4].x = x;         triVertices[4].y = y + height; triVertices[4].z = 0.0f;
	triVertices[5].x = x;         triVertices[5].y = y;          triVertices[5].z = 0.0f;
	DrawTriangles(triVertices, 6, (color & 0x00FFFFFF) | 0x88FFFFFF);

	Vertex lineVertices[8];
	lineVertices[0].x = x;         lineVertices[0].y = y;          lineVertices[0].z = 0.0f;
	lineVertices[1].x = x + width; lineVertices[1].y = y;          lineVertices[1].z = 0.0f;
	lineVertices[2].x = x + width; lineVertices[2].y = y;          lineVertices[2].z = 0.0f;
	lineVertices[3].x = x + width; lineVertices[3].y = y + height; lineVertices[3].z = 0.0f;
	lineVertices[4].x = x + width; lineVertices[4].y = y + height; lineVertices[4].z = 0.0f;
	lineVertices[5].x = x;         lineVertices[5].y = y + height; lineVertices[5].z = 0.0f;
	lineVertices[6].x = x;         lineVertices[6].y = y + height; lineVertices[6].z = 0.0f;
	lineVertices[7].x = x;         lineVertices[7].y = y;          lineVertices[7].z = 0.0f;
	DrawLines(lineVertices, 8, color);
}

//--------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------//

Visualizer::NullVisualizer::NullVisualizer(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

Visualizer::NullVisualizer::~NullVisualizer(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

void Visualizer::NullVisualizer::DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color)
{
	((void)vertices);
	((void)vertexCount);
	((void)color);
}

//--------------------------------------------------------------------------------------------------------------------//

void Visualizer::NullVisualizer::DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color)
{
	((void)vertices);
	((void)vertexCount);
	((void)color);
}

//--------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------//

Visualizer::TurtleBrainsVisualizer::TurtleBrainsVisualizer(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

Visualizer::TurtleBrainsVisualizer::~TurtleBrainsVisualizer(void)
{
}

//--------------------------------------------------------------------------------------------------------------------//

void Visualizer::TurtleBrainsVisualizer::DrawTriangles(const Vertex* vertices, const uint32_t& vertexCount, const Color& color)
{
	tbImplementation::Renderer::Vertex2D* tbVertices = new tbImplementation::Renderer::Vertex2D[vertexCount];

	for (uint32_t index(0); index < vertexCount; ++index)
	{
		tbVertices[index].x = vertices[index].x;
		tbVertices[index].y = vertices[index].y;
		tbVertices[index].u = tbVertices[index].v = 0.0f;

		tbVertices[index].abgr = tbGraphics::Color(color).GetColorABGR();
	}

	tbImplementation::Renderer::Render(tbImplementation::Renderer::kTriangles, tbVertices, vertexCount);

	delete [] tbVertices;
	tbVertices = nullptr;
}

//--------------------------------------------------------------------------------------------------------------------//

void Visualizer::TurtleBrainsVisualizer::DrawLines(const Vertex* vertices, const uint32_t& vertexCount, const Color& color)
{
	for (uint32_t index(0); index < vertexCount; index += 2)
	{
		const tbMath::Vector2 startPoint(vertices[index].x, vertices[index].y);
		const tbMath::Vector2 finalPoint(vertices[index + 1].x, vertices[index + 1].y);
		tbGraphics::Line line(startPoint, finalPoint, tbGraphics::Color(color));
		line.Render();
	}
}

//--------------------------------------------------------------------------------------------------------------------//
